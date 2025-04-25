
#include <iostream>

using namespace std;

struct ListNode{

  int val;
  ListNode* next;

  ListNode(): val(0), next(NULL) {}
  ListNode(int x): val(x), next(NULL) { }
  ListNode(int x, ListNode* node): val(x), next(node) {}
};

class MyLinkedList {
public:

    MyLinkedList() {
      linked_list_ = new ListNode();
    }
    
    int get(int index) {

      ListNode* head = linked_list_->next;

      int curpos = 0;

      if(index < 0) return -1;

      while (head != NULL){
        
        ListNode* cur = head;

        if(curpos == index) return cur->val;

        head = head->next;

        curpos++;
      }

      return -1;
      
    }
    
    void addAtHead(int val) {
      
      ListNode* new_node = new ListNode(val);

      new_node->next = linked_list_->next;

      linked_list_->next = new_node;
    }
    
    void addAtTail(int val) {

      ListNode* new_node = new ListNode(val);

      ListNode* head = linked_list_->next;

      ListNode* prev = linked_list_;

      while (head != NULL){

        prev = head;
        
        head = head->next;
      }

      prev->next = new_node;
        
    }
    
    void addAtIndex(int index, int val) {
        
      if(index < 0) { addAtHead(val); return; }

      ListNode* head = linked_list_->next;

      ListNode* prev = linked_list_;

      int curpos = 0;

      while (head != NULL){
        
        ListNode* cur = head;

        if(curpos == index){

          ListNode* new_node = new ListNode(val);

          prev->next = new_node;

          new_node->next = head;

          return;
        }

        head = head->next;

        prev = head;

        curpos++;
      }

      if(index == curpos) { addAtTail(val); return; }      
    }
    
    void deleteAtIndex(int index) {
      
      if(index < 0) return;

      ListNode* head = linked_list_->next;

      ListNode* prev = linked_list_;

      int curpos = 0;

      while (head != NULL){
        
        ListNode* cur = head;

        if(curpos == index){

          prev->next = cur->next;

          delete cur;

          return;
        }

        head = head->next;

        prev = head;

        curpos++;
      }
    }

    private:

    ListNode* linked_list_;
};