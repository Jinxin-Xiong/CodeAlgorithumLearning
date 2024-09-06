#include <iostream>
#include <string>
#include <vector>

using namespace std;

void buildNextTable(const string str, int*& next){

  int i = 0, j = 0;

  next[0] = 0;

  for (i = 1; i < str.size(); i++){
    
    while (j > 0 && str[i] != str[j]) { j = next[j - 1]; }

    if(str[i] == str[j]) { j++; }

    next[i] = j;
    
  }  
}

int strStr(const string haystack, const string needle){

  if(needle.empty()) return 0;

  if(haystack.empty() || haystack.size() < needle.size()) return -1;

  int needle_size = needle.size();

  int* next = new int[needle_size]{0};

  buildNextTable(needle, next);

  int needle_index = 0;
  
  for ( int hay_index = 0; hay_index < haystack.size(); hay_index++){
    
    while(needle_index > 0 && needle[needle_index] != haystack[hay_index]){ needle_index = next[needle_index - 1]; }

    if(needle[needle_index] == haystack[hay_index]) { needle_index++; }

    if(needle_index == needle_size ) { return (hay_index - needle_size + 1); }
  }

  delete[] next;

  return -1;
} 

int main(){

  string str = "mississippi";

  string needle = "issip";

  int index = strStr(str, needle);

  cout << index << endl;
}
