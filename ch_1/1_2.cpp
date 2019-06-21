#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkPermutation(string str1, string str2)
{
  bool return_val = true;

  if (str1.length() != str2.length()) {
    return_val = false;
  } else {
    int char_cnt[256] = {0,};
    for (int i=0; i < str1.length(); i++)
    {
      int val = str1[i];
      if (char_cnt[val])
        char_cnt[val]++;
      else
        char_cnt[val] = 1;
    }
    //int val = str1[i];
    //cout << "val: " << val << " cnt: " << char_cnt[val] << endl;
    for (int i=0; i < str2.length(); i++)
    {
      int val = str2[i];
      if (char_cnt[val] < 0)
        return false;
      else if (char_cnt[val])
        char_cnt[val]--;
      else
        return false;
    }
  }

  return return_val;
}

int main()
{
  cout << "main function!" << endl;

  vector <string> strings_1 = {"test", "apple", "aaapp"};
  vector <string> strings_2 = {"tset", "elapp", "tes1"};

  for (string string1: strings_1)
  {
    for (string string2: strings_2)
    {
       cout << "compare string1: " << string1 << " and string2: " << string2 << endl;
       cout << "result: " << boolalpha << checkPermutation(string1, string2) << endl;
    }
  }

  return 0;
}
