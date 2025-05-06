#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

      if(s.empty() || s.size() == 1) return s;

      stack<char> str;

      int index;

      str.push(s[s.size() - 1]);

      for(index = s.size() - 2; index >= 0; --index){

        if(str.empty()) { str.push(s[index]); continue; }

        if(s[index] == str.top()) { str.pop(); }
        else str.push(s[index]);
      }

      string out;

      while(!str.empty()) { out += str.top(); str.pop(); }

      return out;
        
    }
};