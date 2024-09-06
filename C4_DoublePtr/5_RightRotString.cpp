
#include <string>
#include <iostream>

using namespace std;

void ReverseStringBlock(const int start_idx, const int end_idx, string& s){

  for (int i = start_idx, j = end_idx; i <= end_idx && j >= start_idx && i < j; i++, j--){
    
    char tmp = s[i];

    s[i] = s[j];

    s[j] = tmp;
  }  
}

string rightRotString(string s, const int num) {

  string tmp = s;

  ReverseStringBlock(0, tmp.size() - 1, tmp);

  ReverseStringBlock(0, num - 1, tmp);
  
  ReverseStringBlock(num, tmp.size() - 1, tmp);
  
  return tmp;
}


int main(){

  string s =  "abcdefg";

  int num = 2;

  cout << s << endl;

  string out = rightRotString(s, num);
  
  cout << out << endl;
}