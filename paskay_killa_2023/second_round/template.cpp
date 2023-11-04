#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

#define int long long
// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

const int N = 2e5 + 10;
typedef array<int, 3> ii;
// ii a[N];

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> t(n), d(n);
  for (auto &x : t) cin >> x;
  for (auto &x : d) cin >> x;
  sort(t.begin(), t.end());
  sort(d.begin(), d.end());
  vector<pair<int, int>> vp(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    vp[i].first = t[i];
    vp[i].second = d[n - i - 1];
    mx = max(vp[i].first * vp[i].second, mx);
  }
  int inf = 0, sup = mx;
  int ans = sup;
  while (inf < sup) {
    int m = (inf + sup) / 2;
    int mn = 1e9;
    int operaciones = 0;
    for (int i = 0; i < n; i++) {
      int cnt = max(0ll, vp[i].first - m / vp[i].second);
      int mn = min(mn, m / vp[i].second * vp[i].second);
      operaciones += cnt;
    }
    if (m == sup - 1) break;
    if (operaciones <= k) {
      ans = min(ans, mn);
      sup = m;
    } else {
      inf = m;
    }
  }
  cout << ans << endl;
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
