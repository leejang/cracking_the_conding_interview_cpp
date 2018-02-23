#include <iostream>
#include <string>

using namespace std;

// return value of string.find method:
// The position of the first character of the first match.
// If no matches were found, the function returns string::npos.
bool isRotation (string str1, string str2)
{
  string concatStr = str1 + str1;
  if (str1.length() == str2.length()) {
    if (concatStr.find(str2) != string::npos) {
      cout << concatStr << endl;
      return true;
    }
  }

  return false;
}

int main()
{
  string str1, str2;
  cout << "enter string 1: " << endl;
  cin >> str1;
  cout << "enter string 2: " << endl;
  cin >> str2;

  if (isRotation(str1, str2)) {
    cout << str2 << " is rotation of " << str1 << endl;
  } else {
    cout << str2 << " is NOT rotation of " << str1 << endl;
  }

  return 0;
}
