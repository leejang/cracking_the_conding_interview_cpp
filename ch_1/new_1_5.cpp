#include <iostream>
#include <cmath>

using namespace std;

bool isOneEdit(string const &str1, string const &str2)
{
  // check length of each input string
  // the return type of str.length() => size_t
  int diff_length = abs(int(str1.length()) - int(str2.length()));

  //cout << str1.length() << str2.length() << diff_length << endl;
  
  string long_str;
  string short_str;

  if (str1.length() > str2.length()) {
    long_str = str1;
    short_str= str2;
  } else {
    long_str = str2;
    short_str= str1;
  }

  if (diff_length > 1) {
    return false;
  } else {

    bool one_edit = false;
    int j = 0;
    for (int i = 0; i < long_str.length(); i++) {

      if (long_str[i] != short_str[j]) {
        if (one_edit) {
          return false;
        } else {
          one_edit = true;
        }
      } else {
        j++;
      }
    }

    return true;
  }
}

int main()
{
  string string1;
  string string2;
  // ex1: pal, pale
  // ex2: pael, pal
  cout << "please enter two strings to check if they are one edit away." << endl;
  cout << "we assume that there is no space and non-letter characters." << endl;
  cout << "string 1: " << endl;
  //cin >> string1;
  getline(cin, string1);
  cout << "string 2: " << endl;
  getline(cin, string2);

  if (isOneEdit(string1, string2))
    cout << "string: " << string1 << " and string: " << string2 << " are one edit away." << endl; 
  else
    cout << "string: " << string1 << " and string: " << string2 << " are NOT one edit away." << endl;

  return 0;
}
