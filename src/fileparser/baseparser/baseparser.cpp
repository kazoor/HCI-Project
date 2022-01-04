#include "baseparser.hpp"
#include <fstream>

baseParser::baseParser(const std::string &filePath)
{
    this->m_filePath = filePath;

    m_stream = new std::ifstream(filePath, std::ifstream::binary);
}

std::string baseParser::getFilePath()
{
    return this->m_filePath;
}

std::ifstream *baseParser::getStreamPointer()
{
    return this->m_stream;
}

void baseParser::clean()
{
    this->m_filePath = "";
    this->m_stream = nullptr;

    delete this->m_stream;
}