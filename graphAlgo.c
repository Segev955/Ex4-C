#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

#define infinity 20000000

#include <limits.h>

typedef struct dijkstra_graph {
    pnode node;
//    int node_num;
//    pedge edges;
    int tag;
    int weight;
    struct dijkstra_graph *next;
} copy, *pcopy;

pcopy copyg(pnode head, int src) {
    pcopy firstHead = NULL;
    pcopy *temp = &firstHead;
    while (head != NULL) {
        (*temp) = (pcopy) malloc(sizeof(copy));
        (*temp)->node = head;
        (*temp)->tag = -1;
        (*temp)->weight = infinity;
        if (head->node_num == src) {
            (*temp)->weight = 0;
        }
        (*temp)->next = NULL;

        head = head->next;
        temp = &((*temp)->next);
    }
    return firstHead;
}

pcopy getPCopyNode(pcopy head, int id) {
    pcopy i = head;
    while (i != NULL) {
        if (i->node->node_num == id) {
            return i;
        } else {
            i = i->next;
        }
    }
    return NULL;
}

pcopy listMin(pcopy list) {
    int min = list->weight;
    pcopy key = list;
    list = list->next;
    while (list != NULL) {
        if (list->weight < min) {
            min = list->weight;
            key = list;
        }
        list = list->next;
    }
    return key;
}


void dijkstra(int src, pnode g) {
    pcopy l = copyg(g,src);
    pcopy cn = listMin(l);
    while (cn != NULL) {
        pedge e = cn->node->edges;
        while (e != NULL) {
            pcopy dest = getPCopyNode(l,e->endpoint->node_num);
            if (dest->weight > cn->weight + e->weight) { //if des_weight > src_weight + edges_weight
                dest->weight = cn->weight + e->weight; //des_weight = src_weight + edges_weight
                dest->tag = cn->node->node_num; //des_tag = src
            }
            e = e->next;
        }
        cn = listMin(l);
    }
}

//void maxVal(pcopy *head) {
//    while ((*head)->next != NULL) {
//        (*head)->tag = -1;
//        (*head)->weight = infinity;
//    }
//}

int *newArr(int n) {
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

void clearArr(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        *(arr + i) = -1;
    }
}

int arrempty(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] != -1) {
            return 0;
        }
    }
    return 1;
}

void extendArr(int *arr, int src, int dest, int n) {
    int i = 0;
    while (src != dest) {
        arr[i] = dest;
        dest = dest->tag;
    }
}

int TSP_cmd(pnode head) {
    int n;
    scanf("%d", &n);
    int *node_lst = newArr(n);
    int *path = (int *) malloc(sizeof(int) * n);
    int *finalPath = (int *) malloc(sizeof(int) * n);
    int finalDis = INT_MAX;
    for (int i = 0; i < n; ++i) { //nodeList
        int dis = 0;
        int *newLst = (int *) malloc(sizeof(int) * n);
        memcpy(newLst, node_lst, sizeof(int) * n);
        int s = newLst[i];
        newLst[i] = -1;
        clearArr(path, n);
        while (arrempty(newLst, n)) {
            int maxDis = INT_MAX;
            int firstDis = 0;
            int *tempPath = (int *) malloc(sizeof(int) * n);
            for (int j = 0; j < n; ++j) { //newList
                firstDis = shortsPath(s, newLst[j]);
                if (firstDis < maxDis) {
                    clearArr(tempPath, n);
                    maxDis = firstDis;
                    extendArr(tempPath, s, newLst[j], n);

                }
            }
        }
    }
}






