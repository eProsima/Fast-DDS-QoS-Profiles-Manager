// Copyright 2023 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file ParseXMLTags.hpp
 */

#ifndef _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_TAGS_HPP_
#define _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_TAGS_HPP_

namespace eprosima {
namespace qosprof {
namespace tag {

// HEADER TAGS
constexpr const char* XMLNS = "xmlns";
constexpr const char* EPROSIMA_URL = "http://www.eprosima.com/XMLSchemas/fastRTPS_Profiles";

// MAIN ROOT TAGS
constexpr const char* ROOT = "dds";
constexpr const char* PROFILES = "profiles";
constexpr const char* LIBRARY_SETTINGS = "library_settings";
constexpr const char* TRANSPORT_DESCRIPTORS = "transport_descriptors";
constexpr const char* PROFILE_NAME = "profile_name";
constexpr const char* DEFAULT_PROF = "is_default_profile";
constexpr const char* PARTICIPANT = "participant";
constexpr const char* PUBLISHER = "publisher";
constexpr const char* SUBSCRIBER = "subscriber";
constexpr const char* RTPS = "rtps";
constexpr const char* TYPES = "types";
constexpr const char* LOG = "log";
constexpr const char* REQUESTER = "requester";
constexpr const char* REPLIER = "replier";

constexpr const char* TRANSPORT_DESCRIPTOR = "transport_descriptor";
constexpr const char* TRANSPORT_ID = "transport_id";
constexpr const char* UDP_OUTPUT_PORT = "output_port";
constexpr const char* TCP_WAN_ADDR = "wan_addr";
constexpr const char* RECEIVE_BUFFER_SIZE = "receiveBufferSize";
constexpr const char* SEND_BUFFER_SIZE = "sendBufferSize";
constexpr const char* TTL = "TTL";
constexpr const char* NON_BLOCKING_SEND = "non_blocking_send";
constexpr const char* WHITE_LIST = "interfaceWhiteList";
constexpr const char* MAX_MESSAGE_SIZE = "maxMessageSize";
constexpr const char* MAX_INITIAL_PEERS_RANGE = "maxInitialPeersRange";
constexpr const char* KEEP_ALIVE_FREQUENCY = "keep_alive_frequency_ms";
constexpr const char* KEEP_ALIVE_TIMEOUT = "keep_alive_timeout_ms";
constexpr const char* MAX_LOGICAL_PORT = "max_logical_port";
constexpr const char* LOGICAL_PORT_RANGE = "logical_port_range";
constexpr const char* LOGICAL_PORT_INCREMENT = "logical_port_increment";
constexpr const char* ENABLE_TCP_NODELAY = "enable_tcp_nodelay";
constexpr const char* METADATA_LOGICAL_PORT = "metadata_logical_port";
constexpr const char* LISTENING_PORTS = "listening_ports";
constexpr const char* CALCULATE_CRC = "calculate_crc";
constexpr const char* CHECK_CRC = "check_crc";
constexpr const char* SEGMENT_SIZE = "segment_size";
constexpr const char* PORT_QUEUE_CAPACITY = "port_queue_capacity";
constexpr const char* PORT_OVERFLOW_POLICY = "port_overflow_policy";
constexpr const char* SEGMENT_OVERFLOW_POLICY = "segment_overflow_policy";
constexpr const char* HEALTHY_CHECK_TIMEOUT_MS = "healthy_check_timeout_ms";
constexpr const char* DISCARD = "DISCARD";
constexpr const char* FAIL = "FAIL";
constexpr const char* RTPS_DUMP_FILE = "rtps_dump_file";
constexpr const char* ON = "ON";

constexpr const char* OFF = "OFF";
constexpr const char* USER_DATA_ONLY = "USER_DATA_ONLY";
constexpr const char* FULL = "FULL";

constexpr const char* QOS_PROFILE = "qos_profile";
constexpr const char* APPLICATION = "application";
constexpr const char* TYPE = "type";
//constexpr const char* TOPIC = "topic";
constexpr const char* DATA_WRITER = "data_writer";
constexpr const char* DATA_READER = "data_reader";

/// RTPS Domain attributes
constexpr const char* INTRAPROCESS_DELIVERY = "intraprocess_delivery";

/// RTPS Participant attributes
constexpr const char* ALLOCATION = "allocation";
constexpr const char* PREFIX = "prefix";
constexpr const char* DEF_EXT_UNI_LOC_LIST = "default_external_unicast_locators";
constexpr const char* DEF_UNI_LOC_LIST = "defaultUnicastLocatorList";
constexpr const char* DEF_MULTI_LOC_LIST = "defaultMulticastLocatorList";
constexpr const char* SEND_SOCK_BUF_SIZE = "sendSocketBufferSize";
constexpr const char* LIST_SOCK_BUF_SIZE = "listenSocketBufferSize";
constexpr const char* BUILTIN = "builtin";
constexpr const char* PORT = "port";
constexpr const char* PORTS = "ports_";
constexpr const char* LOGICAL_PORT = "logical_port";
constexpr const char* PHYSICAL_PORT = "physical_port";
constexpr const char* USER_DATA = "userData";
constexpr const char* PART_ID = "participantID";
constexpr const char* THROUGHPUT_CONT = "throughputController";
constexpr const char* USER_TRANS = "userTransports";
constexpr const char* USE_BUILTIN_TRANS = "useBuiltinTransports";
constexpr const char* PROPERTIES_POLICY = "propertiesPolicy";
constexpr const char* NAME = "name";
constexpr const char* REMOTE_LOCATORS = "remote_locators";
constexpr const char* MAX_UNICAST_LOCATORS = "max_unicast_locators";
constexpr const char* MAX_MULTICAST_LOCATORS = "max_multicast_locators";
constexpr const char* TOTAL_PARTICIPANTS = "total_participants";
constexpr const char* TOTAL_READERS = "total_readers";
constexpr const char* TOTAL_WRITERS = "total_writers";
constexpr const char* SEND_BUFFERS = "send_buffers";
constexpr const char* PREALLOCATED_NUMBER = "preallocated_number";
constexpr const char* DYNAMIC_LC = "dynamic";
constexpr const char* MAX_PROPERTIES = "max_properties";
constexpr const char* MAX_USER_DATA = "max_user_data";
constexpr const char* MAX_PARTITIONS = "max_partitions";

/// Publisher-subscriber attributes
constexpr const char* TOPIC = "topic";
constexpr const char* QOS = "qos";
constexpr const char* TIMES = "times";
constexpr const char* EXT_UNI_LOC_LIST = "external_unicast_locators";
constexpr const char* UNI_LOC_LIST = "unicastLocatorList";
constexpr const char* MULTI_LOC_LIST = "multicastLocatorList";
constexpr const char* REM_LOC_LIST = "remoteLocatorList";
//constexpr const char* THROUGHPUT_CONT = "throughputController";
constexpr const char* EXP_INLINE_QOS = "expectsInlineQos";
constexpr const char* HIST_MEM_POLICY = "historyMemoryPolicy";
//constexpr const char* PROPERTIES_POLICY = "propertiesPolicy";
constexpr const char* USER_DEF_ID = "userDefinedID";
constexpr const char* ENTITY_ID = "entityID";
constexpr const char* MATCHED_SUBSCRIBERS_ALLOCATION = "matchedSubscribersAllocation";
constexpr const char* MATCHED_PUBLISHERS_ALLOCATION = "matchedPublishersAllocation";

///
constexpr const char* IGN_NON_MATCHING_LOCS = "ignore_non_matching_locators";
constexpr const char* PROPERTIES = "properties";
constexpr const char* BIN_PROPERTIES = "binary_properties";
constexpr const char* PROPERTY = "property";
constexpr const char* VALUE = "value";
constexpr const char* PROPAGATE = "propagate";
constexpr const char* PREALLOCATED = "PREALLOCATED";
constexpr const char* PREALLOCATED_WITH_REALLOC = "PREALLOCATED_WITH_REALLOC";
constexpr const char* DYNAMIC = "DYNAMIC";
constexpr const char* DYNAMIC_REUSABLE = "DYNAMIC_REUSABLE";
constexpr const char* LOCATOR = "locator";
constexpr const char* UDPv4_LOCATOR = "udpv4";
constexpr const char* UDPv6_LOCATOR = "udpv6";
constexpr const char* TCPv4_LOCATOR = "tcpv4";
constexpr const char* TCPv6_LOCATOR = "tcpv6";
constexpr const char* KIND = "kind";
constexpr const char* ADDRESS = "address";
constexpr const char* UNIQUE_LAN_ID = "unique_lan_id";
constexpr const char* WAN_ADDRESS = "wan_address";
constexpr const char* RESERVED = "RESERVED";
constexpr const char* UDPv4 = "UDPv4";
constexpr const char* UDPv6 = "UDPv6";
constexpr const char* TCPv4 = "TCPv4";
constexpr const char* TCPv6 = "TCPv6";
constexpr const char* SHM = "SHM";
constexpr const char* INIT_ACKNACK_DELAY = "initialAcknackDelay";
constexpr const char* HEARTB_RESP_DELAY = "heartbeatResponseDelay";
constexpr const char* INIT_HEARTB_DELAY = "initialHeartbeatDelay";
constexpr const char* HEARTB_PERIOD = "heartbeatPeriod";
constexpr const char* NACK_RESP_DELAY = "nackResponseDelay";
constexpr const char* NACK_SUPRESSION = "nackSupressionDuration";
constexpr const char* BY_NAME = "durationbyname";
constexpr const char* BY_VAL = "durationbyval";
constexpr const char* SECONDS = "sec";
constexpr const char* NANOSECONDS = "nanosec";
constexpr const char* SHARED = "SHARED";
constexpr const char* EXCLUSIVE = "EXCLUSIVE";
// For backward compatibility we allow any DURATION_XXX in duration_t element and any subelement
// constexpr const char* DURATION_INFINITY = R"xsd(\s*DURATION_INFINITY\s*)xsd";
// constexpr const char* DURATION_INFINITE_SEC = R"xsd(\s*(DURATION_INFINITY|DURATION_INFINITE_SEC)\s*)xsd";
// constexpr const char* DURATION_INFINITE_NSEC = R"xsd(\s*(DURATION_INFINITY|DURATION_INFINITE_NSEC)\s*)xsd";
constexpr const char* DURATION_INFINITY = R"xsd(\s*(DURATION_INFINITY|DURATION_INFINITE_SEC|DURATION_INFINITE_NSEC)\s*)xsd";
constexpr const char* DURATION_INFINITE_SEC = DURATION_INFINITY;
constexpr const char* DURATION_INFINITE_NSEC = DURATION_INFINITY;
/// QOS
constexpr const char* DURABILITY = "durability";
constexpr const char* DURABILITY_SRV = "durabilityService";
constexpr const char* DEADLINE = "deadline";
constexpr const char* LATENCY_BUDGET = "latencyBudget";
constexpr const char* LIVELINESS = "liveliness";
constexpr const char* RELIABILITY = "reliability";
constexpr const char* LIFESPAN = "lifespan";
constexpr const char* TIME_FILTER = "timeBasedFilter";
constexpr const char* OWNERSHIP = "ownership";
constexpr const char* OWNERSHIP_STRENGTH = "ownershipStrength";
constexpr const char* DEST_ORDER = "destinationOrder";
constexpr const char* PRESENTATION = "presentation";
constexpr const char* PARTITION = "partition";
constexpr const char* TOPIC_DATA = "topicData";
constexpr const char* GROUP_DATA = "groupData";
constexpr const char* PUB_MODE = "publishMode";
constexpr const char* DISABLE_POSITIVE_ACKS = "disablePositiveAcks";
constexpr const char* DISABLE_HEARTBEAT_PIGGYBACK = "disable_heartbeat_piggyback";
constexpr const char* DATA_SHARING = "data_sharing";

constexpr const char* SYNCHRONOUS = "SYNCHRONOUS";
constexpr const char* ASYNCHRONOUS = "ASYNCHRONOUS";
constexpr const char* NAMES = "names";
constexpr const char* INSTANCE = "INSTANCE";
constexpr const char* GROUP = "GROUP";
constexpr const char* COHERENT_ACCESS = "coherent_access";
constexpr const char* ORDERED_ACCESS = "ordered_access";
constexpr const char* BY_RECEPTION_TIMESTAMP = "BY_RECEPTION_TIMESTAMP";
constexpr const char* BY_SOURCE_TIMESTAMP = "BY_SOURCE_TIMESTAMP";
constexpr const char* MIN_SEPARATION = "minimum_separation";
constexpr const char* DURATION = "duration";
constexpr const char* MAX_BLOCK_TIME = "max_blocking_time";
constexpr const char* _BEST_EFFORT = "BEST_EFFORT";
constexpr const char* _RELIABLE = "RELIABLE";
constexpr const char* AUTOMATIC = "AUTOMATIC";
constexpr const char* MANUAL_BY_PARTICIPANT = "MANUAL_BY_PARTICIPANT";
constexpr const char* MANUAL_BY_TOPIC = "MANUAL_BY_TOPIC";
constexpr const char* LEASE_DURATION = "lease_duration";
constexpr const char* ANNOUNCE_PERIOD = "announcement_period";
constexpr const char* COUNT = "count";
constexpr const char* PERIOD = "period";
constexpr const char* SRV_CLEAN_DELAY = "service_cleanup_delay";
constexpr const char* HISTORY_KIND = "history_kind";
constexpr const char* HISTORY_DEPTH = "history_depth";
constexpr const char* MAX_SAMPLES = "max_samples";
constexpr const char* MAX_INSTANCES = "max_instances";
constexpr const char* MAX_SAMPLES_INSTANCE = "max_samples_per_instance";
constexpr const char* _VOLATILE = "VOLATILE";
constexpr const char* _TRANSIENT_LOCAL = "TRANSIENT_LOCAL";
constexpr const char* _TRANSIENT = "TRANSIENT";
constexpr const char* _PERSISTENT = "PERSISTENT";
constexpr const char* KEEP_LAST = "KEEP_LAST";
constexpr const char* KEEP_ALL = "KEEP_ALL";
constexpr const char* _NO_KEY = "NO_KEY";
constexpr const char* _WITH_KEY = "WITH_KEY";
constexpr const char* DATA_TYPE = "dataType";
constexpr const char* HISTORY_QOS = "historyQos";
constexpr const char* RES_LIMITS_QOS = "resourceLimitsQos";
constexpr const char* DEPTH = "depth";
constexpr const char* ALLOCATED_SAMPLES = "allocated_samples";
constexpr const char* EXTRA_SAMPLES = "extra_samples";
constexpr const char* BYTES_PER_SECOND = "bytesPerPeriod";
constexpr const char* PERIOD_MILLISECS = "periodMillisecs";
constexpr const char* PORT_BASE = "portBase";
constexpr const char* DOMAIN_ID_GAIN = "domainIDGain";
constexpr const char* PARTICIPANT_ID_GAIN = "participantIDGain";
constexpr const char* OFFSETD0 = "offsetd0";
constexpr const char* OFFSETD1 = "offsetd1";
constexpr const char* OFFSETD2 = "offsetd2";
constexpr const char* OFFSETD3 = "offsetd3";
constexpr const char* RTPS_PDP_TYPE = "discoveryProtocol";
constexpr const char* NONE = "NONE";
constexpr const char* CLIENT = "CLIENT";
constexpr const char* SERVER = "SERVER";
constexpr const char* BACKUP = "BACKUP";
constexpr const char* SUPER_CLIENT = "SUPER_CLIENT";
constexpr const char* IGNORE_PARTICIPANT_FLAGS = "ignoreParticipantFlags";
constexpr const char* FILTER_DIFFERENT_HOST = "FILTER_DIFFERENT_HOST";
constexpr const char* FILTER_DIFFERENT_PROCESS = "FILTER_DIFFERENT_PROCESS";
constexpr const char* FILTER_SAME_PROCESS = "FILTER_SAME_PROCESS";
constexpr const char* WRITER_LVESS_PROTOCOL = "use_WriterLivelinessProtocol";
constexpr const char* DISCOVERY_SETTINGS = "discovery_config";
constexpr const char* _EDP = "EDP";
constexpr const char* DOMAIN_ID = "domainId";
constexpr const char* LEASEDURATION = "leaseDuration";
constexpr const char* LEASE_ANNOUNCE = "leaseAnnouncement";
constexpr const char* INITIAL_ANNOUNCEMENTS = "initialAnnouncements";
constexpr const char* AVOID_BUILTIN_MULTICAST = "avoid_builtin_multicast";
constexpr const char* SIMPLE_EDP = "simpleEDP";
constexpr const char* META_EXT_UNI_LOC_LIST = "metatraffic_external_unicast_locators";
constexpr const char* META_UNI_LOC_LIST = "metatrafficUnicastLocatorList";
constexpr const char* META_MULTI_LOC_LIST = "metatrafficMulticastLocatorList";
constexpr const char* INIT_PEERS_LIST = "initialPeersList";
constexpr const char* CLIENTANNOUNCEMENTPERIOD = "clientAnnouncementPeriod";
constexpr const char* SERVER_LIST = "discoveryServersList";
constexpr const char* RSERVER = "RemoteServer";
constexpr const char* SIMPLE = "SIMPLE";
constexpr const char* STATIC = "STATIC";
constexpr const char* PUBWRITER_SUBREADER = "PUBWRITER_SUBREADER";
constexpr const char* PUBREADER_SUBWRITER = "PUBREADER_SUBWRITER";
constexpr const char* STATIC_ENDPOINT_XML = "staticEndpointXMLFilename";
constexpr const char* STATIC_ENDPOINT_XML_URI = "static_edp_xml_config";
constexpr const char* READER_HIST_MEM_POLICY = "readerHistoryMemoryPolicy";
constexpr const char* WRITER_HIST_MEM_POLICY = "writerHistoryMemoryPolicy";
constexpr const char* READER_PAYLOAD_SIZE = "readerPayloadSize";
constexpr const char* WRITER_PAYLOAD_SIZE = "writerPayloadSize";
constexpr const char* MUTATION_TRIES = "mutation_tries";
constexpr const char* ACCESS_SCOPE = "access_scope";
constexpr const char* ENABLED = "enabled";
constexpr const char* DOMAIN_IDS = "domain_ids";
constexpr const char* SHARED_DIR = "shared_dir";
constexpr const char* MAX_DOMAINS = "max_domains";

// Endpoint parser
constexpr const char* STATICDISCOVERY = "staticdiscovery";
constexpr const char* READER = "reader";
constexpr const char* WRITER = "writer";
constexpr const char* USER_ID = "userId";
constexpr const char* EXPECT_INLINE_QOS = "expectsInlineQos";
constexpr const char* TOPIC_NAME = "topicName";
constexpr const char* TOPIC_DATA_TYPE = "topicDataType";
constexpr const char* TOPIC_KIND = "topicKind";
constexpr const char* RELIABILITY_QOS = "reliabilityQos";
constexpr const char* UNICAST_LOCATOR = "unicastLocator";
constexpr const char* MULTICAST_LOCATOR = "multicastLocator";
constexpr const char* _RELIABLE_RELIABILITY_QOS = "RELIABLE_RELIABILITY_QOS";
constexpr const char* _BEST_EFFORT_RELIABILITY_QOS = "BEST_EFFORT_RELIABILITY_QOS";
constexpr const char* DURABILITY_QOS = "durabilityQos";
constexpr const char* _PERSISTENT_DURABILITY_QOS = "PERSISTENT_DURABILITY_QOS";
constexpr const char* _TRANSIENT_DURABILITY_QOS = "TRANSIENT_DURABILITY_QOS";
constexpr const char* _TRANSIENT_LOCAL_DURABILITY_QOS = "TRANSIENT_LOCAL_DURABILITY_QOS";
constexpr const char* _VOLATILE_DURABILITY_QOS = "VOLATILE_DURABILITY_QOS";
constexpr const char* OWNERSHIP_QOS = "ownershipQos";
constexpr const char* OWNERSHIP_KIND_NOT_PRESENT = "OWNERHSIP kind NOT PRESENT";
constexpr const char* _SHARED_OWNERSHIP_QOS = "SHARED_OWNERSHIP_QOS";
constexpr const char* _EXCLUSIVE_OWNERSHIP_QOS = "EXCLUSIVE_OWNERSHIP_QOS";
constexpr const char* PARTITION_QOS = "partitionQos";
constexpr const char* LIVELINESS_QOS = "livelinessQos";
constexpr const char* LIVELINESS_KIND_NOT_PRESENT = "LIVELINESS kind NOT PRESENT";
constexpr const char* _AUTOMATIC_LIVELINESS_QOS = "AUTOMATIC_LIVELINESS_QOS";
constexpr const char* _MANUAL_BY_PARTICIPANT_LIVELINESS_QOS = "MANUAL_BY_PARTICIPANT_LIVELINESS_QOS";
constexpr const char* _MANUAL_BY_TOPIC_LIVELINESS_QOS = "MANUAL_BY_TOPIC_LIVELINESS_QOS";
constexpr const char* LEASE_DURATION_MS = "leaseDuration_ms";
constexpr const char* _INF = "INF";
constexpr const char* EPROSIMA_UNKNOWN_STRING = "EPROSIMA_UNKNOWN_STRING";
constexpr const char* _OWNERSHIP_KIND_NOT_PRESENT = "OWNERSHIP_KIND_NOT_PRESENT";
constexpr const char* STRENGTH = "strength";

// TYPES parser
constexpr const char* BOOLEAN = "boolean";
constexpr const char* CHAR = "char8";
constexpr const char* WCHAR = "char16";
constexpr const char* TBYTE = "byte";
constexpr const char* OCTET = "octet";
constexpr const char* UINT8 = "uint8";
constexpr const char* INT8 = "int8";
constexpr const char* SHORT = "int16";
constexpr const char* LONG = "int32";
constexpr const char* USHORT = "uint16";
constexpr const char* ULONG = "uint32";
constexpr const char* LONGLONG = "int64";
constexpr const char* ULONGLONG = "uint64";
constexpr const char* FLOAT = "float32";
constexpr const char* DOUBLE = "float64";
constexpr const char* LONGDOUBLE = "float128";
constexpr const char* STRING = "string";
constexpr const char* WSTRING = "wstring";
constexpr const char* LITERAL = "literal";
constexpr const char* STRUCT = "struct";
constexpr const char* UNION = "union";
constexpr const char* SEQUENCE = "sequence";
constexpr const char* MAP = "map";
constexpr const char* TYPEDEF = "typedef";
constexpr const char* BITSET = "bitset";
constexpr const char* BITMASK = "bitmask";
constexpr const char* ENUM = "enum";
constexpr const char* CASE = "case";
constexpr const char* DEFAULT = "default";
constexpr const char* DISCRIMINATOR = "discriminator";
constexpr const char* CASE_DISCRIMINATOR = "caseDiscriminator";
constexpr const char* ARRAY_DIMENSIONS = "arrayDimensions";
constexpr const char* STR_MAXLENGTH = "stringMaxLength";
constexpr const char* SEQ_MAXLENGTH = "sequenceMaxLength";
constexpr const char* MAP_MAXLENGTH = "mapMaxLength";
constexpr const char* MAP_KEY_TYPE = "key_type";
constexpr const char* ENUMERATOR = "enumerator";
constexpr const char* NON_BASIC_TYPE = "nonBasic";
constexpr const char* NON_BASIC_TYPE_NAME = "nonBasicTypeName";
constexpr const char* KEY = "key";
constexpr const char* MEMBER = "member";
constexpr const char* BITFIELD = "bitfield";
constexpr const char* BIT_VALUE = "bit_value";
constexpr const char* POSITION = "position";
constexpr const char* BIT_BOUND = "bit_bound";
constexpr const char* BASE_TYPE = "baseType";

// LOG
constexpr const char* USE_DEFAULT = "use_default";
constexpr const char* CONSUMER = "consumer";
constexpr const char* CLASS = "class";

// Allocation config
constexpr const char* INITIAL = "initial";
constexpr const char* MAXIMUM = "maximum";
constexpr const char* INCREMENT = "increment";

// TLS Config
constexpr const char* TLS = "tls";
constexpr const char* TLS_PASSWORD = "password";
constexpr const char* TLS_OPTIONS = "options";
constexpr const char* TLS_CERT_CHAIN_FILE = "cert_chain_file";
constexpr const char* TLS_PRIVATE_KEY_FILE = "private_key_file";
constexpr const char* TLS_TMP_DH_FILE = "tmp_dh_file";
constexpr const char* TLS_VERIFY_FILE = "verify_file";
constexpr const char* TLS_VERIFY_MODE = "verify_mode";
constexpr const char* TLS_VERIFY_PATHS = "verify_paths";
constexpr const char* TLS_DEFAULT_VERIFY_PATH = "default_verify_path";
constexpr const char* TLS_VERIFY_DEPTH = "verify_depth";
constexpr const char* TLS_RSA_PRIVATE_KEY_FILE = "rsa_private_key_file";
constexpr const char* TLS_HANDSHAKE_ROLE = "handshake_role";
constexpr const char* TLS_SERVER_NAME = "server_name";

// TLS HandShake Role
constexpr const char* TLS_HANDSHAKE_ROLE_DEFAULT = "DEFAULT";
constexpr const char* TLS_HANDSHAKE_ROLE_CLIENT = "CLIENT";
constexpr const char* TLS_HANDSHAKE_ROLE_SERVER = "SERVER";

// TLS Verify Stuff
constexpr const char* TLS_VERIFY_PATH = "verify_path";
constexpr const char* TLS_VERIFY = "verify";

// TLS Options
constexpr const char* TLS_OPTION = "option";
constexpr const char* TLS_DEFAULT_WORKAROUNDS = "DEFAULT_WORKAROUNDS";
constexpr const char* TLS_NO_COMPRESSION = "NO_COMPRESSION";
constexpr const char* TLS_NO_SSLV2 = "NO_SSLV2";
constexpr const char* TLS_NO_SSLV3 = "NO_SSLV3";
constexpr const char* TLS_NO_TLSV1 = "NO_TLSV1";
constexpr const char* TLS_NO_TLSV1_1 = "NO_TLSV1_1";
constexpr const char* TLS_NO_TLSV1_2 = "NO_TLSV1_2";
constexpr const char* TLS_NO_TLSV1_3 = "NO_TLSV1_3";
constexpr const char* TLS_SINGLE_DH_USE = "SINGLE_DH_USE";

// TLS Verify Mode
constexpr const char* TLS_VERIFY_NONE = "VERIFY_NONE";
constexpr const char* TLS_VERIFY_PEER = "VERIFY_PEER";
constexpr const char* TLS_VERIFY_FAIL_IF_NO_PEER_CERT = "VERIFY_FAIL_IF_NO_PEER_CERT";
constexpr const char* TLS_VERIFY_CLIENT_ONCE = "VERIFY_CLIENT_ONCE";

// Requester and Replier
constexpr const char* SERVICE_NAME = "service_name";
constexpr const char* REQUEST_TYPE = "request_type";
constexpr const char* REPLY_TYPE = "reply_type";
constexpr const char* REQUEST_TOPIC_NAME = "request_topic_name";
constexpr const char* REPLY_TOPIC_NAME = "reply_topic_name";

} /* tag */
} /* qosprof */
} /* eprosima */

#endif // _FAST_DDS_QOS_PROFILES_MANAGER_UTILS_PARSE_XML_TAGS_HPP_
