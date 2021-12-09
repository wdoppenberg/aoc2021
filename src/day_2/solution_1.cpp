#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

namespace day_2
{
    enum class MoveDirection {
        Forward,
        Up, 
        Down
    };

    std::map<std::string, MoveDirection> direction_map {
        {"forward", MoveDirection::Forward},
        {"up", MoveDirection::Up},
        {"down", MoveDirection::Down}
    };

    namespace solution_1 {

        typedef struct Position {
            int horizontal = 0, vertical = 0;
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
                    case MoveDirection::Forward : position.horizontal += magnitude; break;
                    case MoveDirection::Up : position.vertical += magnitude; break;
                    case MoveDirection::Down : position.vertical -= magnitude; break;
                }
            }

            fp.close();

            return position.vertical * (-position.horizontal);
        }
    }
}