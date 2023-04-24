.. include:: ../../01-exports/roles.include

.. _fastdds_qos_profiles_manager_cli_datawriter_elements:

DataWriter profiles configuration access
----------------------------------------

This section explains how to access the different configurable parameters in a DataWriter profile.
The scope of this section does not include explaining the usage of these specific parameters.
Please, refer to `Fast DDS documentation <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/datawriter.html>`_ for that information.

The DataWriter profile is accessed through the ``datawriter`` element.
The profile name is mandatory and must be passed within brackets.
Whitespaces are allowed in the profile name if the profile name is quoted.
Consequently, ``datawriter`` is a complex parameter map according to the :ref:`fastdds_qos_profiles_manager_element_classification` with the profile name as ``key``.

.. important::

    The only case when the profile name is not required is when printing or clearing the default profile attribute.

.. code-block:: bash

    fastddsqosprof <file> <verb> datawriter[profile_name].<subelement>
    fastddsqosprof <file> <verb> datawriter["profile name"].<subelement>

The currently supported DataWriter configurable ``<subelements>`` are explained in the table below.

.. list-table::
    :header-rows: 1
    :align: left

    * - ``<subelement>``
      - CLI access
      - :ref:`fastdds_qos_profiles_manager_element_classification`
      - Valid ``set`` values
    * - Default profile attribute
      - ``datawriter[(profile_name)].default_profile``
      - Simple parameter
      - ``true`` |br|
        ``false`` |br|
        ``profile_name`` is only required with verb ``set``.
    * - QoS configuration
      - ``datawriter[profile_name].qos``
      - Complex parameter. |br|
        Please, refer to :ref:`fastdds_qos_profiles_manager_cli_common_qos_element` |br|
        section for more information.
      - N/A

.. warning::

    Any other configurable ``<subelement>`` is not yet supported.
