#include <array>
#include <string>
#include <iostream>

#ifndef MOVE_PARSER_H
#define MOVE_PARSER_H


struct ParsedMove {
    std::array<int, 2> from;
    std::array<int, 2> to;
    bool valid{0};
    std::string flag;
};


ParsedMove parse_move(std::string move_candidate);



#endif