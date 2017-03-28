cmake_minimum_required(VERSION 3.6)
project(Demo)

set(CMAKE_CXX_STANDARD 11)
find_package(Boost 1.63.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})


set(SOURCE_FILES main.cpp linear_reg.h vectorOp.h linear_reg.cpp vectorOp.cpp)
add_executable(Demo ${SOURCE_FILES})
target_link_libraries(Demo ${Boost_LIBRARIES})