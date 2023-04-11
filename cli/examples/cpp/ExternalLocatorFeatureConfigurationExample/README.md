# Fast DDS QoS Profiles Manager CLI example

This folder includes an example with a bash script that automatizes the generation of the XML configuration files given some deployment information.
The deployment information is included in the JSON file.

The deployment includes 2 drones with 2 Virtual Machines (VM) running inside, each of them running 2 containers.
However, only 4 XML configuration files are generated because the XML configuration file differs only at the VM level.
Consequently, the same XML configuration file should be used for every container running within the corresponding VM.

The example depends on [jq](https://stedolan.github.io/jq/) in order to parse the deployment information contained in the JSON file.
To install in Ubuntu just run:

```bash
sudo apt install jq
```

Run the script with the following command. Be aware that the deployment JSON configuration file must be in the folder where the command is run and it must be called `deployment.json`.

```bash
bash cli_example_script.sh
```

Disclaimer: this specific example only configures the external locators taking into account the deployment information provided.
The example should be extended if some other configuration is required.
