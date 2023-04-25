.. _linux_installation:

Linux installation from sources
===============================

The *eProsima Fast DDS QoS Profiles Manager* tool suite is composed by many packages as described in the :ref:`home <qos_prof_description_>` section.
It is organized as follows:

.. contents::
    :local:
    :backlinks: none
    :depth: 2

The tool suite can either be built using `colcon <https://colcon.readthedocs.io/en/released/>`_ or `CMake <https://cmake.org/>`_.
With CMake, the tool suite build and the environment source process must be done manually and following the tool package dependencies, whereas colcon automatizes this process with a single command.
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

Despite that the *eProsima Fast DDS QoS Profiles Manager* tool suite packages can be build using CMake, colcon simplifies the task substantially.
colcon is a command line tool based on CMake aimed at building sets of software packages.
Install colcon by executing the following command:

   .. code-block:: bash

       pip3 install -U colcon-common-extensions

.. note::

    Mind that under non-root users, :code:`pip3` may install python :code:`colcon` executable in :code:`$HOME/.local/bin`, for instance when running with :code:`--user`.
    To be able to run this application, make sure that :code:`pip3` binary installation directory is in your :code:`$PATH` (:code:`$HOME/.local/bin` is normally introduced while login on an interactive non-root shell).

Dependencies
------------

Library tool
^^^^^^^^^^^^

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
It is possible to activate them with the opportune `CMake configuration options <https://cmake.org/cmake/help/v3.6/manual/cmake.1.html#options>`_ when calling colcon or CMake.
If following the colcon deployment, the GTest dependency needs to be included in the *Library* ``colcon.pkg`` file.
Please check the :ref:`colcon build procedure <installation_build_source_linux>` for further information.

GTest installation can be performed either following the `GTest installation instructions <https://google.github.io/googletest/>`_, or including the `Gtest repository <https://github.com/google/googletest>`_ in the workspace directory, running:

.. code-block:: bash

    git clone https://github.com/google/googletest ~/fastdds_qosprofman_ws/src/googletest-distribution

CLI tool
^^^^^^^^

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

Doxygen
"""""""

`Doxygen <https://www.doxygen.nl/>`_ is a C++ documentation generator.
It is required to build the :ref:`fastdds_qos_profiles_manager_lib_api_reference` from the header files.
In Ubuntu, the dependency can be installed running:

.. code-block:: bash

    sudo apt install doxygen

Python3 virtual environment (recomended)
""""""""""""""""""""""""""""""""""""""""

It is recommended to install the *Documentation* tool dependencies in a `python3 <https://www.python.org/downloads/>`_ virtual environment.
That would avoid polluting the user's installation setup.
In Ubuntu, python3 can be installed running:

.. code-block:: bash

    sudo apt install python3

Tool suite build process
------------------------

Create a workspace directory and download the project:

.. code-block:: bash

    mkdir -p ~/fastdds_qosprofman_ws/src
    cd ~/fastdds_qosprofman_ws/src
    git clone https://github.com/eProsima/Fast-DDS-QoS-Profiles-Manager.git

.. note::

    It is recommended to deploy the project in a python3 virtual environment, by running the following commands:

    .. code-block:: bash

        cd ~/fastdds_qosprofman_ws
        python3 -m venv fastdds_qosprofman_venv
        source fastdds_qosprofman_venv/bin/activate

The *Documentation* tool has several dependencies described in the ``requirements.txt`` project file.

.. literalinclude:: /requirements.txt
    :language: text

Install them using `pip3 <https://docs.python.org/3/installing/index.html>`_:

.. code-block:: bash

    pip3 install -r ~/fastdds_qosprofman_ws/src/Fast-DDS-QoS-Profiles-Manager/docs/requirements.txt

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

            For instance, the *Library* test suite building is enabled by building with the CMake option `EPROSIMA_BUILD_TESTS`, among adding the GTest dependency (``"googletest-distribution"``) in the *Library* `colcon.pkg <https://colcon.readthedocs.io/en/released/user/configuration.html?highlight=colcon.meta#colcon-pkg-files>`_ file. Also, colcon provides `certain arguments <https://colcon.readthedocs.io/en/released/reference/package-selection-arguments.html>`_ to perform package selection, excluding undesired packages or including specific packages in the build process.

            The following command would build the *Library* tool with its test suite.

            .. code-block:: bash

                colcon build --packages-select fastdds_qos_profiles_manager_lib --cmake-args -DEPROSIMA_BUILD_TESTS=ON

        .. important::

            The *Library* package is required for building the remain tool packages.

    .. tab:: Building with CMake

        *eProsima Fast DDS QoS Profiles Manager* tool suite is build using `CMake <https://cmake.org/>`_ following these steps:

        **Library**

        .. code-block:: bash

            mkdir -p ~/fastdds_qosprofman_ws/build/lib
            cd ~/fastdds_qosprofman_ws/build/lib
            cmake ../../src/Fast-DDS-QoS-Profiles-Manager/lib -DCMAKE_INSTALL_PREFIX=../../install/lib
            cmake --build . --target install

        .. note::

            If *Library* test suite compilation is needed, the enable test build flag `EPROSIMA_BUILD_TESTS` should be included while building the *Library* package:

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

Local documentation
-------------------

The *Documentation* generated can be opened in a web browser locally by running:

.. tabs::

    .. tab:: Built with colcon

        .. code-block:: bash

            xdg-open ~/fastdds_qosprofman_ws/build/fastdds_qos_profiles_manager_docs/docs/html/index.html

    .. tab:: Built with CMake

        .. code-block:: bash

            xdg-open ~/fastdds_qosprofman_ws/build/docs/docs/html/index.html
