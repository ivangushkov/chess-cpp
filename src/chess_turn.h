#include "board.h"
#include "pieces.h"
#include "move_parser.h"

#include <string>
#include <vector>
#include <iostream>

#ifndef CHESSTURN_H
#define CHESSTURN_H

ChessBoard chess_turn(ChessBoard board, bool white_turn);
std::string get_move(bool white_turn, std::string move);

#endif