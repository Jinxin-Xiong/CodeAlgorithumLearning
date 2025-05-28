#include<iostream>
#include<vector>

using namespace std;

struct  TreeNode{
  
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* recursiveSortedArrayToBST(vector<int>& nums, int beginid, int endid) {
    
      if(beginid >= endid) return NULL;

      int index = beginid + (endid - beginid) / 2;

      TreeNode* newnode = new TreeNode(nums[index]);

      int leftbeginid = beginid;
      int leftendid = index;

      int rightbeginid = index + 1;
      int rightendid = endid;

      newnode->left = recursiveSortedArrayToBST(nums, leftbeginid, leftendid);
      newnode->right = recursiveSortedArrayToBST(nums, rightbeginid, rightendid);

      return newnode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {

      if(nums.size() == 0) return NULL;

      TreeNode* result = recursiveSortedArrayToBST(nums, 0, nums.size());

      return result;        
    }
};