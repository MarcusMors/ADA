#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

#define int long long
// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

const int N = 1e5 + 10;
typedef array<int, 3> ii;
struct Cmp
{
  bool operator()(const ii &i, const ii &j) const
  {
    if (i[1] + i[2] == j[1] + j[2]) {
      return i[0] < j[0];
      // return i[0] < j[0];
    }
    return i[1] + i[2] < j[1] + j[2];
  }
};

ii a[N];

void solve()
{
  int n;
  cin >> n;
  set<ii, Cmp> s1;
  set<ii> s2;
  for (int i = 0; i < n; ++i) {
    ii x;
    cin >> x[1] >> x[2];
    x[0] = i;
    s1.insert(x);
    a[i] = x;
  }

  int ans = 0, tx = 0, ix = 0;
  for (int i = 0; i < n; ++i) {
    if (s2.empty()) {
      auto x = *s1.begin();
      tx = x[1] + x[2];
      s1.erase(x);
      for (int j = ix; j < x[0]; ++j) { s2.insert(a[j]); }
      ix = x[0] + 1;
    } else {
      auto x = *s2.begin();
      ans = max(ans, tx - x[1]);
      tx += x[2];
      s1.erase(x);
      s2.erase(x);
    }
  }
  cout << ans << "\n";
}

signed main()
{
  fastio();

  // unsigned t;
  // cin >> t;

  // while (t--) { solve(); }
  solve();

  return 0;
}
