#include<iostream>
#include<vector>
#include<limits.h>
#include<map>
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

    //用map结构去存储，因此开辟了额外的内存
    TreeNode* pre = NULL;
    int pretimes_ = 0;

    void recursiveFindMode(TreeNode* node, map<int, vector<int>>& modes){

      if(node == NULL) return ;

      recursiveFindMode(node->left, modes);

      if(pre != NULL){

        if(pre->val == node->val) pretimes_++;
        else{
          
          if(modes.find(pretimes_) == modes.end()){
            
            vector<int> tmp{pre->val};
            modes.insert(make_pair(pretimes_, tmp));
          }
          else{ modes[pretimes_].push_back(pre->val); }

          pre = node; pretimes_ = 1;
        }
      }
      else{

          pre = node; pretimes_ = 1;
      }

      recursiveFindMode(node->right, modes);      
    }

    vector<int> findMode(TreeNode* root) {

      vector<int> result;

      if(root == NULL) return result;

      map<int, vector<int>> outresult;

      recursiveFindMode(root, outresult);

      if(outresult.find(pretimes_) == outresult.end()){
            
            vector<int> tmp{pre->val};
            outresult.insert(make_pair(pretimes_, tmp));
      }
      else{ outresult[pretimes_].push_back(pre->val); }

      map<int, vector<int>>::reverse_iterator itr = outresult.rbegin();

      result = itr->second;

      return result;        
    }


    //无需开辟额外空间
    TreeNode* pre = NULL;
    int maxFreq = 0;
    int curFreq = 0;

    void recursiveFindMaxFreq(TreeNode* node, vector<int>& array){

      if(node == NULL) return;

      recursiveFindMaxFreq(node->left, array);

      if(pre == NULL){
        
        curFreq = 1;
      }
      else{

        if(pre->val == node->val) curFreq++;
        else curFreq = 1;
      }

      pre = node;

      if(curFreq == maxFreq) array.push_back(node->val);

      else if(curFreq > maxFreq){

        array.clear();

        array.push_back(node->val);

        maxFreq = curFreq;
      }


      recursiveFindMaxFreq(node->right, array);
    }

    vector<int> findMode(TreeNode* root) {

      vector<int> array;

      if(root == NULL) return array;

      recursiveFindMaxFreq(root, array);

      return array;

    }

    //如果不是二叉搜索树，只是普通的二叉树，该如何计算
    void recursiveSearchTree(TreeNode* node, map<int,int>& basket){

      if(node == NULL) return;

      basket[node->val]++;

      recursiveSearchTree(node->left, basket);
      recursiveSearchTree(node->right, basket);
    }

    static bool cmp(pair<int, int> a, pair<int, int> b){

      return a.second > b.second;
    }

    vector<int> findMode(TreeNode* root) {

      map<int, int> basket;

      recursiveSearchTree(root, basket);

      vector<pair<int, int>> basket_array(basket.begin(), basket.end());

      sort(basket_array.begin(),basket_array.end(),cmp);

      vector<int> result{basket_array[0].first};

      for(int i = 1; i < basket_array.size(); i++){

        if(basket_array[i].second == basket_array[0].second) result.push_back(basket_array[i].first);
      }

      return result;

    }
};