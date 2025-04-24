/* 给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 

提示：

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

进阶：

如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。 */

/*
Idea:

暴力解法：
  a.两个循环实现
  b.从第0个元素开始，首尾指针指向第0个元素，向前移动尾指针，直到首尾指针区间内的数值和大与等于target
  c.一旦满足b条件，首指针向前移动，尾指针回到首指针处
  d.当首尾指针移动到最后一个元素，且不满足总和大于target的条件，则返回0

  时间复杂度：O(n*n)
  空间复杂度：O(1)

滑动窗口法：
  a.一个循环实现
  b.设置循环条件，如果首和尾指针的索引超出了数组大小，则跳出
  c.从第0个元素开始，首尾指针指向第0个元素，向前移动尾指针，直到首尾指针区间内的数值和大与等于target
  d.一旦满足d条件，首指针向前移动，尾指针不变，并将元素合的变量减去首指针上一次指的元素
  e.当循环条件触发，跳出循环，则判断记录的最小长度是否是初始值，输出

  Tip:在编程时，比较容易陷入暴力解法，关键是首尾指针的移动时机的判定

  时间复杂度:O(n)
  空间复杂的:O(1)

*/
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:

//Brute Force
    int minSubArrayLenBruteForce(int target, vector<int>& nums) {
        
      int start_index = 0, end_index = 0, sum_val = 0, min_len = INT_MAX;

      for (start_index = 0; start_index < nums.size(); start_index++){
        
        sum_val = 0; end_index = start_index;

        while (end_index < nums.size()){
        
          if(end_index - start_index + 1 >= min_len) break;

          sum_val += nums[end_index];

          if(sum_val >= target) { min_len = min(min_len, end_index - start_index + 1); break; }

          end_index++;

        }        
      }

      return min_len == INT_MAX ? 0 : min_len;      
    }

//Sliding windows
    int minSubArrayLen(int target, vector<int>& nums) {
    
      int end_idx = 0, start_idx = 0, sum_val = 0, min_len = INT32_MAX;

      for ( end_idx = 0; end_idx < nums.size(); end_idx++){
        
        sum_val += nums[end_idx];

        if(sum_val >= target){

          while (start_idx <= end_idx && sum_val >= target){
            
            min_len = min(min_len, end_idx - start_idx + 1);

            sum_val -= nums[start_idx++];
          }      
        }
      }

      return min_len == INT32_MAX ? 0 : min_len;
    }
};

int main(){

  vector<int> fruit = { 2,3,1,2,4,3 };

  Solution obj;
  int num = obj.minSubArrayLen(7,fruit);

  cout << num << endl;
}