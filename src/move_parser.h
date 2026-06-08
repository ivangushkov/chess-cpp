#include <array>
#include <string>
#include <iostream>

#ifndef MOVE_PARSER_H
#define MOVE_PARSER_H


enum LetterMove {
  a,
  b,
  c,
  d,
  e,
  f,
  g,
  h
};


struct ParsedMove {
    std::array<int, 4> move;
    bool valid{0};
    std::string flag;
};


ParsedMove parse_move(std::string move_candidate);



#endif