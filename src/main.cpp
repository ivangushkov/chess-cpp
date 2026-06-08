#include "board.h"
#include "pieces.h"
#include "move_parser.h"
#include "chess_turn.h"

#include <iostream>
#include <string>
#include <typeinfo>

#include <raylib.h>

int main() {

    std::cout << "Hello, world!" << std::endl;

    // Some pseudocode

    // Raylib Window stuff
    const int screenWidth = 800;
    const int screenHeight = 600;

    const int board_marginX = 50;
    const int board_marginY = 50;

    // chess stuff
    bool white_turn = 1;
    ChessBoard my_chess{board_marginX, board_marginY, screenWidth, screenHeight};
    

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    Piece testPawn = init_piece(0, 1, 1, PAWN);

    BeginDrawing();
            
        ClearBackground(SKYBLUE);
        my_chess.draw_board(testPawn);
        
    EndDrawing();     

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while(!WindowShouldClose()) {

        // Perform a chess turn
        my_chess = chess_turn(my_chess, white_turn);



        // Flip turn
        if (white_turn) {            
            white_turn = 0;
        } else {
            white_turn = 1;
        }

        BeginDrawing();
            
            ClearBackground(SKYBLUE);
            my_chess.draw_board(testPawn);
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
