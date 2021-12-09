#pragma once

#include "solution_1.cpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

namespace day_2
{
    namespace solution_2 {
        
        typedef struct Position {
            int horizontal = 0, vertical = 0, aim = 0;
        } position_t;

        int solution()
        {
            std::ifstream fp{"../src/day_2/data.txt"};
            std::string line;

            std::string direction;
            int magnitude;

            position_t position;

            while (std::getline(fp, line)) {
                std::stringstream ss{line};
                ss >> direction;
                ss >> magnitude;
                
                switch( direction_map.at(direction) ) {
                    case MoveDirection::Forward : {
                        position.horizontal += magnitude;
                        position.vertical += magnitude * position.aim; 
                        break;
                        }
                    case MoveDirection::Up : position.aim += magnitude; break;
                    case MoveDirection::Down : position.aim -= magnitude; break;
                }
            }

            fp.close();

            return position.vertical * (-position.horizontal);
        }
    }
}