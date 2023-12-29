
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
#include <iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * fake_header = new ListNode();
        fake_header -> next = head;
        ListNode *pre = head,*ppv = fake_header,*cur;
        if(head != nullptr) cur = head->next;
        else return head;
        while(cur != nullptr){
            pre->next = cur->next;
            ppv->next = cur;
            cur->next = pre;
            ppv = pre;
            pre = pre->next;
            if(pre != nullptr)cur = pre->next;
            else break;
        }
        return fake_header->next;
    }
};
int main(){
    
    return 0 ;
}