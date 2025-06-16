#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:

    vector<vector<int>> result;
    vector<int> pair;

    void backTracking(vector<int>& nums, int statridx){

      if(pair.size() >= 2) { result.push_back(pair); }

      if(statridx >= nums.size()) return;
      
      unordered_set<int> uset;

      for(int i = statridx; i < nums.size(); i++){

        if(pair.size() > 0 && nums[i] < pair.back()) continue;

        if(uset.size() > 0 && uset.find(nums[i]) != uset.end()) continue;

        pair.push_back(nums[i]);
        uset.insert(nums[i]);

        backTracking(nums, i+1);

        pair.pop_back();
      }
      
    }

    vector<vector<int>> findSubsequences(vector<int>& nums){
      
      if(nums.empty()) return result;

      backTracking(nums, 0);

      return result;
    }
};