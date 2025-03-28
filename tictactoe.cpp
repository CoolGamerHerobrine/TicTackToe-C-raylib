#include <raylib.h>


const int screen_width = 800;
const int screen_heigth = 800;
const int grid = 3;


class TicTacToe{
    private:
        const int cell_size = screen_width / grid;
        Rectangle cell_rec[grid][grid];
        Color grid_color[grid][grid];

        Vector2 mouse_pos;
        int turn = -1;
        Color green_data = GREEN;
        Color purple_data = PURPLE;

        bool player_1 = false;
        bool player_2 = false;
    
    public:
        TicTacToe();
        void draw();
        void update();
        void check_win();
};

TicTacToe :: TicTacToe(){
    for(int i = 0; i < grid; i++){
        for(int j = 0; j < grid; j++){
            grid_color[i][j] = BLUE;

            cell_rec[i][j].x = i * cell_size;
            cell_rec[i][j].y = j * cell_size;

            cell_rec[i][j].height = cell_size - 5;
            cell_rec[i][j].width = cell_size - 5;
        }
    }
}

void TicTacToe :: draw(){
    BeginDrawing();
        for(int rows = 0; rows < grid; rows++)
            for(int cols = 0; cols < grid; cols++)
                DrawRectangleRec(cell_rec[rows][cols], grid_color[rows][cols]);
            
        if(player_1 == true){
            DrawRectangle(0, 0, screen_width, screen_heigth, DARKGRAY);
            DrawText("Player 1 or the Green player won the game", (screen_width / 6) - 100, (screen_heigth / 2) - 50, 32, DARKGREEN);
        }
        
        if(player_2 == true){
            DrawRectangle(0, 0, screen_width, screen_heigth, DARKGRAY);
            DrawText("Player 2 or the Purple player won the game", (screen_width / 6) - 100, (screen_heigth / 2) - 50, 32, DARKGREEN);
    }
    
    EndDrawing();
}

void TicTacToe :: update(){
    mouse_pos = GetMousePosition();
    for(int rows = 0; rows < grid; rows++){
        for(int cols = 0; cols < grid; cols++){

            if(CheckCollisionPointRec(mouse_pos, cell_rec[rows][cols]) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if((turn == -1) || (turn == 1)){
                    grid_color[rows][cols] = Color(GREEN);
                    turn = 0;
                }
                else if(turn == 0){
                    grid_color[rows][cols] = Color(PURPLE);
                    turn = 1;
                }
            }
        }
    }
}

void TicTacToe :: check_win(){

    // Diagonals
    if(
        grid_color[0][0].a == green_data.a &&
        grid_color[0][0].b == green_data.b &&
        grid_color[0][0].g == green_data.g &&
        grid_color[0][0].r == green_data.r &&

        grid_color[1][1].a == green_data.a &&
        grid_color[1][1].b == green_data.b &&
        grid_color[1][1].g == green_data.g &&
        grid_color[1][1].r == green_data.r &&

        grid_color[2][2].a == green_data.a &&
        grid_color[2][2].b == green_data.b &&
        grid_color[2][2].g == green_data.g &&
        grid_color[2][2].r == green_data.r
    ){
        player_1 = true;
    }

    if(
        grid_color[0][0].a == purple_data.a &&
        grid_color[0][0].b == purple_data.b &&
        grid_color[0][0].g == purple_data.g &&
        grid_color[0][0].r == purple_data.r &&

        grid_color[1][1].a == purple_data.a &&
        grid_color[1][1].b == purple_data.b &&
        grid_color[1][1].g == purple_data.g &&
        grid_color[1][1].r == purple_data.r &&

        grid_color[2][2].a == purple_data.a &&
        grid_color[2][2].b == purple_data.b &&
        grid_color[2][2].g == purple_data.g &&
        grid_color[2][2].r == purple_data.r
    ){
        player_2 = true;
    }

    if(
        grid_color[0][2].a == green_data.a &&
        grid_color[0][2].b == green_data.b &&
        grid_color[0][2].g == green_data.g &&
        grid_color[0][2].r == green_data.r &&

        grid_color[1][1].a == green_data.a &&
        grid_color[1][1].b == green_data.b &&
        grid_color[1][1].g == green_data.g &&
        grid_color[1][1].r == green_data.r &&

        grid_color[2][0].a == green_data.a &&
        grid_color[2][0].b == green_data.b &&
        grid_color[2][0].g == green_data.g &&
        grid_color[2][0].r == green_data.r
    ){
        player_1 = true;
    }

    if(
        grid_color[0][2].a == purple_data.a &&
        grid_color[0][2].b == purple_data.b &&
        grid_color[0][2].g == purple_data.g &&
        grid_color[0][2].r == purple_data.r &&

        grid_color[1][1].a == purple_data.a &&
        grid_color[1][1].b == purple_data.b &&
        grid_color[1][1].g == purple_data.g &&
        grid_color[1][1].r == purple_data.r &&

        grid_color[2][0].a == purple_data.a &&
        grid_color[2][0].b == purple_data.b &&
        grid_color[2][0].g == purple_data.g &&
        grid_color[2][0].r == purple_data.r
    ){
        player_2 = true;
    }

    // Now loops
    for(int rows = 0; rows < grid; rows++){
        for(int cols = 0; cols < grid; cols++){

            // Rows
            if(
                grid_color[0][cols].a == green_data.a &&
                grid_color[0][cols].b == green_data.b &&
                grid_color[0][cols].g == green_data.g &&
                grid_color[0][cols].r == green_data.r &&

                grid_color[1][cols].a == green_data.a &&
                grid_color[1][cols].b == green_data.b &&
                grid_color[1][cols].g == green_data.g &&
                grid_color[1][cols].r == green_data.r &&

                grid_color[2][cols].a == green_data.a &&
                grid_color[2][cols].b == green_data.b &&
                grid_color[2][cols].g == green_data.g &&
                grid_color[2][cols].r == green_data.r 
            ){player_1 = true;}

            if(
                grid_color[0][cols].a == purple_data.a &&
                grid_color[0][cols].b == purple_data.b &&
                grid_color[0][cols].g == purple_data.g &&
                grid_color[0][cols].r == purple_data.r &&

                grid_color[1][cols].a == purple_data.a &&
                grid_color[1][cols].b == purple_data.b &&
                grid_color[1][cols].g == purple_data.g &&
                grid_color[1][cols].r == purple_data.r &&

                grid_color[2][cols].a == purple_data.a &&
                grid_color[2][cols].b == purple_data.b &&
                grid_color[2][cols].g == purple_data.g &&
                grid_color[2][cols].r == purple_data.r          
            ){player_2 = true;}

            // Columns
            if(
                grid_color[rows][0].a == green_data.a &&
                grid_color[rows][0].b == green_data.b &&
                grid_color[rows][0].g == green_data.g &&
                grid_color[rows][0].r == green_data.r &&

                grid_color[rows][1].a == green_data.a &&
                grid_color[rows][1].b == green_data.b &&
                grid_color[rows][1].g == green_data.g &&
                grid_color[rows][1].r == green_data.r &&

                grid_color[rows][2].a == green_data.a &&
                grid_color[rows][2].b == green_data.b &&
                grid_color[rows][2].g == green_data.g &&
                grid_color[rows][2].r == green_data.r 
            ){player_1 = true;}

            if(
                grid_color[rows][0].a == purple_data.a &&
                grid_color[rows][0].b == purple_data.b &&
                grid_color[rows][0].g == purple_data.g &&
                grid_color[rows][0].r == purple_data.r &&

                grid_color[rows][1].a == purple_data.a &&
                grid_color[rows][1].b == purple_data.b &&
                grid_color[rows][1].g == purple_data.g &&
                grid_color[rows][1].r == purple_data.r &&

                grid_color[rows][2].a == purple_data.a &&
                grid_color[rows][2].b == purple_data.b &&
                grid_color[rows][2].g == purple_data.g &&
                grid_color[rows][2].r == purple_data.r          
            ){player_2 = true;}
        }        
    }
}

int main(){
    TicTacToe game;
    InitWindow(screen_width, screen_heigth, "TicTacToe");
    SetTargetFPS(30);

    while(!WindowShouldClose()){
        game.draw();
        game.update();
        game.check_win();
    }
    CloseWindow();
    return 0;
}
