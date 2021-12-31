#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#define null 0
pnode getNode(pnode* head, int id);

int size=0;

void build_graph_cmd(pnode *head) {
    deleteGraph_cmd(head);
    int nodesize = null;
    scanf("%d", &nodesize);
    char n = 'n';
    int x = 0;
    for (int i = 0; i < nodesize; i++) {
        scanf("%c", &n);
        insert_node_cmd(head);
        size++;
    }
}

pnode copy(pnode *head,int gsize){
    for(int i=0; i < gsize;i++){

    }
}

void insert_node_cmd(pnode *head) {
    int id = -1;
    scanf("%d", &id);
    pnode n = getNode(head,id);
    
    if (n == NULL) {
        n = (pnode)malloc(sizeof(node));
        n->node_num = id;
        n->edges = NULL;
        n->next = *head; //put n befor head
        *head = n; // set n to be new head
        size++;
    }
    else { //if node exist
        pedge e = n->edges;
        while (e != NULL) {
            pedge t = e->next;
            free(e);
            e = t;
            size--;
        }
    }
    int destid = -1;
    while(scanf("%d", &destid) != null) {
        pnode dest = getNode(head,destid);
        int w = -1;
        scanf("%d", &w);
        pedge edg = (pedge)malloc(sizeof(edge));
        edg->weight = w;
        edg->endpoint = dest;
        edg->next = NULL;
    }
    
}




pnode getNode(pnode* head, int id) {
    pnode i = *head;
    while (i != NULL) {
        if (i->node_num == id) {
            return i;
        } 
        else {
            i = i->next;
        }
    }
    return NULL;
}

void delete_node_cmd(pnode *head){
    int id;
    scanf("%d",id);
    pnode i= *head;
    if(!getNode(head,id)) {
        while (i->node_num != id) {
            if(i->next->node_num==id){
                pnode j=i->next;
                i->next=j->next;
                pedge e= j->edges;
                pedge n;
                while (e!=NULL){
                    n=e;
                    e=e->next;
                    free(n);
                    size--;
                }
                free(j);
            }
        }
    }
}

void deleteGraph_cmd(pnode* head){
    while ((*head)->next!=NULL){
        delete_node_cmd(head);
    }
    size=0;
}

void shortsPath_cmd(pnode head){
    int src=null ,dest=null;
    scanf("%d%d", &src, &dest);
    if(src==dest) {
        printf("%d", null);
        return;
    }

}




