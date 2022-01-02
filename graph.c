#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

#define null 0

pnode getNode(pnode *head, int id);

int size = 0;

void build_graph_cmd(pnode *head) {
    deleteGraph_cmd(head);
    int nodesize = null;
    scanf("%d", &nodesize);
    char n = 'n';
    scanf("%c", &n);
    for (int i = 0; i < nodesize; i++) {
        scanf("%c", &n);
        insert_node_cmd(head);
    }
}


void printGraph_cmd(pnode head)
{
    pnode nodeIndex = head;
    while (nodeIndex != NULL)
    {
        printf("Node %d: ", nodeIndex->node_num);
        pedge edgeIndex = nodeIndex->edges;
        while (edgeIndex != NULL)
        {
            printf("dest %d: weight %d, ", edgeIndex->endpoint->node_num, edgeIndex->weight);
            edgeIndex = edgeIndex->next;
        }
        printf("\n");
        nodeIndex = nodeIndex->next;
    }
}

void insert_node_cmd(pnode *head) {
    int id = -1;
    scanf("%d", &id);
    pnode n = getNode(head, id);

    if (n == NULL) {
        n = (pnode) malloc(sizeof(node));
        n->node_num = id;
        n->edges = NULL;
        n->next = *head; //put n befor head
        *head = n; // set n to be new head
    } else { //if node exist - delete edges out
        pedge e = n->edges;
        while (e != NULL) {
            pedge t = e->next;
            free(e);
            e = t;
        }
    }
    pedge *e = &(n->edges);
    int destid = -1;
    while (scanf("%d", &destid) != null) {
        if (destid == 'n') {
            break;
        }
        pnode dest = getNode(head, destid);
        if(dest == NULL) { //if not exist
            dest = (pnode) malloc(sizeof(node));
            dest->node_num = destid;
            dest->edges = NULL;
            dest->next = *head; //put n befor head
            *head = dest; // set n to be new head
        }
        //connect

        int w = -1;
        scanf("%d", &w);
        *e = (pedge)malloc(sizeof(edge));
        (*e)->endpoint = dest;
        (*e)->weight = w;
        (*e)->next = NULL;
        e = &((*e)->next);
    }
}


pnode getNode(pnode *head, int id) {
    pnode i = *head;
    while (i != NULL) {
        if (i->node_num == id) {
            return i;
        } else {
            i = i->next;
        }
    }
    return NULL;
}


void deleteGraph_cmd(pnode *head) {
    while (*head != NULL) {
        delete_node_cmd(head);
    }
}



void free_edges(pnode ptr){
    if(ptr->edges!=NULL)
    {
        pedge temp = ptr->edges;

        while(temp->next!=NULL)
        {
            pedge p1 = NULL;
            p1 = temp;
            temp = temp->next;
            free(p1);
        }
    }
}
void delete_edge(pnode *head,int id){
    pnode i = *head;
    while (i != NULL){
        if(i->node_num != id && i->edges != NULL){
            if(i->edges->endpoint->node_num != id){
                pedge tempEdge = i->edges;
                while (tempEdge->next!= NULL){
                    if(tempEdge->next->endpoint->node_num == id){
                        pedge p1 = tempEdge->next;
                        tempEdge->next=tempEdge->next->next;
                        free(p1);
                        break;
                    }
                    tempEdge = tempEdge->next;
                }
            }
            else{
                if(i->edges->next == NULL)
                {
                    pedge p1 = i->edges;
                    i->edges = NULL;
                    free(p1);
                }
                else{
                    pedge p1 = i->edges;
                    i->edges = p1->next;
                    free(p1);
                }
            }
        }
        i = i->next;
    }
}
void delete_node_cmd(pnode *head){
    int id = 0;
    scanf("%d",&id);
    delete_edge(head,id);
    pnode i = *head;
    node *ptr = NULL;
    if(i->node_num != id){
        while (i->next->node_num != id){
            i = i->next;
        }
        ptr = i->next;
        i->next=i->next->next;
        free_edges(ptr);
        free(ptr);
    }
    else{
        ptr = *head;
        *head = ptr->next;
        free_edges(ptr);
        free(ptr);
    }
}

