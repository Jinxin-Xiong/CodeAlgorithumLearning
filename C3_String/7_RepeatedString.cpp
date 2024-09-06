#include<iostream>
#include<string>
#include<vector>

using namespace std;

int setupExtTable(const string s, vector<int>& next){

  int i = 0, j = 0, repeat_index = 0;

  bool b_first = false;

  next[0] = 0;

  for (i = 1; i < s.size(); ++i){
    
    while(j > 0 && s[i] != s[j]) j = next[j-1];

    if(s[i] == s[j]) j++;

    next[i] = j;

    if(next[i] > 0 && !b_first) { repeat_index = i; b_first = true; }
  }

  return repeat_index;
  
}

bool repeatedSubstringPattern(string s){

  vector<int> next(s.size(), 0);

  int repeat_index = setupExtTable(s, next);

  int length = next[s.size()-1];

  if(length > 0 && s.size() % (s.size() - length) == 0) return true;

  return false;
}

int main(){

  string s = "abaababaab";

  bool is_repeated_str = repeatedSubstringPattern(s);

  string out = is_repeated_str == false ? "false" : "true";

  int x = 12 % 9;

  cout << x << endl;

  cout << out << endl;

  return 0;
}