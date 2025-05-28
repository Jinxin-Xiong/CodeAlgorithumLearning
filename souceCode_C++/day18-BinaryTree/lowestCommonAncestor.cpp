#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_set>
#include<algorithm>

using namespace std;

struct  TreeNode{
  
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    //记录下p，q从深到浅所有的父节点，存在数组中，对比数组中最先出现的父节点，耗时且需要额外空间
    bool findLeafFromVector(TreeNode* node, vector<TreeNode*> array){

      for(int i = 0; i < array.size(); i++){

        if(node->val == array[i]->val) return true;
      }

      return false;
    }

    void recursiveFindParents(TreeNode* cur, vector<TreeNode*>& array){

      if(cur == NULL) return;

      recursiveFindParents(cur->left, array);
      recursiveFindParents(cur->right, array);

      if(cur->left && findLeafFromVector(cur->left, array)) { array.push_back(cur); return; }
      if(cur->right && findLeafFromVector(cur->right, array)) { array.push_back(cur); return; }
     //if(array.find(cur)!=array.end()) { array.insert(cur); return; }

    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
      vector<TreeNode*> parents_p;
      parents_p.push_back(p);
      recursiveFindParents(root, parents_p);

      vector<TreeNode*> parents_q;
      parents_q.push_back(q);
      recursiveFindParents(root, parents_q);

      for(int i = 0; i < parents_p.size(); i++){
        TreeNode* parent = parents_p[i];
        cout << parent->val << endl;
      }
      for(int i = 0; i < parents_p.size(); i++){

        TreeNode* parent = parents_p[i];

        if(!findLeafFromVector(parent, parents_q)) continue;

        return parent;
      }

      return NULL;
    }

    //后序遍历树，找到最近公共祖先，不需要额外空间
    TreeNode* recursiveFindParent(TreeNode* node, TreeNode* p, TreeNode* q){

      if(node == NULL) return NULL;
      if(node == p || node == q) return node;

      TreeNode* left = recursiveFindParent(node->left, p, q);
      TreeNode* right = recursiveFindParent(node->right, p, q);

      if(left == NULL && right == NULL) return NULL;
      else if(left != NULL && right == NULL) return left;
      else if(left == NULL && right != NULL) return right;
      else return node;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
      if(root == NULL || p == NULL || q == NULL) return NULL;

      TreeNode* result = recursiveFindParent(root, p, q);

      return result;   
    }
    
};