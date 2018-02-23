#include <iostream>
#include <string>
#include <cstring>

using namespace std;


string compress_string(string str)
{
  char next_ch = ' ';
  int consecutive_cnt = 1;
  int total_cnt = 2;

  for (int i=0; i < str.length() - 1; i++)
  {
    //next letter
    next_ch = str[i + 1];

    if (next_ch == str[i]) {
      consecutive_cnt++;
    } else {
      consecutive_cnt = 1;
      total_cnt += 2;
    }
  }

  cout << "total_cnt: " << total_cnt << endl;

  char compressed_str[total_cnt];
  memset(compressed_str, 0, sizeof(char)*total_cnt);

  int index = 0;
  consecutive_cnt = 1;

  for (int i=1; i < str.length(); i++)
  {
    cout << "index: " << index << endl;
    cout << "str[i-1]: " << str[i-1] << endl;
    if (str[i-1] == str[i]) {
      consecutive_cnt++;
    } else {
      compressed_str[index++] = str[i-1];
      sprintf(&compressed_str[index++], "%d", consecutive_cnt);
      consecutive_cnt = 1;
    }
  }

  // final letter
  compressed_str[index++] = str[str.length()-1];
  sprintf(&compressed_str[index++], "%d", consecutive_cnt);

  return compressed_str;
} 

// only accept lowercase letters
string remove_non_chs(string str)
{
  int min_ch = (int)'a';
  int max_ch = (int)'z';
 
  int ch_cnt = 0;

  for (int i=0; i < str.length(); i++)
  {
    int cur_ch = str[i];

    if ((cur_ch >= min_ch) && (cur_ch <= max_ch))
      ch_cnt++;
  }

  char str_ch_only[ch_cnt]; 
  memset(str_ch_only, 0, sizeof(char)*ch_cnt);
  
  //cout << "ch count: " << ch_cnt << endl;

  ch_cnt = 0;

  for (int i=0; i < str.length(); i++)
  {
    int cur_ch = str[i];

    if ((cur_ch >= min_ch) && (cur_ch <= max_ch)) {
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
