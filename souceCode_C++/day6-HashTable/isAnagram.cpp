#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram_map(string s, string t) {

      if(t.size() != s.size()) return false;

      unordered_map<char, int> word_map;

      for (auto letter: s){

        unordered_map<char, int>::iterator it = word_map.find(letter);

        if(it == word_map.end()) {

          word_map.insert({letter, 1});
        }

        else{
        
          it->second += 1;
        }

      }

      for (auto letter: t){

        unordered_map<char, int>::iterator it = word_map.find(letter);

        if(it == word_map.end()) return false;

        else{

          it->second -= 1;

          if(it->second <= 0) word_map.erase(letter);
        }
      }

      if(word_map.size() > 0) return false;
      
      return true;
    }

    bool isAnagram(string s, string t) {

      if(t.size() != s.size()) return false;

      vector<int> word_array(26, 0);

      for (auto x : s){
        
        word_array[x - 'a']++;
      }

      for(auto x : t){

        word_array[x - 'a']--;
      }

      for(auto x : word_array){
        if(x != 0) return false;
      }

      return true;
      
    }
};

