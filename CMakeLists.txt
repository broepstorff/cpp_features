cmake_minimum_required(VERSION 3.16.2)

#usage: print_list_prefix("..." "${MYLIST}")
function(print_list_prefix prefix list)
    foreach(msg ${list})
        message("${prefix}${msg}")
    endforeach()
endfunction()

project(cpp_features VERSION 0.1)

message("CMAKE_CONFIGURATION_TYPES: ${CMAKE_CONFIGURATION_TYPES}")
message("CMAKE_GENERATOR: ${CMAKE_GENERATOR}")
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message("CMAKE_CFG_INTDIR: ${CMAKE_CFG_INTDIR}")
message("CMAKE_MAKE_PROGRAM: ${CMAKE_MAKE_PROGRAM}")
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("CMAKE_STANDARD_LIBRARIES: ${CMAKE_STANDARD_LIBRARIES}")
message("CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
message("CMAKE_XCODE_PLATFORM_TOOLSET: ${CMAKE_XCODE_PLATFORM_TOOLSET}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("src")
file(GLOB_RECURSE sources "src/*.cpp")
file(GLOB_RECURSE headers "src/*.h")
SET(all_sources ${sources} ${headers})

message("Headers:")
print_list_prefix("   " "${headers}")

add_executable(
    cpp_features 
    ${all_sources}
)