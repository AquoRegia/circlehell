#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "include/raylib.h"
#include "listofcirc.h"
#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

float phi;
int coeff;
int crazy = 1;
Color circ_color = DARKBLUE;


float rand_angle(){
    return (float)rand() / RAND_MAX * (2.0f * PI);
}
int rand_coeff(){
    return (int)(rand() % 5)+1;
}

float theta_val = 0.0f;
float* theta = &theta_val;

void update_theta(float *theta){
    *theta +=  1.f * crazy * GetFrameTime();  
    if (*theta > 2.0f * PI) {
        *theta -= 2.0f * PI; 
    }
}


int main()
{

    srand(time(NULL));

    listofcirc* thelist = create_circlist();

    InitWindow(1000,  800, "Circle Hell");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        update_theta(theta);
        
        if (crazy > 1){
            circ_color = RED;
        }
        
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        update_p(thelist, theta_val);

        if (IsKeyDown(KEY_UP)){
            phi = rand_angle();
            coeff = rand_coeff();
            addto_circlist(thelist,phi,coeff);
        }
        if (IsKeyDown(KEY_DOWN)){
            if(crazy==1){
            remove_circlist(thelist);
            }
        }
        
        d_frame(thelist, circ_color);
        DrawText(TextFormat("Theta: %.2f", theta_val), 10, 10, 20, BLACK);
        DrawText("Add Circle: Arrow up", 10, 40, 20, BLACK);
        DrawText("Remove Circle: Arrow down", 10,70, 20, BLACK);
        

        if (crazy==1){
            if (GuiButton((Rectangle) {10,100,100,30}, "CRAZY MODE")){
                crazy = 2;
                } 
        }
        if (crazy==2){
            if (GuiButton((Rectangle) {890,10,100,30}, "GO BACK")){
                crazy = 3;
                } 
        }
        if (crazy==3){
            DrawText("THERE IS NO GOING BACK BITCH!", 10,120, 40, RED);
        }
       
        EndDrawing();
    }

    CloseWindow();
    delete_circlist(thelist);





     
}


//gcc main.c listofcirc.c framedrawer.c -o lol.exe -Iinclude -Llib -lraylib -lm -lwinmm -lgdi32