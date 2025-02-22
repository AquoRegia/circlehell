#include "listofcirc.h"
#include <stdio.h>
#include <stdlib.h>
#include "include/raylib.h"

void update_p(listofcirc* circlist, float theta_val){
     if (circlist->head->next==NULL){
        return;
    }
    circnode* temp1 = circlist->head->next;
    temp1 ->px = roundf(circlist->head->px + 30 * cos(temp1->angle + theta_val));
    temp1 ->py = roundf(circlist ->head->py + 30 * sin(temp1->angle + theta_val));
    while(temp1->next != NULL){
        circnode* temp2 = temp1->next;
        temp2 ->px = roundf(temp1->px + 30 * cos(temp2->angle + (temp2->coeff*theta_val)));
        temp2 ->py = roundf(temp1->py + 30 * sin(temp2->angle + (temp2->coeff*theta_val)));
        temp1 = temp1->next;
    }

}

void d_frame(listofcirc* circlist, Color color){
    DrawCircle(500, 400, 10, color);
    if (circlist->head->next==NULL){
        return;
    }
    circnode* temp1 = circlist->head->next;
    DrawLine(500,400,temp1->px,temp1->py,BLACK);
    DrawCircle(temp1->px, temp1->py, 10, color);
    while(temp1->next != NULL){
        circnode* temp2 = temp1->next;
        DrawLine(temp1->px,temp1->py,temp2->px,temp2->py,BLACK);
        DrawCircle(temp2->px, temp2->py, 10, color);
        temp1 = temp1->next;
    }
    
}