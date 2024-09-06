#include<iostream>
#include<string>

using namespace std;

//Simplified code
inline void reverseStr_core(string& s, const int startIndex, const int endIndex){

  int startID = startIndex, endID = endIndex;

  while (startID < endID)
  {
    swap(s[startID], s[endID]);

    startID++;  endID--;
  }
  
}

string reverseStr(string s, int k){

  string tmp_s(s);

  for (int i = 0; i < tmp_s.size(); i += 2 * k){
    
    int left_charsize = tmp_s.size() - i; 

    if(left_charsize < k){ reverseStr_core(tmp_s, i, left_charsize - 1); }

    else { reverseStr_core(tmp_s, i, i + k - 1); }
  }
  
  return tmp_s;
}


int main(){

  string s = "abcdefg";

  int k = 2;

  string out = reverseStr(s, k);

  cout << s << endl;

  cout << out << endl;

  return 1;
}