#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define push_back
#define all(v) v.begin(), v.end()

using namespace std;
using ui = unsigned int;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using ii = std::pair<int, int>;


cui n_max = 1'000'000;
ui DP[n_max]{};

void solve()
{
  string str;
  cin >> str;
  int n = str.size();

  FOR_N(i, n_max) { DP[i] = 0; }
  DP[0] = 0;
  for (size_t i = 1; i < n; i++) { DP[i] = DP[i - 1] + str[i] - '0'; }

  int max_size = 0;
  for (size_t sz = 0; sz <= n; sz += 2) {
    for (size_t i = 0; i + sz <= n; i++) {
      int j = i + sz;
      if (DP[j - sz] - DP[i] == DP[j] - DP[i + sz] and sz > max_size) {
        max_size = sz;
        break;
      }
    }
  }

  cout << max_size << "\n";
}

signed main()
{
  fastio();

  unsigned t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
