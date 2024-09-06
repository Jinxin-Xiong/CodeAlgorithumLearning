#include <iostream>
#include <vector>

using namespace std;

//brute force solution
template<typename T>
void orderedSquares(vector<T>& nums){

  int index = 0;

  int size = nums.size();

  T temp;

  for (int i = 0; i < size; i++){

    index = i;

    for (int j = i + 1; j < size; j++){
      
      if(nums[index]*nums[index] > nums[j]*nums[j]) index = j;

    }

    if(index != i) { temp = nums[i]; nums[i] = nums[index]; nums[index] = temp; }
  }
  
}

//double pointer solution
template<typename T>
vector<T> orderedSquares_DP(vector<T>& nums){

  vector<T> result(nums.size());

  int slowIndex = 0, fastIndex = nums.size() - 1;

  for (int i = nums.size() - 1; i >= 0; i--){
    
    if(nums[slowIndex]*nums[slowIndex] > nums[fastIndex]*nums[fastIndex]) { result[i] = nums[slowIndex]*nums[slowIndex]; slowIndex++; }

    else { result[i] = nums[fastIndex]*nums[fastIndex]; fastIndex--; }
  }

  for(auto factor : result) cout << factor << "  ";
  
  cout << endl;
  
  return result;
}

int main(){

  vector<int> nums = {-4, -1, 0, 3, 10};

  //orderedSquares(nums);

  //for(auto factor : nums) cout << factor*factor << "  ";

  vector<int> result = orderedSquares_DP(nums);

  for(auto factor : result) cout << factor << "  ";

  cout << endl;

  return 1;
}