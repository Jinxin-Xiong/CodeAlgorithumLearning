#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

      vector<int> word_array(26,0);

      for (auto x : magazine){
        
        word_array[x - 'a']++;
      }

      for(auto x : ransomNote){
        word_array[x - 'a']--;
      }

      for(auto x : word_array){
        if(x < 0) return false;
      }
      
      return true;        
    }
};
