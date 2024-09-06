
#include <iostream>
#include <vector>

using namespace std;


//////////////////////  Remove Element   ///////////////////
//Brute force solve
int removeElement(vector<int>& nums, const int target){

  int numsCount = nums.size();

  int newCount = 0;

  for (int i = 0; i < numsCount; i++ ){

    if(nums[i] == target){

      for (int j = i+1; j < numsCount; j++)        
        { nums[j-1] = nums[j]; }

      numsCount--;

      i--;

      newCount++;

    }
    
  }
  
  return newCount;
  
}

//Double pointer solve
int removeElement(vector<int>& nums, const int target){

  int fastIndex = 0, slowIndex = 0;

  for (fastIndex = 0; fastIndex < nums.size(); fastIndex++){
    
    if(nums[fastIndex] != target){

      nums[slowIndex] = nums[fastIndex];

      slowIndex++;

    }
  }
  
  return slowIndex;
}



//////////////////////  26. 删除排序数组中的重复项   ///////////////////
int removeDuplicates(vector<int>& nums) {
    
    int fastIndex = 1, slowIndex = 1;

    int val = nums[0];

    for(fastIndex = 1; fastIndex < nums.size(); fastIndex++){
        
        if(nums[fastIndex] != val){

            nums[slowIndex] = nums[fastIndex];

            val = nums[fastIndex];

            slowIndex++;
        }
    }

    return slowIndex;
}

int main(){

  vector<int> nums = {3, 2, 2, 3};

  int target = 3;

  int count = removeElement(nums, target);

  cout << "new count is:  " << count << endl;

  for (auto i : nums)
    cout << i << ' ';
  
  cout << endl;
}