.. include:: ../../01-exports/roles.include

.. _fastdds_qos_profiles_manager_cli_participant_elements:

Participant profiles configuration access
-----------------------------------------

This section explains how to access the different configurable parameters in a DomainParticipant profile.
The scope of this section does not include explaining the usage of these specific parameters.
Please, refer to `Fast DDS documentation <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/domainparticipant.html>`_ for that information.

The DomainParticipant profile is accessed through the ``participant`` element.
The profile name is mandatory and must be passed within brackets.
Whitespaces are allowed in the profile name if the profile name is quoted.
Consequently, ``participant`` is a complex parameter map according to the :ref:`fastdds_qos_profiles_manager_element_classification` with the profile name as ``key``.

.. important::

    The only case when the profile name is not required is when printing or clearing the default profile attribute.

.. code-block:: bash

    fastddsqosprof <file> <verb> participant[profile_name].<subelement>
    fastddsqosprof <file> <verb> participant["profile name"].<subelement>

The currently supported DomainParticipant configurable ``<subelements>`` are explained in the table below.

.. list-table::
    :header-rows: 1
    :align: left

    * - ``<subelement>``
      - CLI access
      - :ref:`fastdds_qos_profiles_manager_element_classification`
      - Valid ``set`` values
    * - Builtin configuration
      - ``participant[profile_name].builtin``
      - Complex parameter. |br|
        Please, refer to :ref:`fastdds_qos_profiles_manager_cli_participant_builtin_element` |br|
        section for more information.
      - N/A
    * - Default external unicast |br| locators configuration
      - ``participant[profile_name].external_locators.default_unicast[(index)]``
      - Complex parameter list. |br|
        Please, refer to :ref:`fastdds_qos_profiles_manager_cli_common_external_locators_element` |br|
        section for more information.
      - N/A
    * - Default profile attribute
      - ``participant[(profile_name)].default_profile``
      - Simple parameter
      - ``true`` |br|
        ``false`` |br|
        (``profile_name`` is only required with verb ``set``).
    * - Name element
      - ``participant[profile_name].name``
      - Simple parameter
      - ``string``
    * - Use builtin transports flag
      - ``participant[profile_name].use_builtin_transports``
      - Simple parameter
      - ``true`` |br|
        ``false``
    * - User transports list
      - ``participant[profile_name].user_transports[(index)]``
      - Simple parameter list
      - ``string``

.. warning::

    Any other configurable ``<subelement>`` is not yet supported.


.. _fastdds_qos_profiles_manager_cli_participant_builtin_element:

Builtin configuration
^^^^^^^^^^^^^^^^^^^^^

The DomainParticipant builtin configuration is accessed through the ``builtin`` element which is a complex parameter according to the :ref:`fastdds_qos_profiles_manager_element_classification`.
The scope of this section does not include explaining the usage of these specific parameters.
Please, refer to `Fast DDS documentation <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/domainparticipant.html#builtin-parameters>`_ for that information.

The currently supported builtin configurable ``<subelements>`` are explained in the table below.

.. list-table::
    :header-rows: 1
    :align: left

    * - ``<subelement>``
      - CLI access
      - :ref:`fastdds_qos_profiles_manager_element_classification`
      - Valid ``set`` value
    * - Discovery configuration
      - ``participant[profile_name].builtin.discovery_config``
      - Complex parameter. |br|
        Please, refer to :ref:`fastdds_qos_profiles_manager_cli_participant_builtin_discovery_config_element` |br|
        section for more information.
      - N/A
    * - Initial peers configuration
      - ``participant[profile_name].builtin.locators.initial_peers[(index)]``
      - Complex parameter list. |br|
        Please, refer to :ref:`fastdds_qos_profiles_manager_cli_common_locators_element` |br|
        section for more information.
      - N/A
    * - Metatraffic external unicast |br| locators configuration
      - ``participant[profile_name].builtin.external_locators.metatraffic_unicast[(index)]``
      - Complex parameter list. |br|
        Please, refer to :ref:`fastdds_qos_profiles_manager_cli_common_external_locators_element` |br|
        section for more information.
      - N/A

.. warning::

    Any other configurable ``subelement`` is not yet supported.

.. _fastdds_qos_profiles_manager_cli_participant_builtin_discovery_config_element:

Discovery configuration
"""""""""""""""""""""""

The DomainParticipant builtin discovery configuration is accessed through the ``discovery_config`` element which is a complex parameter according to the :ref:`fastdds_qos_profiles_manager_element_classification`.
The scope of this section does not include explaining the usage of these specific parameters.
Please, refer to `Fast DDS documentation <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/domainparticipant.html#dconf>`_ for that information.

The currently supported discovery configurable ``<subelements>`` are explained in the table below.

.. list-table::
    :header-rows: 1
    :align: left

    * - ``<subelement>``
      - CLI access
      - :ref:`fastdds_qos_profiles_manager_element_classification`
      - Valid ``set`` value
    * - Lease announcements
      - ``participant[profile_name].builtin.discovery_config.duration.announcements``
      - Complex parameter. |br|
        Please, refer to :ref:`fastdds_qos_profiles_manager_cli_common_duration_type_element` |br|
        section for more information.
      - N/A
    * - Lease duration
      - ``participant[profile_name].builtin.discovery_config.duration.lease``
      - Complex parameter. |br|
        Please, refer to :ref:`fastdds_qos_profiles_manager_cli_common_duration_type_element` |br|
        section for more information.
      - N/A


.. warning::

    Any other configurable ``subelement`` is not yet supported.
