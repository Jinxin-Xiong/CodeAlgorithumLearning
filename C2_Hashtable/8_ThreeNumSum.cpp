#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

  vector<int> sort_nums(nums);

  sort(sort_nums.begin(), sort_nums.end());

  vector<vector<int>> result;

  if(sort_nums[0] > 0 || sort_nums[sort_nums.size()-1] < 0) return result;

  int left_index, right_index;

  for (int i = 0; i < nums.size(); ++i){
    
    if(i > 0 && sort_nums[i] == sort_nums[i-1]) continue;

    left_index = i + 1;  right_index = sort_nums.size() - 1;

    while (right_index > left_index){
      
      if(sort_nums[i] + sort_nums[left_index] + sort_nums[right_index] > 0) right_index--;

      else if(sort_nums[i] + sort_nums[left_index] + sort_nums[right_index] < 0) left_index++;

      else{

        vector<int> tmp = { sort_nums[i], sort_nums[left_index], sort_nums[right_index] };

        result.push_back(tmp);

        while(right_index > left_index && sort_nums[left_index] == sort_nums[left_index+1]) left_index++;

        while(right_index > left_index && sort_nums[right_index] == sort_nums[right_index-1]) right_index--;

        right_index--;

        left_index++;

      }
    }
  }

  return result;
  

}

int main(){

  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  vector<vector<int>> out = threeSum(nums);

  for(auto i : out){
    for(auto k : i){

      cout << k << "  ";
    }

    cout << endl;
  }

  return 1;
}