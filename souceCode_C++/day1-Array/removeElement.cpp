/* 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：

更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
返回 k。

  示例 1：

  输入：nums = [3,2,2,3], val = 3
  输出：2, nums = [2,2,_,_]
  解释：你的函数函数应该返回 k = 2, 并且 nums 中的前两个元素均为 2。
  你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
  示例 2：

  输入：nums = [0,1,2,2,3,0,4,2], val = 2
  输出：5, nums = [0,1,4,0,3,_,_,_]
  解释：你的函数应该返回 k = 5，并且 nums 中的前五个元素为 0,0,1,3,4。
  注意这五个元素可以任意顺序返回。
  你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。 */

/*
Idea:

  1. 暴力解法
     a.定义一个新数组，遍历nums数组，不等于val的元素填入新数组
     b.将新数组的元素复制到nums中

     时间复杂度O(n*n)
     空间复杂度O(1)

  2. 双指针法
     a.定义快慢指针
     b.利用快指针遍历数组，当索引元素不等于目标值时，将慢指针索引元素赋值为快指针索引元素，
       慢指针索引+1，否则不变
     c.遍历结束后，慢指针索引即为不等于目标值的元素数量

     时间复杂度O(n)
     空间复杂度O(1)

*/

#include <vector>

using namespace std;

class Solution {
public:
    int removeElementBruteForce(vector<int>& nums, int val) {
        
      int array_size = nums.size();

      for (int i = 0; i < array_size; i++){
        
        if(nums.at(i) == val){

          for (int j = i + 1; j < array_size; j++){
          
            nums.at(j-1) = nums.at(j);
          }

          i--;

          array_size--;
          
        }

        return array_size;
      
      }
    }

    int removeElement(vector<int>& nums, int val) {
        
      int fast_index = 0, slow_index = 0;

      while (fast_index < nums.size()){
        
        if(nums[fast_index] != val) { nums[slow_index] = nums[fast_index]; slow_index++; }

        fast_index++; 
      }

      return slow_index;
    }
};