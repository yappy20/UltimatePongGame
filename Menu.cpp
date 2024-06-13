#include "menuH.h"
#include <raylib.h>

#include "game.h"
using namespace std;

void displayMenu() {
    const int screenWidth = 1280;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Ultimate Pong");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Rectangle button = { screenWidth / 2.0f - 100, screenHeight / 2.0f - 25, 200, 50 };
    bool buttonHovered = false;
    bool buttonClicked = false;

    // Main game loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key

        // Update
        buttonHovered = CheckCollisionPointRec(GetMousePosition(), button);

        if (buttonHovered && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            buttonClicked = true;
        }
        
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("PONG", 500, 200, 100, RED);

        // Draw button
        if (buttonHovered) {
            DrawRectangleRec(button, BLUE);
        }
        else {
            DrawRectangleRec(button, GRAY);
        }
        DrawText("START GAME", screenWidth / 2.0f - 80, screenHeight / 2.0f - 15, 20, buttonHovered ? DARKGRAY : BLACK);

        // Button click action
        if (buttonClicked) {
            DrawText("Button Clicked!", 500, 300, 40, GREEN);
            startGame();
            buttonClicked = false;
            
            // Reset button click
        }

        EndDrawing();
    }
    
    // Main game loop
    
    //----------------------------------------------------------------------------------

    CloseWindow();
}

