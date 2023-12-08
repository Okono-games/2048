#include <stdio.h>
#include "raylib.h"

// CONSTANTS //

#define WINDOW_W  1280
#define WINDOW_H  720

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------



//----------------------------------------------------------------------------------
// Global Variables Declaration
//----------------------------------------------------------------------------------

Camera2D camera;

//----------------------------------------------------------------------------------
// Module Functions Declaration (local)
//----------------------------------------------------------------------------------
void DrawSprites();
void SetFullscreen();
void GameInput();
void GameFrame();
void InitGame();


//----------------------------------------------------------------------------------
// Program main entry point
//----------------------------------------------------------------------------------
int main(){

    InitGame();

    while (!WindowShouldClose()){

        SetFullscreen();

        GameInput();

        GameFrame();

        DrawSprites();
    }

    /* CLEANING AND CLOSING */
    CloseWindow();
    return 0;
}


//----------------------------------------------------------------------------------
// Module Functions Definitions (local)
//----------------------------------------------------------------------------------
void SetFullscreen() {
    /* FULLSCREEN */
    if(IsKeyPressed(KEY_ENTER) && IsKeyDown(KEY_LEFT_ALT)) {
        // see what display we are on right now
        int display = GetCurrentMonitor();
        
        if(IsWindowFullscreen()) {
            // if we are full screen, then go back to the windowed size
            SetWindowSize(WINDOW_W, WINDOW_H);
        }
        else {
            // if we are not full screen, set the window size to match the monitor we are on
            SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        }
        // toggle the state	
        ToggleFullscreen();
    }
}

void InitGame(){

    InitWindow(WINDOW_W, WINDOW_H, "test");
    
    // basic defaults
    SetTargetFPS(60);
    // HideCursor();

    //camera init
    camera.offset = (Vector2){WINDOW_W/2,WINDOW_H/2};
    camera.target = (Vector2){WINDOW_W/2, WINDOW_H/2};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void GameInput(){
    if (IsKeyDown(KEY_A)){
        camera.target.x -= 4;
    }else if (IsKeyDown(KEY_D)){
    	camera.target.x += 4;
    }
    if (IsKeyDown(KEY_W)){
        camera.target.y -= 4;
    }else if (IsKeyDown(KEY_S)){
    	camera.target.y += 4;
    }

}

void GameFrame(){
}

void DrawSprites(){
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(camera);
    DrawRectangle(200, 300, 400, 300, WHITE);
    EndMode2D();
    DrawRectangle(WINDOW_W/2-20,WINDOW_H/2-20,40,40, RED);
    EndDrawing();
}
