#include<string>
#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:

    vector<vector<int>> result;
    vector<int> pair;

    void backTrack(vector<int>& nums, int startidx){

      result.push_back(pair);

      if(startidx >= nums.size()){
        
        return;
      }

      for (int i = startidx; i < nums.size(); i++){
        
        pair.push_back(nums[i]);

        backTrack(nums, i+1);

        pair.pop_back();
      }
      
    }


    vector<vector<int>> subsets(vector<int>& nums) {
      
      if(nums.empty()) return result;

      backTrack(nums, 0);
      
      return result;
    }
};