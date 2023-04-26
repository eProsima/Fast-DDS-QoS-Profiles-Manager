#! /bin/bash

# Deployment file
FILE=deployment.json
XML_FILE_NAME_PREFIX=fastdds_config

# Parse deployment file
COUNTER=0
NAME=$(jq .nodes[$COUNTER] $FILE | jq .name)
# Extract node deployment information and generate corresponding XML configuration file
while [ $NAME != "null" ]; do
    # Parse node information and remove quote character
    NAME=${NAME//\"}

    echo "Creating $NAME XML configuration file"

    # Calls to Fast DDS QoS Profile Manager CLI
    XML_FILE_NAME="${XML_FILE_NAME_PREFIX}_${NAME}.xml"
    ## Transport descriptor
    fastddsqosprof $XML_FILE_NAME set transport_descriptor[ContainerTransport].interface_whitelist[] 172.17.0.1
    fastddsqosprof $XML_FILE_NAME set transport_descriptor[ContainerTransport].interface_whitelist[] 127.0.0.1
    ### This transport is defined but not used (!)
    fastddsqosprof $XML_FILE_NAME set transport_descriptor[LocalShmTransport].kind shm
    ## Participant lease duration
    fastddsqosprof $XML_FILE_NAME set participant[participant_profile_fog_sw].builtin.discovery_config.duration.lease 50 0
    ## Participant announcement period
    fastddsqosprof $XML_FILE_NAME set participant[participant_profile_fog_sw].builtin.discovery_config.duration.announcements 6 0
    ## User transports
    fastddsqosprof $XML_FILE_NAME set participant[participant_profile_fog_sw].user_transports[] ContainerTransport
    ## Disable builtin transports
    fastddsqosprof $XML_FILE_NAME set participant[participant_profile_fog_sw].use_builtin_transports false
    ## DataWriter QoS
    ### Reliability
    fastddsqosprof $XML_FILE_NAME set datawriter[datawriter_profile_fog_sw].qos.reliability.kind best_effort
    ###Durability
    fastddsqosprof $XML_FILE_NAME set datawriter[datawriter_profile_fog_sw].qos.durability volatile
    ## DataReader QoS
    ### Reliability
    fastddsqosprof $XML_FILE_NAME set datareader[datareader_profile_fog_sw].qos.reliability.kind best_effort
    ###Durability
    fastddsqosprof $XML_FILE_NAME set datareader[datareader_profile_fog_sw].qos.durability volatile
    ## Set as default profile (the profile MUST exist)
    fastddsqosprof $XML_FILE_NAME set participant[participant_profile_fog_sw].default_profile
    fastddsqosprof $XML_FILE_NAME set datawriter[datawriter_profile_fog_sw].default_profile
    fastddsqosprof $XML_FILE_NAME set datareader[datareader_profile_fog_sw].default_profile

    COUNTER=$COUNTER+1
    NAME=$(jq .nodes[$COUNTER] $FILE | jq .name)
done
