#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    MyStack() {
    }
    
    void push(int x) {
        queue_.push(x);
    }
    
    int pop() {

        int pop_size = queue_.size() - 1;
        
        for(int i = 0; i < pop_size; i++){
          queue_.push(queue_.front());
          queue_.pop();
        }


        int out = queue_.front();
        queue_.pop();

        return out;
    }
    
    int top() {
        int out = this->pop();
        queue_.push(out);

        return out;
    }
    
    bool empty() {
        if(queue_.empty()) return true;
        else return false;
    }

  private:
    queue<int> queue_;
};