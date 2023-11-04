#include <bits/stdc++.h>
#include <cstddef>
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

void solve()
{
  string str;
  cin >> str;

  cui n = str.size();
  ui max_sz = 0;
  // ui r = str[1] - '0';
  size_t sz = 2;
  for (size_t i = 0; i + sz <= n; i++) {
    ui l = str[i] - '0';
    ui r = str[i + 1] - '0';
    if (l == r and sz > max_sz) { max_sz = sz; }
    while (i + sz <= n) {
      cui m = str[i + sz / 2] - '0';
      sz += 2;
      l += m;
      r += str[i + (sz - 1)] - '0';
      r += str[i + (sz - 2)] - '0';
      r -= m;
      if (l == r and sz > max_sz) { max_sz = sz; }
    }
    sz = 2;
  }
  cout << max_sz << "\n";
}

signed main()
{
  fastio();

  unsigned t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
