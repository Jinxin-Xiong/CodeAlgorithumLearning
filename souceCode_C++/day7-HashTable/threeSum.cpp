#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        if(nums[0] > 0) return result;

        int left_idx = 0, right_idx = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++){
          
          if(i > 0 && nums[i] == nums[i-1]) continue;

          left_idx = i + 1; right_idx = nums.size() - 1;

          while(left_idx < right_idx){

            int count = nums[i] + nums[left_idx] + nums[right_idx];

            if(count  > 0) right_idx--;
            else if(count < 0) left_idx++;
            else{

              result.push_back(vector<int>{i,left_idx,right_idx});

              while(left_idx < right_idx && nums[left_idx] == nums[left_idx+1]) left_idx++;
              while(left_idx < right_idx && nums[right_idx] == nums[right_idx-1]) right_idx--;
            }

            right_idx--;
            left_idx++;
          }
        }
        
        return result;        
    }
};