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

    int recursiveCountNodes(TreeNode* node){

      if(node == NULL) return 0;      

      int leftcount = recursiveCountNodes(node->left);
      int rightcount = recursiveCountNodes(node->right);

      return leftcount + rightcount + 1;
    }

    int countNodes(TreeNode* root) {

        int count = 0;

        count = recursiveCountNodes(root);

        return count;
    }
};