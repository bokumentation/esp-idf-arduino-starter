#
# Main CMakeLists.txt. Define the component and its properties
# Documentation: https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/build-system.html
#

# Search all ".c" and ".cpp" file. Uncomment this if wanna use GLOB_RECURSE
# file(GLOB_RECURSE SOURCES "*.c" "*.cpp")

idf_component_register(
    # Add sources code. We just using the "arduino_style" for the main point.
    SRCS "arduino_style.cpp"

    # Uncomment this if wanna use GLOB_RECURSE
    # SRCS ${SOURCES}

    # Include all header ".h" file
    INCLUDE_DIRS "."

    # Adding my custom library or components
    PRIV_REQUIRES my_components_cxx my_components
)
