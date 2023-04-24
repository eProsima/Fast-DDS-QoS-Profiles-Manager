.. raw:: html

  <h1>
    eProsima Fast DDS Profiles QoS Manager
  </h1>

.. image:: /rst/figures/logo.png
    :height: 100px
    :width: 100px
    :align: left
    :alt: eProsima
    :target: http://www.eprosima.com/

*eProsima Fast DDS QoS Profiles Manager* is a tool suite for the generation of `Fast DDS <https://fast-dds.docs.eprosima.com/en/latest/>`_ `XML configuration files <https://fast-dds.docs.eprosima.com/en/latest/fastdds/xml_configuration/xml_configuration.html>`_.
The suite provides both a Graphical User Interface (GUI) and a Command Line Interface (CLI).

Graphical User Interface
^^^^^^^^^^^^^^^^^^^^^^^^

*eProsima Fast DDS QoS Profiles Manager* provides a GUI to facilitate users the creation and modification of XML configuration files in an easy way.
With an easy to use interface which allows to navigate between the configuration menus, the corresponding features can be configured and the XML to be deployed can be validated and created.
Thus, the user can be agnostic of the specific XML format followed by *eProsima Fast DDS*.
More information can be found in the :ref:`fastdds_qos_profiles_manager_gui` section.

Command Line Interface
^^^^^^^^^^^^^^^^^^^^^^

*eProsima Fast DDS QoS Profiles Manager CLI* provides a command line interface which can be integrated in any script to automatically generate the deployment XML configuration files.
More information about the CLI and how to use it can be found in the :ref:`fastdds_qos_profiles_manager_cli` section.
Also, examples of how to integrate the CLI in a script to generate deployment configuration files can be found in the `tool suite repository <https://github.com/eProsima/Fast-DDS-QoS-Profiles-Manager/tree/main/cli/examples>`_.

Fast DDS QoS Profiles Manager Library
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Both the CLI and GUI tools depends on a library which takes charge of handling and modifying the XML configuration files.
The :ref:`fastdds_qos_profiles_manager_lib_api_reference` section summarizes the API exposed publicly.
Any user can consequently develop any other integration tool adapted to its own development environment, although the most common use would be through the CLI or GUI tools provided by eProsima.
The graph below shows the relationship between the different packages provided in the tool suite.

.. mermaid::
  :caption: Fast DDS QoS Profiles Manager Tool Suite
  :align: center

  erDiagram
    GUI |o--|| library : uses
    CLI |o--|| library : uses
    library |o--|{ XML : generates
    XML {
      contains profiles
    }

.. warning::

  The tool suite is still in its development stage.
  For this reason, the API should not be considered stable, as API breaks may accur before the first official release.
  Furthermore, several features may not be implemented yet.
