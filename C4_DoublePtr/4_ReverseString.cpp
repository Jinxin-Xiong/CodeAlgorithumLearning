
#include <string>
#include <iostream>

using namespace std;

/* void RemoveFrontBlank(string& s){

  for (string::iterator ite = s.begin(); ite != s.end();){
    
    if((*ite) != ' ') break;

    ite = s.erase(ite);
  }  
}

void RemoveEndBlank(string& s){

  int length = s.length();

  int blank_count = 0;

  for (int i = length - 1; i >= 0; --i){
    
    if(s.at(i) != ' ') break;

    blank_count++;
  }

  if(blank_count > 0) s.resize(length - blank_count);
  
}

void RemoveMidBlank(string& s){

  bool blank_flag = false;

  for (string::iterator ite = s.begin(); ite != s.end();){
    
    if((*ite) != ' ') blank_flag = false;

    else{

      if(blank_flag) { ite = s.erase(ite, ite+1); continue; }

      else { blank_flag = true; }
    }

    ite++;
  }  
}

void SwapWordBlock(const int start_idx, const int end_idx, string& s){

  int front_index = start_idx, last_index = end_idx;

  while(front_index < last_index){

    char tmp = s[front_index];

    s[front_index] = s[last_index];

    s[last_index] = tmp;

    front_index++;

    last_index--;
  }
}

string reverseWords(string s) {

  RemoveFrontBlank(s);
  cout << s << endl;
  RemoveEndBlank(s);
  cout << s << endl;
  RemoveMidBlank(s);
  cout << s << endl;

  int start_index = 0, end_index = 0;

  SwapWordBlock(0, s.length() - 1, s);
  cout << s << endl;

  for (end_index = 0; end_index < s.length();){
    
    if(s[end_index] != ' ') end_index++;

    else{

      SwapWordBlock(start_index, end_index - 1, s);

      end_index++;

      start_index = end_index;
    }
  }

  SwapWordBlock(start_index, end_index - 1, s);

  return s;
  
} */

/*****   Better solution     ******/

void RemoveExtraBlank(string& str){

  int slow_idx = 0, i = 0;

  while(i < str.size()){
    
    if(str[i] != ' ' ){

      if(slow_idx != 0) str[slow_idx++] = ' '; 

      while(i < str.size() && str[i] != ' ') { str[slow_idx++] = str[i++]; }
    }

    else i++;
  }

  str.resize(slow_idx);
}

void ReverseStringBlock(const int start_idx, const int end_idx, string& s){

  for (int i = start_idx, j = end_idx; i <= end_idx && j >= start_idx && i < j; i++, j--){
    
    char tmp = s[i];

    s[i] = s[j];

    s[j] = tmp;
  }  
}

string reverseWords(string s) {

  string tmp = s;

  RemoveExtraBlank(tmp);

  ReverseStringBlock(0, tmp.size()-1, tmp);

  int start_idx = 0, end_idx = 0;

  for (int i = 0; i <= tmp.size(); i++){
    
    if(tmp[i] == ' '){

     end_idx = i - 1;

     ReverseStringBlock(start_idx, end_idx, tmp);

     start_idx = i + 1; 
    }

    if(i == tmp.size()) ReverseStringBlock(start_idx, i - 1, tmp);
  }
  
  return tmp;
}


int main(){

  string s =  " a good   example";


  cout << s << endl;

  RemoveExtraBlank(s);

  cout << s << endl;

  string out = reverseWords(s);
  
  cout << out << endl;
}