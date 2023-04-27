.. _linux_installation:

Linux installation from sources
===============================

The *eProsima Fast DDS QoS Profiles Manager* tool suite is composed by several packages as described in the :ref:`Introduction <qos_prof_description_>`.
It is organized as follows:

.. contents::
    :local:
    :backlinks: none
    :depth: 2

The tool suite can either be built using `colcon <https://colcon.readthedocs.io/en/released/>`_ or `CMake <https://cmake.org/>`_.
With CMake, the tool suite build and environment source processes must be done manually and following the tool package dependencies, whereas colcon automatizes these two actions with a single command.
For that reason, the use of colcon is highly recommended.

.. _installation_prerequisites_source_linux:

Prerequisites
-------------

The installation of the tool suite in a Linux environment from sources requires some :ref:`installation_required_tools_source_linux` to be installed in the system.

.. _installation_required_tools_source_linux:

Build and development tools
^^^^^^^^^^^^^^^^^^^^^^^^^^^

The following packages are required to build the *eProsima Fast DDS QoS Profiles Manager* tool suite from sources.
Install `CMake <https://cmake.org/>`_, `g++ <https://gcc.gnu.org/>`_, `pip3 <https://docs.python.org/3/installing/index.html>`_ and `git <https://git-scm.com/>`_ using the package manager of the appropriate Linux distribution.
For example, on Ubuntu use the command:

.. code-block:: bash

    sudo apt update
    sudo apt install cmake g++ python3-pip git

.. _installation_optional_tools_source_linux:

Recommended build tools (optional)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Despite the fact that the *eProsima Fast DDS QoS Profiles Manager* tool suite packages can be built using CMake, colcon simplifies the task substantially.
colcon is a command line tool based on CMake aimed at building sets of software packages.
Install colcon by executing the following command:

.. code-block:: bash

    pip3 install -U colcon-common-extensions

.. note::

    Mind that under non-root users, :code:`pip3` may install python :code:`colcon` executable in :code:`$HOME/.local/bin`, for instance when running with :code:`--user`.
    To be able to run this application, make sure that :code:`pip3` binary installation directory is in your :code:`$PATH` (:code:`$HOME/.local/bin` is normally introduced while login on an interactive non-root shell).

Dependencies
------------

This section deals with the required dependencies for each package included in the tool suite.

.. important::

    The *Library* package is required for building the remain tool packages.

Library tool
^^^^^^^^^^^^

The *eProsima Fast DDS QoS Profiles Manager Library* requires Xerces.
The package test suite depends on GTest.

Xerces
""""""

`Xerces C++ <https://xerces.apache.org/xerces-c/>`_ is an Apache project that provides XML parsers and related components solutions for development.
In Ubuntu, it can be installed running:

.. code-block:: bash

    sudo apt install libxerces-c-dev

GTest (optional)
""""""""""""""""

GTest is a unit testing library for C++.
By default, *eProsima Fast DDS QoS Profiles Manager* does not compile tests.
It is possible to activate them with the opportune CMake configuration options when calling colcon or CMake.

GTest installation can be performed either following the `GTest installation instructions <https://google.github.io/googletest/>`_, or including the `Gtest repository <https://github.com/google/googletest>`_ in the workspace directory, running:

.. code-block:: bash

    git clone https://github.com/google/googletest ~/fastdds_qosprofman_ws/src/googletest-distribution

.. note::

    If the colcon deployment is followed, and GTest has been installed in the workspace directory, the GTest dependency needs to be included in the *Library* ``colcon.pkg`` file.
    Please check the :ref:`colcon build procedure <installation_build_source_linux>` for further information.

CLI tool
^^^^^^^^

The *eProsima Fast DDS QoS Profiles Manager CLI* depends on the tool suite *Library* and also on the following package.

Docopt
""""""

`docopt <http://docopt.org/>`_ is a CLI description language that defines the interface of the command line applications and generates a parser for it automatically.
In Ubuntu, the dependency can be installed running:

.. code-block:: bash

    sudo apt install libdocopt-dev

GUI tool
^^^^^^^^

.. warning::

    This tool is still in development process.

Documentation tool
^^^^^^^^^^^^^^^^^^

The *eProsima Fast DDS QoS Profiles Manager Documentation* depends on the tool suite *Library* and also on the following package.

Doxygen
"""""""

`Doxygen <https://www.doxygen.nl/>`_ is a C++ documentation generator.
It is required to build the :ref:`Library API reference <fastdds_qos_profiles_manager_lib_api_reference>`.
In Ubuntu, the dependency can be installed running:

.. code-block:: bash

    sudo apt install doxygen

Python3 virtual environment (recomended)
""""""""""""""""""""""""""""""""""""""""

It is recommended to install the *Documentation* tool dependencies in a `python3 <https://www.python.org/downloads/>`_ virtual environment.
That would avoid polluting the user's installation setup.
Also, the *Documentation* tool has several dependencies described in the ``requirements.txt`` project file.

.. literalinclude:: /requirements.txt
    :language: text

.. important::

    Once :ref:`the repository is downloaded <installation_download_project_source_linux>`, deploy the project in a python3 virtual environment and install the ``requirements.txt`` dependencies by running:

    .. code-block:: bash

        # Python3 installation
        sudo apt install python3.10-venv

        # Virtual environment deployment
        cd <path_to_virtual_environment_directory>
        python3 -m venv fastdds_qosprofman_venv
        source fastdds_qosprofman_venv/bin/activate

        # Required dependencies installation
        pip3 install -r ~/fastdds_qosprofman_ws/src/Fast-DDS-QoS-Profiles-Manager/docs/requirements.txt

    .. note::

        The ``<path_to_virtual_environment_directory>`` could be inside the workspace directory if project is built using CMake.
        As long as colcon performs a recursive search to build packages inside the workspace directory, it is recommended to deploy the virtual environment outside of the workspace directory in order to avoid conflicts.

            .. tabs::

                .. tab:: Building with colcon

                        .. code-block:: bash

                            # Virtual environment deployment
                            cd ~

                .. tab:: Building with CMake

                        .. code-block:: bash

                            # Virtual environment deployment
                            cd ~/fastdds_qosprofman_ws

.. _installation_download_project_source_linux:

Tool suite build process
------------------------

Create a workspace directory and download the project:

.. code-block:: bash

    mkdir -p ~/fastdds_qosprofman_ws/src
    cd ~/fastdds_qosprofman_ws/src
    git clone https://github.com/eProsima/Fast-DDS-QoS-Profiles-Manager.git

.. _installation_build_source_linux:

.. tabs::

    .. tab:: Building with colcon

        *eProsima Fast DDS QoS Profiles Manager* complete tool suite is build using `colcon <https://colcon.readthedocs.io/en/released/>`_  by running:

        .. code-block:: bash

            cd ~/fastdds_qosprofman_ws
            colcon build

        .. note::

            Being based on `CMake <https://cmake.org/>`_ it is possible to pass `CMake configuration options <https://colcon.readthedocs.io/en/released/reference/verb/build.html#cmake-specific-arguments>`_ to the :code:`colcon build` command.
            These options can be also passed through a `colcon.meta <https://colcon.readthedocs.io/en/released/user/configuration.html?highlight=colcon.meta#using-meta-files>`_ file.

            For instance, the *Library* and *Documentation* test suites building is enabled by building with the CMake option `EPROSIMA_BUILD_TESTS`.
            If GTest repository has been included in the workspace directory, add the GTest dependency (``"googletest-distribution"``) in both *Library* and *Documentation* `colcon.pkg <https://colcon.readthedocs.io/en/released/user/configuration.html?highlight=colcon.meta#colcon-pkg-files>`_ files.
            Also, colcon provides `certain arguments <https://colcon.readthedocs.io/en/released/reference/package-selection-arguments.html>`_ to perform package selection, excluding undesired packages or including specific packages in the build process.

            Thus, the following command would build the *Library* and *Documentation* tools with its test suite.

            .. code-block:: bash

                colcon build --packages-up-to fastdds_qos_profiles_manager_docs --cmake-args -DEPROSIMA_BUILD_TESTS=ON

    .. tab:: Building with CMake

        *eProsima Fast DDS QoS Profiles Manager* tool suite is build using `CMake <https://cmake.org/>`_ following these steps:

        **Library**

        .. code-block:: bash

            mkdir -p ~/fastdds_qosprofman_ws/build/lib
            cd ~/fastdds_qosprofman_ws/build/lib
            cmake ../../src/Fast-DDS-QoS-Profiles-Manager/lib -DCMAKE_INSTALL_PREFIX=../../install/lib
            cmake --build . --target install

        .. note::

            If the *Library* test suite compilation is needed, the enable test build flag `EPROSIMA_BUILD_TESTS` should be included while configuring the building of the *Library* package:

            .. code-block:: bash

                cmake ../../src/Fast-DDS-QoS-Profiles-Manager/lib -DCMAKE_INSTALL_PREFIX=../../install/lib -DEPROSIMA_BUILD_TESTS=ON

        **CLI**

        .. code-block:: bash

            mkdir -p ~/fastdds_qosprofman_ws/build/cli
            cd ~/fastdds_qosprofman_ws/build/cli
            export CMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}:~/fastdds_qosprofman_ws/install/lib
            cmake ../../src/Fast-DDS-QoS-Profiles-Manager/cli -DCMAKE_INSTALL_PREFIX=../../install/cli
            cmake --build . --target install

        .. note::

            Note that the already installed *Library* path has been sourced in the *CLI* build process with the command:

            .. code-block:: bash

                export CMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}:~/fastdds_qosprofman_ws/install/lib

        **Documentation**

        .. important::

            If the *Library* path has been sourced in the previous step, there is no need to include it again in the environment variable ``CMAKE_PREFIX_PATH``.
            If, on the other hand, it has not been sourced previously, as long as it is required also to build the *Documentation* package, it needs to be sourced.

        .. code-block:: bash

            mkdir -p ~/fastdds_qosprofman_ws/build/docs
            cd ~/fastdds_qosprofman_ws/build/docs
            cmake ../../src/Fast-DDS-QoS-Profiles-Manager/docs -DCMAKE_INSTALL_PREFIX=../../install/docs
            cmake --build . --target install

Run CLI example
---------------

The ``fastddsqosprof`` executable file is generated in the installation path.
In order to run the CLI, please, ensure to source the environment:

.. tabs::

    .. tab:: Built with colcon

        .. code-block:: bash

            source ~/fastdds_qosprofman_ws/install/setup.bash

    .. tab:: Built with CMake

        .. code-block:: bash

            export LD_LIBRARY_PATH=~/fastdds_qosprofman_ws/install/lib/lib
            export PATH=$PATH:~/fastdds_qosprofman_ws/install/cli/bin

*CLI* should display its software version by running:

.. code-block:: bash

    fastddsqosprof -v

.. note::

    A complete example of the *CLI* is included in the *eProsima Fast DDS QoS Profiles Manager* repository.
    It depends on `jq <https://stedolan.github.io/jq/>`_ in order to parse the deployment information contained in a JSON file.
    The instructions below would run the example and generate several XML configuration files.

    .. code-block:: bash

        sudo apt install jq
        cd ~/fastdds_qosprofman_ws/src/Fast-DDS-QoS-Profiles-Manager/cli/examples/ExternalLocatorFeatureConfigurationExample
        bash cli_example_script.sh



Local documentation
-------------------

The *Documentation* generated can be opened in a web browser locally by running:

.. tabs::

    .. tab:: Built with colcon

        .. code-block:: bash

            xdg-open ~/fastdds_qosprofman_ws/install/fastdds_qos_profiles_manager_docs/docs/fastdds_qos_profiles_manager_docs/sphinx/html/index.html

    .. tab:: Built with CMake

        .. code-block:: bash

            xdg-open ~/fastdds_qosprofman_ws/install/docs/docs/fastdds_qos_profiles_manager_docs/sphinx/html/index.html
