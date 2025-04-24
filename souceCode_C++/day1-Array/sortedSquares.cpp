/* 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

 

示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
示例 2：

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
 

提示：

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 已按 非递减顺序 排序
 

进阶：

请你设计时间复杂度为 O(n) 的算法解决本问题 */

/*
Idea:
   a.定义一个新数组，去存储最终数组
   b.对于原始的非递减数组，如果存在负值元素的情况下，首尾的元素必是平方最大值；无负值元素情况下，尾部元素是最大值；
   c.使用双指针，一个指向首，一个指向尾，遍历数组，每次迭代时将两个指针索引的元素进行对比，平方较大值存入新数组；
   d.用一个索引从后往前填充新数组

   时间复杂的：O(n)
   空间复杂度：O(n)

*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

      vector<int> new_nums(nums.size());

      int new_index = nums.size() - 1;

      int start_index = 0, end_index = nums.size() - 1;

      while (start_index <= end_index){
        
        int start_square = nums[start_index]*nums[start_index];

        int end_square = nums[end_index]*nums[end_index];

        if(start_square >= end_square){

          new_nums[new_index--] = start_square;

          start_index++;
        }
        else{

          new_nums[new_index--] = end_square;

          end_index--;
        }
      }
      
      return new_nums;  
    }
};