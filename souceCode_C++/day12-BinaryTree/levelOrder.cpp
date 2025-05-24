#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode{
  
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(NULL), right(NULL) {};
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

      vector<vector<int>> result;

      if(root == NULL) return result;

      queue<TreeNode*> que;

      que.push(root);

      while(!que.empty()){

        int size = que.size();

        vector<int> layer;

        for(int i = 0; i < size; i++){

          TreeNode* cur = que.front();

          layer.push_back(cur->val);

          que.pop();

          if(cur->left) que.push(cur->left);
          if(cur->right) que.push(cur->right);
        }

        result.push_back(layer);
      }

      return result;
        
    }

    void recursiveOrder(TreeNode* root, vector<vector<int>>& result, int depth){

      if(root == NULL) return;

      if(result.size() == depth) result.push_back(vector<int>());

      result[depth].push_back(root->val);

      recursiveOrder(root->left, result, depth + 1);
      recursiveOrder(root->right, result, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root){

      vector<vector<int>> result;

      int depth = 0;

      recursiveOrder(root, result, depth);

      return result;
    } 
};