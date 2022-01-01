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

pnode copy(pnode *head, int gsize) {
    for (int i = 0; i < gsize; i++) {

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

void delete_node_cmd(pnode *head) {
    int id = -1;
    scanf("%d", &id);
    pnode n = getNode(head, id);
    //node i = *head;
    if (n != NULL) {
        while ((*head) != NULL) {
            if ((*head)->next->node_num == id) {
                pnode j = (*head)->next;
                (*head)->next = j->next;
                pedge e = j->edges;
                pedge n;
                while (e != NULL) {
                    n = e;
                    e = e->next;
                    free(n);
                }
                free(j);
            }
            (*head)=(*head)->next;
        }
    }
}

void deleteGraph_cmd(pnode *head) {
    while (*head != NULL) {
        delete_node_cmd(head);
    }
}

/*void shortsPath_cmd(pnode head) {
    int src = null, dest = null;
    scanf("%d%d", &src, &dest);
    if (src == dest) {
        printf("%d", null);
        return;
    }

}*/

//void delete_node(pnode *head){
//    int id=-1;
//    scanf("%d",&id);
//    while((*head)->node_num != id){
//        if((*head)->next->node_num ==id){
//            pedge e= (*head)->next->edges;
//            while(e->next ==NULL )
//        }
//    }
//}


