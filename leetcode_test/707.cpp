#include <iostream>
using namespace std;
class MyLinkedList {
public:
     struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };
    MyLinkedList() {
        size = 0;
        fake_header = new LinkedNode(0);
    }
    
    int get(int index) {
        if(index >= size-1) return -1;
        LinkedNode * p = fake_header;
        for(int i = 0;i<index;i++)
            p = p->next;
        return p->next->val;
    }
    
    void addAtHead(int val) {
        LinkedNode * tmp = new LinkedNode(val);
        tmp->next = fake_header->next;
        fake_header->next = tmp;
        size++;
    }
    
    void addAtTail(int val) {
        LinkedNode * tmp = new LinkedNode(val),*p = fake_header;
        while(p->next != nullptr) p=p->next;
        p->next = tmp;
        size ++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        LinkedNode * tmp = new LinkedNode(val), *p = fake_header;
        for(int i = 0;i<index;i++) p = p->next;
        tmp->next = p->next;
        p->next = tmp;
        size ++;
        
      
        
    }
    
    void deleteAtIndex(int index) {
        if(index > size-1) {

            return;
        }
        LinkedNode *p = fake_header;
        for(int i = 0;i<index;i++) p = p->next;
        LinkedNode * tmp = p->next;
        if(p->next->next != nullptr)
            p->next = p->next->next;
        else p->next = nullptr;
        delete tmp;
        size --;
    }
private:
    LinkedNode *fake_header;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    MyLinkedList list;
    // list.addAtHead(7);
    // list.addAtHead(2);
    // list.addAtHead(1);
    // list.addAtIndex(3,0);
    // list.deleteAtIndex(2);
    // list.addAtHead(6);
    // list.addAtTail(4);
    // list.get(4);
    // list.addAtHead(4);
    // list.addAtIndex(5,0);
    // list.addAtHead(6);

        list.addAtHead(1);
            list.addAtTail(3);
                list.addAtIndex(1,2);
                    list.get(1);
                        list.deleteAtIndex(1);
                            list.get(1);




}