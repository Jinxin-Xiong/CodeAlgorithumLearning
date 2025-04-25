
#include <iostream>

using namespace std;

struct ListNode{

  int val;
  ListNode* next;

  ListNode(): val(0), next(NULL) {}
  ListNode(int x): val(x), next(NULL) { }
  ListNode(int x, ListNode* node): val(x), next(node) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      
      if(head ==NULL) return NULL;

      ListNode* pre = NULL;
      ListNode* cur = head;

      while (cur != NULL){
        
        ListNode* tmp = cur->next;

        cur->next = pre;

        pre = cur;

        cur = tmp;
      }

      return pre;
      
    }


};