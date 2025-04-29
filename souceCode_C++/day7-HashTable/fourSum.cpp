#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

      vector<vector<int>> result;

      sort(nums.begin(), nums.end());

      int left_idx, right_idx;

      for(int i = 0; i < nums.size(); i++){

        if(nums[i] >= 0 && nums[i] > target) break;

        if(i > 0 && nums[i] == nums[i-1]) continue;

        for (int j = i+1; j < nums.size(); j++){

          if(nums[i] + nums[j] >= 0 && nums[i] + nums[j] > target) break;

          if(j > i+1 && nums[j] == nums[j-1]) continue;

          left_idx = j + 1; right_idx = nums.size() - 1;

          while(left_idx < right_idx){

            long count = static_cast<long>(nums[i]) + static_cast<long>((nums[j]) + static_cast<long>(nums[left_idx])+ static_cast<long>(nums[right_idx]));
            
            if(count > target) right_idx--;
            else if(count < target) left_idx++;
            else{

              result.push_back(vector<int>{nums[i],nums[j],nums[left_idx],nums[right_idx]});

              while(left_idx < right_idx && nums[left_idx] == nums[left_idx+1]) left_idx++;
              while(left_idx < right_idx && nums[right_idx] == nums[right_idx-1]) right_idx--;

              left_idx++;
              right_idx--;
            }
          }
        }        
      }

      return result;
        
    }
};