#include<iostream>
#include<string>

using namespace std;

/* string replaceNumber(string s){

  string tmp_s;

  for(auto i : s){

    if(i - 'a' < 0){

      tmp_s += "number";
    }

    else { tmp_s += i; }
  }

  return tmp_s;
} */

void replaceNumber(string& s){

  int num_count = 0;

  int str_size = s.size();

  for(auto i : s){

    if(i >= '0' && i <= '9') num_count++;
  }

  s.resize(str_size + 5 * num_count);

  int index_old = str_size - 1;

  int index_new = s.size() - 1;

  while (index_old >= 0){
    

    if(s.at(index_old) >= '0' && s.at(index_old) <= '9'){

      s.at(index_new--) = 'r';
      s.at(index_new--) = 'e';
      s.at(index_new--) = 'b';
      s.at(index_new--) = 'm';
      s.at(index_new--) = 'u';
      s.at(index_new--) = 'n';
    }

    else{

      s.at(index_new--) = s.at(index_old);
    }

    index_old--;
  }
}

int main(){

  cin >> s;

  replaceNumber(s);

  cout << s << endl;
}