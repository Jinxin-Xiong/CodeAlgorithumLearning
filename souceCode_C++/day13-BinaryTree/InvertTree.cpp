#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
  
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(NULL), right(NULL) {};
};

class Solution {
public:

    void recursiveInvertTree(TreeNode* &node){

      if(node == NULL) return;

      TreeNode* tmp = node->left;
      node->left = node->right;
      node->right = tmp;

      recursiveInvertTree(node->left);
      recursiveInvertTree(node->right);
    }

    TreeNode* invertTree(TreeNode* root) {

      if(root == NULL) return root;

      recursiveInvertTree(root);

      return root;        
    }
};