.. _fastdds_qos_profiles_manager_lib_api_reference:

Introduction
============

This section presents the public API provided by *eProsima Fast DDS QoS Profiles Manager Library*.

The *Library* needs to be initialized and closed in each use.
The ``initialize`` method would create a XML workspace in which any *Library* call can be executed.
When no more *Library* API calls needed, the ``terminate`` method would apply the possible changes in the filesystem, and would close the XML workspace.

See :ref:`initialize and terminate methods reference <api_qos_profiles_manager>` for further information.
