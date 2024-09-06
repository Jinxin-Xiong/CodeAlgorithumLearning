#include<iostream>
#include<string>

using namespace std;


//空间复杂度O(n)
string reverseWords(string s){

  string output_str;

  int fast_index = s.size() - 1;

  int slow_index = s.size() - 1;

  while (fast_index > 0)
  {
    
    if(s.at(fast_index) != ' ') { fast_index--; continue; }

    if(s.at(fast_index) == ' ' && s.at(slow_index) == ' ') { fast_index--; slow_index--; continue; }  

    string tmp(s.begin() + fast_index + 1, s.begin() + slow_index + 1);

    output_str += tmp + " ";

    fast_index--;

    slow_index = fast_index;  

  }

  if(s.at(fast_index) != ' '){

    string tmp(s.begin(), s.begin() + slow_index + 1);

    output_str += tmp;
  }

  if(output_str.at(output_str.size()-1) == ' ') output_str.erase(output_str.size()-1);

  return output_str;
}

//空间复杂度O(1)
void removeExtraSpaces(string& s){

  int fast_index = 0, slow_index = 0;

  while(fast_index < s.size()){

    if(s[fast_index] == ' ') { fast_index++; continue; }

    while(fast_index < s.size() && s[fast_index] != ' '){

      s[slow_index++] = s[fast_index++];
    }

    s[slow_index++] = ' ';
  }

  s.resize(slow_index-1);

}

void reverse(string& s, int start, int end){

  for (int tmp_start = start, tmp_end = end; tmp_start < tmp_end; tmp_start++, tmp_end--){
    
    swap(s[tmp_start], s[tmp_end]);
  }
  
}

string reverseWordsEfficient(string s){

  removeExtraSpaces(s);

  reverse(s, 0, s.size()-1);

  int fast_ptr = 0, slow_ptr = 0;

  while (fast_ptr < s.size()){
    
    if(s[fast_ptr] == ' ') { reverse(s, slow_ptr, fast_ptr - 1); fast_ptr++; slow_ptr = fast_ptr; continue; }

    fast_ptr++;
  }

  reverse(s, slow_ptr, fast_ptr - 1);

  return s;
}

int main(){

  string s = "  hello world  ";

  cout << s << endl;

  //string out_str = reverseWords(s);

  string xx = reverseWordsEfficient(s);
  

  cout << xx << endl;
}