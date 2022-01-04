#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../basehandler/basehandler.hpp"

struct attentionData
{
    int start;
    int end;
    Json::String holds;
    Json::String argument;
};

class attentionOnHandler : public baseHandler
{
public:
    attentionOnHandler(const std::string &filePath) : baseHandler(filePath)
    {
        this->findJsonClass("Attention_on");
    };

    void getData();

    std::vector<attentionData> m_attentionData;
};

std::ostream &operator<<(std::ostream &os, const attentionData &attentionData);