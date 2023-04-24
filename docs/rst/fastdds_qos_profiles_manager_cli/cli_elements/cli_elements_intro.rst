.. _fastdds_qos_profiles_manager_cli_element_intro:

Configuration parameter access
==============================

The access to each configuration parameter is done sequentially using a dot-separated entity string.
This section explains with detail how to access the different configuration parameters.

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

.. _fastdds_qos_profiles_manager_element_classification:

Configuration parameter classification
--------------------------------------

Every configurable parameter can be classified using the following concepts:

* **Simple parameters**: these parameters are final configurable elements.
  Access through the CLI is done by means of a dot-separated string until reaching the final element which is always a simple parameter.
* **Complex parameters**: these parameters contain another configurable parameters.
  Consequently, complex parameters are not final and another subelement can be configured within them.
* **Parameter lists**: some parameters allows for an undefined number of elements.
  These collections should be accessed by means of a given integer index between brackets to select the specific collection element.
  Both positive and negative indexes are allowed to access the collection from both ends.
  If no index is provided, the complete collection is selected (either to be printed or cleared, for instance).
  To push a new element into the collection, no index should be provided to the ``set`` command.
  Parameter lists can be simple or complex depending on the contained element.
* **Parameter maps**: these parameters are a specific collection kind whose access is performed using a ``key`` instead of an integer index.
  Parameter maps can be simple or complex depending on the contained element.

.. note::

  The verb ``query`` can only be used with parameter lists or maps.
  Querying a non-collection parameter would result in an error being displayed.

Main supported elements configurable parameters
-----------------------------------------------

The sections below explain the configurable parameters in each of the main supported elements.

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
