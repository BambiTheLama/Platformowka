#include "raylib.h"
#include "Hero.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1600;
    const int screenHeight = 900;
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Font fontRegular = LoadFont("script.font");
    Hero* hero = new Hero(6,200,200,14,8,0,255,10);
    room* Room = new room();
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int a = 32;
    int q = 1;
    int n = 1920 / a;
    int m = 1080 / a;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
            hero->updata(Room);



            // Update
            //----------------------------------------------------------------------------------
            // TODO: Update your variables here
            //----------------------------------------------------------------------------------

            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();

            ClearBackground(RAYWHITE);
            for (int i = 0; i < 28;i++)
            {
                for (int j = 0; j < 50; j++)
                    DrawRectangle(j * 32, 32 * i, 32, 32, Color{ (unsigned char)69,(unsigned char)(10 * j),(unsigned char)(20 * i),(unsigned char)(200) });
            }


            Room->draw();
            hero->draw();
            
            
            //DrawText("HELLOW WORLD", 600, 600, 100, BLACK);
            // DrawText("Gra", GetScreenWidth()/2 - 3  ,GetScreenHeight()/3, 40, BLACK);
            // DrawText("Muzyka", 800, GetScreenHeight()/3+50, 40, BLACK);
             //DrawText("Wejscie ", 800, GetScreenHeight() /3+100, 40, BLACK);

            DrawText(FormatText("%d", GetFPS()), 0, 0, 50, BLACK);
            EndDrawing();
            //----------------------------------------------------------------------------------
        
       
    }
    delete hero;
    delete Room;
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}