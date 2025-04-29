#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseStr(string s, int k) {

      string out = s;

      for (int i = 0; i < out.size(); i += 2 * k){
        
        if(i + k  >= out.size()) reverse(out, i, out.size() - 1);
        else reverse(out, i, i + k - 1);
      }      
      
      return out;
    }
};