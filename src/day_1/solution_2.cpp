#pragma once

#include <fstream>
#include <iostream>

namespace day_1
{

    namespace solution_2 {
        int solution()
        {
            std::ifstream myfile;
            myfile.open("../src/day_1/data.txt", std::ios::in);
            int measurement = 0, prev = 0, counter = -1;

            int m_0, m_1, m_2;

            myfile >> m_0;
            myfile >> m_1;

            while (myfile >> m_2) {
                // std::cout << measurement << std::endl;
                
                measurement = m_0 + m_1 + m_2;
                
                if (measurement > prev)
                    counter++;
                m_0 = m_1;
                m_1 = m_2;
                prev = measurement;
            }

            myfile.close();

            // std::cout << "The number of increases is: " << counter << std::endl;

            return counter;
        }
    }
}