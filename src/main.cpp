#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <tuple>
#include <filesystem>
#include <json/json.h>
#include "datahandlers/positionhandler/positionhandler.hpp"
#include "datahandlers/attentiononhandler/attentiononhandler.hpp"

float getAvgSeconds(std::vector<float> &times)
{
    float tot = 0.0f;
    for (auto &time : times)
    {
        tot += time;
    }

    return (tot / times.size()) / 1000;
}

std::vector<positionData> getObjRightSide(positionHandler position, attentionOnHandler attention)
{
    std::vector<positionData> posData;

    for (size_t i = 0; i < position.m_positionData.size(); ++i)
    {
        for (size_t j = 0; j < attention.m_attentionData.size(); ++j)
        {
            if (position.m_positionData[i].argument == "Obj_Property" && position.m_positionData[i].holds == "Right_Sidewalk" && attention.m_attentionData[j].holds == "Obj_Property")
            {
                if (attention.m_attentionData[j].start > position.m_positionData[i].start && attention.m_attentionData[j].end < position.m_positionData[i].end)
                    posData.push_back(position.m_positionData[i]);
            }
        }
    }

    return posData;
}

std::vector<positionData> getObjLeftSide(positionHandler position, attentionOnHandler attention)
{
    std::vector<positionData> posData;

    for (size_t i = 0; i < position.m_positionData.size(); ++i)
    {
        for (size_t j = 0; j < attention.m_attentionData.size(); ++j)
        {
            if (position.m_positionData[i].argument == "Obj_Property" && position.m_positionData[i].holds == "Left_Sidewalk" && attention.m_attentionData[j].holds == "Obj_Property")
            {
                if (attention.m_attentionData[j].start > position.m_positionData[i].start && attention.m_attentionData[j].end < position.m_positionData[i].end)
                    posData.push_back(position.m_positionData[i]);
            }
        }
    }

    return posData;
}

std::vector<positionData> getAgentRightSide(positionHandler position, attentionOnHandler attention)
{
    std::vector<positionData> posData;

    for (size_t i = 0; i < position.m_positionData.size(); ++i)
    {
        for (size_t j = 0; j < attention.m_attentionData.size(); ++j)
        {
            if (position.m_positionData[i].argument == "Agent" && position.m_positionData[i].holds == "Right_Sidewalk" && (attention.m_attentionData[j].holds == "Agent_Brel" || attention.m_attentionData[j].holds == "Agent_Birr"))
            {
                if (attention.m_attentionData[j].start > position.m_positionData[i].start && attention.m_attentionData[j].end < position.m_positionData[i].end)
                    posData.push_back(position.m_positionData[i]);
            }
        }
    }

    return posData;
}

std::vector<positionData> getAgentLeftSide(positionHandler position, attentionOnHandler attention)
{
    std::vector<positionData> posData;

    for (size_t i = 0; i < position.m_positionData.size(); ++i)
    {
        for (size_t j = 0; j < attention.m_attentionData.size(); ++j)
        {
            if (position.m_positionData[i].argument == "Agent" && position.m_positionData[i].holds == "Left_Sidewalk" && (attention.m_attentionData[j].holds == "Agent_Brel" || attention.m_attentionData[j].holds == "Agent_Birr"))
            {
                if (attention.m_attentionData[j].start > position.m_positionData[i].start && attention.m_attentionData[j].end < position.m_positionData[i].end)
                    posData.push_back(position.m_positionData[i]);
            }
        }
    }

    return posData;
}

std::vector<float> getObjRightSideTime(positionHandler position, attentionOnHandler attention)
{
    std::vector<float> timeData;

    for (size_t i = 0; i < position.m_positionData.size(); ++i)
    {
        for (size_t j = 0; j < attention.m_attentionData.size(); ++j)
        {
            if (position.m_positionData[i].argument == "Obj_Property" && position.m_positionData[i].holds == "Right_Sidewalk" && attention.m_attentionData[j].holds == "Obj_Property")
            {
                if (attention.m_attentionData[j].start > position.m_positionData[i].start && attention.m_attentionData[j].end < position.m_positionData[i].end)
                    timeData.push_back(attention.m_attentionData[j].start - position.m_positionData[i].start);
            }
        }
    }

    return timeData;
}

std::vector<float> getObjLeftSideTime(positionHandler position, attentionOnHandler attention)
{
    std::vector<float> timeData;

    for (size_t i = 0; i < position.m_positionData.size(); ++i)
    {
        for (size_t j = 0; j < attention.m_attentionData.size(); ++j)
        {
            if (position.m_positionData[i].argument == "Obj_Property" && position.m_positionData[i].holds == "Left_Sidewalk" && attention.m_attentionData[j].holds == "Obj_Property")
            {
                if (attention.m_attentionData[j].start > position.m_positionData[i].start && attention.m_attentionData[j].end < position.m_positionData[i].end)
                    timeData.push_back(attention.m_attentionData[j].start - position.m_positionData[i].start);
            }
        }
    }

    return timeData;
}

std::vector<float> getAgentRightSideTime(positionHandler position, attentionOnHandler attention)
{
    std::vector<float> timeData;

    for (size_t i = 0; i < position.m_positionData.size(); ++i)
    {
        for (size_t j = 0; j < attention.m_attentionData.size(); ++j)
        {
            if (position.m_positionData[i].argument == "Agent" && position.m_positionData[i].holds == "Right_Sidewalk" && (attention.m_attentionData[j].holds == "Agent_Brel" || attention.m_attentionData[j].holds == "Agent_Birr"))
            {
                if (attention.m_attentionData[j].start > position.m_positionData[i].start && attention.m_attentionData[j].end < position.m_positionData[i].end)
                    timeData.push_back(attention.m_attentionData[j].start - position.m_positionData[i].start);
            }
        }
    }

    return timeData;
}

std::vector<float> getAgentLeftSideTime(positionHandler position, attentionOnHandler attention)
{
    std::vector<float> timeData;

    for (size_t i = 0; i < position.m_positionData.size(); ++i)
    {
        for (size_t j = 0; j < attention.m_attentionData.size(); ++j)
        {
            if (position.m_positionData[i].argument == "Agent" && position.m_positionData[i].holds == "Left_Sidewalk" && (attention.m_attentionData[j].holds == "Agent_Brel" || attention.m_attentionData[j].holds == "Agent_Birr"))
            {
                if (attention.m_attentionData[j].start > position.m_positionData[i].start && attention.m_attentionData[j].end < position.m_positionData[i].end)
                    timeData.push_back(attention.m_attentionData[j].start - position.m_positionData[i].start);
            }
        }
    }

    return timeData;
}

int main()
{
    std::string FilePath = "Annotation_P24_merged.json";

    positionHandler position(FilePath);

    position.getData();

    attentionOnHandler attention(FilePath);

    attention.getData();

    std::vector<positionData> rightObjs = getObjRightSide(position, attention);

    std::vector<positionData> leftObjs = getObjLeftSide(position, attention);

    std::vector<positionData> rightAgents = getAgentRightSide(position, attention);

    std::vector<positionData> leftAgents = getAgentLeftSide(position, attention);

    std::vector<float> rightObjTimes = getObjRightSideTime(position, attention);

    std::vector<float> leftObjTimes = getObjLeftSideTime(position, attention);

    std::vector<float> rightAgentTimes = getAgentRightSideTime(position, attention);

    std::vector<float> leftAgentTimes = getAgentLeftSideTime(position, attention);

    std::cout << "Objects detected on right side: " << rightObjs.size() << std::endl;

    std::cout << "Objects detected on left side: " << leftObjs.size() << std::endl;

    std::cout << "Agents detected on right side: " << rightAgents.size() << std::endl;

    std::cout << "Agents detected on left side: " << leftAgents.size() << std::endl;

    std::cout << "Objects on right side average detection time: " << getAvgSeconds(rightObjTimes) << std::endl;

    std::cout << "Objects on left side average detection time: " << getAvgSeconds(leftObjTimes) << std::endl;

    std::cout << "Agents on right side average detection time: " << getAvgSeconds(rightAgentTimes) << std::endl;

    std::cout << "Agents on left side average detection time: " << getAvgSeconds(leftAgentTimes) << std::endl;

    return 0;
}