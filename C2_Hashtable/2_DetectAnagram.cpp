#include <iostream>

using namespace std;

bool isAnagram(int* words_array, const string& s, const string& t){

  for(auto tmp : s){

    words_array[tmp - 'a']++;
  }

  for(auto tmp : t){

    words_array[tmp - 'a']--;
  }

  for(int i = 0; i < 26; ++i){

    if(words_array[i] != 0) return false;
  }

  return true;
  
}

int main(){

  int words_array[26] = {0};

  string s = "cat";

  string t  = "cat";

  bool result = isAnagram(words_array, s, t);

  cout << " result is:  " << result << endl;


  return 1;
}