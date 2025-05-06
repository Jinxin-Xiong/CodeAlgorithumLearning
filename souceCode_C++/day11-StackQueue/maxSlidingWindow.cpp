#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
#include <queue>

using namespace std;

class MyDeque {

  private:
    deque<int> que;
  
  public:
    void pop(const int val){

      if(!que.empty() && val == que.front()) que.pop_front();
    }

    void push(const int val){

      while(!que.empty() && val > que.back()) que.pop_back();

      que.push_back(val);
    }

    int getMaxValue(){
      return que.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindowBruteForce(vector<int>& nums, int k) {
        
        vector<int> out;

        int leftbounder, rightbounder;
        int maxvalue;

        for (int i = 0; i < nums.size() - k + 1; i++){
          
          leftbounder = i; rightbounder = i + k - 1;

          maxvalue = INT_MIN;

          while(leftbounder <= rightbounder){

            maxvalue = max(maxvalue, nums[leftbounder]);

            leftbounder++;
          }

          out.push_back(maxvalue);
        }

        return out;        
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
      if(nums.empty()) return nums;

      MyDeque que;

      vector<int> out;

      for(int i = 0; i < k; i++){ que.push(nums[i]); }

      out.push_back(que.getMaxValue()); 

      for(int i = k; i < nums.size(); i++){

        que.pop(nums[i-k]);
        que.push(nums[i]);

        out.push_back(que.getMaxValue());       
      }
    
      return out;
    }
};