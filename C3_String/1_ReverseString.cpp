#include<iostream>
#include<vector>

using namespace std;


void reverseString(vector<char>& s) {

  int start_index = 0;

  int end_index = s.size() - 1;

  while(start_index < end_index){

    /* char tmp = s.at(start_index);

    s.at(start_index) = s.at(end_index);

    s.at(end_index) = tmp; */

    swap(s.at(start_index), s.at(end_index));

    start_index++;

    end_index--;

  }
}

int main(){

  vector<char> s = { 'h','e','l','l','o' };

  for(auto i : s){ cout<< i; }

  cout << endl;

  reverseString(s);

  for(auto i : s){ cout<< i; }

  cout << endl;

  return 1;
}