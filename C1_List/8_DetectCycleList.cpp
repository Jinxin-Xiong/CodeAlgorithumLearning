#include <iostream>

using namespace std;

class ListNode{

  public:

  int value;

  ListNode* next;

  ListNode(int x) : value(x), next(NULL) {}
};

class Solution {
public:
    static ListNode *detectCycle(ListNode *head) {

      ListNode* fastptr = head;

      ListNode* slowptr = head;

      while (fastptr != NULL && fastptr->next != NULL)
      {

        fastptr = fastptr->next->next;

        slowptr = slowptr->next;

        if(fastptr == slowptr){

          ListNode* index1 = fastptr;

          ListNode* index2 = head;

          while (fastptr != NULL)
          {
            
            if(index1 == index2) return index2;

            index1 = index1->next;

            index2 = index2->next;

          }
          
        }

      }

      return NULL;  
        
    }
};

void print(ListNode* ln, int node_count){

  ListNode* cur = ln;

  while(cur != NULL && node_count--){
  
    cout << cur->value << "  " ;

    cur = cur->next;
  } 

  cout << endl;

}


int main(){

  ListNode* in_list1 = new ListNode(1);

  ListNode* a = new ListNode(2);
  ListNode* b = new ListNode(3);
  ListNode* c = new ListNode(4);
  ListNode* d = new ListNode(5);
  ListNode* e = new ListNode(6);
  ListNode* f = new ListNode(7);
  ListNode* g = new ListNode(8);
  ListNode* h = new ListNode(9);
  ListNode* i = new ListNode(10);
  ListNode* j = new ListNode(11);
  ListNode* k = new ListNode(12);
  ListNode* l = new ListNode(13);

  in_list1->next = a;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = c;

  print(in_list1,8);

  ListNode* inter_node = Solution::detectCycle(in_list1);

  if(inter_node != NULL)  cout << "Cycle node is:  " << inter_node->value << endl;

  else cout << "There is not cycle list" << endl;

  return 1;
}