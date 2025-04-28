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

          if(nums[i] > 0) return result;


          left_idx = i + 1;

          while(left_idx < nums.size() && right_idx > left_idx){

            int first_num = nums[i];
            int second_num = nums[left_idx];
            int third_num = nums[right_idx];

            int count = first_num + second_num + third_num;

            if(count == 0){

              vector<int> tmp{ first_num, second_num, third_num };
              result.push_back(tmp);
            }
            else if(count < 0){

              left_idx++;
            }
            else{

              right_idx--;
            }
          }  
        }
        return result;
    }
};