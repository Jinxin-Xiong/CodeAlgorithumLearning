#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{

  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x): val(x), left(NULL), right(NULL) {}

};

class Solution {
public:

    TreeNode* recursiveBinaryTree(vector<int>& indorder, vector<int>& postorder, int subinleftidx, int subinrightidx, int subpostleftidx, int subpostrightidx){

      if(subpostleftidx == subpostrightidx) return NULL;

      TreeNode* root = new TreeNode(postorder[subpostrightidx-1]);

      if (subpostrightidx - subpostleftidx == 1) return root;

      int index = 0;
      for (int i = subinleftidx; i < subinrightidx; i++){
        
        if(indorder[i] == postorder[subpostrightidx-1]) { index = i; break; }
      }

      int new_subinleftidx_lefttree = subinleftidx;
      int new_subinrightidx_lefttree = index;

      int new_subinleftidx_righttree = index + 1;
      int new_subinrightidx_righttree = subinrightidx;

      int new_subpostleftidx_lefttree = subpostleftidx;
      int new_subpostrightidx_lefttree = new_subinrightidx_lefttree - new_subinleftidx_lefttree;

      int new_subpostleftidx_righttree = new_subpostrightidx_lefttree;
      int new_subpostrightidx_righttree = subpostrightidx - 1;

      root->left = recursiveBinaryTree(indorder, postorder, new_subinleftidx_lefttree, new_subinrightidx_lefttree, new_subpostleftidx_lefttree, new_subpostrightidx_lefttree);
      root->right = recursiveBinaryTree(indorder, postorder, new_subinleftidx_righttree, new_subinrightidx_righttree, new_subpostleftidx_righttree, new_subpostrightidx_righttree);
      
      return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

      TreeNode* root;

      root = recursiveBinaryTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
      
      return root;
    }
};