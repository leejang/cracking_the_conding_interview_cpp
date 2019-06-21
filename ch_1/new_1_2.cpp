#include <iostream>

using namespace std;

bool checkPermutation(const string &str_1, const string &str_2)
{
  int ref_table[256] = {0, };
  //cout << "I got strings: " << str_1 << " " << str_2 << endl;
  if (str_1.length() != str_2.length()) {
    return false;
  } else {
    // for string 1
    for (int i = 0; i < str_1.length(); i++) {
      int val = str_1[i];
      ref_table[val]++;
    }

    // for string 2
    for (int i = 0; i < str_2.length(); i++) {
      int val = str_2[i];
      if (ref_table[val] > 0) {
        ref_table[val]--;
      } else {
        return false;
      }
    }

    return true;
  }
}

int main()
{

  string test_str_1[] = {"abc", "test"};
  string test_str_2[] = {"cbs", "sbs", "ttse"};

  for (auto cur_str: test_str_1) {
    for (auto cur_str_2: test_str_2) {
      cout << "given string 1 and 2: " << cur_str << " " << cur_str_2 << endl;
      cout << boolalpha << checkPermutation(cur_str, cur_str_2) << endl;
    }
  }
}

