#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

void solve(int t)
{
  unsigned n;
  cin >> n;

  FOR_N(i, n)
  {
    int e;
    cin >> e;
  }

  cout << "case #" << t << ":";
}

signed main()
{
  fastio();

  unsigned t;
  cin >> t;

  while (t--) { solve(t); }

  return 0;
}
