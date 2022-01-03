#include "positionextractor.hpp"

void positionExtractor::getData()
{
    Json::Value classObj = this->getClassObj();

    for (const Json::Value &it : classObj["instances"])
    {
        m_positionData.push_back({it["start"].asInt(),
                                  it["end"].asInt(),
                                  it["holds"].asString(),
                                  it["arguments"]["argument1"].asString()});
    }
}

std::ostream &operator<<(std::ostream &os, const positionData &posData)
{
    return os
           << "positionData { " << std::endl
           << "Start: " << posData.start << std::endl
           << "End: " << posData.end << std::endl
           << "Holds: " << posData.holds << std::endl
           << "Argument: " << posData.argument << std::endl
           << "}" << std::endl
           << std::endl;
}