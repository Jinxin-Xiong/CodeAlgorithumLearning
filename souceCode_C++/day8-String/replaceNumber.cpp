#include <iostream>
#include <string>

using namespace std;

void replaceNumberInString(string& str){

  int pos = 0, num_count = 0;

  int origin_str_size = str.size();

  while(pos < str.size()){

    if(str[pos] >= '0' && str[pos] <= '9'){

      num_count++;
    }

    pos++;
  }

  str.resize(str.size() + 5 * num_count);

  int ori_pos = origin_str_size - 1;

  int new_pos = str.size() - 1;

  while(ori_pos >= 0){

    if(str[ori_pos] >= '0' && str[ori_pos] <= '9'){

      str[new_pos--] = 'r';
      str[new_pos--] = 'e';
      str[new_pos--] = 'b';
      str[new_pos--] = 'm';
      str[new_pos--] = 'u';
      str[new_pos--] = 'n';

    }else{

      str[new_pos--] = str[ori_pos];

    }

    ori_pos--;
  }
}

int main(){

  string s = "a1b2c3";

  cout << s << endl << endl;

  replaceNumberInString(s);

  cout << s << endl;
}