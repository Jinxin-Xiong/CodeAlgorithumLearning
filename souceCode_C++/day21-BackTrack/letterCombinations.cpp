#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:

    void backTracking(vector<vector<int>>& array, vector<char>& pair, vector<string>& combine, int startidx){

      if(pair.size() == array.size()){

        string tmp = "";

        for(auto x : pair) tmp += x;

        combine.push_back(tmp);

        return;
      }

      for (int i = startidx; i < array.size(); i++){
        
        for(int j = 0; j < array[i].size(); j++){

          char tmp = 'a' + array[i][j];
          pair.push_back(tmp);

          backTracking(array, pair, combine, i+1);
          
          pair.pop_back();
        }
      }
      
    }


    vector<string> letterCombinations(string digits) {

      vector<string> combine;
      if(digits.empty()) return combine;

      int number = stoi(digits);

      vector<vector<int>> array;

      while(number > 0){

        int tmp = number % 10;
        number /= 10;

        vector<int> pair;
        switch (tmp)
        {
        case 2:
          pair = {0,1,2};
          array.push_back(pair);
          pair.clear();
          break;
        case 3:
          pair = {3,4,5};
          array.push_back(pair);
          pair.clear();
          break;
        case 4:
          pair = {6,7,8};
          array.push_back(pair);
          pair.clear();
          break;
        case 5:
          pair = {9,10,11};
          array.push_back(pair);
          pair.clear();
          break;
        case 6:
          pair = {12,13,14};
          array.push_back(pair);
          pair.clear();
          break;
        case 7:
          pair = {15,16,17,18};
          array.push_back(pair);
          pair.clear();
          break;
        case 8:
          pair = {19,20,21};
          array.push_back(pair);
          pair.clear();
          break;
        case 9:
          pair = {22,23,24,25};
          array.push_back(pair);
          pair.clear();
          break;        
        default:
          break;
        }
      }

      std::reverse(array.begin(), array.end());

      vector<char> pair;

      int startidx = 0;

      backTracking(array, pair, combine, startidx);
      
      return combine;
    }

    //题解
    class Solution {
    private:
      const string letterMap[10] = {
          "", // 0
          "", // 1
          "abc", // 2
          "def", // 3
          "ghi", // 4
          "jkl", // 5
          "mno", // 6
          "pqrs", // 7
          "tuv", // 8
          "wxyz", // 9
      };

    public:
      vector<string> result;
      string s;

      void backTracking(const string& digits, int index){

        if(index == digits.size()){
          result.push_back(s);
          return;
        }

        int digit = digits[index] - '0';
        string letters = letterMap[digit];

        for (int i = 0; i < letters.size(); i++)
        {
          s.push_back(letters[i]);
          backTracking(digits, index+1);
          s.pop_back();
        }        
      }

      vector<string> letterCombinations(string digits) {
      
        s.clear();
        result.clear();
        if (digits.size() == 0) {
            return result;
        }
        backTracking(digits, 0);
        return result;
      }


};