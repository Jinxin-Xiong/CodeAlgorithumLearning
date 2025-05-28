#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

struct  TreeNode{
  
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};



class Solution {
public:

    TreeNode* recursiveBuildTree(vector<int>& nums, int beginidx, int endidx){

      if(beginidx >= endidx) return NULL;

      int rootidx, maxvalue = INT_MIN;

      for(int i = beginidx; i < endidx; i++){

        if(nums[i] > maxvalue) { rootidx = i; maxvalue = nums[i]; }
      }

      TreeNode* root = new TreeNode(maxvalue);

      if(endidx - beginidx == 1) return root;

      int beginleftidx = beginidx;
      int endleftidx = rootidx;

      int beginrightidx = rootidx + 1;
      int endrightidx = endidx;

      root->left = recursiveBuildTree(nums, beginleftidx, endleftidx);
      root->right = recursiveBuildTree(nums, beginrightidx, endrightidx);

      return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        if(nums.size() == 0) return NULL;

        TreeNode* root = recursiveBuildTree(nums, 0, nums.size());

        return root;
    }
};