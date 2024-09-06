#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {

  vector<int> sort_nums(nums);

  sort(sort_nums.begin(), sort_nums.end());

  vector<vector<int>> result;

  int left_index, right_index;

  for (int i = 0; i < sort_nums.size(); ++i){

    if(sort_nums[i] > target && sort_nums[i] > 0) break;

    if(i > 0 && sort_nums[i] == sort_nums[i-1]) continue;

    for(int j = i + 1; j < sort_nums.size(); ++j){

      if(sort_nums[j] + sort_nums[i] > target && sort_nums[j] + sort_nums[i] >= 0) break;
    
      if(j > i + 1 && sort_nums[j] == sort_nums[j-1]) continue;

      left_index = j + 1;  right_index = sort_nums.size() - 1;

      while (right_index > left_index){
        
        if(sort_nums[i] + sort_nums[j] + sort_nums[left_index] + sort_nums[right_index] > target) right_index--;

        else if(sort_nums[i] + sort_nums[j] + sort_nums[left_index] + sort_nums[right_index] < target) left_index++;

        else{

          vector<int> tmp = { sort_nums[i], sort_nums[j], sort_nums[left_index], sort_nums[right_index] };

          result.push_back(tmp);

          while(right_index > left_index && sort_nums[left_index] == sort_nums[left_index+1]) left_index++;

          while(right_index > left_index && sort_nums[right_index] == sort_nums[right_index-1]) right_index--;

          right_index--;

          left_index++;

        }
      }
    }
  }

  return result;
  

}

int main(){

  vector<int> nums = {2,2,2,2,2};

  int target = 8;

  vector<vector<int>> out = fourSum(nums, target);

  for(auto i : out){
    for(auto k : i){

      cout << k << "  ";
    }

    cout << endl;
  }

  return 1;
}