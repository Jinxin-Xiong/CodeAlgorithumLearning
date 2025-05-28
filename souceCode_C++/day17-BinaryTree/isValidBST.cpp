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

    //将二叉树通过中序遍历转换为数组，再判断数组是否是递增数组
    void recursiveBST(TreeNode* root, vector<int>& array){

      if(root == NULL) return;

      recursiveBST(root->left, array);

      array.push_back(root->val);

      recursiveBST(root->right, array);
    }

    bool isValidBST(TreeNode* root) {

        if(root == NULL) return true;

        vector<int> array;

        recursiveBST(root, array);

        int beginidx = 0, endidx = 1;

        if(array.size() <= 1) return true;

        while(endidx < array.size()){

          if(array[beginidx] >= array[endidx]) return false;

          beginidx++; endidx++;
        }

        return true;
    }

    //中序递归二叉树
    TreeNode* pre = NULL;

    bool recursiveBST(TreeNode* root){

      if(root == NULL) return true;

      bool leftresult = recursiveBST(root->left);

      if(pre != NULL && pre->val >= root->val) return false;

      pre = root;

      bool rightresult = recursiveBST(root->right);

      return leftresult & rightresult;

    }

    bool isValidBST(TreeNode* root) {

      bool result = recursiveBST(root);

      return result;
    }
};