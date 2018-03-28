#include <iostream>

using namespace std;


void sorted_merge(int *arr_a, int *arr_b, int last_a, int last_b)
{

  int index_merged = last_a + last_b  - 1;
  int index_a = last_a - 1;
  int index_b = last_b - 1;

  while (index_b >= 0) {

    if (index_a >= 0 && arr_a[index_a] > arr_b[index_b]) {
      arr_a[index_merged] = arr_a[index_a];
      index_a--;
    } else {
      arr_a[index_merged] = arr_b[index_b];
      index_b--;
    }
    index_merged--;
  }
}

int main()
{
  int array_a[15] = {2, 3, 4, 5, 6, 10, 14, 0, 0, 0, 0, 0, 0, 0, 0};
  int array_b[6] = {1, 4, 8, 8, 9, 11};

  sorted_merge(array_a, array_b, 7, 6);

  cout << "after sorted merging:" << endl;

  for (int i = 0; i < 15; i++) {
    cout << array_a[i] << " " ;
  }
  cout << endl;

  return 0;
}
