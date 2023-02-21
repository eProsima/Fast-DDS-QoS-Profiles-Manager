# Fast DDS XML generator library

This library exposes APIs to configure Fast DDS profiles and to save them in XML files.

## Build

To build the library, in a terminal with current directory in the library root directory, run the following commands:

```bash
    mkdir build && cd build
    cmake ..
    make
    cmake --install . --prefix "../install"
```

The library will be compiled. Library will be installed in a new `install/lib/` folder, and public headers will be installed in a new `install/include` folder.

## Generate API Reference

After building the library a `Doxyfile` has been generated in the binaries folder inside `doc` folder.
Running the following command will generate the API reference:

```bash
    doxygen <path>/doxyfile
```
