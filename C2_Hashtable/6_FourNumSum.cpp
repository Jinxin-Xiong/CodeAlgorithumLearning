#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

  unordered_map<int, int> sum_map_s12;

  int count = 0;

  for (auto s1_factor : nums1){
    for(auto s2_factor : nums2){

      sum_map_s12[s1_factor+s2_factor] += 1;
    }
  }

  for (auto s3_factor : nums3){
    for(auto s4_factor : nums4){

      unordered_map<int, int>::iterator ite = sum_map_s12.find(-s3_factor-s4_factor);

      if(ite != sum_map_s12.end()){

        count += ite->second;
      }
    }
  }

  return count;
  
}

int main(){

  vector<int> nums1 = {1, 2};
  
  vector<int> nums2 = {-2, -1};
  
  vector<int> nums3 = {-1, 2};
  
  vector<int> nums4 = {0, 2};

  int count = fourSumCount(nums1, nums2, nums3, nums4);

  cout << count << endl;

  return 1;
}
