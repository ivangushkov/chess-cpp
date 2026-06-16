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

            currentSquare.rect.x = (screenWidth-board_side)/2 + j*square_side;
            currentSquare.rect.y = (board_marginY + board_side - square_side) - i*square_side;
            currentSquare.rect.width = square_side;
            currentSquare.rect.height = square_side;

            Piece emptyPiece = init_piece(i, j, 1, NONE);
            currentSquare.piece = emptyPiece;

            currentSquare.color = (i + j) % 2 == 0 ? MAROON : RAYWHITE; 
    
            boardSquares[i][j] = currentSquare;
        }
    }

    this->setup_chess_game();
    this->resolve_occupancy();

}

void ChessBoard::setup_chess_game() {

    for (int j = 0; j <= 7; j++) {

        // Pawns
        boardSquares[1][j].piece = init_piece(1, j, 1, PAWN); // White
        boardSquares[6][j].piece = init_piece(1, j, 0, PAWN); // Black
        
        // Rooks
        if (j == 0) {

            // White
            boardSquares[0][j].piece = init_piece(0, j, 1, ROOK);
            boardSquares[0][7-j].piece = init_piece(0, j, 1, ROOK);

            // Black
            boardSquares[7][j].piece = init_piece(0, j, 0, ROOK);
            boardSquares[7][7-j].piece = init_piece(0, j, 0, ROOK);
        }
        // Knights 
        if (j == 1) {
            // White
            boardSquares[0][j].piece = init_piece(0, j, 1, KNIGHT);
            boardSquares[0][7-j].piece = init_piece(0, j, 1, KNIGHT);

            // Black
            boardSquares[7][j].piece = init_piece(0, j, 0, KNIGHT);
            boardSquares[7][7-j].piece = init_piece(0, j, 0, KNIGHT);

        }
        // Bishops 
        if (j == 2) {
            // White
            boardSquares[0][j].piece = init_piece(0, j, 1, BISHOP);
            boardSquares[0][7-j].piece = init_piece(0, j, 1, BISHOP);
            
            // Black
            boardSquares[7][j].piece = init_piece(0, j, 0, BISHOP);
            boardSquares[7][7-j].piece = init_piece(0, j, 0, BISHOP);
        }
        // QUEENS 
        if (j == 3) {
            boardSquares[0][j].piece = init_piece(0, j, 1, QUEEN); // White
            boardSquares[7][j].piece = init_piece(0, j, 0, QUEEN); // Black
        }
        // KINGS 
        if (j == 4) {
            boardSquares[0][j].piece = init_piece(0, j, 1, KING); // White
            boardSquares[7][j].piece = init_piece(0, j, 0, KING); // Black
        }


        
    }
}

// Jury is still out on whether this is needed at all
void ChessBoard::resolve_occupancy() {
    // Loop over the 64 grid of the chess board and 
    // resolve if the square is occupied or not
    for (int i = 0; i<= 7; i++) {
        for (int j = 0; j <= 7; j++) {

            if (boardSquares[i][j].piece.type != NONE) {
                boardSquares[i][j].occupied = true;
            }
        }
    }
}

void ChessBoard::disp_positions() {
    
    // Just displays the positions array to the terminal

    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++){
            std::cout << "\t" << positions[i][j]; 
        }
        std::cout << "\n";
    }
}


void ChessBoard::draw_board() {

    for (int i = 0; i<= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            
            // Draw the square
            DrawRectangle(
                boardSquares[i][j].rect.x,
                boardSquares[i][j].rect.y,
                boardSquares[i][j].rect.width,
                boardSquares[i][j].rect.height,
                boardSquares[i][j].color
            );

            DrawText(
                positions[i][j].c_str(), 
                boardSquares[i][j].rect.x + boardSquares[i][j].rect.width/2, 
                boardSquares[i][j].rect.y + boardSquares[i][j].rect.width/2, 
                20, BLACK);

            if (boardSquares[i][j].piece.type != NONE) {
                DrawTexturePro(
                boardSquares[i][j].piece.texture, 
                boardSquares[i][j].piece.sourceRec, 
                boardSquares[i][j].rect,
                boardSquares[i][j].piece.origin, 
                boardSquares[i][j].piece.rotation, 
                boardSquares[i][j].piece.color);
            
            }
        
        }

    }

}

void ChessBoard::unload_textures() {

    for (int i = 0; i<= 7; i++) {
        for (int j = 0; j <= 7; j++) {
        
            UnloadTexture(boardSquares[i][j].piece.texture);
        
        }

    }

}