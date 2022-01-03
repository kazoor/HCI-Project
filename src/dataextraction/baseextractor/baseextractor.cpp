#include "baseextractor.hpp"
#include "../../fileparser/jsonparser/jsonparser.hpp"

baseExtractor::baseExtractor(const std::string &filePath)
{
    jsonParser parser(filePath);

    parser.read();

    this->m_root = parser.getRoot();
}

void baseExtractor::findJsonClass(const std::string &className)
{
    for (const Json::Value &it : this->m_root["annotations"])
    {
        if (it["class"].asString() == className)
        {
            this->m_classObj = it;
        }
    }
}

Json::Value baseExtractor::getClassObj()
{
    if (!this->m_classObj)
        return 0;

    return this->m_classObj;
}