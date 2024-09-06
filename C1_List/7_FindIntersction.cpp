#include <iostream>

using namespace std;

template<typename T>
class ListNode{

  public:

  T value;

  ListNode* next;

  ListNode() : value(0), next(nullptr) {};

  ListNode(const T factor): value(factor), next(nullptr) {};

  ListNode(const ListNode* node) { value = node->value; next = node->next; }

  virtual T getValue() const { return value; }
};

template<typename T>
class MyLinkedList: ListNode<T>
{
private:

  ListNode<T>* m_list;

public:

  MyLinkedList() { m_list = new ListNode<T>(); }

  MyLinkedList(const T factor){ m_list = new ListNode<T>(factor); }

  MyLinkedList(ListNode<T>* node) { m_list = new ListNode<T>(node); }

  ~MyLinkedList() { delete m_list; m_list = nullptr; }

  ListNode<T>* getPtr() const { return m_list; }

  virtual T getValue() const { return m_list->value; }

  static bool findIntersection(const ListNode<T>* listA, const ListNode<T>* listB, ListNode<T>* out);


};

template<typename T>
static ListNode<T>* findIntersection(ListNode<T>* listA, ListNode<T>* listB){

  int listA_length = 0, listB_length = 0;

  ListNode<T>* tmp_list1 = listA;

  while (tmp_list1 != nullptr)
  {
    listA_length++;

    tmp_list1 = tmp_list1->next;
  }

  ListNode<T>* tmp_list2 = listB;

  while (tmp_list2 != nullptr)
  {
    listB_length++;

    tmp_list2 = tmp_list2->next;
  }

  int gap = abs(listA_length - listB_length);
  
  if(listA_length > listB_length) { tmp_list1 = listA; tmp_list2 = listB; }
  
  else{ tmp_list1 = listB; tmp_list2 = listA; }

  int count = 0; 

  while (tmp_list1 != nullptr)
  {
    if(count < gap) { tmp_list1 = tmp_list1->next; count++;  continue; }


    if(tmp_list1 == tmp_list2) break;

    tmp_list1 = tmp_list1->next;

    tmp_list2 = tmp_list2->next;

  }

  if(tmp_list1 == nullptr) return nullptr;

  return tmp_list1;
  
  
}

template<typename T>
void print(MyLinkedList<T>& ln){

  ListNode<T>* cur = ln.getPtr();

  while(cur != NULL){
  
    cout << cur->getValue() << "  " ;

    cur = cur->next;
  } 

  cout << endl;

}


int main(){

  ListNode<int>* in_list1 = new ListNode<int>(1);

  ListNode<int>* in_list2 = new ListNode<int>(1);


  ListNode<int>* a = new ListNode<int>(2);
  ListNode<int>* b = new ListNode<int>(3);
  ListNode<int>* c = new ListNode<int>(4);
  ListNode<int>* d = new ListNode<int>(5);
  ListNode<int>* e = new ListNode<int>(6);
  ListNode<int>* f = new ListNode<int>(7);
  ListNode<int>* g = new ListNode<int>(8);
  ListNode<int>* h = new ListNode<int>(9);
  ListNode<int>* i = new ListNode<int>(10);
  ListNode<int>* j = new ListNode<int>(11);
  ListNode<int>* k = new ListNode<int>(12);
  ListNode<int>* l = new ListNode<int>(13);

  in_list1->next = a;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = NULL;  

  in_list2->next = g;
  g->next = h;
  h->next = i;
  i->next = c;
  

  MyLinkedList<int> linked_list1(in_list1);

  MyLinkedList<int> linked_list2(in_list2);

  print(linked_list1);

  print(linked_list2);

  ListNode<int>* inter_node = findIntersection(in_list1, in_list2);

  cout << "intersect is:  " << inter_node->value << endl;

  cout << "address is:   " << &inter_node << endl;

  return 1;
}