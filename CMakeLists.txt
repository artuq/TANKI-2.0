cmake_minimum_required(VERSION 3.10)
project(Tanks)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect sources
file(GLOB_RECURSE TANKS_SOURCES "src/*.cpp" "src/**/*.cpp")

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(Tanks ${TANKS_SOURCES})

# SDL2: try to find system SDL2, otherwise user can point SDL2_INCLUDE_DIR/SDL2_LIBRARY
find_package(SDL2 QUIET)
if (SDL2_FOUND)
    include_directories(${SDL2_INCLUDE_DIRS})
    target_link_libraries(Tanks ${SDL2_LIBRARIES})
else()
    message(WARNING "SDL2 not found by CMake. Please set SDL2_INCLUDE_DIR and SDL2_LIBRARY or install SDL2.")
    if (WIN32)
        # common fallback: use bundled SDL in resources/SDL (user must provide path to .lib/.dll)
        include_directories(${CMAKE_SOURCE_DIR}/resources/SDL/include)
    endif()
endif()

# Additional linker flags on Windows (if using MinGW/Visual Studio you may adjust)
if (WIN32)
    if (MINGW)
        target_link_libraries(Tanks winmm imm32)
    endif()
endif()
