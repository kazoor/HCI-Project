#include <iostream>
#include "jsonparser.hpp"

void jsonParser::read()
{
    std::ifstream *stream = this->getStreamPointer();

    *stream >> this->m_root;
}

void jsonParser::dump()
{
    if (!this->m_root)
    {
        std::cout << "Failed to dump data, m_root is NULL" << std::endl;
        return;
    }

    std::cout << this->m_root << std::endl;
}

Json::Value jsonParser::getRoot()
{
    if (!this->m_root)
        return 0;

    return this->m_root;
}