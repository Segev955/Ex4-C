#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

#define infinity 20000000


typedef struct dijkstra_graph {
    pnode node;
    int tag;
    int weight;
    int done; //done == 1
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
        (*temp)->done = 0;
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


void freeList(pcopy list) {
    while (list != NULL) {
        pcopy t = list->next;
        free(list);
        list = t;

    }
    free(list);
}

pcopy listMin(pcopy list) {
    int min = infinity;
    pcopy key = NULL;
//    list = list->next;
    while (list != NULL) {
        if (list->done == 1) {
            list = list->next;
            continue;
        }
        if (list->weight < min) {
            min = list->weight;
            key = list;
        }
        list = list->next;
    }
    if (key != NULL) {
        key->done = 1;
    }
    return key;
}


void dijkstra(pcopy l) {
    pcopy cn = listMin(l);
    while (cn != NULL) {
        pedge e = cn->node->edges;
        while (e != NULL) {
            pcopy dest = getPCopyNode(l, e->endpoint->node_num);
            if (dest->weight > cn->weight + e->weight) { //if des_weight > src_weight + edges_weight
                dest->weight = cn->weight + e->weight; //des_weight = src_weight + edges_weight
                dest->tag = cn->node->node_num; //des_tag = src
            }
            e = e->next;
        }
        cn = listMin(l);
    }
}

int shortsPath_cmd(pnode head, int src, int dest) {
    pcopy l = copyg(head, src);
    dijkstra(l);
    pcopy xNode = getPCopyNode(l, dest);
    int dis = xNode->weight;
    if (dis == infinity) {
        freeList(l);
        return -1;
    }
    freeList(l);
    return dis;
}


int *newArr(int n) {
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

/*void clearArr(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        *(arr + i) = -1;
    }
}

int arrempty(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] != -1) {
            return 1;
        }
    }
    return 0;
}

void getDads(int *arr, int src, int dest, int n, pcopy l) {
    for (int i = 0; i < n || src != dest; ++i) {
        arr[i] = dest;
        dest = getPCopyNode(l, dest)->tag;
    }
}

void extendArr(int *dest, int *src, int n) {
    for (int i = 0; i < n; ++i) {
        dest[i] = src[i];
    }
}

void shortsPathTSP(pnode *head, int src, int dest, int *tempLst, int *dis) {
    pcopy l = copyg(*head, src);
    dijkstra(l);
    pcopy xNode = getPCopyNode(l, dest);
    *dis = xNode->weight;
    tempLst[0] = dest;
    int i = 1;
    while (xNode->node->node_num != src) {
        if (xNode->weight == infinity) {
            break;
        }
        tempLst[i] = xNode->tag;
        xNode = getPCopyNode(l, xNode->tag);
        i++;
    }

}*/
void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

int TSP_cmd(pnode *head) {
    int listSize;
    scanf("%d", &listSize);
    int *node_lst = newArr(listSize);
    int finalDis = infinity;
    int bool = 0;

    for (int i = 1; i <= listSize; ++i) { //nodeList
        for (int j = 0; j < listSize - 1; ++j) {
            swap(&(node_lst[j]), &(node_lst[j + 1]));
            int path = 0;
            int bool2 = 1;
            for (int k = 0; k < listSize - 1; ++k) {
                int dist = shortsPath_cmd(*head, *(node_lst + k), *(node_lst + (k + 1)));
                if (dist == -1) {
                    bool2 = 0;
                    break;
                }
                path += dist;
            }
            if (path < finalDis && path != 0 && bool2) {
                finalDis = path;
                bool = 1;
            }
        }
    }
    free(node_lst);
    if (!bool)
        return -1;
    return finalDis;

}
/*int TSP_cmd(pnode *head) {
    int listSize;
    scanf("%d", &listSize);
    int *node_lst = newArr(listSize);
    int *newLst = (int *) malloc(sizeof(int) * listSize);
    int finaldis2 = infinity;
    for (int i = 0; i < listSize; ++i) { //nodeList
        int s = node_lst[i];
        extendArr(newLst, node_lst, listSize);
        newLst[i] = -1;
        int finaldis = 0;
        while (arrempty(newLst, listSize)) { //newLst
            int min = infinity;
            int index = -1;
            int dest = -1;
            int bool = 0;
            for (int j = 0; j < listSize; ++j) {
                if (newLst[j] == -1)
                    continue;
                int dis = shortsPath_cmd(head, s, newLst[j]);
                if (dis == -1)
                    break;
                if (dis < min) {
                    bool = 1;
                    min = dis;
                    dest = newLst[j];
                    index = j;
                }
            }
            if (bool) {
                finaldis += min;
                s = dest;
                newLst[index] = -1;
            }
        }
        if (finaldis < finaldis2 && finaldis != 0) {
            finaldis2 = finaldis;
        }
    }
    return finaldis2;
}*/
/*int TSP_cmd(pnode *head) {
    int listSize;
    scanf("%d", &listSize);
    int *node_lst = newArr(listSize);
    int *finalLst = (int *) malloc(sizeof(int));
    int *newLst = (int *) malloc(sizeof(int));
    int finalDis2 = 0; //final
    for (int i = 0; i < listSize; ++i) { //nodeList
        int finalDis = 0;
        int s = node_lst[i];
        int *lst = (int *) malloc(sizeof(int));
        extendArr(newLst,node_lst,listSize);
        int index = -1;
        while(arrempty(newLst,listSize)) { //newLst
            int *tempLst2 = (int *) malloc(sizeof(int));
            int bool = 0;
            int dis = infinity;
            int min = infinity;
            for (int j = 0; j < listSize; ++j) {
                if (newLst[j] ==-1)
                    continue;
                int *tempLst = (int *) malloc(sizeof(int));
                shortsPathTSP(head,s,newLst[j],tempLst,&dis);
                if (dis == infinity) {
                    return -1;
                }
                if (dis < min) {
                    bool = 1;
                    min = dis;
                    extendArr(tempLst2,tempLst,listSize);
                    index = j;
                }
                free(tempLst);
            }
            if (bool == 1) {
                finalDis += min;
                s = newLst[index];
                newLst[index] = -1;
                extendArr(lst,tempLst2, listSize);
                free(tempLst2);
            }
        }
        if (finalDis2 < finalDis) {
            finalDis2 = finalDis;
            free(lst);
        }
    }
    free(newLst);
    free(node_lst);
    free(finalLst);
    return finalDis2;
}*/






