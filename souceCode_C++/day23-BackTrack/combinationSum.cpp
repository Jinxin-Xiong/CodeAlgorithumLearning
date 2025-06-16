#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

//版本一 未剪枝
class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;

    void backTracking(vector<int>& candidates, int target, int sum, int startIndex){

      if(sum > target) return;

      if(sum == target){
        result.push_back(path);
        return;
      }

      for(int i = startIndex; i < candidates.size(); i++){

        sum += candidates[i];
        path.push_back(candidates[i]);

        backTracking(candidates, target, sum, i);

        sum -= candidates[i];
        path.pop_back();
      }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
      result.clear();
      path.clear();
      backTracking(candidates, target, 0, 0);
      return result;
    }
};

//版本二 剪枝
class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;

    void backTracking(vector<int>& candidates, int target, int sum, int startIndex){

      if(sum == target){
        result.push_back(path);
        return;
      }

      for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++){

        sum += candidates[i];
        path.push_back(candidates[i]);

        backTracking(candidates, target, sum, i);

        sum -= candidates[i];
        path.pop_back();
      }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
      result.clear();
      path.clear();

      sort(candidates.begin(), candidates.end());
      
      backTracking(candidates, target, 0, 0);
      return result;
    }
};