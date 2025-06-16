#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:

    vector<vector<string>> result;

    bool isValid(int row, int col, vector<string>& chessboard, int n) {
    // 检查列
    for (int i = 0; i < row; i++) { // 这是一个剪枝
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }
    // 检查 45度角是否有皇后
    for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    // 检查 135度角是否有皇后
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    return true;
  }
    void backTracking(int n, int row, vector<string>& combine){

      if(row == n){

        result.push_back(combine);

        return;
      }

      for (int i = 0; i < n; i++){
        
        if(!isValid(row, i, combine, n)) continue;

        combine[row][i] = 'Q';

        backTracking(n, row+1, combine);

        combine[row][i] = '.';
      }
      
    }

    vector<vector<string>> solveNQueens(int n) {

      if(n <= 0) return result;

      vector<string> combine(n, string(n, '.'));

      backTracking(n, 0, combine);

      return result;        
    }
};