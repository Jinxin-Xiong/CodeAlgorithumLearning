#include <iostream>
#include <vector>

using namespace std;

//brute force solution
int minSubArrayLen(int target, vector<int>& nums) {

    int startIndex = 1, endIndex = 0;

    int sum, shortRange = INT32_MAX;

    for (int i = 0; i < nums.size(); i++){

      sum = 0;
        
      for (int j = i; j < nums.size(); j++){
      
          sum += nums[j];

          if(sum >= target) { 

              startIndex = i; 
              
              endIndex = j; 

              shortRange = (endIndex - startIndex + 1) < shortRange ? endIndex - startIndex + 1 : shortRange; 
              
              break; 
          }
      }
        
    }

    return shortRange == nums.size() ? 0 : shortRange ;
}

//double pointer solution
int FindShortestArray(const int target, const vector<int> nums){

  int fast_index = 0, slow_index = 0, sum = 0, short_range = INT32_MAX;

  for (fast_index = 0; fast_index < nums.size(); fast_index++ ){
    
    sum += nums[fast_index];

    while (sum >= target)
    {
      cout << "fast --> slow:  " << fast_index << "  " << slow_index  << "  -->" << short_range << endl;

      short_range = short_range > fast_index - slow_index + 1 ? fast_index - slow_index + 1 : short_range;

      sum -= nums[slow_index];

      slow_index++;
    }

    cout << "fast --> slow:  " << fast_index << "  " << slow_index  << "  -->" << short_range << endl;


  }

  return short_range == INT32_MAX ? 0 : short_range;
  
}


int main(){

  vector<int> nums = { 7,8,1,2,4,3 };

  int target = 7;

  int rangeSize = FindShortestArray(target, nums);

  cout << "The shortest array size is: " << rangeSize << endl;

  return rangeSize;
}