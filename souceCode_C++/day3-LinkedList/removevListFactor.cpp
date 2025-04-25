
#include <iostream>

using namespace std;

struct ListNode{

  int val;
  ListNode* next;

  ListNode(int x): val(x), next(NULL) {}

  ListNode(int x, ListNode* node): val(x), next(node) { }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

      if(head == nullptr) return nullptr;

      ListNode *dummyhead = new ListNode(0, head);

      ListNode* cur = dummyhead;

      while (cur->next != nullptr){
        
        ListNode* tmp = cur->next;

        if(tmp->val == val) {
            cur->next = tmp->next;
            delete tmp;
        }
        else{
            cur = cur->next;
        }
      }

      ListNode* out = dummyhead->next;

      delete dummyhead;

      return out;  
    }
};


