#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    void getNext(vector<int>& next, string s){

      next[0] = 0;

      int i, j = 0;

      for(i = 1; i < s.size(); ++i){

        while(j > 0 && s[i] != s[j]) j = next[j-1];

        if(s[i] == s[j]) j++;

        next[i] = j;

      }
    }

    bool repeatedSubstringPattern(string s) {

    if(s.empty() || s.size() == 1) return false;

    vector<int> next(s.size(), 0);

    getNext(next, s);

    int len = next[s.size() - 1];

    int repeat_len = s.size() - len;

    if(len != 0 && s.size() % repeat_len == 0) return true;

    return false;
  }
};