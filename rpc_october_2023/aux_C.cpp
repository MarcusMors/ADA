#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using namespace std;

signed main()
{
  vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  do {
    for (auto &&e : v) { cout << e; }
    cout << endl;

  } while (next_permutation(v.begin(), v.end()));

  return 0;
}
