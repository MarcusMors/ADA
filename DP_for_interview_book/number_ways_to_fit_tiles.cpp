#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using uint = unsigned int;

int count_ways(int n)
{
  // terminating conditions
  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  if (n == 2) { return 2; }
  return count_ways(n - 1) + count_ways(n - 2);
}

/*
1 + sum_{i=1}^{roof((n-1)/2)} {n-i C i } = rpta;

int ways = 1;
for(int i = 1; i < roof((n-1)/2); i++)
{
  ways += combinatory (n-i, i);
}
return ways;
*/

int main()
{
  std::vector<uint> tests{};
  for (int i = 0; i < 10; i++) { tests.push_back(i); }
  // std::vector<uint> tests{
  //   5,
  // };

  for (const auto &test : tests) {
    cout << "sum vec: " << endl;
    cout << count_ways(test) << endl;
    cout << endl;
    cout << "---------------------------------------" << endl;
  }


  return 0;
}
