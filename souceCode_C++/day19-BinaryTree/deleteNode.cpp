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

    TreeNode* recursiveDelNode(TreeNode* node, int key){

      if(node == NULL) return NULL;

      //middle
      if(key == node->val){

        if(node->left == NULL && node->right == NULL) { delete node; return NULL; }
        else if(node->left == NULL && node->right != NULL){ TreeNode* out = node->right; delete node; return out; }
        else if(node->left != NULL && node->right == NULL) { TreeNode* out = node->left; delete node; return out; }
        else{

          TreeNode* cur = node->right;
          while(cur->left) cur = cur->left;

          cur->left = node->left;

          TreeNode* tmp = node;
          node = node->right;

          delete tmp;
          return node;
        }
      }

      //left
      else if(key < node->val) node->left = recursiveDelNode(node->left, key);
      
      //right
      else node->right = recursiveDelNode(node->right, key);

      return node;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {

      if(root == NULL) return root;

      TreeNode* result = recursiveDelNode(root, key);

      return result;
    }
};