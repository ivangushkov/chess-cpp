#include <array>
#include <iostream>
#include <string>
#include <raylib.h>

#ifndef BOARD_H
#define BOARD_H

// Declare the chess board class
class ChessBoard {
    private:
        int board_marginX{100};
        int board_marginY{100};
    public:
        ChessBoard(int board_marginX, int board_marginY);
        void disp_positions();
        void draw_board(int screenWidth, int screenHeight);
        
        std::array<std::string, 8> letters;
        std::array<int, 8> number_positions;
        std::array<std::array<std::string, 8>, 8> positions;
        
};


#endif