#include <iostream>
#include <stack>

using namespace std;

bool check_parentheses(const string &input_s)
{
  stack<char> my_stack;
  if (input_s.length() == 1)
    return false;

  for (int i = 0; i < input_s.length(); i++) {
    //cout << input_s[i] << endl;
    char cur_char = input_s[i];

    if ((cur_char == '(') || (cur_char == '[') || (cur_char == '{')) {
      my_stack.push(cur_char);
    } else {
      char popped = my_stack.top();
      my_stack.pop();
      if (cur_char == ')' && popped != '(') return false;
      if (cur_char == ']' && popped != '[') return false;
      if (cur_char == '}' && popped != '{') return false;
    }
  }

  return true;
}

int main()
{
  string test_str_1 = "()";
  string test_str_2 = "()[]{}";
  string test_str_3 = "(]";
  string test_str_4 = "([)]";
  string test_str_5 = "{[]}";

  cout << "Input: " << test_str_1 << endl;
  cout << "Output: " << boolalpha << check_parentheses(test_str_1) << endl;
  cout << "Input: " << test_str_2 << endl;
  cout << "Output: " << boolalpha << check_parentheses(test_str_2) << endl;
  cout << "Input: " << test_str_3 << endl;
  cout << "Output: " << boolalpha << check_parentheses(test_str_3) << endl;
  cout << "Input: " << test_str_4 << endl;
  cout << "Output: " << boolalpha << check_parentheses(test_str_4) << endl;
  cout << "Input: " << test_str_5 << endl;
  cout << "Output: " << boolalpha << check_parentheses(test_str_5) << endl;

}
