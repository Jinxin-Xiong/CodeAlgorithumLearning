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

  void deleteReverseNode(const int rindex);


};

template<typename T>
void MyLinkedList<T>::deleteReverseNode(const int rindex){

  if(rindex <= 0) return; 

  ListNode<T>* slowptr = nullptr;

  ListNode<T>* slowptr_prev = nullptr;
 
  int fast_index = 0;

  ListNode<T>* dummy_head = new ListNode<T>();

  dummy_head->next = m_list;

  ListNode<T>* fastptr = dummy_head;

  while (fastptr->next != nullptr){
    
    if(fast_index < rindex -1) { fast_index++; fastptr = fastptr->next; }

    else if(fast_index == rindex - 1) { slowptr = dummy_head; fast_index++; }

    else {

      fast_index++; 

      fastptr = fastptr->next;

      slowptr_prev = slowptr;

      slowptr = slowptr->next;

    }
  }

  if(slowptr == nullptr) { delete dummy_head;  return; }

  slowptr_prev->next = slowptr->next;

  delete slowptr;  
  
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

  ListNode<int>* in_list = new ListNode<int>(1);

  ListNode<int>* a = new ListNode<int>(2);
  ListNode<int>* b = new ListNode<int>(3);
  ListNode<int>* c = new ListNode<int>(4);
  ListNode<int>* d = new ListNode<int>(5);
  ListNode<int>* e = new ListNode<int>(6);
  ListNode<int>* f = new ListNode<int>(7);

  in_list->next = a;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = NULL;

  MyLinkedList<int> linked_list(in_list);

  print(linked_list);

  linked_list.deleteReverseNode(4);

  print(linked_list);



  return 1;
}