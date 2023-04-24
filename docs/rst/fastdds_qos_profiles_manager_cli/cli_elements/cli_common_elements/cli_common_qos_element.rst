.. include:: ../../../01-exports/roles.include

.. _fastdds_qos_profiles_manager_cli_common_qos_element:

QoS configuration
-----------------

This section explains how to access the different configurable parameters in a Quality of Service (QoS) profile.
The scope of this section does not include explaining the usage of these specific parameters.
Please, refer to `Fast DDS documentation <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/common.html#commonqos>`_ for that information.

.. note::

    The CLI QoS element also includes the Topic Type defined in `Fast DDS <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/common.html#topictype>`_ documentation.

The QoS configuration is accessed through the ``qos`` element which is a complex parameter according to the :ref:`fastdds_qos_profiles_manager_element_classification`.
The currently supported QoS configurable ``<subelements>`` are explained in the table below.

.. list-table::
    :header-rows: 1
    :align: left

    * - ``<subelement>``
      - CLI access
      - :ref:`fastdds_qos_profiles_manager_element_classification`
      - Valid ``set`` value
    * - Durability QoS Policy
      - ``qos.durability``
      - Simple parameter
      - ``volatile`` |br|
        ``transient_local`` |br|
        ``transient`` |br|
        ``persistent``
    * - Reliability QoS Policy
      - ``qos.reliability``
      - Complex parameter. |br|
        Please, refer to :ref:`fastdds_qos_profiles_manager_cli_common_qos_reliability_element` |br|
        section for more information.
      - N/A

.. warning::

    Any other configurable ``subelement`` is not yet supported.

.. _fastdds_qos_profiles_manager_cli_common_qos_reliability_element:

Reliability QoS Policy configuration
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This section explains how to access the different configurable parameters in the Reliability QoS Policy.
The scope of this section does not include explaining the usage of these specific parameters.
Please, refer to `Reliability QoS Policy section <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/common.html#reliabilityqospolicy>`_ in Fast DDS documentation for that information.

The Reliability QoS Policy is accessed through the ``reliability`` element which is a complex parameter according to the :ref:`fastdds_qos_profiles_manager_element_classification`.
The Reliability QoS Policy configurable ``<subelements>`` are explained in the table below.

.. list-table::
    :header-rows: 1
    :align: left

    * - ``<subelement>``
      - CLI access
      - :ref:`fastdds_qos_profiles_manager_element_classification`
      - Valid ``set`` values
    * - Reliability kind
      - ``reliability.kind``
      - Simple parameter
      - ``best_effort`` |br|
        ``reliable``
    * - Reliability maximum blocking time
      - ``reliability.duration.max_blocking_time``
      - Complex parameter. |br|
        Please, refer to :ref:`fastdds_qos_profiles_manager_cli_common_duration_type_element` |br|
        for more information.
      - N/A
