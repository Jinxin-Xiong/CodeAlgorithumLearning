
#include <iostream>
#include <vector>

using namespace std;


//The original Binary Search
int binary_search(const int* nums, const int numsCount, const int target){

  int left = 0, right = numsCount - 1, middle;

  while(left <= right){

    middle = left + (right - left) / 2;

    if(nums[middle] > target) { right = middle - 1; }

    else if(nums[middle] < target) { left = middle + 1; }

    else return middle;
  }

  return -1;

}

//35. 搜索插入位置
int binary_search_insert(const int* nums, const int numsCount, const int target){

  int left = 0, right = numsCount - 1, middle;

  while(left <= right){

    middle = left + (right - left) / 2;

    if(nums[middle] > target) { right = middle - 1; }

    else if(nums[middle] < target) { left = middle + 1; }

    else return middle;
  }

  cout << left << "  " << right << endl;

  //if(nums[0] > target) return 0;

  //if(nums[numsCount] < target) return numsCount + 1;

  return right + 1;

}

//34. 在排序数组中查找元素的第一个和最后一个位置
int binary_search_startpos(const vector<int>& nums, const int target){

  int left = 0, right = nums.size() - 1, middle, startPos = -1;

  while(left <= right){

    middle = left + (right - left) / 2;

    if(nums[middle] >= target) { right = middle - 1; }

    else { left = middle + 1; startPos = left; }
  }

  cout << left << "  " << right << endl;

  //if(nums[0] > target) return 0;

  //if(nums[numsCount] < target) return numsCount + 1;

  if(startPos == -1) return -1;

  if(nums[startPos] != target) return -1;
  else return startPos;
}

int binary_search_endpos(const vector<int>& nums, const int target){

  int left = 0, right = nums.size() - 1, middle, endPos = -1;

  while(left <= right){

    middle = left + (right - left) / 2;

    if(nums[middle] > target) { right = middle - 1; endPos = right; }

    else { left = middle + 1; }
  }

  cout << left << "  " << right << endl;

  //if(nums[0] > target) return 0;

  //if(nums[numsCount] < target) return numsCount + 1;

  if(endPos == -1) return -1;

  if(nums[endPos] != target) return -1;
  else return endPos;
}

//69. x的平方根
int mySqrt(int x){

  int left = 0, right = x, middle;

  if(x < 0) return -1;

  while(left <= right){

    middle = left + (right - left) / 2;

    if(middle * middle > x) { right = middle - 1; }

    else if(middle * middle < x) { left = middle + 1; }

    else return middle;
  }

  return right;

}

//367. 有效的完全平方数
bool is_perfect_square(int num){

  int left = 0, right = num, middle;

  while(left <= right){

    middle = left + (right - left) / 2;

    if(middle * middle > num) { right = middle - 1; }

    else if(middle * middle < num) { left = middle + 1; }

    else return true;
  }

  return false;

}



int main(){

  //int nums[6] = {-1,0,3,5,9,12};
  /* vector<int> nums = {5,7,7,8,8,10};
 
  int target = 8;

  int startIndex = binary_search_startpos(nums,target);
  int endIndex = binary_search_endpos(nums,target);

  cout << "The index of target number is:  " << startIndex << "  " << endIndex << endl;
 */

  int x = 123;

  bool sqrtNum = is_perfect_square(x);

  if(sqrtNum) cout << "The index of target number is:  True" << endl;
  else cout << "The index of target number is:  False" << endl;

  return 1;
}