/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/

#include <iostream>
#include <stack>

using namespace std;

string reverse_str(const string &input_s)
{
  string output_s = input_s;
  stack<char> my_stack;

  for (int i = 0; i < input_s.length(); i++) {
    char cur_ch = input_s[i];

    if (cur_ch == 'a' || cur_ch == 'e' || cur_ch == 'i' ||
        cur_ch == 'o' || cur_ch == 'u') {
      my_stack.push(cur_ch);
    }
  }

  for (int i = 0; i < output_s.length(); i++) {
    char cur_ch = output_s[i];

    if (cur_ch == 'a' || cur_ch == 'e' || cur_ch == 'i' ||
        cur_ch == 'o' || cur_ch == 'u') {
      char new_ch = my_stack.top();
      output_s[i] = new_ch;
      my_stack.pop();
    }
  }

  return output_s;
}

int main()
{
  string test_str_1 = "hello";
  string test_str_2 = "leetcode";

  cout << "Input: " << test_str_1 << endl;
  cout << "Output: " << reverse_str(test_str_1) << endl;

  cout << "Input: " << test_str_2 << endl;
  cout << "Output: " << reverse_str(test_str_2) << endl;
}
