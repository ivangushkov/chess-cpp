#include <array>
#include <string>
#include <raylib.h>

#ifndef PIECES_H
#define PIECES_H

enum PieceType {
  PAWN,
  ROOK,
  KNIGHT
}; 

struct Piece {
    PieceType type;
    Texture2D texture;
    Rectangle sourceRec;
    Vector2 origin;
    float rotation;
    int letter_ind;
    bool isWhite;
    bool captured{0};
};

struct PieceSprite {
    Texture2D texture;
    Rectangle sourceRec;
    Vector2 origin;
    float rotation;
};

struct PieceData {
    PieceSprite sprite;
    int number_ind;
    int letter_ind;
    bool isWhite;
    bool captured{0};
};

class Pawn {
    public:
        Pawn(int number_ind, int letter_ind, bool isWhite);
        PieceData data;
};

#endif