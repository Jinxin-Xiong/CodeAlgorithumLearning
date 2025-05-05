#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:

    bool isValid_selfcode(string s) {
      
      if(s.size() % 2 != 0) return false;

      stack<char> sample;      

      for(int index = s.size() - 1; index >= 0; index--){

        if(sample.size() == 0) { sample.push(s[index]); continue; }

        char cur = s[index];
        char cur_stack = sample.top();

        if(cur == '(' && cur_stack == ')') sample.pop();
        else if(cur == '{' && cur_stack == '}') sample.pop();
        else if(cur == '[' && cur_stack == ']') sample.pop();
        else sample.push(cur);

      }

      if(sample.size() == 0) return true;
      else return false;
    }

    bool isValid(string s){
      
      if(s.size() % 2 != 0) return false;

      stack<char> sample;      

      for(int i = 0; i < s.size(); i++){

        if(s[i] == '(') sample.push(')');
        else if(s[i] == '{') sample.push('}');
        else if(s[i] == '[') sample.push(']');
        else if(sample.empty() || sample.top() != s[i]) return false;
        else sample.pop();
      }

      return sample.empty();
    }
};