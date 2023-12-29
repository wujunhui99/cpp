#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}NODE;
int length(NODE *list){
    int i = 0;
    while(list->next != NULL)
        i++;
    return i;
}
void append(NODE *n1,NODE *n2){
    NODE *tmp = n2->next;
    n2->next = n2->next->next; 
    tmp->next = n1->next;
    n1->next = tmp;
}
void change_list(NODE *h){
    int n = length(h);
    NODE *mid = h,*p1 = h,*p2 = h;
    for(int i = 0;i<n/2 - 1;i++)
        mid = mid ->next;
    p2 = mid;
    while(p2->next!=NULL){
        append(mid,p2);
        p2++;
    }
    while(mid->next!=NULL){
        p1=p1->next;
        append(p1,mid);
        mid=mid->next;
        p1=p1->next;
    }
}