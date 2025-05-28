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

    TreeNode* recursiveTrimBST(TreeNode* node, int low, int high){

      if(node == NULL) return NULL;

      node->left = recursiveTrimBST(node->left, low, high);
      node->right = recursiveTrimBST(node->right, low, high);

      if(node->val < low) { 
        node = node->right; 
      }
      else if(node->val > high) { 
        node = node->left; 
      }
      
      return node;
    }


    TreeNode* trimBST(TreeNode* root, int low, int high) {

      if(root == NULL) return root;

      TreeNode* result = recursiveTrimBST(root, low, high);

      return result;        
    }
};