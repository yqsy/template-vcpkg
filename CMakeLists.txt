cmake_minimum_required(VERSION 3.25)
project(template-vcpkg)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
add_compile_options(/experimental:module)
add_compile_options("/Zc:threadSafeInit-")
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

file(GLOB_RECURSE sources "src/*.ixx")
foreach(source ${sources})
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/src" "" group_path "${source_path}")
    string(REPLACE "/" "\\" group_path "${group_path}")
    source_group("src${group_path}" FILES "${source}")
endforeach()

add_library(template-vcpkg STATIC ${sources})

set(CMAKE_CONFIGURATION_TYPES Release CACHE STRING "Only build Release configuration" FORCE)

install(TARGETS template-vcpkg
        EXPORT template-vcpkg-targets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/template-vcpkg.ixx"
#         DESTINATION include/template-vcpkg)

# install(EXPORT template-vcpkg-targets
#         FILE template-vcpkg-targets.cmake
#         NAMESPACE template-vcpkg::
#         DESTINATION lib/cmake/template-vcpkg)