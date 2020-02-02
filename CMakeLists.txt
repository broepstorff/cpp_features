cmake_minimum_required(VERSION 3.16.2)

#usage: print_list_prefix("..." "${MYLIST}")
function(print_list_prefix prefix list)
    foreach(msg ${list})
        message("${prefix}${msg}")
    endforeach()
endfunction()

project(cpp_features VERSION 0.1)

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