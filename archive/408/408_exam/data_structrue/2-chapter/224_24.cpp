#include <stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;
void RemoveSame(LinkList &list, int n){
    int tags[n+1];
    LNode *p = list;
    for(int i = 0;i<n+1;i++) tags[i] = 0;
    while(p->next != NULL){
        if(tags[p->next->data]){
            LNode *q = p->next;
            p->next = p->next->next;
            free(q);
        }
        else
           tags[p->next->data] = 1; 
        p = p->next;
    }
}