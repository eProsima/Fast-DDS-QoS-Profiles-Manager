# Fast DDS XML generator CLI Proof Of Concept

This PoC is done using two different external libraries for argument parsing.
The aim is to evaluate the convenience of using either cxxopts or docopt argument parsing external libraries in the CLI of this project.

## Build

To build the PoC, in a terminal with current directory in the PoC root directory, run the following commands:

```bash
    mkdir build && cd build
    cmake ..
    make
    cmake --install . --prefix "../install"
```

After the installation, inside `./install/bin` an executable with name `poc_cxxopts` is located.

## Test case used

This PoC focuses in the parsing of the set command for the Locator properties, defined in the Fast DDS QoS Profiles Manager Proposed Solution.
The following commands are extracted from documentation:

```bash
# Locator type: udpv4, udpv6, tcpv4, tcpv6 (Default: udpv4)
fastddsqosprof file.xml set participant["participant_profile_name"].locators.default_unicast[].type tcpv4
# Modify last element of the vector
fastddsqosprof file.xml set participant["participant_profile_name"].locators.default_unicast[-1].port 7400
# TCP exclusive
fastddsqosprof file.xml set participant["participant_profile_name"].locators.default_unicast[-1].physical_port 5100
# Modify first element of the vector (which in this example is also the last)
fastddsqosprof file.xml set participant["participant_profile_name"].locators.default_unicast[0].address 192.168.1.41
# DNS address names are also supported
fastddsqosprof file.xml set participant["participant_profile_name"].locators.default_unicast[].address localhost
# TCPv4 exclusive
fastddsqosprof file.xml set participant["participant_profile_name"].locators.default_unicast[0].unique_lan_id 192.168.1.1.1.1.2.55
fastddsqosprof file.xml set participant["participant_profile_name"].locators.default_unicast[0].wan_address 80.80.99.45
# Ease locator addition: kind address port
fastddsqosprof file.xml set participant["participant_profile_name"].locators.default_unicast[] tcpv6 ::1 8844
```

## PoC using cxxopts

### Execution

The program prints some "debug" information about the parsing being made.
This printed info can be contrasted with the code of the program to see how the external library works and how it can be configured and used.
As an example, with the `/install/bin` folder as current directory of a terminal, the following commands can be executed (separately) in order to run the executable and to see the obtained printed output:

```bash
./poc_cxxopts help
./poc_cxxopts file.xml help
./poc_cxxopts file.xml set
./poc_cxxopts file.xml set participant["participant_profile_name"].locators.default_unicast[].type tcpv4
./poc_cxxopts file.xml set participant["participant_profile_name"].locators.default_unicast[] tcpv6 ::1 8844
```
