
/* 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。 */

#include <iostream>
#include <vector>

using namespace std;

/*Idea:
    1. 使用二分查找
    2. 二分查找的前提是 a.有序数组；b.数组中无重复元素
    3. 区间定义要明确，我比较习惯左闭右闭的方式
    4. 迭代条件要注意，left == right是有意义的
    5. 给定leftIndex, rightIndex, middleIndex
    6. 迭代更新以上值，直到给定leftIndex > rightIndex

    时间复杂度：O(logn)
    空间复杂度：O(1)

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
      int left_index = 0, right_index = nums.size() - 1, mid_index;

      while (right_index >= left_index){
        
        mid_index = left_index + (right_index - left_index) / 2;

        if(nums.at(mid_index) == target) return mid_index;

        else if(nums.at(mid_index) > target) { right_index = mid_index - 1; }
        
        else { left_index = mid_index + 1; }
      }

      return -1;        
    }
};