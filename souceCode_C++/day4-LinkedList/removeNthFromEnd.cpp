
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
    ListNode* reverseList(ListNode* head){

      if(head == NULL) return NULL;

      ListNode* cur = head;
      ListNode* prev = NULL;

      while (cur != NULL){
        
        ListNode* tmp = cur->next;

        cur->next = prev;

        prev = cur;
        cur = tmp;        
      }

      return prev;      
    }
    
    ListNode* removeNthFromEndBasedReverse(ListNode* head, int n) {
      
      if(n <= 0 || head == NULL) return head;

      ListNode* revList = reverseList(head);

      ListNode* dummynode = new ListNode(0);
      dummynode->next = revList;

      ListNode* node = revList;
      ListNode* prev = dummynode;

      for (int i = 0; i < n-1; i++){
        
        prev = node;
        node = node->next;
      }

      prev->next = node->next;

      delete node; node = NULL;      

      ListNode* resultlist = reverseList(dummynode->next);

      return resultlist;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
      if(n <= 0 || head == NULL) return head;

      ListNode* fastnode = head; int fastidx = 0;
      ListNode* slownode = head; int slowidx = 0;

      ListNode* dummynode = new ListNode(0);
      dummynode->next = head;

      ListNode* prev = dummynode;

      while (fastnode->next != NULL){
        
        if(fastidx - slowidx >= n - 1){ 
          
          prev = slownode;

          slowidx++; slownode = slownode->next; 
        }

        fastnode = fastnode->next;
        fastidx++;
      }

      prev->next = slownode->next;

      delete slownode; slownode = NULL;  

      return dummynode->next;    
    }
};