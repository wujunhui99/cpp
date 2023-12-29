#include <stdlib.h>
typedef struct LNode{
    char data;
    struct LNode *next;
}LNode,*String;
int length(String str){
    int i = 0;
    while(str->next != NULL){
        i ++;
        str = str->next;
    }
    return i;
}
LNode* FindAddr(String str1, String str2){
    int s1 = length(str1);
    int s2 = length(str2);
    LNode *p1 = str1, *p2=str2;
    for(;s1>s2;s1--) p1 = p1->next;
    for(;s2>s1;s2--) p2 = p2->next;
    while(p1 != str2 && p1 != NULL && p2 != NULL){
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}