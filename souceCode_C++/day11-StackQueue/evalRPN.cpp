#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:

    int mathOperator(stack<int>& num_stack, const int operat){

      int number1 = num_stack.top();
      num_stack.pop();

      int number2 = num_stack.top();
      num_stack.pop();

      int out;

      switch (operat)
      {
      case 1:
        out = number2 + number1;
        break;
      case 2:
        out = number2 - number1;
        break;
      case 3:
        out = number2 * number1;
        break;
      case 4:
        out = number2 / number1;
        break;

      default:
        out = 0;
        break;
      }

      return out;
    }

    int evalRPN(vector<string>& tokens) {

      if(tokens.size() < 3) return stoi(tokens.front());

      stack<int> number_stack;

      int32_t result = 0;

      for(int i = 0; i < tokens.size(); ++i){

          if(tokens[i] == "+"){

            result = mathOperator(number_stack, 1);
          }
          else if(tokens[i] == "-"){
            result = mathOperator(number_stack, 2);
          }
          else if(tokens[i] == "*"){
            result = mathOperator(number_stack, 3);
          }
          else if(tokens[i] == "/"){
            result = mathOperator(number_stack, 4);
          }
          else{
            number_stack.push(stoi(tokens[i]));
            continue;
          }

          number_stack.push(result);
        }

        return number_stack.top();      
    }
};

int main(){

  vector<string> s {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

  Solution ss;
  ss.evalRPN(s);

  return 1;
}