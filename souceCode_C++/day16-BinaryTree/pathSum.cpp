#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{

  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(): val(0), left(NULL), right(NULL) {}

};


class Solution {
public:

    void recursiveTargetPath(TreeNode* node, int targetSum, vector<int>& path, vector<vector<int>>& allpath){

      path.push_back(node->val);

      if(node->left == NULL && node->right == NULL){

        int sum = 0;

        for(auto x : path) sum += x;

        if(sum == targetSum){

          allpath.push_back(path);
        }

        return;
      }

      if(node->left){

        recursiveTargetPath(node->left, targetSum, path, allpath);
        path.pop_back();
      }

      if(node->right){

        recursiveTargetPath(node->right, targetSum, path, allpath);
        path.pop_back();
      }

    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      
      vector<vector<int>> allpath;

      if(root == NULL) return allpath;

      vector<int> path;

      recursiveTargetPath(root, targetSum, path, allpath);

      return allpath;
    }
};

