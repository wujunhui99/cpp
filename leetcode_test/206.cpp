#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *fake_header = new ListNode();
        fake_header->next = head;
        ListNode *prev = head;
        if(prev == nullptr) return head;
        ListNode *cur = head->next;
        
        while(prev->next != nullptr){
            prev->next = cur->next;
            cur->next = fake_header->next;
            fake_header->next = cur;
            prev = prev->next;
            if(prev == nullptr) break;
            cur = prev->next;
        }
        return fake_header->next;

    }
};
int main(){
    ListNode*p, * head = new ListNode();
    head->val = 1;
    p =head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    Solution mysol;
    mysol.reverseList(head);

}