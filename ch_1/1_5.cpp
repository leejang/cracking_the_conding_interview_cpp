#include <iostream>
#include <cmath>

using namespace std;

bool isOneEdit(string str1, string str2)
{
  string short_str;
  string long_str;

  bool diff = false;

  if (abs(int(str1.length()) - int(str2.length())) > 1) {
    return false;
  } else {
    long_str = str1.length() >= str2.length() ? str1 : str2;
    short_str = str1.length() < str2.length() ? str1 : str2;
    
    //cout << "long_str: " << long_str << endl;
    //cout << "short_str: " << short_str << endl;
    int i = 0, j = 0;
    while (i < short_str.length())
    {
      if (short_str[i] != long_str[j]) {
        if (diff)
          return false;
        else
          diff = true;
        
        // in case of replacement
        if (str1.length() == str2.length()) {
          i++;
          j++;
        } else {
          j++;
        }
      } else {
        i++;
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
  getline(cin, string1);
  cout << "string 2: " << endl;
  getline(cin, string2);

  if (isOneEdit(string1, string2))
    cout << "string: " << string1 << " and string: " << string2 << " are one edit away." << endl; 
  else
    cout << "string: " << string1 << " and string: " << string2 << " are NOT one edit away." << endl;

  return 0;
}
