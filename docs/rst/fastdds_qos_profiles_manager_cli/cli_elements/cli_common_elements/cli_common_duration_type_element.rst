.. include:: ../../../01-exports/roles.include

.. _fastdds_qos_profiles_manager_cli_common_duration_type_element:

Duration type configuration
---------------------------

This section explains how to access the different configurable parameters in a duration type configuration.
The scope of this section does not include explaining the usage of these specific parameters.
Please, refer to `Fast DDS documentation <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/common.html#durationtype>`_ for that information.

The duration type configuration is accessed through the ``duration`` element which is a complex parameter according to the :ref:`fastdds_qos_profiles_manager_element_classification`.
The duration type configurable ``<subelements>`` are explained in the table below.

.. list-table::
    :header-rows: 1
    :align: left

    * - ``subelement``
      - CLI access
      - :ref:`fastdds_qos_profiles_manager_element_classification`
      - Valid ``set`` values
    * - Seconds
      - ``duration.<duration_type>.sec``
      - Simple parameter
      - ``int32_t``
    * - Nanoseconds
      - ``duration.<duration_type>.nanosec``
      - Simple parameter
      - ``uint32_t``

Duration type can also be set in the following supported usages:

* Setting an infinite duration: ``duration.<duration_type> infinite``

* Setting the duration directly: ``duration.<duration_type> <sec_value> <nanosec_value>``

.. note::

    The duration can be directly set also by passing only the ``<sec_value>`` argument: ``duration.<duration_type> <sec_value>``


The ``<duration_type>`` element is defined for each specific element.
The list below includes the currently supported ``<duration_type>`` elements:

* :ref:`Reliability QoS maximum blocking time <fastdds_qos_profiles_manager_cli_common_qos_reliability_element>`.
* :ref:`Participant builtin discovery configuration lease duration <fastdds_qos_profiles_manager_cli_participant_builtin_discovery_config_element>`.
* :ref:`Participant builtin discovery configuration lease announcements <fastdds_qos_profiles_manager_cli_participant_builtin_discovery_config_element>`.

.. warning::

    Any other ``<duration_type>`` is not yet supported.
