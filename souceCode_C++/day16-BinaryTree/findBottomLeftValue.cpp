#include<iostream>
#include<queue>
#include<limits>

using namespace std;

struct TreeNode{

  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(NULL), right(NULL) {}

};

//层序遍历
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

      if(root == NULL) return 0;

      int result;

      queue<TreeNode*> que;

      que.push(root);

      while (!que.empty()){
        
        int size = que.size();

        for (int i = 0; i < size; i++){
          
          TreeNode* tmp = que.front();
          que.pop();

          if(i == 0) result = tmp->val;

          if(tmp->left) que.push(tmp->left);
          if(tmp->right) que.push(tmp->right);
        }       
      }

      return result;         
    }
};

//前序递归&回溯
class Solution {
public:

    int maxdepth_ = __INTMAX_MAX__;

    int result;

    void recursiveFindBL(TreeNode* node, int depth){

      if(node->left == NULL && node->right == NULL){

        if(depth > maxdepth_){

          maxdepth_ = depth;

          result = node->val;
        }

        return;
      }

      if(node->left) {
        
        depth++;
        recursiveFindBL(node->left, depth);
        depth--;
      }

      if(node->right){

        depth++;
        recursiveFindBL(node->right, depth);
        depth--;
      }

    }

    int findBottomLeftValue(TreeNode* root) {

      int depth = 0;
      recursiveFindBL(root,depth);

      return result;
    }
};