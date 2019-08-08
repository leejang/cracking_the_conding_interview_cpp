#include <iostream>
#include <cstring>

using namespace std;

void setZeros(int **matrix, int row, int col)
{
  // to set zero for the first row
  bool setFirstRow = false;

  // 1. check the first row  
  for (int j=0; j < col; j++)
  {
    if (matrix[0][j] == 0) {
      setFirstRow = true;
      break;
    }
  }

  // 2. check the matrix from the "second" row
  // make zero rows
  for (int i=1; i < row; i++)
  {
    bool setZeroRow = false;
    for (int j=0; j < col; j++)
    {
      if (matrix[i][j] == 0) {
        matrix[0][j] = 0;
        setZeroRow = true;
      }
    }
    // 2.1 make this row as zeros
    if (setZeroRow) {
      for (int j=0; j < col; j++)
      {
        matrix[i][j] = 0;
      }
    }
  }
  
  // 3. make zero cols
  for (int j=0; j < col; j++)
  {
    if (matrix[0][j] == 0) {
      for (int i=0; i < row; i++)
      {
        matrix[i][j] = 0;
      }
    }
  }

  // 4. make first row as zeros if needed
  if (setFirstRow) {
    for (int j=0; j < col; j++)
    {
        matrix[0][j] = 0;
    }
  } 
}

void displayMatrix(int *matrix, int row, int col)
{
  for (int i=0; i < row; i++)
  {
    for (int j=0; j < col; j++)
    {
      cout << matrix[i*row + j] << " ";
    }
    cout << endl;
  }
}


void displayMatrix2(int **matrix, int row, int col)
{
  for (int i=0; i < row; i++)
  {
    for (int j=0; j < col; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  // create test matrix 
  int matrix_row = 5;
  int matrix_col = 3;

  int init_val = 1;
  //int *test_matrix = new int [matrix_row*matrix_col];
  //memset(test_matrix, 0, sizeof(test_matrix[0])*matrix_row*matrix_col);

  int **test_matrix2 = new int *[matrix_row];
  for (int i=0; i < matrix_row; i++)
  {
    test_matrix2[i] = new int[matrix_col];
  }
  
 cout << "Test Matrix[5][3]" << endl;

  for (int i=0; i < matrix_row; i++)
  {
    for (int j=0; j < matrix_col; j++)
    {
      cout << "Plese enter test matrix[" << i << "][" << j << "]" << endl;
      cin >> test_matrix2[i][j];
      //cin >> test_matrix[i*matrix_row + j];
      //test_matrix[i*matrix_row + j] = init_val;
      //test_matrix2[i][j] = init_val;
      //init_val++;
    }
  }

  cout << "Before setZeros: " << endl;
  //displayMatrix(test_matrix, matrix_row, matrix_col);
  displayMatrix2(test_matrix2, matrix_row, matrix_col);

  cout << "After setZeros: " << endl;

  setZeros(test_matrix2, matrix_row, matrix_col);
  displayMatrix2(test_matrix2, matrix_row, matrix_col);

  for (int i=0; i < matrix_row; i++)
  {
    delete[] test_matrix2[i];
  }
  delete [] test_matrix2;

  return 0;
}
