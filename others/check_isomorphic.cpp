#include <iostream>
#include <cstring>

using namespace std;

// c+ also has a class unorderd_map for hash table
// so that you can implement much easier with "unordered_map"
//
bool isIsomorphic(string const &str_1, string const &str_2)
{
  if (str_1.length() != str_2.length()) {
    cout << "we assume two strings have the same length." << endl;
    return false;
  } else {

    char ck_tbl[128];
    memset(ck_tbl, 0, sizeof(char) * 128);

    for (int i = 0; i < str_1.length(); i++) {
      int ch_f_s = (int)str_1[i];
      char ch_f_t = str_2[i];

      if (ck_tbl[ch_f_s] == 0) {
        ck_tbl[ch_f_s] = ch_f_t;
      } else if (ck_tbl[ch_f_s] != ch_f_t) {
          return false;
      }
    }

  }
  return true;
}


int main()
{
  string test_s_1 = "egg";
  string test_t_1 = "add";
  string test_s_2 = "foo";
  string test_t_2 = "bar";
  string test_s_3 = "paper";
  string test_t_3 = "title";

  cout << "Inputs: " << test_s_1 << " and " << test_t_1 << endl;
  cout << "Is Isomorphic? " << boolalpha << isIsomorphic(test_s_1, test_t_1) << endl;

  cout << "Inputs: " << test_s_2 << " and " << test_t_2 << endl;
  cout << "Is Isomorphic? " << boolalpha << isIsomorphic(test_s_2, test_t_2) << endl;

  cout << "Inputs: " << test_s_3 << " and " << test_t_3 << endl;
  cout << "Is Isomorphic? " << boolalpha << isIsomorphic(test_s_3, test_t_3) << endl;
}
