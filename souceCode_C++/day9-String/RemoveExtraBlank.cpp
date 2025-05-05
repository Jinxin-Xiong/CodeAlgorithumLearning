#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

   void reverseWords(string& str){

    //查找首尾多余空格
/*     while(str[0] == ' ') str.erase(str.begin());

    while(str[str.size() - 1] == ' ') { str.erase(str.end() - 1); }

    //查找中间多余空格
    for(int i = 0; i < str.size()-1; i++){

      if(str[i] != ' ') continue;

      while(str[i+1] == ' ') str.erase(str.begin()+i+1);
    } */

   int slow_idx = 0;
   for (int i = 0; i < str.size(); ++i){
    
    if(str[i] != ' '){

      if(slow_idx != 0) str[slow_idx++] = ' ';

      while(str[i] != ' ' && i < str.size()) str[slow_idx++] = str[i++];
    }
   }

   str.resize(slow_idx);

   cout << str << endl;
   

    //反转整个字符串
    int left_idx = 0, right_idx = str.size() - 1;

    while(left_idx < right_idx){

      swap(str[left_idx++], str[right_idx--]);
    }

    //反转每个单词
    left_idx = 0; right_idx = 0;

    while (right_idx < str.size()){
      
      while(str[right_idx] != ' ' && right_idx < str.size()) right_idx++;

      int start_idx = left_idx, end_idx = right_idx - 1;

      while(start_idx < end_idx){

        swap(str[start_idx++], str[end_idx--]);
      }

      right_idx++; left_idx = right_idx;
    }
    
   }

};

int main(){

  string str = "the sky is blue";

  Solution ptr;

  cout << str << endl << endl;

  ptr.reverseWords(str);

  cout << str<< endl;
}