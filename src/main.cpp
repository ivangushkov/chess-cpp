#include "board.h"
#include "pieces.h"
//#include "move_parser.h"

#include <iostream>
#include <string>
#include <typeinfo>

#include <raylib.h>

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

int main() {

    std::cout << "Hello, world!" << std::endl;

    // Some pseudocode

    bool white_turn = 1;
    bool invalid_move = 1; //Move is assumed invalid until parsed

    std::string move;

    // Window stuff
    const int screenWidth = 800;
    const int screenHeight = 600;

    const int board_marginX = 50;
    const int board_marginY = 50;

    ChessBoard my_chezz{board_marginX, board_marginY, screenWidth, screenHeight};
    

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    Piece testPawn = init_piece(0, 1, 1, PAWN);

    BeginDrawing();
            
        ClearBackground(SKYBLUE);
        my_chezz.draw_board(testPawn);
        
    EndDrawing();     

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while(!WindowShouldClose()) {

        // Decide whose turn it is and get a move
        //move = get_move(white_turn, move);
        //parse_move(move);


        // Flip turn
        if (white_turn) {            
            white_turn = 0;
        } else {
            white_turn = 1;
        }

        BeginDrawing();
            
            ClearBackground(SKYBLUE);
            my_chezz.draw_board(testPawn);
            //DrawTexture(testPawn, 250.0, 100.0, RAYWHITE);
            //DrawTexturePro(testPawn, sourceRec, destRec, origin, rotation, RAYWHITE);

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        
        EndDrawing();        

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(testPawn.texture);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    

    return 0;
}
