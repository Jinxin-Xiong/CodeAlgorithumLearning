#include <iostream>

using namespace std;

class ListNode{

  public:

  int val;

  ListNode* next;

  public:

  ListNode(): val(0) {};

  ListNode(int x): val(x), next(NULL) { }
};

//Operate factors in the original list
ListNode* RemoveFactor(ListNode* node, const int val){

  ListNode* tmp = NULL;

  while (node != NULL && node->val == val){
    
    tmp = node;

    node = node->next;

    delete tmp;
  }

  ListNode* cur = node;

  while (cur->next != NULL && cur != NULL){

    if(cur->next->val == val) { tmp = NULL;  tmp = cur->next; cur->next = cur->next->next;   delete tmp;  }

    else { cur = cur->next; }
  } 
  
  return node;

}

//Insert a head pointer into the list
ListNode* RemoveFactorAddHead(ListNode* node, const int val){

  ListNode* head = new ListNode(0);

  head->next = node;

  ListNode* cur = head;

  while (cur->next != NULL){
    
    if(cur->next->val == val) { ListNode* tmp = cur->next;  cur->next = cur->next->next; delete tmp; }

    else { cur = cur->next; }
  }

  node = head->next;

  delete head;

  return node;
  
}


int main(){

  int num = 7;

  ListNode* in_list = new ListNode(1);
  ListNode* a = new ListNode(2);
  ListNode* b = new ListNode(6);
  ListNode* c = new ListNode(3);
  ListNode* d = new ListNode(4);
  ListNode* e = new ListNode(5);
  ListNode* f = new ListNode(6);

  in_list->next = a;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = NULL;

  ListNode* cur = in_list;

  while(cur != NULL){
  
    cout << cur->val << "  " ;

    cur = cur->next;
  } 

  cout << endl;

  int target = 6;

  //RemoveFactor(in_list,target);
  RemoveFactorAddHead(in_list,target);

  cur = in_list;

  while(cur != NULL){
  
    cout << cur->val << "  " ;

    cur = cur->next;
  } 

  cout << endl;

  return 1;
  
}