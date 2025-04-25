
#include <iostream>

using namespace std;

struct ListNode{
  
  int val;
  ListNode* next;
  ListNode* prev;

  ListNode(int x): val(x), next(NULL), prev(NULL) {}
  ListNode(int x, ListNode* pre, ListNode* nex): val(x), next(nex), prev(pre) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

      if(head == NULL) return NULL;

      ListNode* dummynode = new ListNode(0);
      dummynode->next = head;

      ListNode* cur = dummynode->next;

      ListNode* prev = dummynode;

      while (cur != NULL && cur->next != NULL){
        
        ListNode* tmp = cur->next->next;

        ListNode* tmp_right = cur->next;
        tmp_right->next = cur;

        ListNode* tmp_left = cur;
        tmp_left->next = tmp;

        prev->next = tmp_right;
        prev = tmp_left;

        cur = tmp;
      }

      ListNode* newhead = dummynode->next;

      delete dummynode; dummynode = NULL;

      return newhead;       
    }
};
