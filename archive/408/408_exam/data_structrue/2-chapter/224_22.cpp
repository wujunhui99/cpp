#include <stdlib.h>
#include <stdio.h>
typedef struct LNode{
    int data;
    struct LNode *link;
}LNode, *LinkList;
int FindK(LinkList &List, int k){
    LNode *p1 = List, *p2 = List;
    for(int i = 0;i<k - 1;i++) //p1 foreach front k,start with the first,need for k-1
        if(p1->link != NULL) p1 = p1->link;
        else return 0;
    while (p1 -> link != NULL)
    {
        p1 = p1->link;
        p2= p2->link;
    }
    printf("%d",p2->data);
    return 1;
}
int main(){
    LNode l1;
    return 0;
}