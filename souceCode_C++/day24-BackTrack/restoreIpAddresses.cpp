#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:

    vector<string> result;
    int dotnum = 0;

    bool isValidIP(string s, int start, int end){

      if(start > end) return false;

      if(s[start] == '0' && start != end) return false;

      int num = 0;
      for (int i = start; i <= end; i++){
        
        if(s[i] > '9' && s[i] < '0') return false;

        num = num * 10 + (s[i] - '0');

        if(num > 255) return false;
      }

      return true;      
    }

    void backTrack(string& s, int startidx){

      if(dotnum == 3){

        if (isValidIP(s, startidx, s.size() - 1)) { result.push_back(s); }

        return;
      }

      for (int i = startidx; i < s.size(); i++){
        
        if(!isValidIP(s, startidx, i)) continue;

        s.insert(s.begin()+i+1, '.');
        dotnum++;

        backTrack(s, i+2);

        s.erase(s.begin()+i+1);
        dotnum--;
      }
    }

    vector<string> restoreIpAddresses(string s) {
      
      if(s.empty()) return result;

      backTrack(s, 0);

      return result;
    }
};
