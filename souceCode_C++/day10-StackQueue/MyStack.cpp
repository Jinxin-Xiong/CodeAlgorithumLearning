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
        while(queue_.size() > 1){
          int x = queue_.front();
          queue_.pop();

          queue_backup_.push(x);
        }

        int out = queue_.front();
        queue_.pop();

        while(!queue_backup_.empty()){
          int x= queue_backup_.front();
          queue_backup_.pop();
          queue_.push(x);
        }

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
    queue<int> queue_backup_;
};