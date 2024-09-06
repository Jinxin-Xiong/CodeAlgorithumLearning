#include<string>
#include <iostream>

using namespace std;


void printVec(string s){

  cout << s << endl;

}

void replaceNumberInString(string& str){

  string::iterator itr = str.begin();

  int digit_num = 0;

  while(itr != str.end()){

    if(isdigit(*itr)) digit_num++; 
    
    itr++;
  }

  int old_idx = str.size() - 1;

  str.resize(str.size() + 5 * digit_num);

  int new_idx = str.size() - 1;

  while(new_idx > old_idx){

    if(!isdigit(str[old_idx])){ str[new_idx] = str[old_idx]; new_idx--; old_idx--; continue; }

    str[new_idx--] = 'r';
    str[new_idx--] = 'e';
    str[new_idx--] = 'b';
    str[new_idx--] = 'm';
    str[new_idx--] = 'u';
    str[new_idx--] = 'n';

    old_idx--;
  }
  
}

int main(){

  string s;

  cin >> s;

  printVec(s);

  replaceNumberInString(s);

  printVec(s);

  return 0;
}