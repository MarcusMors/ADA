#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

// int vals[9];

void solve()
{
  unsigned n;
  cin >> n;

  for (size_t i = 0; i < n + 1; i++) {
    // cout << "for :" << i << endl;
    bool j_found = false;
    for (size_t j = 1; j < 10; j++) {
      if (n % j == 0 and i % (n / j) == 0) {
        j_found = true;
        cout << j;
        break;
      }
    }
    if (not j_found) { cout << "-"; }
  }
}
/*
if there is a divisor j of N that is between 1 and 9, inclusive, and i is a multiple of N/j, then si​ is the digit
corresponding to the smallest such j (s_i​ will thus be one of 1, 2, ..., 9); if no such j exists, then si​ is -.
*/

signed main()
{
  fastio();
  solve();

  return 0;
}
