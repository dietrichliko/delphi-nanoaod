# DELPHI Nano-AOD
#
# CMakeLists.txt
#
# Create DELPHI NanoAOD
#
# Dietrich Liko <Dietrich.Liko@oeaw.ac.at>

cmake_minimum_required(VERSION 3.26)

project(DELPHI-NanoAOD VERSION 0.1 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftemplate-depth=50")

# PHDST and SKELANA Wrappers
# add_subdirectory(Wrapper)

# fetch argparse
include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
)
FetchContent_MakeAvailable(yaml-cpp)

add_executable(delphi-nanoaod src/delphi-nanoaod.cpp)
target_link_libraries(delphi-nanoaod argparse yaml-cpp)