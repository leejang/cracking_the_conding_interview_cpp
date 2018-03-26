#include <iostream>
#include <vector>

using namespace std;

#if 0
int count_ways (unsigned int n, vector<int> memo)
{
  int sum = 0;

  if (n == 0)
    return 1;
  for (int i = 0; i < memo.size(); i++) {
    if (n >= memo[i]) {
      //cout << "n - memo[i]: " << n - memo[i] << endl;
      sum += count_ways((n - memo[i]), memo);
    }
  }

  return sum;
}

int count_ways(unsigned int n)
{

  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return 2;
  } else if (n == 2) {
    return 3;
  } else {

    vector<int> memo;
    memo.push_back(1);
    memo.push_back(2);
    memo.push_back(3);

    return count_ways(n, memo);
  }
}
#endif

int count_ways(int n, int *memo)
{
  if (n < 0) {
    return 0;
  } else if (n == 0) {
    return 1;
  } else if (memo[n] > -1) {
    return memo[n];
  } else {
    memo[n] = count_ways(n - 1, memo) +
              count_ways(n - 2, memo) +
              count_ways(n - 3, memo);
    return memo[n];
  }
}

int count_ways(unsigned int n)
{
  int *memo = new int[n + 1];
  fill_n(memo, n + 1 , -1);

  return count_ways(n, memo);
}

int main()
{
  int total_ways = count_ways(6);
  cout << total_ways << endl;

  return 0;
}
