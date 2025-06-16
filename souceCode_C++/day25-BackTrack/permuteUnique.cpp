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

    void backTracking(vector<int>& nums, vector<bool>& used){

      if(pair.size() == nums.size()){

        result.push_back(pair);
        return;
      }

      for (int i = 0; i < nums.size(); i++){
        
        if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;

        if(used[i]) continue;

        pair.push_back(nums[i]);
        used[i] = true;

        backTracking(nums, used);

        pair.pop_back();
        used[i] = false;
      }      
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {

      if(nums.empty()) return result;

      vector<bool> used(nums.size(), false);

      sort(nums.begin(), nums.end());
      
      backTracking(nums, used);

      return result;
    }
};