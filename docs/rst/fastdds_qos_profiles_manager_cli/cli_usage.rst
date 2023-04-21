.. include:: ../01-exports/api-lib-aliases.include

.. _fastdds_qos_profiles_manager_cli_usage:

CLI Usage
=========

*eProsima Fast DDS QoS Profiles Manager CLI* general usage is:

.. code-block:: bash

    fastddsqosprof <file> <verb> <element> [<value>]

After the executable, the first parameter expected is the name of the XML configuration file that is going to be read/modified.
The file path can be provided both in an absolute or relative manner.
If the file is non-existent, the |FileNotFound-api| exception thrown by the library is caught and the corresponding error is shown to the user, except if the commanded verb has been ``set``.
In that specific case, the file is created with the corresponding configuration parameter.

The CLI supported verbs are shown in the table below:

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
        This might be useful for automated scripts that leverages the CLI to automatically generate the deployment configuration files.
    * - ``set``
      - Add a configuration parameter into the XML configuration file.
    * - ``validate``
      - Validate given XML configuration file against Fast DDS XSD schema.

The element specifies the configuration parameter that the user wants to read/modify.
The access to the specific configuration parameter is done following the structure explained in :ref:`fastdds_qos_profiles_manager_cli_element_intro` section.
If the parameter is being ``set``, the corresponding configuration ``value`` has to be passed to the CLI.

.. important::

  At any time, passing ``help`` (or the also supported flags ``--help`` and ``-h``) as the last value in the CLI will provide the user with the usage for the specific element/subelement that is trying to configure.
  For instance, the following command

  .. code-block:: bash
    
    fastddsqosprof file.xml set participant -h
    
  will show the usage corresponding to the DomainParticipant profiles configuration.

The previous usage is the most common among the supported verbs.
However, some of the verbs have a specific usage which is shown below.

.. warning::

  Currently only ``set`` and ``help`` verb are supported.

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