cmake_minimum_required(VERSION 3.6)
project(hci)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(JSON_INCLUDE ${CMAKE_SOURCE_DIR}/jsoncpp/include/)
set(JSON_LIB_PATH ${CMAKE_SOURCE_DIR}/jsoncpp/lib/libjsoncpp.a)
include_directories(${JSON_INCLUDE})

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
    "src/fileparser/baseparser/baseparser.cpp"
    "src/fileparser/baseparser/baseparser.hpp"
    "src/fileparser/jsonparser/jsonparser.hpp"
    "src/fileparser/jsonparser/jsonparser.cpp"
    "src/datahandlers/basehandler/basehandler.cpp"
    "src/datahandlers/basehandler/basehandler.hpp"
    "src/datahandlers/positionhandler/positionhandler.cpp"
    "src/datahandlers/positionhandler/positionhandler.hpp"
    "src/datahandlers/attentiononhandler/attentiononhandler.hpp"
    "src/datahandlers/attentiononhandler/attentiononhandler.cpp")

target_link_libraries(${PROJECT_NAME} ${JSON_LIB_PATH})
