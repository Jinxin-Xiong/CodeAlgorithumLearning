#include<iostream>


using namespace std;

struct TreeNode{

  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(NULL), right(NULL) {}

};

class Solution {
public:

    void recursiveSum(TreeNode* node, int& sum){

      if(node == NULL) return;

      if(node->left) recursiveSum(node->left, sum);
      if(node->right) recursiveSum(node->right, sum);

      if(node->left != NULL && node->left->left == NULL && node->left->right == NULL){

        sum += node->left->val;
        return;
      }
    }

    int sumOfLeftLeaves(TreeNode* root) {

      int sum = 0;

      if(root == NULL) return sum;

      recursiveSum(root, sum);

      return sum;
        
    }
};