#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:

    int findContentChildren(vector<int>& g, vector<int>& s) {

      sort(g.begin(), g.end());
      sort(s.begin(), s.end());

      int satisfiedchildren = 0, index = 0;

      for (int i = 0; i < s.size(); i++){
        
       if(index < g.size() && g[index] <= s[i]) index++;
      }
      

      return satisfiedchildren;        
    }
};