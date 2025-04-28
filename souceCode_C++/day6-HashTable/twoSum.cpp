#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

      
      multimap<int, int> number_map;

      for (int i = 0; i < nums.size(); i++){
        
        number_map.insert({nums[i],i});
      }

      for (int i = 0; i < nums.size(); i++){

        int rest = target - nums[i];

        auto range = number_map.equal_range(rest);

        for (auto it = range.first; it != range.second; ++it) {
          
          if(it->second != i) { return vector<int>{i,it->second}; }
        }      
    }

    return vector<int>{0,0};
  }

  vector<int> twoSumFast(vector<int>& nums, int target) {

      
      unordered_map<int, int> number_map;

      for (int i = 0; i < nums.size(); i++){

        int rest = target - nums[i];

        auto itr = number_map.find(rest);

        if(itr == number_map.end()){

          number_map.insert({nums[i], i});
        }
        else { return vector<int>{i, itr->second}; }
    }

    return vector<int>{0,0};
  }
};