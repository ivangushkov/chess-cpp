#include "board.h"
#include "pieces.h"

#include <iostream>
#include <array>
#include <string>
#include <raylib.h>


ChessBoard::ChessBoard(int board_marginX, int board_marginY, int screenWidth, int screenHeight) 
    : board_marginX {board_marginX}, board_marginY {board_marginY}
{

    // Available chess positions
    letters = {"a", "b", "c", "d", "e", "f", "g", "h"};

    std::cout << board_marginX << std::endl;
    std::cout << board_marginY << std::endl;

    int board_side = (screenHeight - 2*board_marginY);
    int square_side = board_side / 8;
    
    // Loop over the 64 grid of the chess board
    for (int i = 0; i<= 7; i++) {
        for (int j = 0; j <= 7; j++) {

            //std::cout << letters[i] << std::to_string(j+1) << std::endl;
            positions[i][j] = letters[j] + std::to_string(i+1);
            
            BoardSquare currentSquare;
            currentSquare.number = i + 1;
            currentSquare.letter =  letters[j];

            currentSquare.rect.x = (screenWidth-board_side)/2 + i*square_side;
            currentSquare.rect.y = (board_marginY + board_side - square_side) - j*square_side;
            currentSquare.rect.width = square_side;
            currentSquare.rect.height = square_side;


            
            // Decide colors
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    // row even column even
                    currentSquare.color = MAROON;
                } else {
                    // row even column odd
                    currentSquare.color = RAYWHITE;
                }       
            } else {
                if (j % 2 == 0) {
                    // row is odd column is even
                    currentSquare.color = RAYWHITE;
                } else {
                    // row is odd column is odd
                    currentSquare.color = MAROON;
                }
            }
            boardSquares[i][j] = currentSquare;
        };
    }

};

void ChessBoard::disp_positions() {
    
    // Just displays the positions array to the terminal

    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++){
            std::cout << "\t" << positions[i][j]; 
        }
        std::cout << "\n";
    }
}


void ChessBoard::draw_board(PieceSprite pieceSprite) {

    for (int i = 0; i<= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            //DrawRectangle(
            //    (screenWidth-board_side)/2 + i*square_side, 
            //    (board_marginY + board_side - square_side) - j*square_side, 
            //    square_side, 
            //    square_side, 
            //    boardSquares[i][j].color);
            DrawRectangle(
                boardSquares[i][j].rect.x,
                boardSquares[i][j].rect.y,
                boardSquares[i][j].rect.width,
                boardSquares[i][j].rect.height,
                boardSquares[i][j].color
            );

            DrawTexturePro(pieceSprite.texture, pieceSprite.sourceRec, pieceSprite.destRec, pieceSprite.origin, pieceSprite.rotation, RAYWHITE);
        
        }

    }

}