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

    bool recursiveInvertTree(TreeNode* left, TreeNode* right){

      if(left == NULL && right != NULL) return false;
      else if(left != NULL && right == NULL) return false;
      else if(left == NULL && right == NULL) return true;
      else if(left->val != right->val) return false;
      
      bool bresult1 = recursiveInvertTree(left->left, right->right);
      bool bresult2 = recursiveInvertTree(left->right, right->left);
        
      bool result = bresult1 & bresult2;

      return result;            
    }

    bool isSymmetric(TreeNode* root) {

      if(root == NULL) return true;

      bool result = recursiveInvertTree(root->left, root->right);
      
      return result;
    }
};