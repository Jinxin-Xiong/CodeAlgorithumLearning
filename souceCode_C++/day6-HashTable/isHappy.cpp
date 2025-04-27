#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {

      if(n == 1 || n == 10) return true;

      if(n == 0) return false;

      unordered_set<int> number_set;
      
      int powsum = 5, interger = n;

      while (powsum != 1){

        powsum = 0;

        int tmp = 0;

        while(interger >= 1 ){

          tmp = interger % 10;

          interger /= 10;

          powsum += tmp * tmp;
        }

        interger = powsum;

        auto itr = number_set.insert(powsum);

        if(!itr.second) return false;
        
      }

      return true;
      
        
    }
};