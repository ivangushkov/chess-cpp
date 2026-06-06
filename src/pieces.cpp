#include "pieces.h"

#include <raylib.h>



Pawn::Pawn(int number_ind, int letter_ind, bool isWhite) {

    // Load in the texture
    data.sprite.texture = LoadTexture("../assets/white_pawn2.png");

    // Set up the source rectangle
    data.sprite.sourceRec.x = 50.0f;
    data.sprite.sourceRec.y = 50.0f;
    data.sprite.sourceRec.width = (float) (data.sprite.texture.width -50.0);
    data.sprite.sourceRec.height = (float) (data.sprite.texture.height -50.0);

    // The origin of the sprite
    //data.sprite.origin.x = (float) data.sprite.texture.width;
    //data.sprite.origin.y = (float) data.sprite.texture.height;

    data.sprite.origin.x = (float) 0.0;
    data.sprite.origin.y = (float) 0.0;
    
    data.sprite.rotation = (float) 0.0;

    // The rest of the 
    data.number_ind = number_ind;
    data.letter_ind = letter_ind;
    data.isWhite = isWhite;

}

