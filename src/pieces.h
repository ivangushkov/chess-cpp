#include <array>
#include <string>
#include <raylib.h>

#ifndef PIECES_H
#define PIECES_H


struct PieceSprite {
    Texture2D texture;
    Rectangle sourceRec;
    Rectangle destRec;
    Vector2 origin;
    float rotation;
};

#endif