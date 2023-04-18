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
|`fastddsqosprof file.xml set datareader`|`ERROR: datareader requires a profile name` [^1]|`DATAREADER_USAGE`|
|`fastddsqosprof file.xml set datawriter`|`ERROR: datawriter requires a profile name` [^1]|`DATAWRITER_USAGE`|
|`fastddsqosprof file.xml set intraprocess`|**PENDING** (currently `Intra-process configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set log`|**PENDING** (currently `Log module configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant`|`ERROR: participant requires a profile name` [^1]|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set topic`|**PENDING** (currently `Topic configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set transport_descriptor`|**PENDING** (currently `Transport descriptor configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set types`|**PENDING** (currently `Dynamic types configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set other`|`ERROR: other element not recognized`|`SET_SUBPARSER_USAGE`|
|`fastddsqosprof file.xml set datareader -h`|N/A|`DATAREADER_USAGE`|
|`fastddsqosprof file.xml set datareader --help`|N/A|`DATAREADER_USAGE`|
|`fastddsqosprof file.xml set datareader help`|N/A|`DATAREADER_USAGE`|
|`fastddsqosprof file.xml set datareader argument1 argument2 help`|N/A|`DATAREADER_USAGE`|
|`fastddsqosprof file.xml set datareader.default_profile`|`ERROR: datareader requires a profile name` [^1]|`DATAREADER_USAGE`|
|`fastddsqosprof file.xml set datareader[profile]`|`ERROR: datareader must not be FINAL element` [^1]|`DATAREADER_USAGE`|
|`fastddsqosprof file.xml set datareader["a profile"]`|`ERROR: datareader must not be FINAL element` [^1]|`DATAREADER_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].allocations`|**PENDING** (currently `DataReader allocations configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].binary_property`|**PENDING** (currently `DataReader binary properties configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].default_profile`|**PENDING** (currently `DataReader default attribute configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].entity_id`|**PENDING** (currently `DataReader entity ID configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].expect_inline_qos`|**PENDING** (currently `DataReader expect inline qos flag configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].external_locators`|**PENDING** (currently `DataReader default attribute configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].history_memory_policy`|**PENDING** (currently `DataReader history memory policy configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].ignore_non_matching_locators`|**PENDING** (currently `DataReader ignore non matching locators configuration flag not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].locators`|**PENDING** (currently `DataReader locators configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].property`|**PENDING** (currently `DataReader properties configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos`|`ERROR: DataReader <qos> must not be FINAL element`|`DATAREADER_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos -h`|N/A|`DATAREADER_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos[]`|`ERROR: DataReader <qos> must not be keyed []`|`DATAREADER_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos[] -h`|N/A|`DATAREADER_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.datasharing`|**PENDING** (currently `DataSharing QoS configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.duration`|**PENDING** (currently `Duration-related QoS (Deadline, Latency budget and Lifespan) configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.disable_heartbeat_piggyback`|`ERROR: DataReader <disable_heartbeat_piggyback> QoS not recognized`|`DATAREADER_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.disable_positive_acks`|**PENDING** (currently `Disable positive ACKs QoS Policy configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.durability`|`ERROR: set command for DataReader <durability> QoS expects 1 arguments and received 0`|`DURABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.durability[]`|`ERROR: DataReader <durability> QoS must not be keyed []`|`DURABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.durability.other`|`ERROR: DataReader <durability> QoS must be FINAL element`|`DURABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.durability.other help`|N/A|`DURABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.durability argument`|`Fast DDS QoS Profiles Manager exception caught: value 'argument' not in enumeration`|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.durability volatile`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.durability transient_local`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.durability transient`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.durability persistent`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.durability VOLATILE`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.durability TRANSIENT_LOCAL`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.durability TRANSIENT`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.durability PERSISTENT`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.group_data`|**PENDING** (currently `Group Data QoS Policy configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.history`|**PENDING** (currently `History QoS Policy configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.liveliness`|**PENDING** (currently `Liveliness QoS Policy configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.ownership`|**PENDING** (currently `Ownership and Ownership strength QoS Policies configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.partitions`|**PENDING** (currently `Partitions QoS Policy not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.publish_mode`|`ERROR: DataReader <publish_mode> QoS not recognized`|`DATAREADER_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability`|`ERROR: DataReader <reliability> QoS must not be FINAL element`|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability -h`|N/A|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability[]`|`ERROR: DataReader <reliability> QoS must not be keyed []`|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability[] help`|N/A|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.kind`|`ERROR: set command for DataReader <reliability> QoS: 'kind' attribute expects 1 arguments and received 0`|`RELIABILITY_KIND_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.kind[]`|`ERROR: DataReader <reliability> QoS: 'kind' attribute must not be keyed []`|`RELIABILITY_KIND_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.kind[] --help`|N/A|`RELIABILITY_KIND_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.kind.other`|`ERROR: DataReader <reliability> QoS: 'kind' attribute must be FINAL element`|`RELIABILITY_KIND_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.kind.other arg1 help`|N/A|`RELIABILITY_KIND_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.kind best_effort`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.kind reliable`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.kind BEST_EFFORT`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.kind RELIABLE`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.kind argument`|`Fast DDS QoS Profiles Manager exception caught: value 'argument' not in enumeration`|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.duration`|N/A|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.other`|`ERROR: DataReader <reliability> QoS: 'other' attribute not recognized`|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.reliability.other help`|N/A|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.resource_limits`|**PENDING** (currently `Resource Limits QoS configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.topic_data`|**PENDING** (currently `Topic Data QoS configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.user_data`|**PENDING** (currently `User Data QoS configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].qos.other`|`DataReader <other> QoS not recognized`|`DATAREADER_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].qos.other -h`|N/A|`DATAREADER_QOS_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].times`|**PENDING** (currently `DataReader time related parameters configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].user_defined_id`|**PENDING** (currently `DataReader user defined ID configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datareader[profile].other`|`ERROR: other element not recognized`|`DATAREADER_USAGE`|
|`fastddsqosprof file.xml set datareader[profile].other --help`|N/A|`DATAREADER_USAGE`|
|`fastddsqosprof file.xml set datawriter -h`|N/A|`DATAWRITER_USAGE`|
|`fastddsqosprof file.xml set datawriter --help`|N/A|`DATAWRITER_USAGE`|
|`fastddsqosprof file.xml set datawriter help`|N/A|`DATAWRITER_USAGE`|
|`fastddsqosprof file.xml set datawriter argument1 argument2 help`|N/A|`DATAWRITER_USAGE`|
|`fastddsqosprof file.xml set datawriter.default_profile`|`ERROR: datawriter requires a profile name` [^1]|`DATAWRITER_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile]`|`ERROR: datawriter must not be FINAL element` [^1]|`DATAWRITER_USAGE`|
|`fastddsqosprof file.xml set datawriter["a profile"]`|`ERROR: datawriter must not be FINAL element` [^1]|`DATAWRITER_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].allocations`|**PENDING** (currently `DataWriter allocations configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].binary_property`|**PENDING** (currently `DataWriter binary properties configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].default_profile`|**PENDING** (currently `DataWriter default attribute configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].entity_id`|**PENDING** (currently `DataWriter entity ID configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].external_locators`|**PENDING** (currently `DataWriter default attribute configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].history_memory_policy`|**PENDING** (currently `DataWriter history memory policy configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].ignore_non_matching_locators`|**PENDING** (currently `DataWriter ignore non matching locators configuration flag not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].locators`|**PENDING** (currently `DataWriter locators configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].property`|**PENDING** (currently `DataWriter properties configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos`|`ERROR: DataWriter <qos> must not be FINAL element`|`DATAWRITER_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos -h`|N/A|`DATAWRITER_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos[]`|`ERROR: DataWriter <qos> must not be keyed []`|`DATAWRITER_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos[] -h`|N/A|`DATAWRITER_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.datasharing`|**PENDING** (currently `DataSharing QoS configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.duration`|**PENDING** (currently `Duration-related QoS (Deadline, Latency budget and Lifespan) configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.disable_heartbeat_piggyback`|**PENDING** (currently `Disable heartbeat piggyback QoS configuration not yet supported`)|`DATAWRITER_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.disable_positive_acks`|**PENDING** (currently `Disable positive ACKs QoS Policy configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability`|`ERROR: set command for DataWriter <durability> QoS expects 1 arguments and received 0`|`DURABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability[]`|`ERROR: DataWriter <durability> QoS must not be keyed []`|`DURABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability.other`|`ERROR: DataWriter <durability> QoS must be FINAL element`|`DURABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability.other help`|N/A|`DURABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability argument`|`Fast DDS QoS Profiles Manager exception caught: value 'argument' not in enumeration`|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability volatile`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability transient_local`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability transient`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability persistent`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability VOLATILE`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability TRANSIENT_LOCAL`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability TRANSIENT`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.durability PERSISTENT`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.group_data`|**PENDING** (currently `Group Data QoS Policy configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.history`|**PENDING** (currently `History QoS Policy configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.liveliness`|**PENDING** (currently `Liveliness QoS Policy configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.ownership`|**PENDING** (currently `Ownership and Ownership strength QoS Policies configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.partitions`|**PENDING** (currently `Partitions QoS Policy not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.publish_mode`|**PENDING** (currently `Publish mode QoS configuration not yet supported`)|`DATAWRITER_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability`|`ERROR: DataWriter <reliability> QoS must not be FINAL element`|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability -h`|N/A|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability[]`|`ERROR: DataWriter <reliability> QoS must not be keyed []`|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability[] help`|N/A|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.kind`|`ERROR: set command for DataWriter <reliability> QoS: 'kind' attribute expects 1 arguments and received 0`|`RELIABILITY_KIND_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.kind[]`|`ERROR: DataWriter <reliability> QoS: 'kind' attribute must not be keyed []`|`RELIABILITY_KIND_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.kind[] --help`|N/A|`RELIABILITY_KIND_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.kind.other`|`ERROR: DataWriter <reliability> QoS: 'kind' attribute must be FINAL element`|`RELIABILITY_KIND_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.kind.other arg1 help`|N/A|`RELIABILITY_KIND_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.kind best_effort`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.kind reliable`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.kind BEST_EFFORT`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.kind RELIABLE`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.kind argument`|`Fast DDS QoS Profiles Manager exception caught: value 'argument' not in enumeration`|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.duration`|N/A|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.other`|`ERROR: DataWriter <reliability> QoS: 'other' attribute not recognized`|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.reliability.other help`|N/A|`RELIABILITY_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.resource_limits`|**PENDING** (currently `Resource Limits QoS configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.topic_data`|**PENDING** (currently `Topic Data QoS configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.user_data`|**PENDING** (currently `User Data QoS configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].qos.other`|`DataWriter <other> QoS not recognized`|`DATAWRITER_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].qos.other -h`|N/A|`DATAWRITER_QOS_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].times`|**PENDING** (currently `DataWriter time related parameters configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].user_defined_id`|**PENDING** (currently `DataWriter user defined ID configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set datawriter[profile].expect_inline_qos`|`ERROR: expect_inline_qos element not recognized`|`DATAWRITER_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].other`|`ERROR: other element not recognized`|`DATAWRITER_USAGE`|
|`fastddsqosprof file.xml set datawriter[profile].other --help`|N/A|`DATAWRITER_USAGE`|
|`fastddsqosprof file.xml set participant -h`|N/A|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant --help`|N/A|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant help`|N/A|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant argument1 argument2 help`|N/A|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant.name`|`ERROR: participant requires a profile name`|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant[]`|`ERROR: participant requires a profile name` [^1]|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant[profile]`|`ERROR: participant must not be FINAL element`|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant["a profile"]`|`ERROR: participant must not be FINAL element`|`PARTICIPANT_USAGE`|
|`fastddsqosprof file.xml set participant[profile].allocations`|**PENDING** (currently `Participant allocations configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].binary_property`|**PENDING** (currently `Participant binary properties configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin`|`ERROR: Participant <builtin> must not be FINAL element`|`PARTICIPANT_BUILTIN_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].domain_id`|**PENDING** (currently `Participant domain ID configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators`|`ERROR: Participant <external_locators> must not be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].guid_prefix`|**PENDING** (currently `Participant GUID prefix configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].id`|**PENDING** (currently `Participant ID configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].ignore_non_matching_locators`|**PENDING** (currently `Participant ignore non matching locators configuration flag not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].listen_socket_buffer_size`|**PENDING** (currently `Participant listen socket buffer size configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].locators`|**PENDING** (currently `Participant locators configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].name`|`ERROR: set command for Participant <name> expects 1 arguments and received 0`|`PARTICIPANT_NAME_USAGE`|
|`fastddsqosprof file.xml set participant[profile].port`|**PENDING** (currently `Participant port parameters configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].property`|**PENDING** (currently `Participant properties configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].send_socket_buffer_size`|**PENDING** (currently `Participant send socket buffer size configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports`|`ERROR: set command for Participant <use_builtin_transports> expects 1 arguments and received 0`|`PARTICIPANT_USE_BUILTIN_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].user_data`|**PENDING** (currently `Participant user data QoS configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].user_transports`|`ERROR: Participant <user_transports> must be keyed []`|`PARTICIPANT_USER_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].other`|`ERROR: other element not recognized`|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].other -h`|N/A|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin -h`|N/A|`PARTICIPANT_BUILTIN_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin --help`|N/A|`PARTICIPANT_BUILTIN_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin help`|N/A|`PARTICIPANT_BUILTIN_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin argument1 argument2 help`|N/A|`PARTICIPANT_BUILTIN_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin[]`|`ERROR: Participant <builtin> must not be keyed []`|`PARTICIPANT_BUILTIN_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.other`|`ERROR: other element not recognized`|`PARTICIPANT_BUILTIN_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.other arg`|`ERROR: other element not recognized`|`PARTICIPANT_BUILTIN_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.other help`|N/A|`PARTICIPANT_BUILTIN_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.avoid_builtin_multicast`|**PENDING** (currently `Participant builtin avoid_builtin_multicast flag configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.avoid_builtin_multicast arg`|**PENDING** (currently `Participant builtin avoid_builtin_multicast flag configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.avoid_builtin_multicast help`|**PENDING** (currently `Participant builtin avoid_builtin_multicast flag configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config`|`ERROR: Participant builtin <discovery_config> must not be FINAL element`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config[]`|`ERROR: Participant builtin <discovery_config> must not be keyed []`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config help`|N/A|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.client_announcements`|**PENDING** (currently `Participant builtin discovery client announcements configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.discovery_protocol`|**PENDING** (currently `Participant builtin discovery protocol configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration`|`ERROR: Participant builtin discovery config <duration> must not be FINAL element`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration[]`|`ERROR: Participant builtin discovery config <duration> must not be keyed []`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration -h`|N/A|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease`|`ERROR: set command for Participant builtin discovery config <duration>: 'lease' duration type expects at least 1 arguments and received 0`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease[]`|`ERROR: Participant builtin discovery config <duration>: 'lease' duration type must not be keyed []`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease arg1 arg2 arg3`|`ERROR: set command for Participant builtin discovery config <duration>: 'lease' duration type expects at most 2 arguments and received 3`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease infinite`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease 1`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease other`|`Fast DDS QoS Profiles Manager exception caught: value 'other' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease arg1 arg2 help`|N/A|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease 1 500`|**PENDING** (currently `Fast DDS QoS Profiles Manager exception caught: invalid document structure`) [^3]|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease infinite 500`|`Fast DDS QoS Profiles Manager exception caught: value 'infinite' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease 1 other`|**PENDING** (currently `Fast DDS QoS Profiles Manager exception caught: invalid document structure`) [^3]|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.sec`|`ERROR: set command for Participant builtin discovery config <duration>: 'lease' duration type <sec> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.sec[]`|`ERROR: Participant builtin discovery config <duration>: 'lease' duration type <sec> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.sec.other`|`ERROR: Participant builtin discovery config <duration>: 'lease' duration type <sec> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.sec 10`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.sec infinite`|`Fast DDS QoS Profiles Manager exception caught: value 'infinite' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.sec other`|`Fast DDS QoS Profiles Manager exception caught: value 'other' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.sec -h`|N/A|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.nanosec`|`ERROR: set command for Participant builtin discovery config <duration>: 'lease' duration type <nanosec> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.nanosec[]`|`ERROR: Participant builtin discovery config <duration>: 'lease' duration type <nanosec> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.nanosec.other`|`ERROR: Participant builtin discovery config <duration>: 'lease' duration type <nanosec> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.nanosec 100`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.nanosec infinite`|`Fast DDS QoS Profiles Manager exception caught: value 'infinite' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.nanosec other`|`Fast DDS QoS Profiles Manager exception caught: value 'other' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease.nanosec -h`|N/A|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements`|`ERROR: set command for Participant builtin discovery config <duration>: 'announcements' duration type expects at least 1 arguments and received 0`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements[]`|`ERROR: Participant builtin discovery config <duration>: 'announcements' duration type must not be keyed []`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements arg1 arg2 arg3`|`ERROR: set command for Participant builtin discovery config <duration>: 'announcements' duration type expects at most 2 arguments and received 3`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements infinite`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements 1`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements other`|`Fast DDS QoS Profiles Manager exception caught: value 'other' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements arg1 arg2 help`|N/A|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements 1 500`|**PENDING** (currently `Fast DDS QoS Profiles Manager exception caught: invalid document structure`) [^3]|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements infinite 500`|`Fast DDS QoS Profiles Manager exception caught: value 'infinite' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements 1 other`|**PENDING** (currently `Fast DDS QoS Profiles Manager exception caught: invalid document structure`) [^3]|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.sec`|`ERROR: set command for Participant builtin discovery config <duration>: 'announcements' duration type <sec> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.sec[]`|`ERROR: Participant builtin discovery config <duration>: 'announcements' duration type <sec> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.sec.other`|`ERROR: Participant builtin discovery config <duration>: 'announcements' duration type <sec> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.sec 10`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.sec infinite`|`Fast DDS QoS Profiles Manager exception caught: value 'infinite' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.sec other`|`Fast DDS QoS Profiles Manager exception caught: value 'other' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.sec -h`|N/A|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.nanosec`|`ERROR: set command for Participant builtin discovery config <duration>: 'announcements' duration type <nanosec> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.nanosec[]`|`ERROR: Participant builtin discovery config <duration>: 'announcements' duration type <nanosec> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.nanosec.other`|`ERROR: Participant builtin discovery config <duration>: 'announcements' duration type <nanosec> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.nanosec 100`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.nanosec infinite`|`Fast DDS QoS Profiles Manager exception caught: value 'infinite' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.nanosec other`|`Fast DDS QoS Profiles Manager exception caught: value 'other' does not match any member types of the union`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements.nanosec -h`|N/A|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.other`|`ERROR: Participant builtin discovery config <duration>: 'other' duration type not recognized`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.other --help`|N/A|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_DURATION_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.edp`|**PENDING** (currently `Participant builtin discovery EDP configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.ignore_participant_flags`|**PENDING** (currently `Participant builtin discovery ignore participant flags configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.initial_announcements`|**PENDING** (currently `Participant builtin discovery initial announcements configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.remote_servers`|**PENDING** (currently `Participant builtin discovery remote servers list configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.simple_edp`|**PENDING** (currently `Participant builtin discovery simple EDP configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.static_edp_xmls`|**PENDING** (currently `Participant builtin discovery static EDP configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.other`|`ERROR: other element not recognized`|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.discovery_config.other --help`|N/A|`PARTICIPANT_BUILTIN_DISCOVERY_CONFIG_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators`|`ERROR: Participant builtin <external_locators> must not be FINAL element`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators -h`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators --help`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators help`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators argument1 argument2 help`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators[].metatraffic_unicast`|`ERROR: Participant builtin <external_locators> must not be keyed []`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast`|`ERROR: set command for Participant builtin <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast argument`|`ERROR: external locator <metatraffic_unicast> list must be keyed []`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.other argument`|`ERROR: other subelement not recognized`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast -h`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[] -h`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[] argument`|`ERROR: set command for external locator <metatraffic_unicast> list expects 6 arguments and received 1`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[] arg1 arg2 arg3 arg4 arg5 arg6`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].address`|`ERROR: set command for Participant builtin <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].address -h`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].address argument` [^2]|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[11811].address argument`|`Fast DDS QoS Profiles Manager exception caught: udpv4 does not have an element in position 11811`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[0].address arg`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].address[] argument`|`ERROR: external locator <metatraffic_unicast> list <address> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].address.element argument`|`ERROR: external locator <metatraffic_unicast> list <address> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].cost`|`ERROR: set command for Participant builtin <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].cost -h`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].cost argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[11811].cost argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].cost[] argument`|`ERROR: external locator <metatraffic_unicast> list <cost> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].cost.element argument`|`ERROR: external locator <metatraffic_unicast> list <cost> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].externality`|`ERROR: set command for Participant builtin <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].externality -h`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].externality argument`|`Fast DDS QoS Profiles Manager exception caught: value 'argument' does not match regular expression facet '[+\-]?[0-9]+'`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[11811].externality argument`|`Fast DDS QoS Profiles Manager exception caught: non-existent udpv4 element`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].externality 15`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[-1].externality 23`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[-2].externality 23`|`Fast DDS QoS Profiles Manager exception caught: udpv4 does not have an element in position -1`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[11811].externality argument`|`Fast DDS QoS Profiles Manager exception caught: udpv4 does not have an element in position 11811`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].externality 0`|`Fast DDS QoS Profiles Manager exception caught: value '0' must be greater than or equal to minInclusive facet value '1'`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].externality 256`|`Fast DDS QoS Profiles Manager exception caught: value '256' must be less than or equal to maxInclusive facet value '255'`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].externality[] argument`|`ERROR: external locator <metatraffic_unicast> list <externality> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].externality.element argument`|`ERROR: external locator <metatraffic_unicast> list <externality> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].kind`|`ERROR: set command for Participant builtin <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].kind -h`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].kind argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[11811].kind argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].kind[] argument`|`ERROR: external locator <metatraffic_unicast> list <kind> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].kind.element argument`|`ERROR: external locator <metatraffic_unicast> list <kind> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].mask`|`ERROR: set command for Participant builtin <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].mask -h`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].mask argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[11811].mask argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].mask[] argument`|`ERROR: external locator <metatraffic_unicast> list <mask> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].mask.element argument`|`ERROR: external locator <metatraffic_unicast> list <mask> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].port`|`ERROR: set command for Participant builtin <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].port -h`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].port argument`|`Fast DDS QoS Profiles Manager exception caught: value 'argument' does not match regular expression facet '[+\-]?[0-9]+'`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[11811].port argument`|`Fast DDS QoS Profiles Manager exception caught: udpv4 does not have an element in position 11811`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].port 122`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[0].port 432`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[0].port -1`|`Fast DDS QoS Profiles Manager exception caught: value '-1' must be greater than or equal to minInclusive facet value '0'`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[0].port 65536`|`Fast DDS QoS Profiles Manager exception caught: value '65536' must be less than or equal to maxInclusive facet value '65535'`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].port[] argument`|`ERROR: external locator <metatraffic_unicast> list <port> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].port.element argument`|`ERROR: external locator <metatraffic_unicast> list <port> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].other`|`ERROR: set command for Participant builtin <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].other -h`|N/A|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.external_locators.metatraffic_unicast[].other argument`|`ERROR: other subelement not recognized`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.mutation_tries`|**PENDING** (currently `Participant builtin mutation tries configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.mutation_tries arg`|**PENDING** (currently `Participant builtin mutation tries configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.mutation_tries help`|**PENDING** (currently `Participant builtin mutation tries configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators`|`ERROR: Participant builtin <locators> must not be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators[]`|`ERROR: Participant builtin <locators> must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators help`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.other`|`ERROR: Participant builtin <other> locator list not recognized`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.other -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast`|`ERROR: Participant builtin <metatraffic_unicast> locator list must be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[]`|`ERROR: set command for Participant builtin <metatraffic_unicast> locator list expects 3 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[] arg1 -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[] arg1 arg2 arg3`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].address`|`ERROR: set command for Participant builtin <metatraffic_unicast> locator list <address> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].address -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].address argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[11811].address argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].address[] argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <address> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].address.element argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <address> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].kind`|`ERROR: set command for Participant builtin <metatraffic_unicast> locator list <kind> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].kind -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].kind argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[11811].kind argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].kind[] argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <kind> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].kind.element argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <kind> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].physical_port`|`ERROR: set command for Participant builtin <metatraffic_unicast> locator list <physical_port> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].physical_port -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].physical_port argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[11811].physical_port argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].physical_port[] argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <physical_port> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].physical_port.element argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <physical_port> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].port`|`ERROR: set command for Participant builtin <metatraffic_unicast> locator list <port> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].port -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].port argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[11811].port argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].port[] argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <port> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].port.element argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <port> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].unique_lan_id`|`ERROR: set command for Participant builtin <metatraffic_unicast> locator list <unique_lan_id> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].unique_lan_id -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].unique_lan_id argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[11811].unique_lan_id argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].unique_lan_id[] argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <unique_lan_id> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].unique_lan_id.element argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <unique_lan_id> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].wan_address`|`ERROR: set command for Participant builtin <metatraffic_unicast> locator list <wan_address> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].wan_address -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].wan_address argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[11811].wan_address argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].wan_address[] argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <wan_address> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].wan_address.element argument`|`ERROR: Participant builtin <metatraffic_unicast> locator list <wan_address> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].other`|`ERROR: set command for Participant builtin <metatraffic_unicast> locator list <other> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].other -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_unicast[].other argument`|`ERROR: other subelement not recognized`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast`|`ERROR: Participant builtin <metatraffic_multicast> locator list must be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[]`|`ERROR: set command for Participant builtin <metatraffic_multicast> locator list expects 3 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[] arg1 arg2 --help`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[] arg1 arg2 arg3`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].address`|`ERROR: set command for Participant builtin <metatraffic_multicast> locator list <address> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].address -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].address argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[11811].address argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].address[] argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <address> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].address.element argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <address> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].kind`|`ERROR: set command for Participant builtin <metatraffic_multicast> locator list <kind> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].kind -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].kind argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[11811].kind argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].kind[] argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <kind> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].kind.element argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <kind> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].physical_port`|`ERROR: set command for Participant builtin <metatraffic_multicast> locator list <physical_port> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].physical_port -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].physical_port argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[11811].physical_port argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].physical_port[] argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <physical_port> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].physical_port.element argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <physical_port> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].port`|`ERROR: set command for Participant builtin <metatraffic_multicast> locator list <port> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].port -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].port argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[11811].port argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].port[] argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <port> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].port.element argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <port> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].unique_lan_id`|`ERROR: set command for Participant builtin <metatraffic_multicast> locator list <unique_lan_id> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].unique_lan_id -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].unique_lan_id argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[11811].unique_lan_id argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].unique_lan_id[] argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <unique_lan_id> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].unique_lan_id.element argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <unique_lan_id> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].wan_address`|`ERROR: set command for Participant builtin <metatraffic_multicast> locator list <wan_address> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].wan_address -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].wan_address argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[11811].wan_address argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].wan_address[] argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <wan_address> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].wan_address.element argument`|`ERROR: Participant builtin <metatraffic_multicast> locator list <wan_address> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].other`|`ERROR: set command for Participant builtin <metatraffic_multicast> locator list <other> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].other -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.metatraffic_multicast[].other argument`|`ERROR: other subelement not recognized`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers`|`ERROR: Participant builtin <initial_peers> locator list must be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[]`|`ERROR: set command for Participant builtin <initial_peers> locator list expects 3 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[] help`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[] arg1 arg2 arg3`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].address`|`ERROR: set command for Participant builtin <initial_peers> locator list <address> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].address -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].address argument` [^2]|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[11811].address argument`|`Fast DDS QoS Profiles Manager exception caught: locator does not have an element in position 11811`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[0].address arg`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].address[] argument`|`ERROR: Participant builtin <initial_peers> locator list <address> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].address.element argument`|`ERROR: Participant builtin <initial_peers> locator list <address> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].kind`|`ERROR: set command for Participant builtin <initial_peers> locator list <kind> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].kind -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].kind argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[11811].kind argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].kind[] argument`|`ERROR: Participant builtin <initial_peers> locator list <kind> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].kind.element argument`|`ERROR: Participant builtin <initial_peers> locator list <kind> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].physical_port`|`ERROR: set command for Participant builtin <initial_peers> locator list <physical_port> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].physical_port -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].physical_port argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[11811].physical_port argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].physical_port[] argument`|`ERROR: Participant builtin <initial_peers> locator list <physical_port> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].physical_port.element argument`|`ERROR: Participant builtin <initial_peers> locator list <physical_port> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].port`|`ERROR: set command for Participant builtin <initial_peers> locator list <port> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].port -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].port argument` [^2]|`Fast DDS QoS Profiles Manager exception caught: value 'argument' does not match regular expression facet '[+\-]?[0-9]+'`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[11811].port argument`|`Fast DDS QoS Profiles Manager exception caught: locator does not have an element in position 11811`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].port 122`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[0].port 432`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[0].port -1`|`Fast DDS QoS Profiles Manager exception caught: value '-1' must be greater than or equal to minInclusive facet value '0'`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[0].port 65536`|`Fast DDS QoS Profiles Manager exception caught: value '65536' must be less than or equal to maxInclusive facet value '65535'`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].port[] argument`|`ERROR: Participant builtin <initial_peers> locator list <port> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].port.element argument`|`ERROR: Participant builtin <initial_peers> locator list <port> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].unique_lan_id`|`ERROR: set command for Participant builtin <initial_peers> locator list <unique_lan_id> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].unique_lan_id -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].unique_lan_id argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[11811].unique_lan_id argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].unique_lan_id[] argument`|`ERROR: Participant builtin <initial_peers> locator list <unique_lan_id> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].unique_lan_id.element argument`|`ERROR: Participant builtin <initial_peers> locator list <unique_lan_id> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].wan_address`|`ERROR: set command for Participant builtin <initial_peers> locator list <wan_address> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].wan_address -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].wan_address argument` [^2]|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[11811].wan_address argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].wan_address[] argument`|`ERROR: Participant builtin <initial_peers> locator list <wan_address> attribute must not be keyed []`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].wan_address.element argument`|`ERROR: Participant builtin <initial_peers> locator list <wan_address> attribute must be FINAL element`|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].other`|`ERROR: set command for Participant builtin <initial_peers> locator list <other> attribute expects 1 arguments and received 0`|`PARTICIPANT_BUILTIN_METATRAFFIC_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].other -h`|N/A|`PARTICIPANT_BUILTIN_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.locators.initial_peers[].other argument`|`ERROR: other subelement not recognized`|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.reader`|**PENDING** (currently `Participant builtin readers configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.reader arg`|**PENDING** (currently `Participant builtin readers configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.reader help`|**PENDING** (currently `Participant builtin readers configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.use_writer_liveliness_protocol`|**PENDING** (currently `Participant builtin use writer liveliness protocol flag configuration not yet supported`)|`PARTICIPANT_BUILTIN_USAGE`|
|`fastddsqosprof file.xml set participant[profile].builtin.use_writer_liveliness_protocol arg`|**PENDING** (currently `Participant builtin use writer liveliness protocol flag configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.use_writer_liveliness_protocol help`|**PENDING** (currently `Participant builtin use writer liveliness protocol flag configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.writer`|**PENDING** (currently `Participant builtin writers configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.writer arg`|**PENDING** (currently `Participant builtin writers configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].builtin.writer help`|**PENDING** (currently `Participant builtin writers configuration not yet supported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].default_profile -h`|N/A|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile --help`|N/A|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile help`|N/A|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile argument1 argument2 help`|N/A|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile[]`|`ERROR: Participant <default_profile> must not be keyed []`|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile.element`|`ERROR: Participant <default_profile> must be FINAL element`|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].default_profile argument`|`ERROR: set command for Participant <default_profile> expects 0 arguments and received 1`|`PARTICIPANT_DEFAULT_PROFILE_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators --help`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators help`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators argument1 argument2 help`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators[].default_unicast`|`ERROR: Participant <external_locators> must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast`|`ERROR: set command for Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast argument`|`ERROR: external locator <default_unicast> list must be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.other argument`|`ERROR: other subelement not recognized`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[] -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[] argument`|`ERROR: set command for external locator <default_unicast> list expects 6 arguments and received 1`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[] arg1 arg2 arg3 arg4 arg5 arg6`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].address`|`ERROR: set command for Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].address -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].address argument`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].address argument`|`Fast DDS QoS Profiles Manager exception caught: udpv4 does not have an element in position 11811`|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[0].address arg`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].address[] argument`|`ERROR: external locator <default_unicast> list <address> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].address.element argument`|`ERROR: external locator <default_unicast> list <address> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].cost`|`ERROR: set command for Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].cost -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].cost argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].cost argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].cost[] argument`|`ERROR: external locator <default_unicast> list <cost> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].cost.element argument`|`ERROR: external locator <default_unicast> list <cost> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality`|`ERROR: set command for Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality argument`|`Fast DDS QoS Profiles Manager exception caught: value 'argument' does not match regular expression facet '[+\-]?[0-9]+'`|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].externality argument`|`Fast DDS QoS Profiles Manager exception caught: non-existent udpv4 element`|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality 15`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[-1].externality 23`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[-2].externality 23`|`Fast DDS QoS Profiles Manager exception caught: udpv4 does not have an element in position -1`|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].externality argument`|`Fast DDS QoS Profiles Manager exception caught: udpv4 does not have an element in position 11811`|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality 0`|`Fast DDS QoS Profiles Manager exception caught: value '0' must be greater than or equal to minInclusive facet value '1'`|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality 256`|`Fast DDS QoS Profiles Manager exception caught: value '256' must be less than or equal to maxInclusive facet value '255'`|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality[] argument`|`ERROR: external locator <default_unicast> list <externality> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].externality.element argument`|`ERROR: external locator <default_unicast> list <externality> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].kind`|`ERROR: set command for Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].kind -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].kind argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].kind argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].kind[] argument`|`ERROR: external locator <default_unicast> list <kind> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].kind.element argument`|`ERROR: external locator <default_unicast> list <kind> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].mask`|`ERROR: set command for Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].mask -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].mask argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].mask argument`|**UNSUPPORTED** (currently `Fast DDS QoS Profiles Manager exception caught: Unsupported`)|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].mask[] argument`|`ERROR: external locator <default_unicast> list <mask> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].mask.element argument`|`ERROR: external locator <default_unicast> list <mask> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].port`|`ERROR: set command for Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].port -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].port argument`|`Fast DDS QoS Profiles Manager exception caught: value 'argument' does not match regular expression facet '[+\-]?[0-9]+'`|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[11811].port argument`|`Fast DDS QoS Profiles Manager exception caught: udpv4 does not have an element in position 11811`|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].port 122`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[0].port 432`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[0].port -1`|`Fast DDS QoS Profiles Manager exception caught: value '-1' must be greater than or equal to minInclusive facet value '0'`|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[0].port 65536`|`Fast DDS QoS Profiles Manager exception caught: value '65536' must be less than or equal to maxInclusive facet value '65535'`|N/A|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].port[] argument`|`ERROR: external locator <default_unicast> list <port> attribute must not be keyed []`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].port.element argument`|`ERROR: external locator <default_unicast> list <port> attribute must be FINAL element`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].other`|`ERROR: set command for Participant <external_locators> expects at least 1 arguments and received 0`|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].other -h`|N/A|`PARTICIPANT_DEFAULT_EXTERNAL_UNICAST_LOCATORS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].external_locators.default_unicast[].other argument`|`ERROR: other subelement not recognized`|N/A|
|`fastddsqosprof file.xml set participant[profile].name[]`|`ERROR: Participant <name> must not be keyed []`|`PARTICIPANT_NAME_USAGE`|
|`fastddsqosprof file.xml set participant[profile].name.subelement`|`ERROR: Participant <name> must be FINAL element`|`PARTICIPANT_NAME_USAGE`|
|`fastddsqosprof file.xml set participant[profile].name -h`|N/A|`PARTICIPANT_NAME_USAGE`|
|`fastddsqosprof file.xml set participant[profile].name --help`|N/A|`PARTICIPANT_NAME_USAGE`|
|`fastddsqosprof file.xml set participant[profile].name help`|N/A|`PARTICIPANT_NAME_USAGE`|
|`fastddsqosprof file.xml set participant[profile].name arg1 arg2 -h`|N/A|`PARTICIPANT_NAME_USAGE`|
|`fastddsqosprof file.xml set participant[profile].name arg1 arg2`|`ERROR: set command for Participant <name> expects 1 arguments and received 2`|`PARTICIPANT_NAME_USAGE`|
|`fastddsqosprof file.xml set participant[profile].name arg1`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports[]`|`ERROR: Participant <use_builtin_transports> must not be keyed []`|`PARTICIPANT_USE_BUILTIN_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports.subelement`|`ERROR: Participant <use_builtin_transports> must be FINAL element`|`PARTICIPANT_USE_BUILTIN_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports -h`|N/A|`PARTICIPANT_USE_BUILTIN_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports --help`|N/A|`PARTICIPANT_USE_BUILTIN_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports help`|N/A|`PARTICIPANT_USE_BUILTIN_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports arg1 arg2 -h`|N/A|`PARTICIPANT_USE_BUILTIN_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports arg1 arg2`|`ERROR: set command for Participant <use_builtin_transports> expects 1 arguments and received 2`|`PARTICIPANT_USE_BUILTIN_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports true`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports false`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].use_builtin_transports other`|`Fast DDS QoS Profiles Manager exception caught: value 'other' is invalid boolean`|N/A|
|`fastddsqosprof file.xml set participant[profile].user_transports[]`|`ERROR: set command for Participant <user_transports> expects 1 arguments and received 0`|`PARTICIPANT_USER_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].user_transports[].subelement`|`ERROR: Participant <user_transports> must be FINAL element`|`PARTICIPANT_USER_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].user_transports[] -h`|N/A|`PARTICIPANT_USER_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].user_transports[] --help`|N/A|`PARTICIPANT_USER_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].user_transports[] help`|N/A|`PARTICIPANT_USER_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].user_transports[] arg1 arg2 -h`|N/A|`PARTICIPANT_USER_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].user_transports[] arg1 arg2`|`ERROR: set command for Participant <user_transports> expects 1 arguments and received 2`|`PARTICIPANT_USER_TRANSPORTS_USAGE`|
|`fastddsqosprof file.xml set participant[profile].user_transports[] argument`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].user_transports[0] arg1`|N/A|N/A|
|`fastddsqosprof file.xml set participant[profile].user_transports[11811] argument`|`Fast DDS QoS Profiles Manager exception caught: userTransports does not have an element in position 11811`|N/A|

[^1]: **PENDING**: Print and clear default profile command will not require a profile name.
[^2]: **PENDING**: Print, clear and query commands should not allow an empty index with a subelement.
[^3]: **PENDING**: Access to file before previous changes have been written although Xerces has correctly returned from `write` operation.

## Caveats

This current test plan is focused only on the CLI usage and errors.
Currently, this test plan is not concerned about the validity of the arguments passed to Fast DDS QoS Profiles Manager Library, nor about the handling of the returned information.


## Known issues

* Simultaneous `set` operations would lead to an unexpected exception reporting the following message: `Fast DDS QoS Profiles Manager exception caught: invalid document structure`.
  This happens due to accessing the file before previous changes have been written although Xerces has correctly returned from `write` operation.
  These are some of the `set` calls that trigger this issue: `fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.lease 1 500`, `fastddsqosprof file.xml set participant[profile].builtin.discovery_config.duration.announcements 1 500`, and some other non-supported yet calls that have already been designed, as `fastddsqosprof file.xml set participant[profile].locators.default_unicast[] udpv4 127.0.0.1 1234`.
