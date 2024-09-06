#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {

  if(s.empty() || s.size() < 2) return;

  int fast_idx = 0, slow_idx = s.size() - 1;

  while (fast_idx <= slow_idx){
    
    char tmp = s.at(fast_idx);

    s.at(fast_idx++) = s.at(slow_idx);

    s.at(slow_idx--) = tmp;

  }
  
}

void printVec(vector<char> nums){

  for(vector<char>::iterator ite = nums.begin(); ite != nums.end(); ite++){ cout << *ite; }

  cout << endl;

}

int main(){

  vector<char> s = {'h','e','l','l','o'};

  printVec(s);

  reverseString(s);

  printVec(s);

  return 0;
}