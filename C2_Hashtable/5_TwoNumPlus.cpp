#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

//My own solution
/* vector<int> twoSum(vector<int>& nums, int target){

  multimap<int, int> num_map;

  vector<int> result;

  for (int i = 0; i < nums.size(); ++i){

    num_map.insert(make_pair(nums[i], i));
  }

  for (auto i : num_map)
  {
    cout << i.first << "  " << i.second << endl;
  }
  

  for (int i = 0; i < nums.size(); ++i)
  {
    int minus_num = target - nums[i];

    multimap<int, int>::iterator ite = num_map.find(minus_num);

    if(ite != num_map.end() && ite->second != i) { 

      result.push_back(i);

      result.push_back(ite->second);

      break;
    } 

    /* for (int k = 0; k < num_map.count(minus_num); ++k, ++ite)
    {
      if(ite->second <= i) continue;

      result.push_back(i);

      result.push_back(ite->second);
    } */
    

  /* }

  return result;
  
}  */

//Better solution
vector<int> twoSum(vector<int>& nums, int target){

  unordered_map<int, int> nums_map;

  for (int i = 0; i < nums.size(); ++i)
  {
    auto ite = nums_map.find(target - nums[i]);

    if( ite != nums_map.end()){

      return { i, ite->second };      
    }

    nums_map.insert(make_pair(nums[i], i));
  }

  return {};
  
}

int main(){

  vector<int> input{ 2, 7, 3, 6 };

  int target = 9;

  vector<int> out = twoSum(input, target);

  for(auto i : out){

    cout << i << "  ";
  }

  cout << endl;

  return 1;
}