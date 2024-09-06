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

  T get(const int index);

  void addAtHead(const T val);

  void addAtTail(const T val);

  void addAtIndex(const int index, const T val);

  void deleteAtIndex(const int index);

};

template<typename T>
T MyLinkedList<T>::get(const int index){

  ListNode<T>* dummy_head = new ListNode<T>();

  dummy_head->next = this->getPtr();

  int i = 0;

  T out_factor;

  ListNode<T>* cur = dummy_head;

  while(i <= index && cur->next != NULL){

    if(i == index) { 
      
      out_factor = cur->next->getValue(); 
  
      delete dummy_head; 
      
      return out_factor; 
    }
 
    i++;

    cur = cur->next;
  }

  delete dummy_head;

  T returnVal = -1;

  return returnVal;

}

template<typename T>
void MyLinkedList<T>::addAtHead(const T val){

  ListNode<T>* head = new ListNode<T>(val);

  head->next = m_list;

  m_list = head;
  
}

template<typename T>
void MyLinkedList<T>::addAtTail(const T val){

  ListNode<T>* tail = new ListNode<T>(val);

  ListNode<T>* cur = m_list;

  while (cur->next != NULL){
    
    cur = cur->next;
  }

  cur->next = tail;  
}

template<typename T>
void MyLinkedList<T>::addAtIndex(const int index, const T val){

  if(index <= 0) { addAtHead(val); return; }

  int i = 0;

  ListNode<T>* cur = m_list;

  while(i <= index && cur->next != NULL){

    if(i == index - 1) { 

      ListNode<T>* newFactor = new ListNode<T>(val);

      ListNode<T>* temp = cur->next; 

      cur->next = newFactor;

      newFactor->next = temp;

      return; 
    }
 
    i++;

    cur = cur->next;
  }

  addAtTail(val);

}

template<typename T>
void MyLinkedList<T>::deleteAtIndex(const int index){

  ListNode<T>* dummy_head = new ListNode<T>();

  dummy_head->next = m_list;

  int i = 0;

  ListNode<T>* cur = dummy_head;

  while(i <= index && cur->next != NULL){

    if(i == index) { 

      ListNode<T>* temp = cur->next; 

      cur->next = cur->next->next;

      delete temp;

      m_list = dummy_head->next;

      return;
    }
 
    i++;

    cur = cur->next;
  }

  delete dummy_head; 
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

// Test get() function
  int index = 0;
  
  int value = linked_list.get(index);

  cout << "get index " << index << " value is:  " << value << endl;

// Test addAtHead() function

  int add_val = 99;

  linked_list.addAtHead(add_val);

  print(linked_list);

// Test addAtTail() function

  add_val = -99;

  linked_list.addAtTail(add_val);

  print(linked_list);

// Test addAtIndex() function

  add_val = 111;

  index = 10;

  linked_list.addAtIndex(index, add_val);

  print(linked_list);

// Test deleteAtInde() function

  index = 10;

  linked_list.deleteAtIndex(index);

  print(linked_list);

  return 1;
}

