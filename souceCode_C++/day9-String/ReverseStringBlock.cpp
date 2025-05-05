#include <iostream>
#include <string>

using namespace std;

void ReverseString(string& s, const int startpos, const int endpos){

  if(startpos >= endpos) return;

  int left_idx = startpos, right_idx = endpos;

  while(left_idx < right_idx){

    swap(s[left_idx], s[right_idx]);

    left_idx++; right_idx--;
  }
}

void ReverseStringBlock(const int k, string& s){

  ReverseString(s, 0, s.size() - 1);

  ReverseString(s, 0, k-1);

  ReverseString(s, k, s.size() - 1);
}

int main(){

  int k;
  cout << "k is: ";
  cin >> k;

  cout << endl;

  string s;
  cout << "string is: ";
  cin >> s;

  ReverseStringBlock(k, s);
  

  cout << "result is:  " << s << endl;
}