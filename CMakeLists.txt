cmake_minimum_required(VERSION 3.16.0)
project(Osiris)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(MSVC_COMMON_FLAGS 
        /nologo     # Don't show version info
        /W3         # Enable warning level 3
        /fp:fast    # Use fast floating point precision model
        /Zc:wchar_t # Parse wchar_t as internal type
        /GF         # Eliminate Duplicate Strings
        /Gy         # Enable function level linking
        /utf-8      # Set source and execution charset to utf-8
        /Wv:18      # Disable warnings until SDK depedencies switch to UTF-8/ASCII.
        /MP         # Build with multiple processes
        /bigobj     # Allow larger .obj files
        /GL         # Enable Whole Program Optimization
        /Ob2        # Enable inline optimization
        /Oi         # Enable Intrinsic Optimization
        /Ot         # Favor speed over size
        /wd4653     # Ignore PCH for any individual file that has different optimization settings
        /wd4275     # non dll-interface class '' used as base for dll-interface class ''
        /wd4961     # No profile data was merged into '', profile-guided optimizations disabled
        /wd4068     # 'Unknown pragma' - sometimes need these in code to prevent global suppression.
    )

    # Convert the list to a space-separated string
    string(REPLACE ";" " " MSVC_COMMON_FLAGS_STR "${MSVC_COMMON_FLAGS}")

    # Set the flags for different build types
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MSVC_COMMON_FLAGS_STR}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${MSVC_COMMON_FLAGS_STR}")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${MSVC_COMMON_FLAGS_STR}")

    # Additional MSVC-specific settings
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LTCG")
    set(CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} /LTCG")
endif()

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(Source)
add_subdirectory(Dependencies)

option(BUILD_TESTS "Build unit tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(Tests)
endif()