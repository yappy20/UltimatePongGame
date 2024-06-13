#include "menuH.h"
#include <raylib.h>

#include "game.h"
#include "options.h"

using namespace std;

void displayMenu() {
    const int screenWidth = 1280;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Ultimate Pong");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Rectangle startButton = { screenWidth / 2.0f - 100, screenHeight / 2.0f - 25, 200, 50 };
    Rectangle optionsButton = { screenWidth / 2.0f - 100, screenHeight / 2.0f - (-50), 200,50};
    bool startButtonHovered = false;
    bool startButtonClicked = false;

    bool optionsButtonHovered = false;
    bool optionsButtonClicked = false;

    // Main game loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key

        // Update
        startButtonHovered = CheckCollisionPointRec(GetMousePosition(), startButton);
        optionsButtonHovered = CheckCollisionPointRec(GetMousePosition(), optionsButton);
        if (startButtonHovered && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            startButtonClicked = true;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("PONG", 500, 200, 100, RED);

        // Draw button
        if (startButtonHovered) {
            DrawRectangleRec(startButton, BLUE);
        }
        else {
            DrawRectangleRec(startButton, GRAY);
        }
        DrawText("START", screenWidth / 2.0f - 80, screenHeight / 2.0f - 15, 20, startButtonHovered ? DARKGRAY : BLACK);


        if (optionsButtonHovered) {
            DrawRectangleRec(optionsButton, BLUE);
        }
        else {
            DrawRectangleRec(optionsButton, GRAY);
        }
        DrawText("OPTIONS", screenWidth / 2.0f - 80, screenHeight / 2.0f - (-65), 20, startButtonHovered ? DARKGRAY : BLACK);

        // Button click action
        if (startButtonClicked) {

            startGame();
            startButtonClicked = false;
            break;
            // Reset button click
        }

        if (optionsButtonClicked) {

            EndDrawing();
        }

        // Main game loop

        //----------------------------------------------------------------------------------
        CloseWindow();

    }
}

