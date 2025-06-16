#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> result;

    vector<int> combine;

    void backTracking(vector<int>& candidates, int target, int sum, int startidx, vector<bool> used){

      if(sum > target) return;

      if(sum == target){

        result.push_back(combine);

        return;
      }

      for (int i = startidx; i < candidates.size() && sum + candidates[i] <= target; i++){
         
        if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false){
          continue;
        }

        combine.push_back(candidates[i]);
        sum += candidates[i];
        used[i] = true;

        backTracking(candidates, target, sum, i+1, used);

        combine.pop_back();
        sum -= candidates[i];
        used[i] = false;
  
      }
      
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      
      result.clear();
      combine.clear();

      vector<bool> used(candidates.size(), false);

      sort(candidates.begin(), candidates.end());

      backTracking(candidates, target, 0, 0, used);

      return result;
    }
};