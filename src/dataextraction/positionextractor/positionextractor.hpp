#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../baseextractor/baseextractor.hpp"

struct positionData
{
    int start;
    int end;
    Json::String holds;
    Json::String argument;
};

class positionExtractor : public baseExtractor
{
public:
    positionExtractor(const std::string &filePath) : baseExtractor(filePath)
    {
        this->findJsonClass("Position_on");
    };

    void getData();

    std::vector<positionData> m_positionData;
};

std::ostream &operator<<(std::ostream &os, const positionData &posData);