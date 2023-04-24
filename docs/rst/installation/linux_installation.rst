.. _linux_installation:

Linux installation from sources
===============================

The *eProsima Fast DDS QoS Profiles Manager* is composed by many packages as described in the
:ref:`home <qos_prof_description_>` section.

The instructions for installing each of them: the :ref:`library_api_installation_sl`, the
:ref:`Fast DDS QoS Profiles Manager Command Line Interface <cli_installation_sl>`, the
:ref:`Fast DDS QoS Profiles Manager Graphical User Interface <gui_installation_sl>` and the :ref:`doc_installation_sl`
from sources are provided in this page.
It is organized as follows:

.. contents::
    :local:
    :backlinks: none
    :depth: 2

.. _prerequisites_sl:

Prerequisites
-------------

The installation a Linux environment from sources requires :ref:`cmake_gcc_pip3_git_sl` tools to be installed in the system.

.. _cmake_gcc_pip3_git_sl:

CMake, g++, pip3 and git
^^^^^^^^^^^^^^^^^^^^^^^^

These packages provide the tools required to install the *eProsima Fast DDS QoS Profiles Manager* packages and their
dependencies from command line.
Install `CMake <https://cmake.org/>`_, `g++ <https://gcc.gnu.org/>`_,
`pip3 <https://docs.python.org/3/installing/index.html>`_ and `git <https://git-scm.com/>`_ using the package manager
of the appropriate Linux distribution.
For example, on Ubuntu use the command:

.. code-block:: bash

    sudo apt install cmake g++ python3-pip git

.. _download_sources_sl:

Download Fast DDS QoS Profiles Manager from sources
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The *eProsima Fast DDS QoS Profiles Manager* is uploaded in a cloud repository.
Its packages can be build using `CMake <https://cmake.org/>`_, but the use of :ref:`colcon <colcon_installation_sl>`
is highly recommended.

.. _colcon_installation_sl:

Colcon installation
"""""""""""""""""""

`colcon <https://colcon.readthedocs.io/en/released/>`_ is a command line tool based on `CMake <https://cmake.org/>`_
aimed at building sets of software packages.
This section explains how to use it to compile *eProsima Fast DDS QoS Profiles Manager* packages and their dependencies.

#. Install `colcon <https://colcon.readthedocs.io/en/released/>`_ by executing the following command:

   .. code-block:: bash

       pip3 install -U colcon-common-extensions

   .. note::

       Mind that under non-root users, :code:`pip3` may install python :code:`colcon` executable in
       :code:`$HOME/.local/bin`, for instance when running with :code:`--user`.
       To be able to run this application, make sure that :code:`pip3` binary installation directory is in your
       :code:`$PATH` (:code:`$HOME/.local/bin` is normally introduced while login on an interactive non-root shell).


Installation
^^^^^^^^^^^^

Create a :code:`Fast-DDS-QoS-Profiles-Manager` directory and download the project:

.. code-block:: bash

    mkdir -p ~/Fast-DDS-QoS-Profiles-Manager/src
    cd ~/Fast-DDS-QoS-Profiles-Manager/src
    git clone https://github.com/eProsima/Fast-DDS-QoS-Profiles-Manager.git

.. _library_api_installation_sl:

Fast DDS QoS Profiles Manager library
-------------------------------------

This section describes the instructions for installing *eProsima Fast DDS QoS Profiles Manager library* in a Linux
environment from sources.

.. _lib_dependencies_sl:

Dependencies
^^^^^^^^^^^^

*eProsima Fast DDS QoS Profiles Manager library* depends on `Xerces-C++ XML Parser <https://xerces.apache.org/xerces-c/>`_.
In Ubuntu, the dependency can be installed running:

.. code-block:: bash

    sudo apt install libxerces-c-dev

Optionally, `GTest <https://github.com/google/googletest>`_ dependency could be installed to run the test suite.

.. _lib_building_sl:

Build
^^^^^

.. tabs::

    .. tab:: Building with colcon

        *eProsima Fast DDS QoS Profiles Manager library* is build using `colcon <https://colcon.readthedocs.io/en/released/>`_
        by running:

        .. code-block:: bash

            cd ~/Fast-DDS-QoS-Profiles-Manager
            colcon build --packages-select fastdds_qos_profiles_manager_lib

        .. note::

            Being based on `CMake <https://cmake.org/>`_ it is possible to pass CMake configuration options to the
            :code:`colcon build` command.
            That is the case if test compilation is needed.
            To do so, the previous command would be updated to include the enable test build flag `EPROSIMA_BUILD_TESTS`:

            .. code-block:: bash

                colcon build --packages-select fastdds_qos_profiles_manager_lib --cmake-args -DEPROSIMA_BUILD_TESTS=ON

    .. tab:: Building with CMake

        *eProsima Fast DDS QoS Profiles Manager library* is build using `CMake <https://cmake.org/>`_ by running:

        .. code-block:: bash

            mkdir -p ~/Fast-DDS-QoS-Profiles-Manager/build/lib
            cd ~/Fast-DDS-QoS-Profiles-Manager/build/lib
            cmake ../../src/Fast-DDS-QoS-Profiles-Manager/lib -DCMAKE_INSTALL_PREFIX=../../install/lib
            cmake --build . --target install

        .. note::

            If test compilation is needed, the enable test build flag `EPROSIMA_BUILD_TESTS` should be included:

            .. code-block:: bash

                cmake ../../src/Fast-DDS-QoS-Profiles-Manager/lib -DCMAKE_INSTALL_PREFIX=../../install/lib -DEPROSIMA_BUILD_TESTS=ON

.. _cli_installation_sl:

Fast DDS QoS Profiles Manager CLI
---------------------------------

This section describes the instructions for installing *eProsima Fast DDS QoS Profiles Manager CLI* in a Linux
environment from sources.

The *eProsima Fast DDS QoS Profiles Manager library* is required to use the *CLI*, so make sure all steps described in
:ref:`its installation section <library_api_installation_sl>` were reproduced.
Despite that, :ref:`cli_dependencies_sl` detailed below need to be met.

.. _cli_dependencies_sl:

Dependencies
^^^^^^^^^^^^

*eProsima Fast DDS QoS Profiles Manager CLI* depends on `docopt CLI description language <http://docopt.org/>`_.
In Ubuntu, the dependency can be installed running:

.. code-block:: bash

    sudo apt install libdocopt-dev

Optionally, `GTest <https://github.com/google/googletest>`_ dependency could be installed to run the test suite.

.. _cli_building_sl:

Build
^^^^^

.. tabs::

    .. tab:: Building with colcon

        *eProsima Fast DDS QoS Profiles Manager CLI* is build using `colcon <https://colcon.readthedocs.io/en/released/>`_
        by running:

        .. code-block:: bash

            cd ~/Fast-DDS-QoS-Profiles-Manager
            colcon build --packages-select fastdds_qos_profiles_manager_lib fastdds_qos_profiles_manager_cli

        .. note::

            As happened in the *library* build process, if test compilation is needed, the enable test build flag
            `EPROSIMA_BUILD_TESTS` should be included too:

            .. code-block:: bash

                colcon build --packages-select fastdds_qos_profiles_manager_lib fastdds_qos_profiles_manager_cli --cmake-args -DEPROSIMA_BUILD_TESTS=ON

        The ``fastddsqosprof`` executable file is generated in the installation path.
        The following setup call must be run in order to set the *CLI* command:

        .. code-block:: bash

            source ~/Fast-DDS-QoS-Profiles-Manager/install/setup.bash

    .. tab:: Building with CMake

        *eProsima Fast DDS QoS Profiles Manager CLI* is build using `CMake <https://cmake.org/>`_ by running:

        .. code-block:: bash

            mkdir -p ~/Fast-DDS-QoS-Profiles-Manager/build/cli
            cd ~/Fast-DDS-QoS-Profiles-Manager/build/cli
            CMAKE_PREFIX_PATH+=~/Fast-DDS-QoS-Profiles-Manager/install/lib
            cmake ../../src/Fast-DDS-QoS-Profiles-Manager/cli -DCMAKE_INSTALL_PREFIX=../../install/cli
            cmake --build . --target install

        .. note::

            As happened in the *library* build process, if test compilation is needed, the enable test build flag
            `EPROSIMA_BUILD_TESTS` should be included too:

            .. code-block:: bash

                cmake ../../src/Fast-DDS-QoS-Profiles-Manager/cli -DCMAKE_INSTALL_PREFIX=../../install/cli -DEPROSIMA_BUILD_TESTS=ON

        The ``fastddsqosprof`` executable file is generated in the installation path.
        The following setup call must be run in order to set the *CLI* command:

        .. code-block:: bash

            export LD_LIBRARY_PATH=~/Fast-DDS-QoS-Profiles-Manager/install/lib/lib
            export PATH=$PATH:~/Fast-DDS-QoS-Profiles-Manager/install/cli/bin


.. _gui_installation_sl:

Fast DDS QoS Profiles Manager GUI
---------------------------------

.. warning::

    This section is still in development process.

.. _doc_installation_sl:

Fast DDS QoS Profiles Manager Documentation
-------------------------------------------

Finally, this section describes the instructions for installing *eProsima Fast DDS QoS Profiles Manager documentation*
in a Linux environment from sources.

The *eProsima Fast DDS QoS Profiles Manager library* is required to build the *documentation*, so make sure all steps
described in the :ref:`library installation section <library_api_installation_sl>` were reproduced.
Despite that, :ref:`doc_dependencies_sl` detailed below need to be met.

.. _doc_dependencies_sl:

Dependencies
^^^^^^^^^^^^

*eProsima Fast DDS QoS Profiles Manager documentation* depends on `Doxygen code documentation generator
<https://www.doxygen.nl/>`_ for the :ref:`fastdds_qos_profiles_manager_lib_api_reference`.
In Ubuntu, the dependency can be installed running:

.. code-block:: bash

    sudo apt install doxygen

.. note::

    If desired, the remain *documentation* dependencies can be installed in a python3 virtual environment.
    That would avoid polluting the user's installation.
    Create the virtual environment by running the following commands:

    .. code-block:: bash

        sudo apt install python3
        cd ~/Fast-DDS-QoS-Profiles-Manager
        python3 -m venv fastdds_qos_profiles_manager_venv
        source fastdds_qos_profiles_manager_venv/bin/activate

Install the dependencies using `pip3 <https://docs.python.org/3/installing/index.html>`_:

.. code-block:: bash

    cd ~/Fast-DDS-QoS-Profiles-Manager/src/Fast-DDS-QoS-Profiles-Manager/docs
    pip3 install -r requirements.txt


.. _doc_building_sl:

Build
^^^^^

.. tabs::

    .. tab:: Building with colcon

        *eProsima Fast DDS QoS Profiles Manager documentation* is build using
        `colcon <https://colcon.readthedocs.io/en/released/>`_ by running:

        .. code-block:: bash

            cd ~/Fast-DDS-QoS-Profiles-Manager
            colcon build --packages-select fastdds_qos_profiles_manager_lib fastdds_qos_profiles_manager_docs

    .. tab:: Building with CMake

        *eProsima Fast DDS QoS Profiles Manager documentation* is build using `CMake <https://cmake.org/>`_ by running:

        .. code-block:: bash

            mkdir -p ~/Fast-DDS-QoS-Profiles-Manager/build/docs
            cd ~/Fast-DDS-QoS-Profiles-Manager/build/docs
            CMAKE_PREFIX_PATH+=~/Fast-DDS-QoS-Profiles-Manager/install/lib
            cmake ../../src/Fast-DDS-QoS-Profiles-Manager/docs -DCMAKE_INSTALL_PREFIX=../../install/docs
            cmake --build . --target install
