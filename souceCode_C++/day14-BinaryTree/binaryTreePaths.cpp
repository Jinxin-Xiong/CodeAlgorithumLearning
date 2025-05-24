#include<iostream>
#include<string>
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

    void traversal(TreeNode* node, vector<int>& path, vector<string>& strpathes){

      path.push_back(node->val);

      if(node->left == NULL && node->right == NULL){

        string str;

        for(int i = 0; i < path.size()-1; i++){

          str += to_string(path[i]);
          str += "->";
        }

        str += to_string(path[path.size()-1]);

        strpathes.push_back(str);

        return;
      }

      if(node->left) { traversal(node->left, path, strpathes); path.pop_back(); }
      if(node->right) { traversal(node->right, path, strpathes); path.pop_back(); }
    }

    vector<string> binaryTreePaths(TreeNode* root) {

      vector<int> path;

      vector<string> strpathes;

      traversal(root, path, strpathes);

      return strpathes;
        
    }
};

