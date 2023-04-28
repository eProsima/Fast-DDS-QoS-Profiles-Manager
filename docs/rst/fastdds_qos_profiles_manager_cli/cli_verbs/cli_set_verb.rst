.. _fastdds_qos_profiles_manager_cli_set_verb:

``set`` verb
------------

Passing to the CLI the verb ``set`` would include the given ``value`` in the selected XML ``element``.
The verb is the third argument passed to the CLI (see :ref:`fastdds_qos_profiles_manager_cli_usage` section).
The element is given by a dot-separated string accessing the configuration parameter to be set (see :ref:`fastdds_qos_profiles_manager_cli_element_intro` section).
The set command requires usually at least the value desired for the specified element.

.. note::

    There are exceptions in which the verb ``set`` does not need a ``value``, as in the ``default_profile`` attribute cases for ``datareader``, ``datawriter`` and ``participant`` entities.

The snippet below shows different examples:

.. code-block:: bash

    $ fastddsqosprof file set datareader[dr_profile].qos.durability volatile

    $ fastddsqosprof file set datareader[dr_profile].default_profile

    $ fastddsqosprof file set datawriter[dw_profile].qos.reliability.duration.max_blocking_time 1 100

    $ fastddsqosprof file set participant[p_profile].name "My participant"

    $ fastddsqosprof file set participant[p_profile].use_builtin_transports true

    $ fastddsqosprof file set participant[p_profile].user_transports[] td_profile

    $ fastddsqosprof file set transport_descriptor[td_profile].kind shm

The following XML configuration file represents the result of the consecutive CLI commands run.

.. literalinclude:: /code/cli_verb_set_example.xml
    :language: xml
