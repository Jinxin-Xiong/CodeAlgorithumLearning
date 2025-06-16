#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:

    void backTracking(int n, int k, vector<int>& pair, int startidx, vector<vector<int>>& combine){

      if(pair.size() == k){

        combine.push_back(pair);
        return;
      }

      for(int i = startidx; i <= n-(k-pair.size())+1; i++){

        pair.push_back(i);

        backTracking(n, k, pair, i+1, combine);

        pair.pop_back();
      }
    }

    vector<vector<int>> combine(int n, int k) {
        
      vector<vector<int>> result;

      vector<int> pair;

      backTracking(n, k, pair, 1, result);

      return result;
    }
};
