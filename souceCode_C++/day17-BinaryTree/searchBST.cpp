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

    TreeNode* recursiveBST(TreeNode* root, int val){

      if(root == NULL) return NULL;

      if(root->val == val) return root;

      TreeNode* result = NULL;

      if(root->val < val) result = recursiveBST(root->right, val);
      else result = recursiveBST(root->left, val);

      return result;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        
      if(root == NULL) return NULL;

      TreeNode* result = recursiveBST(root, val);

      return result;
    }
};