#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:

    vector<vector<string>> result;

    vector<string> pair;

    bool isPalmString(string s, int start, int end){

      
      for (int i = start, j = end; i <= j; i++, j--){
        
        if(s[i] != s[j]) return false;
      }

      return true;
      
    }

    void backTracking(string s, int startidx){

      if(startidx >= s.size()){

        if(pair.size() > 0) result.push_back(pair);

        return;
      }

      for (int i = startidx; i < s.size(); i++){
        
        if(!isPalmString(s, startidx, i)) continue;

        string tmp = s.substr(startidx, i - startidx + 1);

        pair.push_back(tmp);

        backTracking(s, i+1);

        pair.pop_back();
      }

    }

    vector<vector<string>> partition(string s) {
        
      result.clear();
      pair.clear();

      if(s.empty()) return result;

      backTracking(s, 0);

      return result;
    }
};