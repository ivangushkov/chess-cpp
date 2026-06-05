#include "board.h"

#include <iostream>
#include <string>

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
    
    ChessBoard my_chezz{50, 50};

    my_chezz.disp_positions();

    // Some pseudocode

    bool white_turn = 1;
    bool invalid_move = 1; //Move is assumed invalid until parsed

    std::string move;

    // Window stuff
    const int screenWidth = 1600;
    const int screenHeight = 1200;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while(!WindowShouldClose()) {

        // Decide whose turn it is and get a move
        // move = get_move(white_turn, move);


        // Flip turn
        if (white_turn) {            
            white_turn = 0;
        } else {
            white_turn = 1;
        }

        BeginDrawing();

            ClearBackground(SKYBLUE);
            my_chezz.draw_board(screenWidth, screenHeight);
            
            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();        

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    

    return 0;
}
