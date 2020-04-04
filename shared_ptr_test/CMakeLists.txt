cmake_minimum_required(VERSION 3.15)
project(shared_ptr_test)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD 14)

add_executable(shared_ptr_test
    meta_data.cpp
    big_data.cpp
    main.cpp)
#target_include_directories(shared_ptr_test)
#target_link_directories(shared_ptr_test)
#target_link_libraries(shared_ptr_test)