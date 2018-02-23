#include <iostream>
#include <cstring>

using namespace std;

int rotateMatrix(int *matrix, int matrix_size)
{
  int top_edge_element = 0;
 
  // layer 
  for (int i = 0; i < matrix_size/2; i++)
  {
    for (int j = i; j < matrix_size - 1 - i; j++)
    {
      cout << "i: " << i << " j: " << j;
      cout << " val: " << matrix[i*matrix_size + j] << endl;

      //save top
      top_edge_element =  matrix[i*matrix_size + j];
      // left -> top
      matrix[i*matrix_size + j] = matrix[(matrix_size - 1 - j)*matrix_size + i];
      // bottom -> left
      matrix[(matrix_size - 1 - j)*matrix_size + i] = matrix[(matrix_size - 1 - i)*matrix_size + matrix_size - 1 - j];
      // right -> bottom
      matrix[(matrix_size - 1 - i)*matrix_size + matrix_size - 1 - j] = matrix[j*matrix_size + matrix_size - 1 - i];
      // top -> right
      matrix[j*matrix_size + matrix_size - 1 - i] = top_edge_element;
    }
  }
  return 0;
}

int displayMatrix(int *matrix, int matrix_size)
{
  for (int i=0; i < matrix_size; i++)
  {
    for (int j=0; j < matrix_size; j++)
    {
      cout << matrix[i*matrix_size + j] << " ";
    }
    cout << endl;
  }
  return 0;
}


int main()
{
  unsigned int matrix_size = 0;
  cout << "please enter the size of matrix: " << endl;
  cin >> matrix_size;

  int *test_matrix = new int [matrix_size*matrix_size];
  // init
  memset(test_matrix, 0, sizeof(test_matrix[0])*matrix_size*matrix_size);

  // create test matrix
  int init_val = 1;
  for (int i=0; i < matrix_size; i++)
  {
    for (int j=0; j < matrix_size; j++)
    {
      test_matrix[i*matrix_size + j] = init_val;
      init_val++;
    }
  }
 
  cout << "before rotating: " << endl;
  displayMatrix(test_matrix, matrix_size);

  cout << "after rotating: " << endl;
  rotateMatrix(test_matrix, matrix_size);
  displayMatrix(test_matrix, matrix_size);

  delete [] test_matrix;

  return 0;
}
