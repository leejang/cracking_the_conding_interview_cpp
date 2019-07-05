#include <iostream>
#include <unordered_map>

using namespace std;



int main()
{
  unordered_map<string, int> map;

  map["ey"] = 7;
  map["jw"] = 3;
  map["hana"] = 12;
  map["yuna"] = 10;

  for (auto e:map) {
    cout << e.first << " " << e.second << endl;

  }

  return 0;
}
