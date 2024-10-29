cmake_minimum_required(VERSION 3.16.0)

project(Loader)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Windows-specific configurations
if(WIN32)
    # Set WIN32 executable type (Windows GUI application)
    set(CMAKE_WIN32_EXECUTABLE ON)
    
    # Add Windows-specific compile definitions
    add_definitions(-DUNICODE -D_UNICODE)
    
    # Specify Windows subsystem
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
endif()

# Collect source files
file(GLOB_RECURSE SOURCE_FILES 
    "src/*.cpp"
    "src/*.hpp"
    "src/*.h"
)

# Add resource files
set(RESOURCE_FILES
    "resource.h"
    "loader.rc"
)

# Create executable
add_executable(${PROJECT_NAME} 
    ${SOURCE_FILES}
    ${RESOURCE_FILES}
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/lib
)

# Link Windows libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    kernel32
    user32
)

# Set output directories
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# Debug configurations
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE NEPS_DEBUG)
endif()