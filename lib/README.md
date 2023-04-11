# Fast DDS QoS Profiles Manager library

This library exposes APIs to configure Fast DDS profiles and to save them in XML files.

## Dependencies

*eProsima Fast DDS QoS Profiles Manager Library* depends on [Xerces-C++ XML Parser](https://xerces.apache.org/xerces-c/).
In Ubuntu, the dependency can be installed running:

```bash
sudo apt install libxerces-c-dev
```

## Build

To build the library, in a terminal with current directory in the library root directory, run the following commands:

```bash
    mkdir build && cd build
    cmake .. -DCMAKE_INSTALL_PREFIX=../install
    cmake --build . --target install
```

The library will be compiled. Library will be installed in a new `install/lib/` folder, and public headers will be installed in a new `install/include` folder.

**Note**: The library can be built with colcon as well.

## Build tests

In order to build the tests, [GTest](https://github.com/google/googletest) dependency is required.
The test building is enabled with CMake option `EPROSIMA_BUILD_TESTS`.
Tests can be run either using colcon or directly CTest.

## Generate API Reference

After building the library a `Doxyfile` has been generated in the binaries folder inside `doc` folder.
Running the following command will generate the API reference:

```bash
    doxygen <path>/doxyfile
```

## Caveats

Currently, the library is only supported for POSIX system and has only been tested in Ubuntu 22.04.
