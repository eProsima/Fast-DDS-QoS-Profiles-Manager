.. _fastdds_qos_profiles_manager_cli_common_locators_element:

Locators configuration
----------------------

This section explains how to access the different configurable parameters in a locator list configuration.
The scope of this section does not include explaining the usage of these specific parameters.
Please, refer to `Fast DDS documentation <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/common.html#locatorlisttype>`_ for that information.

The locator list configuration is accessed through the ``locators`` element which is a complex parameter according to the :ref:`fastdds_qos_profiles_manager_element_classification`.
The locator list configurable ``<subelements>`` are explained in the table below.

.. list-table::
    :header-rows: 1
    :align: left

    * - ``subelement``
      - CLI access
      - :ref:`fastdds_qos_profiles_manager_element_classification`
      - Valid ``set`` values
    * - Address element
      - ``locators.<locator_type>[(index)].address``
      - Simple parameter
      - IP or DNS address
    * - Port element
      - ``locators.<locator_type>[(index)].port``
      - Simple parameter
      - ``uint16_t``

.. note::

    As explained in the :ref:`fastdds_qos_profiles_manager_element_classification` section, this collection should be accessed by means of a given integer index between brackets to select the specific collection element.
    Both positive and negative indexes are allowed to access the collection from both ends.
    If no index is provided, the complete collection is selected (either to be printed or cleared, for instance).
    To push a new element into the collection, no index should be provided to the ``set`` command.

The ``<locator_type>`` element is defined for each specific element.
The list below includes the currently supported ``<locator_type>`` elements:

* :ref:`Participant builtin initial peers <fastdds_qos_profiles_manager_cli_participant_builtin_element>`.

.. warning::

    Any other ``<locator_type>`` is not yet supported.
