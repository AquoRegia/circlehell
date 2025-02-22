#ifndef LISTOFCIRC_H
#define LISTOFCIRC_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/raylib.h"

extern float theta_val;
extern float* theta;
extern float phi;
extern int coeff;
extern int crazy;
extern Color circ_color;

/*typedef struct circle
{
    Color color;
    float r;

}circle;

typedef struct link
{
    float length;
    float angle;
}circlink;
*/

typedef struct circnode
{
    struct circnode* prev;
    //circle* circle;
    //circlink* link;
    struct circnode* next;
    float px;
    float py;
    float angle;
    int coeff;
}circnode;


typedef struct listofcirc
{
    circnode* head;
    circnode* tail;
}listofcirc;

listofcirc* create_circlist();

void addto_circlist(listofcirc* circlist, float phi, int coeff);

void remove_circlist(listofcirc* circlist);

void delete_circlist(listofcirc* circlist);

float rand_angle();

void update_theta(float *theta);

void update_p(listofcirc* circlist, float theta_val);

void d_frame(listofcirc* circlist, Color color);

int rand_coeff();


#endif