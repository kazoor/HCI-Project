#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <filesystem>
#include <json/json.h>
#include "dataextraction/positionextractor/positionextractor.hpp"

int main()
{
    positionExtractor position("Annotation_P4a_merged.json");

    position.getData();

    for (auto &x : position.m_positionData)
    {
        std::cout << x;
    }

    return 0;
}