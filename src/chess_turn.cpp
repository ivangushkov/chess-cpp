#include "board.h"
#include "pieces.h"
#include "move_parser.h"
#include "chess_turn.h"

#include <string>
#include <vector>
#include <iostream>


ChessBoard chess_turn(ChessBoard board, bool white_turn) {

    /* A turn of chess!
    */

    std::string move;
    
    move = get_move(white_turn, move);
    parse_move(move);

    return board;

}


std::string get_move(bool white_turn, std::string move) {
    // Decide whose turn it is and get a move
    if (white_turn) {
        std::cout << "White to move: " << "\n";
        std::getline(std::cin, move);
        std::cout << "White entered: " << move << "\n";
    } else {
        std::cout << "Black to move: " << "\n";
        std::getline(std::cin, move);
        std::cout << "Black entered: " << move << "\n";
    }

    return move;
}
