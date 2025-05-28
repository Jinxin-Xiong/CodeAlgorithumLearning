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

    //迭代法
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      
      if(root == NULL){

        TreeNode* newroot = new TreeNode(val);

        return newroot;
      }

      TreeNode* node = root;

      TreeNode* pre = root;

      while(node){
        
        pre = node;

        if(node->val >= val){
          node = node->left;
        }
        else{
          node = node->right;
        }
      }

      TreeNode* newnode = new TreeNode(val);

      if(val <= pre->val ) pre->left = newnode;
      else pre->right = newnode;

      return root;
    }

    //遍历法
    TreeNode* recursiveBST(TreeNode* node, int val) {

      if(node == NULL){

        TreeNode* newnode = new TreeNode(val);
        
        return newnode;
      }

      TreeNode* result = NULL;

      if(val <= node->val) node->left = recursiveBST(node->left, val);
      else node->right = recursiveBST(node->right, val);

      return node;
    }


    TreeNode* insertIntoBST(TreeNode* root, int val) {

      if(root == NULL) {

        TreeNode* newnode = new TreeNode(val);
        
        return newnode;
      }

      recursiveBST(root, val);

      return root;

    }

};