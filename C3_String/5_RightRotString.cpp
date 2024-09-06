#include <iostream>
#include <string>

using namespace std;

void rightRotString(const int k, string& str){

  int size = str.size();

  int rot_index = size - k;

  int start_index = 0;

  while (rot_index < size){
    
    str.insert(str.begin() + start_index, str[rot_index+start_index]);

    start_index++; rot_index++;

  }

  str.resize(size);
  
}

int main(){

  string str;

  int k;

  cin >> k;

  cin >> str;

  rightRotString(k, str);

  cout << str << endl;

  return 1;
}