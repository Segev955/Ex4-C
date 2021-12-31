#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct graph_copy {
    int node_num;
    pedge edges;
    int tag;
    struct graph_copy *next;
} copy, *pcopy;

pcopy copyg(pnode *head, int size){
    pcopy *c;
    c= malloc(sizeof(head)*size);
    if(c==NULL){
        printf("memory allocation failed");
        exit(1);
    }

}

void maxVal(pcopy *head){
    while((*head)->next!=NULL){
        (*head)->tag=-1;
        (*head)->
    }
}


