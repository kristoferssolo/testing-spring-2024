# Overview

[![Tests](https://github.com/jorenchik/testing-spring-2024/actions/workflows/test.yml/badge.svg)](https://github.com/jorenchik/testing-spring-2024/actions/workflows/test.yml)

[Latvian Description](./README-lv.md)

## Project

This is a simple C++ project that includes the function for our colleagues to
test. The function (i.e., the main function and the subfunctions used in it) is
located in `lib.cpp`.

## Additional libraries and executable

Our library `prep` is concerned with preparation of data prior to the function
call. `test.cpp` is a single test file that will contain the tests of our colleagues
and our own development tests. GTest is used for tests.

## Usage

## Compilation on Linux and MacOS

Compilation on Linux and MacOS requires cmake and CXX compiler (e.g., g++).

### MacOS

MacOS require a separate installation of `gcc13`.

```bash
brew install cmake gcc@13
brew install ninja # optional
```

### Linux

You know what to do.

### ninja

```bash
cmake -G Ninja -B
# or
# cmake -G Ninja -B build -D CMAKE_CXX_COMPILER=g++-13 # MacOS
cd build
ninja
./main
```

### Make

```bash
cmake -B build
# or
# cmake -B build -D CMAKE_CXX_COMPILER=g++-13 # for MacOS
cd build
make
./main
```

### Windows and/or VSCode

Install [CMake](https://cmake.org/download/) and VSCode [CMake Tools extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools).

- Open project as root in VSCode.
- Open **View->Command palette...** or `Ctrl+Shift+P` and run `CMake: Build`.

Resulting binaries are `build/main` -- the program and `build/runtests` to
run tests specified in `test.cpp`.
