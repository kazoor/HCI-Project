#include <iostream>
#include <fstream>
#include <json/json.h>
#include "fileparser/jsonparser/jsonparser.hpp"
// #include "fileparser/baseparser/baseparser.hpp"

int main()
{
    jsonParser parser("Annotation_P4a_merged.json");

    parser.read();

    Json::Value root = parser.getRoot();

    std::cout << root["annotations"][5] << std::endl;

    return 0;
}