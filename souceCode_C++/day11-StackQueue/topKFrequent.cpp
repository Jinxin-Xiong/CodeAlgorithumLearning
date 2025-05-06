#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){

  return a.second > b.second;
}

struct MyComparison{

  bool operator() (const pair<int,int>&a , const pair<int,int>& b){
    a.second > b.second;
  }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if(nums.size() < 2) return nums;

        priority_queue<int> que;

        for (int i = 0; i < nums.size(); i++){
          
          que.push(nums[i]);
        }

        vector<pair<int, int>> sorted_factors;

        int factor = 0, times = 0;

        factor = que.top(); times++;  que.pop();

        while(!que.empty()){

          int tmp = que.top();

          if(tmp == factor) times++;
          else {

            sorted_factors.push_back(pair<int, int>(factor, times));
            
            factor = tmp;
            times = 1;
          }

          que.pop();
        }

        sorted_factors.push_back(pair<int, int>(factor, times));
        
        sort(sorted_factors.begin(), sorted_factors.end(), compare);

        vector<int> out;

        for (int i = 0; i < k; i++){
          
          out.push_back(sorted_factors[i].first);
        }
        
        return out;
    }

    vector<int> topKFrequentOptimize(vector<int>& nums, int k) {
        
        if(nums.size() < 2) return nums;

        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){

          map[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparison> que;

        for(unordered_map<int, int>::iterator itr = map.begin(); itr != map.end(); itr++){

          que.push(*itr);

          if(que.size() > k) que.pop();
        }

        vector<int> result;

        for (int i = 0; i < k; i++){
          result.push_back(que.top().first);
          que.pop();
        }
      
        return result;        
    }
};