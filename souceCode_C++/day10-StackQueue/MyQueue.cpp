#include <iostream>
#include <deque>

using namespace std;

class MyStack{

  public:
    MyStack() {
      queue_.clear();
    }
    
    void push(int x) {
        queue_.push_back(x);
    }
    
    int pop() {
        int x = queue_.back();
        queue_.pop_back();
        return x;
    }
    
    int peek() {
        int x = queue_.back();
        return x;
    } 
    
    bool empty() {
        if(queue_.empty()) return true;
        else return false;
    }

  private:
    deque<int> queue_;
};

class MyQueue {
public:
    MyQueue() {
      
    }
    
    void push(int x) {
        stack_in_.push(x);
    }
    
    int pop() {
    
        if(stack_out_.empty()){

          while(!stack_in_.empty()){
            int x = stack_in_.pop();
            stack_out_.push(x);
          }
        }
        
        return stack_out_.pop();
    }
    
    int peek() {
        
        int x = this->pop();

        stack_out_.push(x);

        return x;
    }
    
    bool empty() {
        if(stack_out_.empty() && stack_in_.empty()) return true;
        else return false;
    }

  private:
    MyStack stack_in_;
    MyStack stack_out_;
};


int main(){

  MyStack stack;

  stack.push(1);
  stack.push(2);

  int x = stack.peek(); cout << x << endl;
  int y = stack.pop(); cout << y << endl;
  int z= stack.pop(); cout << z << endl;

  MyQueue queue;
  queue.push(1);
  queue.push(2);

  x = queue.peek(); cout << x << endl;
  y = queue.pop(); cout << y << endl;
  z= queue.pop(); cout << z << endl;
}