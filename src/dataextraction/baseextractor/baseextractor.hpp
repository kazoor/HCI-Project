#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <json/json.h>

class baseExtractor
{
public:
    baseExtractor(const std::string &filePath);

    void findJsonClass(const std::string &className);

    Json::Value getClassObj();

private:
    std::string m_filepath{""};

    Json::Value m_root;

    Json::Value m_classObj;
};