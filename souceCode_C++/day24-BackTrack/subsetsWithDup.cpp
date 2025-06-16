#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:

    vector<vector<int>> result;
    vector<int> pair;

    void backTracking(vector<int>& nums, int statridx, vector<bool>& used){

      result.push_back(pair);

      if(statridx >= nums.size()) return;

      for (int i = statridx; i < nums.size(); i++){
        
        if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;

        pair.push_back(nums[i]);
        used[i] = true;

        backTracking(nums, i+1, used);

        pair.pop_back();
        used[i] = false;
      }
      
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      
      if(nums.empty()) return result;

      sort(nums.begin(), nums.end());

      vector<bool> used(nums.size(), false);

      backTracking(nums, 0, used);

      return result;
    }
};