.. _fastdds_qos_profiles_manager_cli_transport_elements:

Transport Descriptor configuration access
-----------------------------------------

This section explains how to access the different configurable paramenters in a transport descriptor profile.
The scope of this section does not include explaining the usage of these specific parameters.
Please, refer to `Fast DDS documentation <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/transports.html>`_ for that information.

The transport descriptor profile is accessed through the ``transport_descriptor`` element.
The profile name is mandatory and must be passed within brackets.
Whitespaces are allowed in the profile name if the profile name is quoted.

.. code-block:: bash

    fastddsqosprof <file> <verb> transport_descriptor[profile_name].<subelement>
    fastddsqosprof <file> <verb> transport_descriptor["profile name"].<subelement>

The transport descriptor configurable ``<subelements>`` are explained in the table below.

.. list-table::
    :header-rows: 1
    :align: left

    * - CLI access
      - Description
      - Valid ``set``values
    * - kind
      - Simple parameter
      - ``udp_v4``
    
