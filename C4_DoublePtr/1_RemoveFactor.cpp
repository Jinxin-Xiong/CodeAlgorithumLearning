
#include <iostream>
#include <vector>

using namespace std;

//brute force
int removeElement(vector<int>& nums, int val) {

  int fast_index = 0, slow_index = nums.size() - 1, new_size = nums.size();

  while(fast_index < nums.size()){

    if(nums.at(fast_index) != val) fast_index++;

    else{

      int tmp_index = fast_index;

      while(tmp_index < nums.size() - 1) {

        nums.at(tmp_index) = nums.at(tmp_index+1);

        tmp_index++;
      }

      slow_index--;

      new_size--;
    }

    if(fast_index == slow_index) {

      if(nums.at(slow_index) == val) new_size--;

      break;
    }
  }

  nums.resize(new_size);
}

//double ptr
int removeElement_DP(vector<int>& nums, int val) {

  int fast_idx = 0, slow_idx = 0;

  while(fast_idx < nums.size()){

    if(nums.at(fast_idx) != val) { 
      
      nums.at(slow_idx++) = nums.at(fast_idx++);

      continue; 
    }

    fast_idx++;
  } 

  return slow_idx;

}

void printVec(vector<int> nums){

  for(vector<int>::iterator ite = nums.begin(); ite != nums.end(); ite++){ cout << *ite << " "; }

  cout << endl;

}

int main(){


  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};

  int val = 2;

  printVec(nums);

  int new_size = removeElement_DP(nums, val);

  nums.resize(new_size);

  printVec(nums);

  return 0;
}