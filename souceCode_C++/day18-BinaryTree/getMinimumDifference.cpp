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

    int mindiff_ = INT_MAX;
    TreeNode* pre;

    void recursiveMinDiff(TreeNode* root){

      if(root == NULL) return;
      
      recursiveMinDiff(root->left);

      if(pre != NULL) { mindiff_ = min(mindiff_, abs(pre->val - root->val)); }
      
      pre = root;

      recursiveMinDiff(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
      
      if(root == NULL) return -1;
      if(root->left == NULL && root->right == NULL) return -1;

      recursiveMinDiff(root);

      return mindiff_;
    }
};