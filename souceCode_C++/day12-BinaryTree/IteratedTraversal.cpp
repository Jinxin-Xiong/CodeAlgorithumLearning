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
      
      vector<int> treevec;

      stack<TreeNode*> treestack;

      treestack.push(root);

      TreeNode* cur;

      while(!treestack.empty()){

        cur = treestack.top();
        treestack.pop();

        treevec.push_back(cur->val);

        if(cur->right) treestack.push(cur->right);
        if(cur->left) treestack.push(cur->left);
      }

      return treevec;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        
      vector<int> treevec;

      if(root == NULL) return treevec;

      stack<TreeNode*> sta;

      sta.push(root);

      TreeNode* cur;

      while(!sta.empty()){

        cur = sta.top();
        sta.pop();

        treevec.push_back(cur->val);

        if(cur->left) sta.push(cur->left);
        if(cur->right) sta.push(cur->right);

      }

      reverse(treevec.begin(), treevec.end());

      return treevec;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        
      vector<int> treevec;

      stack<TreeNode*> sta;

      if(root == NULL) return treevec;

      TreeNode* cur = root;

      while(!sta.empty() || cur != NULL){

        if(cur != NULL){

          sta.push(cur);

          cur = cur->left;
        }
        else{

          cur = sta.top();
          sta.pop();

          treevec.push_back(cur->val);

          cur = cur->right;
        }
      }
      

      return treevec;
    }
};