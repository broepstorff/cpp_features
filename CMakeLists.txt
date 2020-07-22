cmake_minimum_required(VERSION 3.16.2)

#usage: print_list_prefix("..." "${MYLIST}")
function(print_list_prefix prefix list)
    foreach(msg ${list})
        message("${prefix}${msg}")
    endforeach()
endfunction()

project(cpp_features VERSION 0.1)

message("")
message("")
message("CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
message("CMAKE_CONFIGURATION_TYPES: ${CMAKE_CONFIGURATION_TYPES}")
message("CMAKE_GENERATOR: ${CMAKE_GENERATOR}")
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message("CMAKE_CFG_INTDIR: ${CMAKE_CFG_INTDIR}")
message("CMAKE_MAKE_PROGRAM: ${CMAKE_MAKE_PROGRAM}")
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("CMAKE_STANDARD_LIBRARIES: ${CMAKE_STANDARD_LIBRARIES}")
message("CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
message("CMAKE_XCODE_PLATFORM_TOOLSET: ${CMAKE_XCODE_PLATFORM_TOOLSET}")
message("APPLE: " ${APPLE})
message("UNIX: " ${UNIX})
message("WIN32: " ${WIN32})
message("CMAKE_SYSTEM: " ${CMAKE_SYSTEM})
message("ENV: " ${ENV})
message("MSVC: " ${MSVC})
message("MSVC_VERSION: " ${MSVC_VERSION})
message("XCODE_VERSION: " ${XCODE_VERSION})

 
file(GLOB_RECURSE Sources "src/*.cpp")
file(GLOB_RECURSE Headers "src/*.h")

message("==== Sources: ====")
print_list_prefix("   " "${Sources}")

message("==== Headers: ====")
print_list_prefix("   " "${Headers}")

if("${CMAKE_GENERATOR}" MATCHES "Xcode")
    set(AllSources ${Sources} ${Headers})
else()
    set(AllSources ${Sources})
endif()

add_executable(cpp_features)

target_include_directories(cpp_features PUBLIC "src")
target_sources(cpp_features PRIVATE "${AllSources}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" PREFIX "Source" FILES ${AllSources})

#older way to require standards
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_EXTENSIONS OFF)

#newer way to require standards (works better with nested projects I think):
target_compile_features(cpp_features PUBLIC cxx_std_17)
set_target_properties(cpp_features PROPERTIES CXX_STANDARD_REQUIRED OFF)
set_target_properties(cpp_features PROPERTIES CXX_EXTENSIONS OFF)
