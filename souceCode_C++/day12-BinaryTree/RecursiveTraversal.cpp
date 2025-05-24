#include <iostream>
#include <vector>

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

    void preorderTrav(TreeNode* root, vector<int>& treevec){

      if(root == NULL) return;

      treevec.push_back(root->val);
      preorderTrav(root->left, treevec);
      preorderTrav(root->right, treevec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
      
      vector<int> treevec;

      preorderTrav(root, treevec);

      return treevec;
    }

    void postorderTrav(TreeNode* root, vector<int>& treevec){

      if(root == NULL) return;
      
      postorderTrav(root->left, treevec);
      postorderTrav(root->right, treevec);

      treevec.push_back(root->val);
      
    }

    vector<int> postorderTraversal(TreeNode* root) {
        
      vector<int> treevec;

      postorderTrav(root, treevec);

      return treevec;
    }

    void inorderTrav(TreeNode* root, vector<int>& treevec){

      if(root == NULL) return;
      
      inorderTrav(root->left, treevec);

      treevec.push_back(root->val);

      inorderTrav(root->right, treevec);   
      
    }

    vector<int> inorderTraversal(TreeNode* root) {
        
      vector<int> treevec;

      inorderTrav(root, treevec);

      return treevec;
    }
};