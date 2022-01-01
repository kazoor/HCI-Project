cmake_minimum_required(VERSION 3.6)
project(hci)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(JSON_INCLUDE ${CMAKE_SOURCE_DIR}/jsoncpp/include/)
set(JSON_LIB_PATH ${CMAKE_SOURCE_DIR}/jsoncpp/lib/libjsoncpp.a)
include_directories(${JSON_INCLUDE})

# file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
# file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR} "src/*.hpp")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
    "src/fileparser/baseparser/baseparser.cpp"
    "src/fileparser/baseparser/baseparser.hpp"
    "src/fileparser/jsonparser/jsonparser.hpp"
    "src/fileparser/jsonparser/jsonparser.cpp")

target_link_libraries(${PROJECT_NAME} ${JSON_LIB_PATH})
