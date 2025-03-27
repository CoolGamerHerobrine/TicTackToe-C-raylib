#include <raylib.h>
#include <iostream>
using namespace std;


const int screen_width = 800;
const int screen_heigth = 800;
const int grid = 3;


int main(){
    // Impotant variables
    int cell_size = screen_width / grid;
    int turn = -1;
    Vector2 mouse_pos;
    bool player_1 = false;
    bool player_2 = false;
    Color green_color = GREEN;
    Color red_color = RED;

    // Initialize and stores the colors
    Color box_color[grid][grid];
    for(int i = 0; i < grid; i++)
        for(int j = 0; j < grid; j++)
            box_color[i][j] = Color(BLUE);
            
    
    // Initialize and store the boxes.
    Rectangle box[grid][grid];
    for(int i = 0; i < grid; i++)
        for(int j = 0; j < grid; j++)
            box[i][j] = {0, 0, float(cell_size - 5), float(cell_size - 5)};
    
    InitWindow(screen_width, screen_heigth, "Tic Tac Toe");
    SetTargetFPS(50);
    
    while(!WindowShouldClose()){
        mouse_pos = GetMousePosition();

        BeginDrawing();
            for(int rows = 0; rows < grid; rows++){
                for(int cols = 0; cols < grid; cols++){
                    if(CheckCollisionPointRec(mouse_pos, box[rows][cols]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        if(turn == -1 || turn == 1){
                            box_color[rows][cols] = Color(GREEN);
                            turn = 0;
                        }

                        else if(turn == 0){
                            box_color[rows][cols] = Color(RED);
                            turn = 1;
                        }
                    }

                    DrawRectangleRec(box[rows][cols], box_color[rows][cols]);
                    box[rows][cols].x = rows * cell_size;
                    box[rows][cols].y = cols * cell_size;
                }
            }

            // Winning Logic
            for(int rows = 0; rows < grid; rows++){
                for(int cols = 0; cols < grid; cols++){
                    if(box_color[rows][0].a == green_color.a &&
                       box_color[rows][0].b == green_color.b &&
                       box_color[rows][0].g == green_color.g &&
                       box_color[rows][0].r == green_color.r &&

                       box_color[rows][1].a == green_color.a &&
                       box_color[rows][1].b == green_color.b &&
                       box_color[rows][1].g == green_color.g &&
                       box_color[rows][1].r == green_color.r &&

                       box_color[rows][2].a == green_color.a &&
                       box_color[rows][2].b == green_color.b &&
                       box_color[rows][2].g == green_color.g &&
                       box_color[rows][2].r == green_color.r
                    ){
                        cout << "Player 1 wins" << endl;
                        player_1 = true;
                    }

                    if(
                       box_color[rows][0].a == red_color.a &&
                       box_color[rows][0].b == red_color.b &&
                       box_color[rows][0].g == red_color.g &&
                       box_color[rows][0].r == red_color.r &&

                       box_color[rows][1].a == red_color.a &&
                       box_color[rows][1].b == red_color.b &&
                       box_color[rows][1].g == red_color.g &&
                       box_color[rows][1].r == red_color.r &&

                       box_color[rows][2].a == red_color.a &&
                       box_color[rows][2].b == red_color.b &&
                       box_color[rows][2].g == red_color.g &&
                       box_color[rows][2].r == red_color.r
                    ){
                        cout << "Player 2 wins" << endl;
                        player_2 = true;
                    }

                    if(
                       box_color[0][cols].a == green_color.a &&
                       box_color[0][cols].b == green_color.b &&
                       box_color[0][cols].g == green_color.g &&
                       box_color[0][cols].r == green_color.r &&

                       box_color[1][cols].a == green_color.a &&
                       box_color[1][cols].b == green_color.b &&
                       box_color[1][cols].g == green_color.g &&
                       box_color[1][cols].r == green_color.r &&

                       box_color[2][cols].a == green_color.a &&
                       box_color[2][cols].b == green_color.b &&
                       box_color[2][cols].g == green_color.g &&
                       box_color[2][cols].r == green_color.r
                    ){
                        player_1 = true;
                        cout << "Player 1 wins" << endl;
                    }

                    if(
                       box_color[0][cols].a == red_color.a &&
                       box_color[0][cols].b == red_color.b &&
                       box_color[0][cols].g == red_color.g &&
                       box_color[0][cols].r == red_color.r &&

                       box_color[1][cols].a == red_color.a &&
                       box_color[1][cols].b == red_color.b &&
                       box_color[1][cols].g == red_color.g &&
                       box_color[1][cols].r == red_color.r &&

                       box_color[2][cols].a == red_color.a &&
                       box_color[2][cols].b == red_color.b &&
                       box_color[2][cols].g == red_color.g &&
                       box_color[2][cols].r == red_color.r
                    ){
                        player_2 = true;
                        cout << "Player 2 wins" << endl;
                    }
                }
            }
            if(
                (
                    box_color[0][0].a == green_color.a &&
                    box_color[0][0].b == green_color.b &&
                    box_color[0][0].g == green_color.g &&
                    box_color[0][0].r == green_color.r &&

                    box_color[1][1].a == green_color.a &&
                    box_color[1][1].b == green_color.b &&
                    box_color[1][1].g == green_color.g &&
                    box_color[1][1].r == green_color.r &&

                    box_color[2][2].a == green_color.a &&
                    box_color[2][2].b == green_color.b &&
                    box_color[2][2].g == green_color.g &&
                    box_color[2][2].r == green_color.r
                )
                ||
                (
                    box_color[0][2].a == green_color.a &&
                    box_color[0][2].b == green_color.b &&
                    box_color[0][2].g == green_color.g &&
                    box_color[0][2].r == green_color.r &&

                    box_color[1][1].a == green_color.a &&
                    box_color[1][1].b == green_color.b &&
                    box_color[1][1].g == green_color.g &&
                    box_color[1][1].r == green_color.r &&

                    box_color[2][0].a == green_color.a &&
                    box_color[2][0].b == green_color.b &&
                    box_color[2][0].g == green_color.g &&
                    box_color[2][0].r == green_color.r
                )
            ){
                player_1 == true;
                cout << "Player 1 won" << endl;
            }

            if(
                (
                    box_color[0][0].a == red_color.a &&
                    box_color[0][0].b == red_color.b &&
                    box_color[0][0].g == red_color.g &&
                    box_color[0][0].r == red_color.r &&

                    box_color[1][1].a == red_color.a &&
                    box_color[1][1].b == red_color.b &&
                    box_color[1][1].g == red_color.g &&
                    box_color[1][1].r == red_color.r &&

                    box_color[2][2].a == red_color.a &&
                    box_color[2][2].b == red_color.b &&
                    box_color[2][2].g == red_color.g &&
                    box_color[2][2].r == red_color.r
                )
                ||
                (
                    box_color[0][2].a == red_color.a &&
                    box_color[0][2].b == red_color.b &&
                    box_color[0][2].g == red_color.g &&
                    box_color[0][2].r == red_color.r &&

                    box_color[1][1].a == red_color.a &&
                    box_color[1][1].b == red_color.b &&
                    box_color[1][1].g == red_color.g &&
                    box_color[1][1].r == red_color.r &&

                    box_color[2][0].a == red_color.a &&
                    box_color[2][0].b == red_color.b &&
                    box_color[2][0].g == red_color.g &&
                    box_color[2][0].r == red_color.r
                )
            ){
                player_2 == true;
                cout << "Player 2 won" << endl;
            }




        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
