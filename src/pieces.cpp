#include "pieces.h"
#include <raylib.h>



Piece init_pawn(int number_ind, int letter_ind, bool isWhite, PieceType type) {

    Piece piece;
    // Load in the texture
    piece.texture = LoadTexture("../assets/white_pawn2.png");

    // Set up the source rectangle
    piece.sourceRec.x = 50.0f;
    piece.sourceRec.y = 50.0f;
    piece.sourceRec.width = (float) (piece.texture.width -50.0);
    piece.sourceRec.height = (float) (piece.texture.height -50.0);

    // The origin of the sprite
    //data.sprite.origin.x = (float) data.sprite.texture.width;
    //data.sprite.origin.y = (float) data.sprite.texture.height;

    piece.origin.x = (float) 0.0;
    piece.origin.y = (float) 0.0;
    
    piece.rotation = (float) 0.0;

    piece.color = isWhite ? RAYWHITE : BLACK;
    piece.isWhite = isWhite;

    piece.type = type;

    // The rest of the 
    piece.number_ind = number_ind;
    piece.letter_ind = letter_ind;
    
    return piece;
}

Piece init_piece(int number_ind, int letter_ind, bool isWhite, PieceType type) {
    Piece piece;

    switch(type){
        case PAWN : piece.texture = LoadTexture("../assets/chess_pieces.png"); 
                    break;
        case ROOK : piece.texture = LoadTexture("../assets/white_pawn2.png"); 
                    break;
        case KNIGHT : piece.texture = LoadTexture("../assets/white_pawn2.png"); 
                    break;
        case BISHOP : piece.texture = LoadTexture("../assets/white_pawn2.png"); 
                    break;
        case QUEEN : piece.texture = LoadTexture("../assets/white_pawn2.png"); 
                    break;
        case KING : piece.texture = LoadTexture("../assets/white_pawn2.png"); 
                    break;
            
    }

    // Set up the source rectangle
    piece.sourceRec.x = 0.0f;
    piece.sourceRec.y = 0.0f;
    piece.sourceRec.width = (float) (piece.texture.width -0.0);
    piece.sourceRec.height = (float) (piece.texture.height -0.0);

    // The origin of the sprite
    //data.sprite.origin.x = (float) data.sprite.texture.width;
    //data.sprite.origin.y = (float) data.sprite.texture.height;

    piece.origin.x = (float) 0.0;
    piece.origin.y = (float) 0.0;
    
    piece.rotation = (float) 0.0;

    piece.color = isWhite ? RAYWHITE : BLACK;
    piece.isWhite = isWhite;

    piece.type = type;

    // The rest of the 
    piece.number_ind = number_ind;
    piece.letter_ind = letter_ind;
    
    return piece;
};