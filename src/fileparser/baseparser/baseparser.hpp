#pragma once
#include <string>
#include <fstream>

class baseParser
{
public:
    baseParser(const std::string &filePath);

    ~baseParser()
    {
        this->m_filePath = "";
        this->m_stream = nullptr;

        delete this->m_stream;
    }

    std::string getFilePath();

    std::ifstream *getStreamPointer();

    // Virtual functions to override
    // Function to read data.
    virtual void read() = 0;

    // Function to dump out all read data.
    virtual void dump() = 0;

private:
    std::string m_filePath{NULL};

    std::ifstream *m_stream{nullptr};
};