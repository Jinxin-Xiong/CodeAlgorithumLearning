#include <iostream>

using namespace std;

template<typename T>
class ListNode{

  public:

  T value;

  ListNode* next;

  ListNode() : value(0), next(NULL) {};

  ListNode(const T factor): value(factor), next(NULL) {};

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

  ~MyLinkedList() { delete m_list; m_list = NULL; }

  ListNode<T>* getPtr() const { return m_list; }

  virtual T getValue() const { return m_list->value; }

  void swapListNode();


};

//It is too complicated
/* template<typename T>
void MyLinkedList<T>::swapListNode(){

  if(m_list == NULL) return;

  ListNode<T>* cur = m_list;

  ListNode<T>* out_firstNode;

  if(m_list->next != NULL) out_firstNode = m_list->next;

  else out_firstNode = m_list;

  while(cur != NULL && cur->next != NULL){
      
      ListNode<T>* first = cur;

      ListNode<T>* second = cur->next;

      ListNode<T>* third = cur->next->next;

      if(cur->next->next == NULL){

          second->next = cur;

          first->next = NULL;

          break;
      }

      else{

          if(cur->next->next->next == NULL){

              first->next = cur->next->next;

              second->next = cur;
          }

          else{

              first->next = cur->next->next->next;

              second->next = cur;
          }
      }

      cur = third;
  }


  m_list = out_firstNode;


} */

template<typename T>
void MyLinkedList<T>::swapListNode(){

  ListNode<T>* dummy_head = new ListNode<T>();

  dummy_head->next = m_list;

  ListNode<T>* cur = dummy_head;

  while (cur->next != NULL && cur->next->next != NULL){
    
    ListNode<T>* tmp_first = cur->next;

    ListNode<T>* tmp_third = cur->next->next->next;

    cur->next = cur->next->next;

    cur->next->next = tmp_first;

    cur->next->next->next = tmp_third;

    cur = cur->next->next;

  }

  m_list = dummy_head->next;
  
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

  linked_list.swapListNode();

  print(linked_list);



  return 1;
}