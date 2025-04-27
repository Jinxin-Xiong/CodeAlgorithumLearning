#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

      unordered_set<int> nums1_set;

      for(auto x : nums1) nums1_set.insert(x);

      unordered_set<int> result;

      for(auto x : nums2){

        auto itr = nums1_set.find(x);

        if(itr != nums1_set.end()) { result.insert(x); }
      } 

      return vector<int>(result.begin(), result.end());    
    }
};