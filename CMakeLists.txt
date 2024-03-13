cmake_minimum_required(VERSION 3.1...3.28)

enable_testing()

project(
  Template
  VERSION 0.1.0
  LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src/cppunit)
add_subdirectory(src/modules)

add_executable(main src/main.cc)
add_library(lib src/lib.cc src/lib.hh src/validation.cc src/validation.hh)
target_link_libraries(main PUBLIC lib)
target_link_libraries(lib PUBLIC modules)
target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}"
                                       "${PROJECT_SOURCE_DIR}/prep")
target_include_directories(lib PUBLIC "${PROJECT_BINARY_DIR}"
                                      "${PROJECT_SOURCE_DIR}/prep")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(runtests src/test.cc)
target_link_libraries(runtests PUBLIC lib gtest gtest_main)
target_include_directories(runtests PUBLIC "${PROJECT_BINARY_DIR}")

include(GoogleTest)
gtest_discover_tests(runtests)
