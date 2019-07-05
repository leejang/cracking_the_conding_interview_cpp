#include<iostream>

using namespace std;

void rotate_matrix_anticlock_90(int ** matrix, int N )
{
  for (int i = 0; i < N/2; i++ ) {
    for (int j = i; j < N-i-1; j++ ) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][N-i-1];
      matrix[j][N-i-1] = matrix[N-i-1][N-j-1];
      matrix[N-i-1][N-j-1]= matrix[N-j-1][i];
      matrix[N-j-1][i] = temp;
    }
  }
}

void rotate_matrix(int ** matrix, int N )
{
  for (int i = 0; i < N/2; i++ ) {
    for (int j = i; j < N-i-1; j++ ) {
      // think about moving corner points
      // top -> temp
      int temp = matrix[i][j];
      // left -> top
      matrix[i][j] = matrix[N-j-1][i];
      // bottom -> left
      matrix[N-j-1][i] = matrix[N-i-1][N-j-1];
      // right -> bottom
      matrix[N-i-1][N-j-1] = matrix[j][N-i-1];
      // top -> right
      matrix[j][N-i-1] = temp;
    }
  }
}

void printMatrix(int ** matrix, int N)
{
  for (int i = 0; i < N; i++ ) {
    for(int j = 0; j < N; j++ ) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


int main() {
  unsigned int N = 0;
  cout << "please enter the size of matrix: " << endl;
  cin >> N;

  int ** matrix = new int*[N];
  for (int i = 0; i < N; ++i ) {
    matrix[i] = new int[N];
  }

  // create test matrix
  int init_val = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j ) {
      matrix[i][j] = init_val;
      init_val++;
    }
  }

 
  cout << "before rotating: " << endl;
  printMatrix(matrix, N);

  // do rotate
  rotate_matrix(matrix, N);
  cout << "after rotating: " << endl;
  printMatrix(matrix, N);

  // do recovery
  rotate_matrix_anticlock_90(matrix, N);
  cout << "recovery: " << endl;
  printMatrix(matrix, N);

  // release memory
  
  for (int i = 0; i < N; ++i ) {
    delete [] matrix[i];
  }

  delete [] matrix;

  return 0;
}
