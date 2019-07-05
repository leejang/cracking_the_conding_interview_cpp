#include <iostream>
#include <string>
#include <cstring>

using namespace std;


string compress_string(string str)
{ 
  string comp_str = {""};

  int ch_cnt = 1;

  for (int i = 1; i < str.length(); i++)
  {
    if (str[i-1] == str[i]) {
      ch_cnt++;
    } else {
      comp_str += str[i-1]; 
      comp_str += to_string(ch_cnt);
      ch_cnt = 1;
    }
  }

  // for last ch
  comp_str += str[str.length() - 1];
  comp_str += to_string(ch_cnt);

  if (comp_str.length() >= str.length())
    return str;

  return comp_str;
} 

// only accept lowercase letters
string remove_non_chs(string str)
{
  int min_ch = (int)'a';
  int max_ch = (int)'z';

  // to keep 
  int ch_cnt = 0;

  for (int i=0; i < str.length(); i++)
  {
    int cur_ch = str[i];

    if ((cur_ch >= min_ch) && (cur_ch <= max_ch))
      ch_cnt++;
  }

  char str_ch_only[ch_cnt + 1]; 
  memset(str_ch_only, 0, sizeof(char)*(ch_cnt + 1));
  
  //cout << "ch count: " << ch_cnt << endl;

  ch_cnt = 0;

  for (int i=0; i < str.length(); i++)
  {
    int cur_ch = str[i];

    if ((cur_ch >= min_ch) && (cur_ch <= max_ch)) {
      //cout << "str[i]: " << str[i] << endl;
      str_ch_only[ch_cnt] = str[i];
      ch_cnt++;
    }
  }

  return str_ch_only;
}

int main()
{
  string origin_string;

  // the below code
  // only reads up to the first whitespace character.
  cout << "please enter string you wish to compress:" << endl;
  //cin >> origin_string;
  // If you want to get the a whole line, use the following code:
  getline(cin, origin_string);

  // 1. remove non characters
  string origin_ch_only = remove_non_chs(origin_string);
  cout << "original string: " << origin_ch_only << endl;
  cout << "original string.length: " << origin_ch_only.length() << endl;

  string compressed_string = compress_string(origin_string);

  cout << "compressed string: " << compressed_string << endl;

  return 0;
}
