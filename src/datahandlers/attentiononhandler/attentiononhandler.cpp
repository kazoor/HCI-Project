#include "attentiononhandler.hpp"

void attentionOnHandler::getData()
{
    Json::Value classObj = this->getClassObj();

    for (const Json::Value &it : classObj["instances"])
    {
        m_attentionData.push_back({it["start"].asInt(),
                                   it["end"].asInt(),
                                   it["holds"].asString(),
                                   it["arguments"]["argument1"].asString()});
    }
}

std::ostream &operator<<(std::ostream &os, const attentionData &attentionData)
{
    return os
           << "attentionData { " << std::endl
           << "Start: " << attentionData.start << std::endl
           << "End: " << attentionData.end << std::endl
           << "Holds: " << attentionData.holds << std::endl
           << "Argument: " << attentionData.argument << std::endl
           << "}" << std::endl
           << std::endl;
}