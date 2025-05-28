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

    TreeNode* recursiveMergeTree(TreeNode* root1, TreeNode* root2){

      if(root1 == NULL) return root2;
      if(root2 == NULL) return root1;
      
      root1->val += root2->val;

      root1->left = recursiveMergeTree(root1->left, root2->left);
      root1->right = recursiveMergeTree(root1->right, root2->right);

      return root1;         
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      
      if(root1 == NULL) return root2;
      if(root2 == NULL) return root1;

      TreeNode* root = recursiveMergeTree(root1,root2);

      return root;
    }
};