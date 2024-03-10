# Overview

## Project

This is a simple C++ project that includes the function for our colleagues to
test. The function (i.e., the main function and the subfunctions used in it) is
located in `lib.cpp`.

## Additional libraries and executable

Our library `prep` is concerned with preparation of data prior to the function
call. `test.cpp` is a single test file that will contain the tests of our colleagues
and our own development tests. GTest is used for tests.

## Usage

## Compilation

Compilation on Linux requires cmake and CXX compiler (e.g., g++).

### ninja

```bash
cmake -Gninja -Bbuild
cd build
ninja
./main
```

### Make

```bash
cmake -Bbuild
cd build
make
./main
```

Resulting binaries are `build/main` - the program and `build/runtests` to
run tests specified in `test.cpp`.

## TODOS

- [ ] Translate README in Latvian
- [ ] Check the compilation process on Windows and add description in README
