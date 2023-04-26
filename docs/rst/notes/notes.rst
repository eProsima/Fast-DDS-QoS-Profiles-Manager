.. _release_notes:

Version 0.1.0
=============

This first release includes the following features:

Fast DDS QoS Profiles Manager Library
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1. Library infrastructure.
2. Implementation of several `set` functions:
    - DomainParticipant name.
    - DomainParticipant external locators (default and metatraffic): externality, address, and port.
    - DomainParticipant initial peers: address and port.
    - DomainParticipant lease duration and lease announcements.
    - DomainParticipant use of custom transports disabling builtin transports.
    - Reliability and Durability QoS for DataReader and DataWriter profiles.
    - Default profile attribute for DomainParticipant, DataReader and DataWriter.

Fast DDS QoS Profiles Manager CLI
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Support for the library features.
* External locators example

Fast DDS QoS Profiles Manager Documentation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* :ref:`Installation manual <linux_installation>`
* :ref:`Library API Reference <fastdds_qos_profiles_manager_lib_api_reference>`
* :ref:`CLI documentation for supported features <fastdds_qos_profiles_manager_cli>`
* Automatic CI
