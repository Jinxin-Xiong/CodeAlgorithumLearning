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

    TreeNode* pre = NULL;

    void recursiveConvertBST(TreeNode* root) {
        
      if(root == NULL) return ;

      recursiveConvertBST(root->right);

      if(pre != NULL){

        root->val += pre->val;
      }

      pre = root;

      recursiveConvertBST(root->left);  
    }

    TreeNode* convertBST(TreeNode* root) {
      
      if(root == NULL) return NULL;

      recursiveConvertBST(root);

      return root;
    }
};