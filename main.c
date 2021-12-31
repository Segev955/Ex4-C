#include <stdio.h>
#include "graph.h"
int main() {
    char Case;
    int size;
    scanf("%c", &Case);
    pnode firstHead = NULL;
    pnode *head = &firstHead;
    switch (Case) {
        case 'A':
            build_graph_cmd(head);
            break;
        case 'B':
            insert_node_cmd(head);
            break;
        case 'D':
            delete_node_cmd(head);
            break;
        case 'S':
            shortsPath_cmd(head);
            break;
        case 'T':
            TSP_cmd(head);
            break;
        default:
            break;
    }
}
