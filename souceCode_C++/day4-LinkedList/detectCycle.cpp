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
    ListNode *detectCycle(ListNode *head) {

      if(head == NULL || head->next == NULL) return NULL;

      ListNode* slow = head;
      ListNode* fast = head;

      while (fast != NULL && fast->next != NULL){
        
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){

          ListNode* index1 = head;
          ListNode* index2 = fast;

          while(index1 != index2){

            index1 = index1->next;
            index2 = index2->next;
          }

          return index1;
        }
      }

      return NULL;        
    }
};