# Fast DDS QoS Profiles Manager CLI testing

The CLI test plan is still pending.
This document includes CLI commands and the expected CLI output in order to help with the test implementation.

| CLI command | Expected output | Usage |
|---|---|---|
|`fastddsqosprof`|`Arguments did not match expected patterns`|`USAGE`|
|`fastddsqosprof -h`|N/A|`USAGE`|
|`fastddsqosprof --help`|N/A|`USAGE`|
|`fastddsqosprof -v`|`fastdds_qos_profiles_manager_cli <version>`|N/A|
|`fastddsqosprof --version`|`fastdds_qos_profiles_manager_cli <version>`|N/A|
|`fastddsqosprof file.xml`|`Arguments did not match expected patterns`|`USAGE`|
|`fastddsqosprof file.xml clear`|`ERROR: clear command requires only one follow-up argument`|`CLEAR_USAGE`|
|`fastddsqosprof file.xml clear element`|**PENDING** (currently `Clear subparser not yet implemented`)|Docopt error `Docopt usage string could not be parsed`|
|`fastddsqosprof file.xml compare`|`ERROR: compare command requires only one follow-up argument`|`COMPARE_USAGE`|
|`fastddsqosprof file_1.xml compare file_2.xml`|**PENDING** (currently `Compare feature not yet implemented`)|N/A|
|`fastddsqosprof file.xml help`|N/A|`USAGE`|
|`fastddsqosprof file.xml help element`|`ERROR: help command requires no follow-up element`|`HELP_USAGE`|
|`fastddsqosprof file.xml print`|**PENDING** (currently `Print of file feature not yet implemented`)|N/A|
|`fastddsqosprof file.xml print element`|**PENDING** (currently `Print subparser not yet implemented`)|Docopt error `Docopt usage string could not be parsed`|
|`fastddsqosprof file.xml query`|`ERROR: query command requires at least one follow-up argument`|`QUERY_USAGE`|
|`fastddsqosprof file.xml query element`|**PENDING** (currently `Query subparser not yet implemented`)|N/A|
|`fastddsqosprof file.xml set`|`ERROR: set command requires at least one follow-up argument`|`SET_USAGE`|
|`fastddsqosprof file.xml validate`|**PENDING** (currently `Validate feature not yet implemented`)|N/A|
|`fastddsqosprof file.xml other`|`ERROR: other command not recognized`|`USAGE`|
|`fastddsqosprof file.xml set -h`|N/A|`SET_SUBPARSER_USAGE`|
|`fastddsqosprof file.xml set --help`|N/A|`SET_SUBPARSER_USAGE`|
|`fastddsqosprof file.xml set help`|N/A|`SET_SUBPARSER_USAGE`|
|`fastddsqosprof file.xml set datareader`|**PENDING** (currently `DataReader configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter`|**PENDING** (currently `DataWriter configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set intraprocess`|**PENDING** (currently `Intra-process configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set log`|**PENDING** (currently `Log module configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant`|`ERROR: profile name is required for participant elements` [^1]|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set topic`|**PENDING** (currently `Topic configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set transport_descriptor`|**PENDING** (currently `Transport descriptor configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set types`|**PENDING** (currently `Dynamic types configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set other`|`ERROR: other element not recognized`|`SET_SUBPARSER_USAGE`|
|`fastddsqosprof file.xml set participant -h`|N/A|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant --help`|N/A|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant help`|N/A|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant argument1 argument2 help`|N/A|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant.name`|`ERROR: profile name is required for participant elements`|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant[]`|`ERROR: profile name is required for participant elements`|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant[profile]`|`ERROR: participant must not be FINAL element`|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant["a profile"]`|`ERROR: participant must not be FINAL element`|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant[profile].allocations`|**PENDING** (currently `Participant allocations configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].binary_property`|**PENDING** (currently `Participant binary properties configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin`|**PENDING** (currently `Participant builtin configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].default_profile`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].domain_id`|**PENDING** (currently `Participant domain ID configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators`|`ERROR: Participant <external_locators> must not be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].guid_prefix`|**PENDING** (currently `Participant GUID prefix configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].id`|**PENDING** (currently `Participant ID configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].ignore_non_matching_locators`|**PENDING** (currently `Participant ignore non matching locators configuration flag not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].listen_socket_buffer_size`|**PENDING** (currently `Participant listen socket buffer size configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].locators`|**PENDING** (currently `Participant locators configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].name`|**PENDING** (currently `Participant name configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].port`|**PENDING** (currently `Participant port parameters configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].property`|**PENDING** (currently `Participant properties configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].send_socket_buffer_size`|**PENDING** (currently `Participant send socket buffer size configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports`|**PENDING** (currently `Participant use builtin transports flag configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].user_data`|**PENDING** (currently `Participant user data QoS configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].user_transports`|**PENDING** (currently `Participant user transports configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].other`|`ERROR: other element not recognized`|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].other -h`|N/A|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile -h`|N/A|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile --help`|N/A|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile help`|N/A|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile argument1 argument2 help`|N/A|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile[]`|`ERROR: Participant <default_profile> must not be keyed []`|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile.element`|`ERROR: Participant <default_profile> must be FINAL element`|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile argument`|`ERROR: Participant <default_profile> expects 0 arguments and received 1`|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators --help`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators help`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators argument1 argument2 help`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators[].default_unicast`|`ERROR: Participant <external_locators> must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast`|`ERROR: Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast argument`|`ERROR: external locator <default_unicast> list must be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.other argument`|`ERROR: other subelement not recognized`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[] -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[] argument`|`ERROR: external locator <default_unicast> list expects 6 arguments and received 1`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[] arg1 arg2 arg3 arg4 arg5 arg6`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].address`|`ERROR: Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].address -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].address argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].address argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].address[] argument`|`ERROR: external locator <default_unicast> list <address> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].address.element argument`|`ERROR: external locator <default_unicast> list <address> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].cost`|`ERROR: Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].cost -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].cost argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].cost argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].cost[] argument`|`ERROR: external locator <default_unicast> list <cost> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].cost.element argument`|`ERROR: external locator <default_unicast> list <cost> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality`|`ERROR: Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].externality argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality[] argument`|`ERROR: external locator <default_unicast> list <externality> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality.element argument`|`ERROR: external locator <default_unicast> list <externality> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].kind`|`ERROR: Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].kind -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].kind argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].kind argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].kind[] argument`|`ERROR: external locator <default_unicast> list <kind> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].kind.element argument`|`ERROR: external locator <default_unicast> list <kind> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].mask`|`ERROR: Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].mask -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].mask argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].mask argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].mask[] argument`|`ERROR: external locator <default_unicast> list <mask> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].mask.element argument`|`ERROR: external locator <default_unicast> list <mask> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].port`|`ERROR: Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].port -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].port argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].port argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].port[] argument`|`ERROR: external locator <default_unicast> list <port> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].port.element argument`|`ERROR: external locator <default_unicast> list <port> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].other`|`ERROR: Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].other -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].other argument`|`ERROR: other subelement not recognized`|N/A|

[^1]: **PENDING**: Print and clear default profile command will not require a profile name.

## Caveats

This current test plan is focused only on the CLI usage and errors.
Currently, this test plan is not concerned about the validity of the arguments passed to Fast DDS QoS Profiles Manager Library, nor about the handling of the returned information.
