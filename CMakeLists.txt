cmake_minimum_required(VERSION 3.20)

project(programSDL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the output directory to the build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

# Include the pkg-config module to find the dependencies
include(FindPkgConfig)

# Find all the dependencies
find_package(SDL2 REQUIRED)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

# Include Directories for SDL2 Libraries
include_directories(
    ${SDL2_INCLUDE_DIRS} 
    ${SDL2_MIXER_INCLUDE_DIRS} 
    ${SDL2_IMAGE_INCLUDE_DIRS} 
    ${SDL2_TTF_INCLUDE_DIRS}
)

# Include Directories for Source Code
include_directories(${CMAKE_SOURCE_DIR}/src)

# Specify additional directories where the linker should look for libraries.
link_directories(${SDL2_LIBRARY_DIRS})

#Search all .cpp file in the src directory tree
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Add the executable
add_executable(programSDL ${SRC_FILES})

# Link Libraries for SDL2 Libraries
target_link_libraries(
    programSDL
    ${SDL2_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
)


# Print some debug information
message(STATUS "SDL2_LIBRARIES: ${SDL2_LIBRARIES}")
message(STATUS "SDL2_MIXER_LIBRARIES: ${SDL2_MIXER_LIBRARIES}")
message(STATUS "SDL2_TTF_LIBRARIES: ${SDL2_TTF_LIBRARIES}")
message(STATUS "SDL2_IMAGE_LIBRARIES: ${SDL2_IMAGE_LIBRARIES}")


