#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

int squareDigits(const unsigned int n){

  int sum = 0;

  unsigned int tmp_n = n;

  while(tmp_n != 0){

    int num = tmp_n % 10;

    sum += num * num;

    tmp_n /= 10;
  }

  return sum;
  
}

bool isHappyNumber(const unsigned int n){

  unordered_set<unsigned int> result_set;

  int result = n;

  while(result != 1){

    if(result_set.find(result) != result_set.end()) return false;

    result_set.insert(result);

    result = squareDigits(result);

    cout << result << endl;

  }

  return true;
}

int main(){

  int n = 19;

  bool is_happy_num = isHappyNumber(n);

  string message = is_happy_num == false ? "false" : "true";

  cout << n << "  is happy number?  ==>  " <<  message;

  cout << endl;
  


  return 1;
}