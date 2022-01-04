#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <tuple>
#include <filesystem>
#include <json/json.h>
#include "datahandlers/positionhandler/positionhandler.hpp"
#include "datahandlers/attentiononhandler/attentiononhandler.hpp"

int main()
{
    positionHandler position("Annotation_P4a_merged.json");

    position.getData();

    attentionOnHandler attention("Annotation_P4a_merged.json");

    attention.getData();

    std::vector<std::tuple<positionData, attentionData>> val;

    for (size_t i = 0; i < position.m_positionData.size(); ++i)
    {
        for (size_t j = 0; j < attention.m_attentionData.size(); ++j)
        {
            if (position.m_positionData[i].argument == "Obj_Property" && attention.m_attentionData[j].holds == "Obj_Property")
            {
                val.push_back(std::make_tuple(position.m_positionData[i], attention.m_attentionData[j]));
            }
        }
    }

    for (auto &x : val)
    {
        std::cout << std::get<0>(x) << " " << std::get<1>(x) << std::endl;
    }
    return 0;
}