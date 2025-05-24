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

    int getDepth(TreeNode* node){

      if(node == NULL) return 0;

      int leftdepth = getDepth(node->left);

      if(leftdepth == -1) return -1;

      int rightdepth = getDepth(node->right);

      if(rightdepth == -1) return -1;

      if(abs(leftdepth-rightdepth) > 1) return -1;
      else return (1 + max(leftdepth, rightdepth));
    }

   
    bool isBalanced(TreeNode* root) {

      if(root == NULL) return true;

      int height = getDepth(root);

      if(height == -1) return false;

      return true;
        
    }
};