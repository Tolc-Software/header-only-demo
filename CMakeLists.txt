cmake_minimum_required(VERSION 3.15)

project(tolc-demo LANGUAGES CXX)

add_library(Greeter INTERFACE)
target_include_directories(Greeter INTERFACE include)

set_target_properties(
  Greeter
  PROPERTIES INTERFACE_CXX_STANDARD 17
             INTERFACE_CXX_STANDARD_REQUIRED ON
             INTERFACE_CXX_EXTENSIONS OFF)

# Can be ["latest", "v1.2.0", ...]
set(tolc_version latest)
include(FetchContent)
FetchContent_Declare(
  tolc_entry
  URL https://github.com/Tolc-Software/tolc/releases/download/${tolc_version}/tolc-${CMAKE_HOST_SYSTEM_NAME}.tar.xz
)
FetchContent_Populate(tolc_entry)

find_package(tolc CONFIG PATHS ${tolc_entry_SOURCE_DIR} REQUIRED)

# Creates a CMake target Greeter_python that can be
# imported and used from python as 'import Greeter'
tolc_create_bindings(
  # Target to translate from
  # Uses PUBLIC include directories to find headers
  TARGET
  Greeter
  # Language to target
  LANGUAGE
  python
  # Where to put the bindings (here pybind11)
  OUTPUT
  ${CMAKE_CURRENT_BINARY_DIR}/python-bindings)

# Copy the built lib to the python directory
add_custom_command(
  TARGET Greeter_python
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Greeter_python>
          ${CMAKE_CURRENT_LIST_DIR}/python)
