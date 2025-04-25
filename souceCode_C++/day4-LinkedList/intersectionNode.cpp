
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
    ListNode *getIntersectionNodeBruteForce(ListNode *headA, ListNode *headB) {
        
        ListNode* curA = headA;

        while (curA != NULL){
          
          ListNode* curB = headB;

          while (curB != NULL){
            
            if(curA == curB ) return curA;

            curB = curB->next;
          }

          curA = curA->next;          
        }

        return NULL;
        
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* curA = headA; int Alen = 0;
        ListNode* curB = headB; int Blen = 0;

        if(curA == NULL || curB == NULL) return NULL;

        while(curA != NULL) { Alen++; curA = curA->next; }
        while(curB != NULL) { Blen++; curB = curB->next; }

        curA = headA;  curB = headB;

        int gap = Alen - Blen;

        if(gap >= 0){
          while(gap--) curA = curA->next;
        }
        else {
          
          gap = abs(gap);
          while(gap--) curB = curB->next;
        }

        while(curA != NULL && curB != NULL){
          
                  
          if(curA == curB ) return curA;

          curB = curB->next;
         
          curA = curA->next;          
        }

        return NULL;
        
    }
};