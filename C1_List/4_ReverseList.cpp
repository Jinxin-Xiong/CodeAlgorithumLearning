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

  void reverseList();

  void reverseListRecur();

};


//Double pointer
template<typename T>
void MyLinkedList<T>::reverseList(){

  ListNode<T>* cur = m_list;

  ListNode<T>* temp1 = NULL;

  ListNode<T>* preNode = NULL;

  while (cur != NULL){
    
    temp1 = cur->next; 

    cur->next = preNode; 

    preNode = cur; 

    cur = temp1;    

  }

  m_list = preNode;

}

//Recursive
template<typename T>
static ListNode<T>* RecursiveCore(ListNode<T>* pre, ListNode<T>* cur){

  if(cur == NULL) { return pre; }

  ListNode<T>* temp = cur->next;

  cur->next = pre;   

  RecursiveCore(cur, temp);

}

template<typename T>
void MyLinkedList<T>::reverseListRecur(){

  ListNode<T>* cur = m_list;

  ListNode<T>* preNode = NULL;

  m_list = RecursiveCore(preNode, cur);
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
  ListNode<int>* b = new ListNode<int>(6);
  ListNode<int>* c = new ListNode<int>(3);
  ListNode<int>* d = new ListNode<int>(4);
  ListNode<int>* e = new ListNode<int>(5);
  ListNode<int>* f = new ListNode<int>(6);

  in_list->next = a;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = e;
  e->next = f;
  f->next = NULL;

  MyLinkedList<int> linked_list(in_list);

  print(linked_list);

  linked_list.reverseList(); //Test Double pointer

  print(linked_list);

  linked_list.reverseListRecur();

  print(linked_list);

  return 1;
}