#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int left_idx = 0, right_idx = s.size() - 1;

        while(left_idx < right_idx){

          char tmp = s[right_idx];

          s[right_idx] = s[left_idx];

          s[left_idx] = tmp;

          left_idx++;
          right_idx--;
        }

    }
};