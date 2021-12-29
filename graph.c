#include <stdio.h>


void build_graph_cmd(pnode *head) {
    deleteGraph_cmd(head);
    int nodesize = 0;
    scanf("%d", &nodesize);
    char n = 'n';
    int x = 0;
    for (int i = 0; i < size; i++) {
        scanf("%c", &n);
        insert_node_cmd(head);
    }
}


void insert_node_cmd(pnode *head) {
    int id = -1;
    scanf("%d", &id);
    pnode n = getNode(head,id);
    
    if (n == NULL) {
        n = (pnode)malloc(sizeof(node))
        n->node_num = id;
        n->edges = NULL;
        n->next = head; //put n befor head
        *head = n; // set n to be new head
    }
    else { //if node exist
        pedge e = n->edges
        while (e != NULL) {
            pedge t = e->next;
            free(e);
            e = t;
        }
    }
    int destid = -1;
    while(scanf("%d", &destid) != NULL) {
        dest = getNode(head,destid);
        int w = -1;
        scanf("%d", &w);
        edg = (pedge)malloc(sizeof(edge));
        edg->weight = w;
        edg->endpoint = dest;
        edg->next = ;
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


