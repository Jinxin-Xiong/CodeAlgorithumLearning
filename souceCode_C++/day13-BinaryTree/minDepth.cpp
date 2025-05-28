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

    int recursiveDepth(TreeNode* node){

      if(node == NULL) return 0;

      int result1 = recursiveDepth(node->left);
      int result2 = recursiveDepth(node->right);

      if(node->left == NULL && node->right != NULL) return 1 + result2;
      
      if(node->left != NULL && node->right == NULL) return 1 + result1;
      
      int result = 1 + min(result1, result2);

      return result;
    }

    int minDepth(TreeNode* root) {
        
      if(root == NULL) return 0;

      return recursiveDepth(root);
    }
};