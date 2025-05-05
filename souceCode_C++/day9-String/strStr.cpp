#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void getNext(vector<int>& next, string needle){

      next[0] = 0;

      int i, j = 0;

      for(i = 1; i < needle.size(); i++){

        while(j > 0 && needle[i] != needle[j]) j = next[j-1];

        if(needle[i] == needle[j]) j++;

        next[i] = j;
      }
    }

    int strStr(string haystack, string needle) {
        
      if(needle.empty()) return 0;

      vector<int> next(needle.size(), 0);

      getNext(next, needle);

      int pos = 0, result;

      for(int i = 0; i < haystack.size(); ++i){

        while(pos > 0 && haystack[i] != needle[pos]) 
          pos = next[pos - 1];

        if(haystack[i] == needle[pos]) pos++;

        if(pos == needle.size()) return (i - pos + 1);
      }

      return -1;

    }
};