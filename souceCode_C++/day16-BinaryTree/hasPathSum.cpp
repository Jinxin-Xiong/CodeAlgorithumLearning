#include<iostream>

using namespace std;

struct TreeNode{

  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(NULL), right(NULL) {}

};

class Solution {
public:

    bool recursiveAllPath(TreeNode* node, int& count, int target){

      if(node->left == NULL && node->right == NULL){

        if(count == target) return true;
        
        return false;
      }

      if(node->left) {

        count += node->left->val;
        bool result = recursiveAllPath(node->left, count, target);
        if(result == true) return true;
        count -= node->left->val;
      }

      if(node->right){

        count += node->right->val;
        bool result = recursiveAllPath(node->right, count, target);
        if(result == true) return true;
        count -= node->right->val;        
      }

      return false;
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
      
      if(root == NULL) return false;

      int count = root->val;

      return recursiveAllPath(root, count, targetSum);
    }
};