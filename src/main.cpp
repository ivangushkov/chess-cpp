#include "board.h"
#include "pieces.h"

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
    const int screenWidth = 1600;
    const int screenHeight = 1200;

    const int board_marginX = 50;
    const int board_marginY = 50;

    ChessBoard my_chezz{board_marginX, board_marginY, screenWidth, screenHeight};

    my_chezz.disp_positions();


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    Texture2D testPawn = LoadTexture("../assets/white_pawn2.png");

    Rectangle sourceRec = {50.0f, 50.0f, (float) (testPawn.width -50.0), (float) (testPawn.height -50.0)};
    Rectangle destRec = {400.0, 400.0, 200.0, 200.0};
    Vector2 origin = {(float) testPawn.width, (float) testPawn.height};

    float rotation = 0.0;

    PieceSprite pawnSprite = {testPawn, sourceRec, destRec, origin, rotation}; 

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
            my_chezz.draw_board(pawnSprite);
            //DrawTexture(testPawn, 250.0, 100.0, RAYWHITE);
            //DrawTexturePro(testPawn, sourceRec, destRec, origin, rotation, RAYWHITE);

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        
        EndDrawing();        

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(testPawn);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    

    return 0;
}
