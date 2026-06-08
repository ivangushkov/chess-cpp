#include "pieces.h"

#include <array>
#include <iostream>
#include <string>
#include <raylib.h>

#ifndef BOARD_H
#define BOARD_H

struct BoardSquare {
    int number;
    std::string letter;
    Rectangle rect;
    Color color;
};

// Declare the chess board class
class ChessBoard {
    private:
        int board_marginX{100};
        int board_marginY{100};
    public:
        ChessBoard(int board_marginX, int board_marginY, int screenWidth, int screenHeight);
        void disp_positions();
        void draw_board(Piece testPawn);
        
        std::array<std::string, 8> letters;
        std::array<int, 8> number_positions;
        std::array<std::array<std::string, 8>, 8> positions;
        std::array<std::array<BoardSquare, 8>, 8> boardSquares; // The board squares
        
};


#endif