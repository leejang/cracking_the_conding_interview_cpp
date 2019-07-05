#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(string const &input_s)
{
  stack<char> my_stack;

  for (int i = 0; i < input_s.length(); i++) {
    my_stack.push(input_s[i]);
  }

  for (int i = 0; i < input_s.length(); i++) {
    char cur_ch = input_s[i];

    if (input_s[i] != ' ') {
      if (cur_ch != my_stack.top()) {
        return false;
      } else {
        my_stack.pop();
      }
    }
  }
  return true;
}


int main()
{
  string test_1 = "abcdcba";
  string test_2 = "abba";
  string test_3 = "robot learning";

  cout << "Input: " << test_1 << endl;
  cout << "Is Palindrome? " << boolalpha << isPalindrome(test_1) << endl;
  cout << "Input: " << test_2 << endl;
  cout << "Is Palindrome? " << boolalpha << isPalindrome(test_2) << endl;
  cout << "Input: " << test_3 << endl;
  cout << "Is Palindrome? " << boolalpha << isPalindrome(test_3) << endl;

  string input_from_user;
  cout << "Do you want to test somethig else? (please type string that you would like to test)" << endl;
  cin >> input_from_user;
  cout << "Input: " << input_from_user << endl;
  cout << "Is Palindrome? " << boolalpha << isPalindrome(input_from_user) << endl;

}
