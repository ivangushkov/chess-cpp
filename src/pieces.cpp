#include "pieces.h"
#include <raylib.h>


Piece init_piece(int number_ind, int letter_ind, bool isWhite, PieceType type) {
    Piece piece;


    piece.texture = LoadTexture("../assets/ChessPieces.png");
    
    float pieceHeight = piece.texture.height / 2;
    float pieceWidth = piece.texture.width / 6;

    // Select the rectangle cutout of the sprite sheet based on the type enum
    piece.sourceRec.y = isWhite * pieceHeight;
    piece.sourceRec.x = type * pieceWidth; // Enum magic!

    piece.sourceRec.width = pieceWidth;
    piece.sourceRec.height = pieceHeight;

    // Origin of the sprite (relative to rectangle)
    piece.origin.x = (float) 0.0;
    piece.origin.y = (float) 0.0;
    
    piece.rotation = (float) 0.0;

    piece.color = RAYWHITE;
    
    piece.isWhite = isWhite;

    piece.type = type;

    // The rest of the 
    piece.number_ind = number_ind;
    piece.letter_ind = letter_ind;
    
    return piece;
};