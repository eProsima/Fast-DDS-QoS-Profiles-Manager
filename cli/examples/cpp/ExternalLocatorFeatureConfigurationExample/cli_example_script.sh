#! /bin/bash

# Deployment file
FILE=deployment.json
XML_FILE_NAME_PREFIX=fastdds_config

# Parse deployment file
COUNTER=0
NAME=$(jq .nodes[$COUNTER] $FILE | jq .name)
USER_PORT=$(jq .global_config.user_port $FILE)
DISCOVERY_PORT=$(jq .global_config.discovery_port $FILE)
# Extract node deployment information and generate corresponding XML configuration file
while [ $NAME != "null" ]; do
    # Parse node information and remove quote character
    NAME=${NAME//\"}
    VM_IP=$(jq .nodes[$COUNTER] $FILE | jq .vm_ip)
    VM_IP=${VM_IP//\"}
    DRONE_IP=$(jq .nodes[$COUNTER] $FILE | jq .drone_ip)
    DRONE_IP=${DRONE_IP//\"}

    echo "Creating $NAME XML configuration file:"
    echo "Virtual Machine IP address: $VM_IP"
    echo "Drone IP address: $DRONE_IP"
    echo "User port: $USER_PORT"
    echo "Discovery port: $DISCOVERY_PORT"

    # Calls to Fast DDS QoS Profile Manager CLI
    XML_FILE_NAME="${XML_FILE_NAME_PREFIX}_${NAME}.xml"
    ## External locators for user traffic
    ### Drone IP
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].external_locators.default_unicast[].externality 2
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].external_locators.default_unicast[-1].address $DRONE_IP
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].external_locators.default_unicast[-1].port $USER_PORT
    ### VM IP
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].external_locators.default_unicast[].externality 1
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].external_locators.default_unicast[-1].address $VM_IP
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].external_locators.default_unicast[-1].port $USER_PORT
    ## External locators for discovery traffic
    ### Drone IP
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.external_locators.metatraffic_unicast[].externality 2
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.external_locators.metatraffic_unicast[-1].address $DRONE_IP
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.external_locators.metatraffic_unicast[-1].port $DISCOVERY_PORT
    ### VM IP
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.external_locators.metatraffic_unicast[].externality 1
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.external_locators.metatraffic_unicast[-1].address $VM_IP
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.external_locators.metatraffic_unicast[-1].port $DISCOVERY_PORT
    ## Initial peers: remote participants locators (discovery)
    ### Other containers in the same VM: multicast
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.locators.initial_peers[].address 239.255.0.1
    #### Attention: this port is the one corresponding to the Domain ID 0 according to the DDS specification.
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.locators.initial_peers[-1].port 7400
    ### Other VM in the same drone: traverse remote VM IPs list to add to initial peers list
    INTERNAL_COUNTER=0
    IP_ADDRESS=$(jq .nodes[$COUNTER] $FILE | jq .remote_vm_ip[$INTERNAL_COUNTER] | jq .ip_address)
    while [ $IP_ADDRESS != "null" ]; do
        IP_ADDRESS=${IP_ADDRESS//\"}
        echo "Adding $IP_ADDRESS to initial peers list"

        fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.locators.initial_peers[].address $IP_ADDRESS
        fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.locators.initial_peers[-1].port $DISCOVERY_PORT

        INTERNAL_COUNTER=$INTERNAL_COUNTER+1
        IP_ADDRESS=$(jq .nodes[$COUNTER] $FILE | jq .remote_vm_ip[$INTERNAL_COUNTER] | jq .ip_address)
    done
    ### Other drones in the mesh: traverse remote Drones IPs list to add to initial peers list
    INTERNAL_COUNTER=0
    IP_ADDRESS=$(jq .nodes[$COUNTER] $FILE | jq .remote_drones_ip[$INTERNAL_COUNTER] | jq .ip_address)
    while [ $IP_ADDRESS != "null" ]; do
        IP_ADDRESS=${IP_ADDRESS//\"}
        echo "Adding $IP_ADDRESS to initial peers list"

        fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.locators.initial_peers[].address $IP_ADDRESS
        fastddsqosprof $XML_FILE_NAME set participant[$NAME].builtin.locators.initial_peers[-1].port $DISCOVERY_PORT

        INTERNAL_COUNTER=$INTERNAL_COUNTER+1
        IP_ADDRESS=$(jq .nodes[$COUNTER] $FILE | jq .remote_drones_ip[$INTERNAL_COUNTER] | jq .ip_address)
    done
    ## Set as default profile (the profile MUST exist)
    fastddsqosprof $XML_FILE_NAME set participant[$NAME].default_profile

    COUNTER=$COUNTER+1
    NAME=$(jq .nodes[$COUNTER] $FILE | jq .name)
done
