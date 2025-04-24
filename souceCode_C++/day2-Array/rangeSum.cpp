
#include <iostream>
#include <vector>

using namespace std;

int main(){

  cout<< "Input the number of the integers: ";

  int num;
  cin >> num;

  cout << endl;

  vector<int> rangesum(num, 0);

  int totalval = 0;

  for (int i = 0; i < num; i++){
    
    cout << "  Type the " << i + 1 << " integer:  ";

    int value;
    cin >> value;

    cout << endl;
    
    totalval += value;

    rangesum[i] += totalval;

  }

  string sign;
  
  while(sign != "yes"){

    int left_range;

    cout << "  Type the left range: " ;
    cin >> left_range;

    cout << endl;

    int right_range;

    cout << "  Type the right range: " ;
    cin >> right_range;

    cout << endl;

    int result = (left_range - 1) < 0 ? rangesum[right_range] : rangesum[right_range] - rangesum[left_range - 1];
    
    cout << "result is:  " << result << endl;

    cout << "do you want stop?  ";
    cin >> sign;
  }

  return 1;
}