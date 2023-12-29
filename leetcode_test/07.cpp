/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdlib>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode  *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = 0, b = 0;
        ListNode *pa = headA, *pb = headB;
        while(pa != NULL || pb != NULL){
            if(pa != NULL){
                a++;
                pa = pa->next;
            }
            if(pb != NULL){
                b++;
                pb = pb->next;
            }
        }
        pa = headA, pb = headB;
        int diff = a - b;
        if(diff > 0)
            while(diff > 0) {
                pa = pa->next;
                diff --;
            }
        else
            while(diff < 0){
                pb = pb->next;
                diff ++;
            }
        while(pa != NULL){
            if(pa == pb) return pa;
            pa = pa->next;
            pb = pb->next;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    ListNode *a, *headA = new ListNode(4);
    ListNode *b, *headB = new ListNode(5);
    a = headA, b = headB;
    a->next = new ListNode(1);
    a = a->next;
    a->next = new ListNode(8);
    a = a->next;
    a->next = new ListNode(4);
    a = a->next;
    a->next = new ListNode(5);
    a = a->next;

    b->next = new ListNode(0);
    b = b->next;
    b->next = new ListNode(1);
    b = b->next;
    b->next = new ListNode(8);
    b = b->next;
    b->next = new ListNode(4);
    b = b->next;
    b->next = new ListNode(5);
    b = b->next;

    Solution mysoul;
    mysoul.getIntersectionNode(headA,headB);
    cout << "666" << endl;
    return 0;
}
