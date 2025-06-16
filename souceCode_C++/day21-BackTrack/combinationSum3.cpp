#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void backtracking(int n, int k, int startidx, int& sum, vector<int>& pair, vector<vector<int>>& combine){

      if(pair.size() == k && sum == n){

        combine.push_back(pair);
        return;
      }

      for(int i = startidx; i <= 9-(k-pair.size())+1; i++){

        if(sum + i > n) continue;
        
        pair.push_back(i);

        sum += i;

        backtracking(n, k, i+1, sum, pair, combine);

        pair.pop_back();

        sum -= i;
      }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
      vector<vector<int>> combine;

      vector<int> pair;

      int sum = 0;

      backtracking(n, k, 1, sum, pair, combine);

      return combine;
    }
};