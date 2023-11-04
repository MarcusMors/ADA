#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll

//~ #define char unsigned char
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define len(x) ((int)x.size())
#define FI first
#define SE second
#define MP make_pair
#define PB push_back

typedef array<int, 2> ii;
typedef array<int, 3> int3;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9, N = 2e6 + 10;
const int SQN = sqrtl(N) + 1, LOGN = __lg(N) + 1;
const ll LINF = 1e18, MOD = 1e9 + 7;
const double EPS = 1e-9;

int f(int op, int x, int y)
{
  //~ cout<<x<<" "<<op<<" "<<y<<"\n";
  if (op == 1)
    return x + y;
  else if (op == 2)
    return x - y;
  return x * y;
}

void solve()
{
  int a[5];
  rep(i, 5) { cin >> a[i]; }
  sort(a, a + 5);
  do {
    rep(i, 3) rep(j, 3) rep(k, 3) rep(m, 3)
    {
      int ans = a[0];
      ans = f(i, ans, a[1]);
      ans = f(j, ans, a[2]);
      ans = f(k, ans, a[3]);
      ans = f(m, ans, a[4]);
      //~ cout<<ans<<"\n";
      //~ return;
      if (ans == 23) {
        cout << "Posible\n";
        return;
      }
    }
  } while (next_permutation(a, a + 5));
  cout << "Imposible\n";
}

signed main()
{
  cin.tie(0)->sync_with_stdio(0);
  cout.precision(10);
  cout << fixed;
  solve();
  return 0;
}
