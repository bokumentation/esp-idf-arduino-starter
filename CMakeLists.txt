#
# This is boilerplate and uses custom python script if it's detected.
# In modern Linux distributions, users predominantly use python3 instead of the generic python command.
# Documentation: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/build-system.html
#
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(.)

# Set Minimal Build
idf_build_set_property(MINIMAL_BUILD ON)

# Fix compile commands for clangd. remove all '-m*' and '-f*' flags from the compile_commands.json.
if(EXISTS "${CMAKE_SOURCE_DIR}/fix_compile_commands.py")
    add_custom_target(
      fix_clangd ALL
      COMMAND ${CMAKE_COMMAND} -E echo "Running fix_compile_commands.py..."
      COMMAND ${CMAKE_COMMAND} -E env python ${CMAKE_SOURCE_DIR}/fix_compile_commands.py
      COMMENT "Cleaning compile_commands.json for clangd"
      VERBATIM
  )
endif()
