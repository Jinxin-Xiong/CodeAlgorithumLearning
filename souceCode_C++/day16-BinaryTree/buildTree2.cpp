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

    TreeNode* recursiveTree(vector<int>& preorder, int preorder_tree_begin, int preorder_tree_end, vector<int>& inorder, int inorder_tree_begin, int inorder_tree_end){

      if(preorder_tree_begin == preorder_tree_end) return NULL;

      int root_value = preorder[preorder_tree_begin];
      TreeNode* root = new TreeNode(root_value);

      if(preorder_tree_end - preorder_tree_begin == 1) return root;

      int index = 0;
      for(int i = inorder_tree_begin; i < inorder_tree_end; i++){

        if(inorder[i] == root_value) { index = i; break; }
      }

      int new_inorder_lefttree_begin = inorder_tree_begin;
      int new_inorder_lefttree_end = index;

      int new_inorder_righttree_begin = index + 1;
      int new_inorder_righttree_end = inorder_tree_end;

      int new_preorder_lefttree_begin = preorder_tree_begin + 1;
      int new_preorder_lefttree_end = new_preorder_lefttree_begin + (new_inorder_lefttree_end - new_inorder_lefttree_begin);

      int new_preorder_righttree_begin = new_preorder_lefttree_end;
      int new_preorder_righttree_end = preorder_tree_end;

      root->left = recursiveTree(preorder,new_preorder_lefttree_begin, new_preorder_lefttree_end, inorder, new_inorder_lefttree_begin, new_inorder_lefttree_end);
      root->right = recursiveTree(preorder, new_preorder_righttree_begin, new_preorder_righttree_end, inorder, new_inorder_righttree_begin, new_inorder_righttree_end);

      return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

      if(preorder.size() == 0 || inorder.size() == 0) return NULL;

      TreeNode* root = recursiveTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());

      return root;
        
    }
};