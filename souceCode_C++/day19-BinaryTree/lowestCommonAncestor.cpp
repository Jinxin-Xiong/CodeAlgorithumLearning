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

    //遍历法
    TreeNode* recursiveFindParent(TreeNode* node, TreeNode* p, TreeNode* q){

        if(node == NULL) return NULL;        
       
        TreeNode* result = NULL;

        if(node->val > p->val && node->val > q->val) result = recursiveFindParent(node->left, p, q);
        else if(node->val < p->val && node->val < q->val) result = recursiveFindParent(node->right, p, q);
        else return node;

        return result;
    }   

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
      if(root == NULL || p == NULL || q == NULL) return NULL;

      TreeNode* result = recursiveFindParent(root, p, q);

      return result;
    }

    //迭代法
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

      while(root){

        if(root->val > p->val && root->val > q->val){

          root = root->left;
        }
        else if(root->val < p->val && root->val < q->val){

          root = root->right;
        }
        else{

          return root;
        }
      }

      return NULL;
    }
};