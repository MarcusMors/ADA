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

cui N = 10000000;
ui DP[N][3];

// HASH

void solve()
{
  map<string, string> m;
  unsigned n;
  cin >> n;

  FOR_N(i, n)
  {
    int e;
    cin >> e;
  }
}

signed main()
{
  fastio();

  unsigned t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
