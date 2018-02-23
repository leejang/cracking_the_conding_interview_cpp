#include <iostream>
#include <cstring>

using namespace std;

bool checkPalindrome(string str)
{
  int minLowCh = (int)'a';
  int maxLowCh = (int)'z';
  int minUpCh = (int)'A';
  int maxUpCh = (int)'Z';

  int freqTable[maxLowCh - minLowCh + 1];
  //cout << maxLowCh - minLowCh + 1 << endl;
  memset(freqTable, 0, sizeof(freqTable[0])*(maxLowCh - minLowCh + 1));

  // 1. crete frequency table
  for (int i=0; i < str.length(); i++)
  {
    int cur_ch_val = (int)str[i];
    // lower case
    if (cur_ch_val >= minLowCh && cur_ch_val <= maxLowCh) {
      freqTable[cur_ch_val - minLowCh]++;
    // uper case
    } else if (cur_ch_val >= minUpCh && cur_ch_val <= maxUpCh) {
      freqTable[cur_ch_val - minUpCh]++;
    }
  }

  // 2. check Palindrome
  bool oddChkFlag = false;
  int freqTableSize = maxLowCh - minLowCh + 1;
  for (int i = 0; i < freqTableSize; i++)
  {
    //cout << freqTable[i] << endl;
    if (freqTable[i] % 2 == 1) {
      if (oddChkFlag) {
        return false;
      } else {
        oddChkFlag = true;
      }
    } 
  }

  return true;
}

bool checkPalindrome2(string str)
{
  int minLowCh = (int)'a';
  int maxLowCh = (int)'z';
  int minUpCh = (int)'A';
  int maxUpCh = (int)'Z';

  int freqTable[maxLowCh - minLowCh + 1];
  //cout << maxLowCh - minLowCh + 1 << endl;
  memset(freqTable, 0, sizeof(freqTable[0])*(maxLowCh - minLowCh + 1));

  int oddCnt = 0;
  int idx = 0;
  // 1. crete frequency table and check Palindrome
  for (int i=0; i < str.length(); i++)
  {
    int cur_ch_val = (int)str[i];
    // lower case
    if (cur_ch_val >= minLowCh && cur_ch_val <= maxLowCh) {
      idx = cur_ch_val - minLowCh;
      freqTable[idx]++;

      if (freqTable[idx] % 2 == 1) {
        oddCnt++;
      } else {
        oddCnt--;
      }
    // uper case
    } else if (cur_ch_val >= minUpCh && cur_ch_val <= maxUpCh) {
      idx = cur_ch_val - minUpCh;;
      freqTable[idx]++;

      if (freqTable[idx] % 2 == 1) {
        oddCnt++;
      } else {
        oddCnt--;
      }
    }

    //cout << "oddCnt: " << oddCnt << endl;
  }
   

  return (oddCnt <= 1);
}

int toggle(int bitVector, int index)
{
  int mask = 1 << index;
  
  if ((bitVector & mask) == 0) {
    bitVector |= mask;
  } else {
    bitVector &= ~mask;
  }

  return bitVector;
}

bool checkPalindrome3(string str)
{
  int minLowCh = (int)'a';
  int maxLowCh = (int)'z';
  int minUpCh = (int)'A';
  int maxUpCh = (int)'Z';

  int bit_vector = 0;
  int idx = 0;

  // 1. crete bit vector and check Palindrome
  for (int i=0; i < str.length(); i++)
  {
    int cur_ch_val = (int)str[i];
    // lower case
    if (cur_ch_val >= minLowCh && cur_ch_val <= maxLowCh) {
       idx = cur_ch_val - minLowCh;
    // uper case
    } else if (cur_ch_val >= minUpCh && cur_ch_val <= maxUpCh) {
       idx = cur_ch_val - minUpCh;
    } else {
       idx = -1;
    }

    if (idx != -1) 
      bit_vector = toggle(bit_vector, idx);
  }

  return (bit_vector == 0 || (bit_vector & (bit_vector - 1)) == 0);
}

int main()
{
  string input_string;
  cout << "please enter a string to check Palindrome Permutation" << endl;
  getline(cin, input_string);

  cout << "1st Appraoch:" << endl;
  if (checkPalindrome(input_string))
    cout << input_string << " is Palindrome Permutation." << endl; 
  else
    cout << input_string << " is NOT Palindrome Permutation." << endl; 

  cout << "2nd Appraoch:" << endl;
  if (checkPalindrome2(input_string))
    cout << input_string << " is Palindrome Permutation." << endl; 
  else
    cout << input_string << " is NOT Palindrome Permutation." << endl; 

  cout << "3rd Appraoch:" << endl;
  if (checkPalindrome3(input_string))
    cout << input_string << " is Palindrome Permutation." << endl; 
  else
    cout << input_string << " is NOT Palindrome Permutation." << endl; 

  return 0;
}
