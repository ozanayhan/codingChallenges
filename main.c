#include "raylib.h"

int main() {
    int width = 800;
    int height = 600;
    InitWindow( width, height, "MYOKOCE" );
    SetTargetFPS( 60 );
    while ( ! WindowShouldClose() ) {
        BeginDrawing();

        ClearBackground( WHITE );
        //DrawCircle( width/2, height/2, 20, RED );

        EndDrawing();

    }
}