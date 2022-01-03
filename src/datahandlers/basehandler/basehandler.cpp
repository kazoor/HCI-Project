#include "basehandler.hpp"
#include "../../fileparser/jsonparser/jsonparser.hpp"

baseHandler::baseHandler(const std::string &filePath)
{
    jsonParser parser(filePath);

    parser.read();

    this->m_root = parser.getRoot();
}

void baseHandler::findJsonClass(const std::string &className)
{
    for (const Json::Value &it : this->m_root["annotations"])
    {
        if (it["class"].asString() == className)
        {
            this->m_classObj = it;
        }
    }
}

Json::Value baseHandler::getClassObj()
{
    if (!this->m_classObj)
        return 0;

    return this->m_classObj;
}