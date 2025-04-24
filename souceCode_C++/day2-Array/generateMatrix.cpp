/* 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

 

示例 1：


输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
示例 2：

输入：n = 1
输出：[[1]]
 

提示：

1 <= n <= 20 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

      int step = n - 1, count = 1, cycle_time = 0;
      
      vector<vector<int>> matrix(n,vector<int>(n,0));

      while(count <= n * n){

        step = (n - 1) - 2 * cycle_time;

        int tmp_row = cycle_time;
        int tmp_col = cycle_time;

        if(step <= 0) { (n % 2) == 1 ? matrix[n/2][n/2] = count++ : cycle_time++; break;}

        for(int i = 0; i < step; i++){

          matrix[tmp_row][tmp_col++] = count++;
        }

        for(int i = 0; i < step; i++){

          matrix[tmp_row++][tmp_col] = count++;
        }

        for(int i = 0; i < step; i++){

          matrix[tmp_row][tmp_col--] = count++;
        }

        for(int i = 0; i < step; i++){

          matrix[tmp_row--][tmp_col] = count++;
        }

        cycle_time++;
        
      }

      return matrix;
        
    }
};

int main(){

  int n = 3;

  Solution obj;

  vector<vector<int>> matrix = obj.generateMatrix(n);

  cout << matrix.data() << endl;
}