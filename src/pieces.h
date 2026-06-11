#include <array>
#include <string>
#include <raylib.h>

#ifndef PIECES_H
#define PIECES_H

enum PieceType {
  QUEEN,
  KING,
  ROOK,
  KNIGHT,
  BISHOP,
  PAWN,
};

struct Piece {
    Texture2D texture;
    Rectangle sourceRec;
    Vector2 origin;
    float rotation;
    Color color;
    bool isWhite;
    PieceType type;
    int number_ind;
    int letter_ind;
    bool captured{0};
    bool firstMove{1};
};


Piece init_piece(int number_ind, int letter_ind, bool isWhite, PieceType type);

#endif