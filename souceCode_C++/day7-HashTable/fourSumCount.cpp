
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
      unordered_map<int, int> count_map;

      int count, result = 0;

      for(int tmps1 : nums1){
        for(int tmps2 : nums2){

          count = tmps1 + tmps2;

          unordered_map<int, int>::iterator itr = count_map.find(count);
          
          if(itr == count_map.end()) count_map.insert({count,1});
          else itr->second++;
        }
      }

      for(int tmps3 : nums3){
        for(int tmps4 : nums4){

          count = -(tmps3 + tmps4);

          unordered_map<int, int>::iterator itr = count_map.find(count);
          
          if(itr != count_map.end()){

            result += itr->second;
          }
        }
      }

      return result;
    }
};