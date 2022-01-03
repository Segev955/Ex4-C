#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

#define null 0

//pnode getNode(pnode *head, int id);
void free_edges(pnode edg);
void del_edge(pnode *head, int nodeId);

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
        if (dest == NULL) { //if not exist
            dest = (pnode) malloc(sizeof(node));
            dest->node_num = destid;
            dest->edges = NULL;
            dest->next = *head; //put n befor head
            *head = dest; // set n to be new head
        }
        //connect

        int w = -1;
        scanf("%d", &w);
        *e = (pedge) malloc(sizeof(edge));
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
    while ((*head) != NULL) {
        pedge e = (*head)->edges;
        while (e != NULL) {
            pedge t = e->next;
            free(e);
            e = t;
        }
        pnode t = (*head);
        (*head) = (*head)->next;
        free(t);
    }
    *head = NULL;
}

void free_edges(pnode edg) {
    if (edg->edges != NULL) {
        pedge temp = edg->edges;

        while (temp != NULL) {
            pedge p1 = NULL;
            p1 = temp;
            temp = temp->next;
            free(p1);
        }
    } else {
        free(edg->edges);
    }
}

void del_edge(pnode *head, int nodeId) {
    pnode tempNode = *head;

    while (tempNode != NULL) {
        if (tempNode->node_num != nodeId && tempNode->edges != NULL) {

            if (tempNode->edges->endpoint->node_num != nodeId) {
                pedge tempEdge = tempNode->edges;

                while (tempEdge->next != NULL) {
                    if (tempEdge->next->endpoint->node_num == nodeId) {
                        pedge p1 = tempEdge->next;
                        tempEdge->next = tempEdge->next->next;
                        free(p1);
                        break;
                    }
                    tempEdge = tempEdge->next;
                }
            } else {
                if (tempNode->edges->next == NULL) {
                    pedge p1 = tempNode->edges;
                    tempNode->edges = NULL;
                    free(p1);
                } else {
                    pedge p1 = tempNode->edges;
                    tempNode->edges = p1->next;
                    free(p1);
                }
            }
        }
        tempNode = tempNode->next;
    }
}

void delete_node_cmd(pnode *head) {
    int D = 0;
    scanf("%d", &D);
    del_edge(head, D);
    pnode tempNode = *head;
    node *p = NULL;
    if (tempNode->node_num != D) {
        while (tempNode->next->node_num != D) {
            tempNode = tempNode->next;
        }
        p = tempNode->next;
        tempNode->next = tempNode->next->next;
        free_edges(p);
        free(p);
    } else {
        p = *head;
        *head = p->next;
        free_edges(p);
        free(p);
    }
}