#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x): val(x), left(NULL), right(NULL){};
};

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
      
      vector<int> result;

      stack<pair<TreeNode*, bool>> sta;

      if(root == NULL) return result;

      sta.push(make_pair(root, false));

      while(!sta.empty()){

        TreeNode* cur = sta.top().first;
        bool visited = sta.top().second;

        sta.pop();

        if(visited) { result.push_back(cur->val); continue; }

        if(cur->right) sta.push(make_pair(cur->right, false));

        if(cur->left) sta.push(make_pair(cur->left, false));

        sta.push(make_pair(cur, true));       

      }      

      return result;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        
      vector<int> result;

      stack<pair<TreeNode*, bool>> sta;

      if(root == NULL) return result;

      sta.push(make_pair(root, false));

      while(!sta.empty()){

        TreeNode* cur = sta.top().first;
        bool visited = sta.top().second;

        sta.pop();

        if(visited) { result.push_back(cur->val); continue; }

        sta.push(make_pair(cur, true));

        if(cur->right) sta.push(make_pair(cur->right, false));

        if(cur->left) sta.push(make_pair(cur->left, false));

      }      

      return result;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        
      vector<int> result;

      stack<pair<TreeNode*, bool>> sta;

      if(root == NULL) return result;

      sta.push(make_pair(root, false));

      while(!sta.empty()){

        TreeNode* cur = sta.top().first;
        bool visited = sta.top().second;

        sta.pop();

        if(visited) { result.push_back(cur->val); continue; }

        if(cur->right) sta.push(make_pair(cur->right, false));

        sta.push(make_pair(cur, true));

        if(cur->left) sta.push(make_pair(cur->left, false));

      }      

      return result;
    }
};