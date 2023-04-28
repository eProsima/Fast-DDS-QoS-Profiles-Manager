.. include:: ../01-exports/api-lib-aliases.include
.. include:: ../01-exports/roles.include

.. _fastdds_qos_profiles_manager_cli_usage:

Usage
=====

*eProsima Fast DDS QoS Profiles Manager CLI* general usage is:

.. code-block:: bash

    fastddsqosprof <file> <verb> <element> [<value>]

After the executable, the first parameter expected is the name of the XML configuration file that is going to be read/modified.
The ``<file>`` path can be provided both in an absolute or relative manner.

The CLI supported verbs are explained in the table below:

.. list-table::
    :header-rows: 1
    :align: left

    * - Verb
      - Description
    * - ``clear``
      - Remove configuration parameter from XML configuration file.
    * - ``compare``
      - Compare two different configuration files.
    * - ``help``
      - Show CLI usage.
    * - ``print``
      - Print configuration parameter from XML configuration file.
    * - ``query``
      - Extract information related to parameter lists.
        This might be useful for automated scripts that leverages the CLI to automatically |br|
        generate the deployment configuration files.
    * - ``set``
      - Add a configuration parameter into the XML configuration file.
    * - ``validate``
      - Validate given XML configuration file against Fast DDS XSD schema.

The next CLI argument, ``<element>``, specifies the configuration parameter to be read/modified.
The access to the specific configuration parameter is done following the structure explained in :ref:`fastdds_qos_profiles_manager_cli_element_intro` section.
If the parameter is being ``set``, the corresponding configuration ``value`` has to be passed to the CLI.

.. important::

  At any time, passing ``help`` (or the also supported flags ``--help`` and ``-h``) as the last value in the CLI will provide the usage for the specific element/subelement which is being configured.
  For instance, the following command

  .. code-block:: bash

    fastddsqosprof file.xml set participant -h

  will show the usage corresponding to the DomainParticipant profiles configuration.
  More information can be found in :ref:`fastdds_qos_profiles_manager_cli_help_verb`.

The previous usage is the most common among the supported verbs.
However, some of the verbs have a specific usage which is shown below.

.. warning::

  Currently only ``set`` and ``help`` verbs are supported.

Compare usage
-------------

.. warning::

  ``compare`` verb is not yet supported.

Query usage
-----------

.. warning::

  ``query`` verb is not yet supported.

Validate usage
--------------

.. warning::

  ``validate`` verb is not yet supported.
