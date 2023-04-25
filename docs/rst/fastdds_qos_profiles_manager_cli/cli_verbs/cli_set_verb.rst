.. _fastdds_qos_profiles_manager_cli_set_verb:

Fast DDS QoS Profiles Manager CLI ``set`` verb
----------------------------------------------

Passing to the CLI the verb ``set`` as the third argument would include the given ``value`` in the selected XML ``element``.

.. note::

    There are exceptions in which the verb ``set`` does not need a ``value``, as in ``default_profile`` cases for the entities ``datareader``, ``datawriter`` and ``participant``.

The snippet below shows different examples:

.. code-block:: bash

    $ fastddsqosprof file set datareader[dr_profile].qos.durability volatile

    $ fastddsqosprof file set datareader[dr_profile].default_profile

    $ fastddsqosprof file set datawriter[dw_profile].qos.reliability.duration.max_blocking_time 1

    $ fastddsqosprof file set participant[p_profile].name "My participant"

    $ fastddsqosprof file set participant[p_profile].use_builtin_transports true

    $ fastddsqosprof file set participant[p_profile].user_transports[] td_profile

    $ fastddsqosprof file set transport_descriptor[td_profile].kind shm

The following XML configuration file represents the result of the consecutive CLI commands run.

.. code-block:: xml

    <?xml version="1.0" encoding="UTF-8" standalone="no" ?>
    <dds xmlns="http://www.eprosima.com/XMLSchemas/fastRTPS_Profiles">
        <profiles>
            <data_reader is_default_profile="true" profile_name="dr_profile">
                <qos>
                    <durability>
                        <kind>VOLATILE</kind>
                    </durability>
                </qos>
            </data_reader>
            <data_writer profile_name="dw_profile">
                <qos>
                    <reliability>
                        <max_blocking_time>
                            <sec>1</sec>
                        </max_blocking_time>
                    </reliability>
                </qos>
            </data_writer>
            <participant profile_name="p_profile">
                <rtps>
                    <name>My participant</name>
                    <useBuiltinTransports>true</useBuiltinTransports>
                    <userTransports>
                        <transport_id>td_profile</transport_id>
                    </userTransports>
                </rtps>
            </participant>
            <transport_descriptors>
                <transport_descriptor>
                    <transport_id>td_profile</transport_id>
                    <type>SHM</type>
                </transport_descriptor>
            </transport_descriptors>
        </profiles>
    </dds>
