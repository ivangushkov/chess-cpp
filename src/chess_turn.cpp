#include "board.h"
#include "pieces.h"
#include "move_parser.h"
#include "chess_turn.h"

#include <string>
#include <vector>
#include <iostream>


ChessBoard chess_turn(ChessBoard board, bool white_turn) {

    /* A turn of chess!

    0. Check game state for chess. If we are in chess inform player and parse move differently.

    1. Get the move from current player                                                     DONE
    2. Parse the move on a semantic level                                                   DONE
    
    3. Parse the move on a game context level                                               TODO

        3.1 Parse on board context level (is one of your pieces there?)                     TODO
        3.2 Parse on piece context level (valid move for piece type?)                       TODO
        3.3 Parse on battle context level (can your piece take the square?                  TODO 
            Is something in the way? Is it occupied by your piece?)
    
    4. Execute move and resolve new board state (New piece possitions. Piece was taken?)    TODO
    */

    std::string move;
    
    move = get_move(white_turn, move);
    ParsedMove parsedMove = parse_move(move);

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
