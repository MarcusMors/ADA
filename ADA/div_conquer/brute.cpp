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

int swaps = 0;

void solve()
{
  unsigned n;
  cin >> n;
  vector<int> v(n);
  FOR_N(i, n) { cin >> v[i]; }
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i + 1; j < n; j++) {
      if (v[i] > v[j]) { swaps++; }
    }
  }

  cout << swaps << endl;
}

signed main()
{
  fastio();
  solve();
  return 0;
}

/*
in:
12
1 5 4 8 10 2 6 9 12 11 3 7
out:
22
 */
