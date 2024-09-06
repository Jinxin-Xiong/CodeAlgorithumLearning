#include<iostream>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {

  if(ransomNote.size() > magazine.size()) return false;

  int hash_magazine[26] = {0};

  for(auto& letter : magazine){

    hash_magazine[letter - 'a']++;
  }

  for(auto& letter : ransomNote){

    hash_magazine[letter - 'a']--;

    if(hash_magazine[letter - 'a'] < 0) return false;
  }

  return true;
}

int main(){

  string ransomNote = "aa";

  string magazine = "ab";

  bool result = canConstruct(ransomNote, magazine);

  string out_str = result == false ? "false" : "true";

  cout << out_str << endl;
}