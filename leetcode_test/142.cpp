#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                ListNode *index1 = fast, *index2 = head;
                while(index1 !=index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;

    }
};

int main(int argc, char const *argv[])
{
    ListNode *p, *head = new ListNode(3);
    p = head;
    p->next = new ListNode(2);
    auto tmp = p->next;
    p = p->next;
    p->next = new ListNode(0);
    p = p->next;
    p->next = new ListNode(-4);
     p = p->next;
    p->next = tmp;

    Solution mysol;
    auto r = mysol.detectCycle(head);
    cout << r->val << endl;


    return 0;
}
