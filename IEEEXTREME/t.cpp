#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((int)(x).size())
#define FI first
#define SE second
#define MP make_pair
#define PB push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;

const int INF = 1e18, N = 2e5 + 10, MOD = 1e9 + 7;
const int SQN = sqrtl(N) + 1, LOGN = __lg(N) + 1;
const ld EPS = 1e-6;

void solve()
{
  int n, h, a, c, q;
  cin >> n >> h >> a >> c >> q;

  int ans = 0;
  vi st;
  st.PB(h);
  rep(i, n - 1)
  {
    h = ((a * h) % q + c) % q;
    ans += len(st);
    while (!st.empty() && st.back() <= h) { st.pop_back(); }
    st.PB(h);
  }
  cout << ans << "\n";
}

signed main()
{
  cin.tie(0)->sync_with_stdio(0);
  cout.precision(10);
  cout << fixed;

  solve();
  return 0;
}
