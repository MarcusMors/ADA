#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

void solve()
{
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

  // unsigned t;
  // cin >> t;

  // while(t--){ solve(); }

  std::vector<int> vec = { 1, 2, 3, 4, 5 };
  int n = vec.size();

  // Nested loops to generate combinations
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      // Pair elements at indices i and j
      int a = vec[i];
      int b = vec[j];

      // Do something with the pair (a, b)
      std::cout << "(" << a << ", " << b << ")" << std::endl;
    }
  }

  return 0;
}
