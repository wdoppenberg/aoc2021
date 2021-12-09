#pragma once

#include <fstream>
#include <iostream>

namespace day_1
{
    namespace solution_1 {

        int solution()
        {
            std::ifstream myfile;
            myfile.open("../src/day_1/data.txt", std::ios::in);
            int measurement, prev = 0, counter = -1;

            while (myfile >> measurement) {
                // std::cout << measurement << std::endl;
                if (measurement > prev)
                    counter++;
                prev = measurement;
            }

            myfile.close();

            return counter;
        }
    }
}