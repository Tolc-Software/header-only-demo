# Header only demo with `tolc` #

## Usage ##

### Prerequisites ###

You need the following installed locally:

* `CMake` - Tested with `>3.15`.
* `python` - The language to translate to.

### Building and importing ###

Clone this repository

Go to the root of the project and generate the build files:

```shell
$ cmake -S. -Bbuild
```

This will automatically download `tolc`, and anything needed to build the library for use in `python` (in this case, [the `pybind11` project](https://github.com/pybind/pybind11)).

Build the library:

```shell
$ cmake --build build
```

You should now be able to start using the `C++` library `Greeter` from `python`:

```shell
$ cd python
$ python3 sayHello.py
Hello from C++!
Hello to Python!
```

Now whenever you change the any of the headers in the include directory and rebuild, the new functions and classes will be available from `python`.
