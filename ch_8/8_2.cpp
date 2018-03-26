#include <iostream>
#include <vector>
#include <unordered_set>


// many part of the below code frome
// https://github.com/careercup/CtCI-6th-Edition-cpp

using namespace std;

struct Point {
    int row;
    int column;
    // constructor
    Point(int r, int c){
     row = r;
     column = c;
    }
};

int** createMatrix(int rows, int columns){
    //initialize number of rows
    int** matrix = new int*[rows];
    //in each row, add a new column array
    for (int i = 0; i < rows; ++i){
        matrix[i] = new int[columns];
    }
    //place values (1 indicates position is valid, -1 indicates it is invalid)
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){
            matrix[i][j] = 1;
        }
    }
    return matrix;
    
}

//Checks if path is valid and simultaneously adds position to a result vector
bool get_path(int** matrix, int currRow, int currColumn,
              vector<Point*>& path, unordered_set<Point*>& visited)
{
    
    //if out of bounds or curr position is off limits, return false
    if (currRow < 0 || currColumn < 0 || matrix[currRow][currColumn] == -1){
        return false;
    }
    
    Point* currPos = new Point(currRow, currColumn);
    
    //If we have already visited this position, then return false
    if (visited.find(currPos) != visited.end()){
        return false;
    }
    
    
    bool atOrigin = false;

    atOrigin = (currRow == 0 && currColumn == 0);
    
    //Everytime robot moves up or left and it is a valid position, add the point to result vector
    if (atOrigin ||
        get_path(matrix, currRow - 1, currColumn, path, visited) ||
        get_path(matrix, currRow, currColumn - 1, path, visited)) {
        path.push_back(currPos);
        return true;
    }
    
    //Keep track of already visited points
    visited.insert(currPos);
    
    return false;
}

vector<Point*> get_path(int** matrix, int rows, int columns){

    //create result vector
    vector<Point*> path;
    
    //create unordered set to keep track of already visited points
    unordered_set<Point*> visited;
    
    //Bounds checking
    if (rows != 0 || matrix != nullptr) {
        //Start checking positions from bottom right to top left
        if (get_path(matrix, rows - 1, columns - 1, path, visited)){
            return path;
        }
    }
    //Return an empty vector indicating path does not exist
    return path;
    
}

int main()
{

  int** matrix = createMatrix(5, 7);

  matrix[1][3] = -1;
  matrix[2][5] = -1;
  matrix[3][2] = -1;
  matrix[0][1] = -1;

  // that input number indicates the destination position
  // se search from the destination to origin (starting point)
  vector<Point*> path = get_path(matrix, 5, 7);

  if (path.size() == 0) {
    cerr << "Path does not exist!" << endl;
        
  } else {
    for (int i = 0; i < path.size(); i++) {
      cout << "[" << path[i]->row << "]" << "[" << path[i]->column << "]" << endl;
    }
        
  }

  delete [] matrix;

  return 0;
}    
