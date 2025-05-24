#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct TreeNode{
  
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(NULL), right(NULL) {};
};

class Solution {
public:

    int result;

    void recursiveDepth(TreeNode* node, int depth){

      result = result > depth ? result : depth;

      if(node->left == NULL && node->right == NULL) return;

      if(node->left){

        recursiveDepth(node->left, 1+depth);
      }

      if(node->right){
        recursiveDepth(node->right, 1+depth);
      }

    }

    int maxDepth(TreeNode* root) {
        
      if(root == NULL) return 0;

      result = 0;

      int depth = 1;

      recursiveDepth(root, depth);

      return result;
    }
};