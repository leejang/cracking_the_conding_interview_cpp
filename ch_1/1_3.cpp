#include <iostream>
#include <string>

using namespace std;

int replaceSpaces (char *str, unsigned int length)
{
  cout << "replace func." << endl;

  int space_cnt = 0;

  for (int i=0; i < length; i++)
  {
    if (str[i] == ' ')
      space_cnt++;    
  }

  //cout << "space cnt: " << space_cnt << endl;

  int index = length + space_cnt * 2 - 1;
  for (int i = length - 1; i > 0; i--)
  {
    cout << "index: " << index << endl;
    if (str[i] == ' ') {
      str[index] = '0';
      str[index - 1] = '2';
      str[index - 2] = '%';
      index = index - 3;
    } else {
      str[index] = str[i];
      index--;
    }

  }

  return 0;
}

int main()
{
  char test_string[] = "My John Smith       ";

  cout << "ch_1_3 test!" << endl;

  replaceSpaces(test_string, 13);

  cout << "after replaceing: " << test_string << endl;

  return 0;
}
