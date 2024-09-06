
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n){

  vector<vector<int>> out_matrix(n, vector<int>(n,0));

  int row_index = 0, col_index = 0;

  int number = 1;

  for (int i = 0; i < n/2; i++){

    row_index = i;
    col_index = i;
    
    while (col_index < n - row_index){
      
      out_matrix[row_index][col_index] = number;

      number++;

      col_index++;

    }

    row_index = i + 1;
    col_index = n - i;

    while (row_index < col_index){
      
      out_matrix[row_index][col_index-1] = number;

      number++;

      row_index++;

    }

    row_index = n - i;
    col_index = n - i - 1;

    while (col_index > i){
      
      out_matrix[row_index-1][col_index-1] = number;

      number++;

      col_index--;

    }

    row_index = n - i - 1;
    col_index = i;

    while (row_index > i + 1){
      
      out_matrix[row_index-1][col_index] = number;

      number++;

      row_index--;

    }
 
  }
  
  out_matrix[n/2][n/2] = number;

  return out_matrix;

}

int main(){

  int n = 5;

  vector<vector<int>> out_mat = generateMatrix(n);

  for (int row = 0; row < out_mat.size(); row++)
  {
    for (int col = 0; col < out_mat[row].size(); col++)
    {
      cout << out_mat[row][col] << " ";
    }
    
    cout << endl;
  }
  
  return 1;
}