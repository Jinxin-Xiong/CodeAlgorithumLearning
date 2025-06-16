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

    void backTrack(vector<int>& nums, vector<bool>& used){

      if(pair.size() == nums.size()) { result.push_back(pair); return; }

      for (int i = 0; i < nums.size(); i++){
        
        if(used[i] == true) continue;

        pair.push_back(nums[i]);
        used[i] = true;

        backTrack(nums, used);

        pair.pop_back();
        used[i] = false;
      }
      
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return result;

        vector<bool> used(nums.size(), false);

        backTrack(nums, used);

        return result;
    }
};