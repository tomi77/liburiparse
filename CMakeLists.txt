cmake_minimum_required (VERSION 3.1.3 FATAL_ERROR)
project(liburiparse)

# Initialize CXXFLAGS.
set(CMAKE_CXX_FLAGS                "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_SOURCE_DIR ./src)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./lib)

add_library(uriparse SHARED src/uri.cpp)
add_library(uriparse_static STATIC src/uri.cpp)

#install (TARGETS local_proxy pub sub DESTINATION bin)

set_target_properties(uriparse_static PROPERTIES OUTPUT_NAME uriparse)
set_target_properties(uriparse_static uriparse PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
