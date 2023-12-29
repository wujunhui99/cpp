#include <iostream>
using namespace std;
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *fake_head = new ListNode(val+1,head);
        ListNode *prev = fake_head, *current = head;
        while(current != nullptr){
            if(current->val == val){
                prev->next = current->next;
            }
            prev = prev->next;
            current = current->next;
            
        }
        return fake_head->next;
    }
};
int main(int argc, char const *argv[])
{
    ListNode *h = new ListNode(1,nullptr),*p = h;
    for(int i = 2;i<7;i++){
        p->next = new ListNode(i,nullptr);
        p=p->next;
    }
    Solution solution;
    solution.removeElements(h,4);
    for(auto p = h;p!=nullptr;p=p->next)
        cout << p->val << endl;
    return 0;
}
