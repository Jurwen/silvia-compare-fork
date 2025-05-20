cmake_minimum_required(VERSION 3.1)
project(example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(CPM)
include(libigl)
include(mtet)

# libigl
option(LIBIGL_WITH_CGAL "Use CGAL"          ON)
find_package(LIBIGL REQUIRED QUIET)

# Add the files containing your project's core functionality (but not exectuable
# main() functions)
file(GLOB SRCFILES include/*.cpp include/*.h)
add_library(core ${SRCFILES})
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
# these files may depend on libigl
target_link_libraries(core igl::core igl_copyleft::cgal mtet::mtet)

# 
add_executable(swept-volumes-modified sv-modified.cpp)
set_target_properties (swept-volumes-modified PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/)
target_include_directories(swept-volumes-modified PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(swept-volumes-modified core igl::core)


