.. _fastdds_qos_profiles_manager_cli_element_intro:

Configuration parameter access
==============================

The access to each configuration parameter is done sequentially using a dot-separated entity string.
This section explains with detail how to access the different configuration parameter.

.. note::

    **Disclaimer**: This section does not explain the meaning of each configuration parameter.
    Please, refer to `Fast DDS documentation <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/xml_configuration.html>`_ for a more in-depth understanding of the configuration parameters.

The main supported elements that can be configured using the CLI are:

.. list-table::
    :header-rows: 1
    :align: left

    * - Main element
      - Description
    * - ``participant``
      - `DomainParticipant profile <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/domainparticipant.html>`_ configuration.
    * - ``datareader``
      - `DataReader profile <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/datareader.html>`_ configuration.
    * - ``datawriter``
      - `DataWriter profile <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/datawriter.html>`_ configuration.
    * - ``topic``
      - `Topic profile <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/topic.html>`_ configuration.
    * - ``transport_descriptor``
      - `Transport descriptor <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/transports.html>`_ configuration.
    * - ``intraprocess``
      - `Intra-process delivery communication <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/library_settings.html>`_ configuration.
    * - ``log``
      - `Fast DDS log module <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/log.html>`_ configuration.
    * - ``types``
      - `Dynamic types <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/dynamic_types.html>`_ configuration.

.. toctree::
  :maxdepth: 2

  cli_participant_element
  cli_datareader_element
  cli_datawriter_element
  cli_topic_element
  cli_transport_descriptor_element
  cli_intraprocess_element
  cli_log_element
  cli_types_element
  cli_common_elements
