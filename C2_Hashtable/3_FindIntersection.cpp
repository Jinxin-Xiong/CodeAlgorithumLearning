#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){

  unordered_set<int> nums1_set(nums1.begin(), nums1.end());

  //unordered_set<int> nums2_set(nums2.begin(), nums2.end());

  unordered_set<int> intersect_set;

  for (auto i : nums2)
  {
    if(nums1_set.find(i) != nums1_set.end()) intersect_set.insert(i);
  }

  vector<int> out{ intersect_set.begin(), intersect_set.end() };

  return out;
  
}

int main(){

  vector<int> nums1 = { 4, 9, 5};

  vector<int> nums2 = {9, 4, 9, 8, 4};

  vector<int> out = intersection(nums1, nums2);

  for (auto i : out)
  {
    cout << i << "  ";
  }

  cout << endl;
  


  return 1;
}