// problem: https://www.codechef.com/problems/EQDIFFER
#include <bits/stdc++.h>

#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)
// #define unsigned unsigned
// #define FOR_FROM(it, start, limit) for (unsigned it = (start); it < lim it; it++)
#define FOR_N(it, limit) for (unsigned it = 0; it < (limit); it++)

using namespace std;

struct n_freq
{
  unsigned n{ 0 };
  mutable unsigned f{ 1 };
  void increment() { f++; }
};

bool operator<(const n_freq &lhs, const n_freq &rhs) { return lhs.n < rhs.n; }

void solve()
{
  unsigned n;
  cin >> n;

  std::set<n_freq> freqs;
  if (n <= 2) {
    for (unsigned i = 0; i < n; i++) {
      unsigned e;
      cin >> e;
    }
    cout << 0 << endl;
    return;
  }

  unsigned max_f = 1;
  FOR_N(i, n)
  {
    unsigned e;
    cin >> e;
    if (auto [it, inserted] = freqs.insert({ e, 1 }); not inserted) {//
      ++(it->f);
      if (it->f > max_f) { max_f = it->f; }
    }
  }
  const unsigned rpta = max_f == 1 ? n - 2 : n - max_f;
  cout << rpta << endl;
  // cout << max_f << endl;
}

signed main()
{
  fastio();

  unsigned t;
  cin >> t;
  while (t--) { solve(); }

  return 0;
}
