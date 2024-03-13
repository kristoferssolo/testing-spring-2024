cmake_minimum_required(VERSION 3.1...3.28)

project(
  Template
  VERSION 0.1.0
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src/modules)

add_executable(main src/main.cc)
add_library(validation src/validation.cc src/validation.hh)
target_link_libraries(main PUBLIC validation)
target_link_libraries(validation PUBLIC modules)
target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}"
                                       "${PROJECT_SOURCE_DIR}/modules")
