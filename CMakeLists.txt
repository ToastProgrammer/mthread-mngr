cmake_minimum_required(VERSION 3.5.0)
project(pdevice-mngr VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

message("Source ${CMAKE_SOURCE_DIR}")
message("Output to ${EXECUTABLE_OUTPUT_PATH}")

## boilerplate for possibly adding boost later
# find_package(Boost REQUIRED COMPONENTS system filesystem)
# include_directories(${Boost_INCLUDE_DIRS})
# add_executable(my_program my_program.cpp)
# target_link_libraries(my_program ${Boost_LIBRARIES})

add_subdirectory(src)
add_subdirectory(include)


include(CTest)
enable_testing()

target_include_directories(pdevice-mngr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(pdevice-mngr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)