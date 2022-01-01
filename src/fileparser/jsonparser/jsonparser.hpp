#pragma once
#include <string>
#include <json/json.h>
#include "../baseparser/baseparser.hpp"

class jsonParser : public baseParser
{
public:
    jsonParser(const std::string &filePath) : baseParser(filePath){};

    void read() override;

    void dump() override;

    // Getter functions
    Json::Value getRoot();

private:
    Json::Value m_root{0};
};