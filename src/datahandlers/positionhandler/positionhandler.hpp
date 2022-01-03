#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../basehandler/basehandler.hpp"

struct positionData
{
    int start;
    int end;
    Json::String holds;
    Json::String argument;
};

class positionHandler : public baseHandler
{
public:
    positionHandler(const std::string &filePath) : baseHandler(filePath)
    {
        this->findJsonClass("Position_on");
    };

    void getData();

    std::vector<positionData> m_positionData;
};

std::ostream &operator<<(std::ostream &os, const positionData &posData);