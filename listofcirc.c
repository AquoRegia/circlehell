#include "listofcirc.h"



listofcirc* create_circlist(){
    listofcirc* circlist = (listofcirc*)malloc(sizeof(listofcirc));
    circnode* newnode = (circnode*)malloc(sizeof(circnode));
    newnode -> px = 500; 
    newnode-> py = 400;
    newnode -> prev = NULL;
    newnode ->next = NULL;
    newnode -> coeff = 0;
    newnode->angle= 0;
    circlist ->head = newnode;
    circlist ->tail = newnode;
    return circlist;
}


void addto_circlist(listofcirc* circlist, float phi, int coeff){
    circnode* newnode = (circnode*)malloc(sizeof(circnode));
    circlist ->tail->next = newnode;
    newnode ->prev = circlist ->tail;
    newnode ->next = NULL;
    newnode->angle= phi;
    newnode -> coeff = coeff;
    newnode ->px = (circlist ->tail->px + 30 * cos(phi));
    newnode ->py = (circlist ->tail->py + 30 * sin(phi));
    circlist -> tail = newnode;
}

void remove_circlist(listofcirc* circlist){
    if(circlist->head == circlist->tail) {
        return;
    }
    circnode* temp = circlist ->tail;
    if (temp->prev==NULL)
    {
        return;
    }
    
    circlist->tail = temp->prev;
    temp->prev->next = NULL;
    free(temp);
}

void delete_circlist(listofcirc* circlist){
    circnode* temp = circlist->tail;
    while(temp->prev != NULL){
        circnode* temp1 = temp;
        temp = temp->prev;
        free(temp1);
    }
    free(circlist->head);
    free(circlist);
    /*circnode* temp = circlist->tail
    while(temp-> prev != NULL){
        circlist->tail = temp->prev;
        temp->prev->next = NULL;
        free(temp);
        circnode* temp = circlist ->tail;
    }  
    free(circlist->head);
    free(circlist->tail);
    free(circlist);*/
}
