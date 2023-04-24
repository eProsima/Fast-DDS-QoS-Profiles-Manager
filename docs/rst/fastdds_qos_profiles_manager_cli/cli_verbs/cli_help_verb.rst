.. _fastdds_qos_profiles_manager_cli_help_verb:

Fast DDS QoS Profiles Manager CLI ``help`` verb
-----------------------------------------------

Passing to the CLI the verb ``help`` as the last argument would display the corresponding subelement CLI usage.
Besides ``help``, the flag ``--help`` and the shorthand ``-h`` are also supported.

The snippet below shows different examples:

.. code-block:: bash

    $ fastddsqosprof --help
      > Generic CLI usage

    $ fastddsqosprof file help
      > Generic CLI usage

    $ fastddsqosprof file set -h
      > Specific SET command usage

    $ fastddsqosprof file set datareader help
      > Specific DataReader element usage

    $ fastddsqosprof file set datareader[profile].default_profile -h
      > Specific default profile attribute usage
