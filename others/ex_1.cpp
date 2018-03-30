// Fiding the longest substring with excatly k ditinct chracters

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int countkDist(string str, int k)
{
    int n = str.length();
 
    // Initialize result
    int res = 0;
    int cnt[26];
    for (int i = 0; i < n; i++)
    {
        int dist_count = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int j=i; j<n; j++)
        {
            if (cnt[str[j] - 'a'] == 0)
                dist_count++;

            cnt[str[j] - 'a']++;

            if (dist_count == k) {
                //cout << "!!" << endl;
                res++;
            }
        }
    }
 
    return res;
}

int longest_substring_with_k_dist(string str, int k)
{
  int *cnt_hash = new int[26];

  vector <string> list_of_subs;

  string sub_str_1;
  string sub_str_2;
  string merged_sub;

  // 1. find the all substrings with k dist
  for (int i = 0; i < str.length(); i++) {
    // empty count and hash_table
    int dist_cnt = 0;
    memset(cnt_hash, 0, sizeof(int)*26);

    sub_str_1 = str[i];

    //cout << "sub_str_1: " << sub_str_1 << endl;

    for (int j = i; j < str.length(); j++) {

      if (cnt_hash[str[j] - 'a'] == 0) {
        sub_str_2 = str[j];
        dist_cnt++;
      } else {
        sub_str_2 += str[j];
      }

      //cout << sub_str_1 << " " << sub_str_2 << endl;

      merged_sub = sub_str_1 + sub_str_2; 
      cnt_hash[str[j] - 'a']++;

      // we found the string with k dist
      if (dist_cnt == k) {
        //cout << "??" << endl;
        list_of_subs.push_back(merged_sub);
      }

    }
  }

  int longest = 0;  
  // 2. finiding the longest substring and retunr the length of it
  for (int i = 0; i != list_of_subs.size(); i++) {
    //cout << i << " " << list_of_subs[i] << endl;
    if (list_of_subs[i].length() > longest) {
      longest = list_of_subs[i].length(); 
    }
  }

  delete [] cnt_hash;

  return longest;
}

int main()
{
  string input_str = "abcdddde";
  //string input_str = "abcd";
  int k = 2;
  // ab, bc, cd

  // the length of the longest substring with k unique chracters
  int ans = 0;

  cout << "Finding the longest substring with excatly ";
  cout << k << " distinct chracters and return legnth of it" << endl;

  cout << "number of candidates: " << countkDist(input_str, k) << endl;
  cout << "the length of the longest substring: " << longest_substring_with_k_dist(input_str, k) << endl;

  return 0;
}
