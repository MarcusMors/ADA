

#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int;
using lli = long long int;
using u = int;
using llu = long long int;
using ull = int long long;
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

u f_r(llu n, u d)
{

  if (d == 1) { return n + 1; }

  llu l = pow(10, d - 1);
  llu msd = (n - l) / l;

  return msd + f_r(l - 1, d - 1);
}

u f(llu n, u d)
{
  if (d == 1) { return n + 1; }

  llu l = pow(10, d - 1);
  llu msd = ((n - l) / l) + 1;
  llu smsd = (n / (l / 10)) % 10;

  u di = d;
  llu nn = n;
  llu ll = l;
  int p = 0;
  bool flag = false;

  while (di != 1) {
    llu t_msd = ((nn - ll) / ll) + 1;
    llu t_smsd = (nn / (ll / 10)) % 10;

    if (t_msd > t_smsd) {
      p = 1;
      break;
    } else if (t_msd == t_smsd) {
      nn = nn % ll;
      ll = ll / 10;
    } else {
      break;
    }
    di--;
  }
  // if (di == 1 and p == 0) {  }

  return msd + f_r(l - 1, d - 1) - p;
}

void solve()
{
  llu n;
  cin >> n;

  if (n == 0) { cout << 1 << endl; }

  //

  llu copy = n;
  llu digits = 0;
  llu msd = 0;

  while (copy) {
    digits++;
    msd = copy;
    copy = copy / 10;
  }

  cout << "digits:" << digits << endl;
  llu l = pow(10, digits - 1);

  // llu smsd = (n / (l / 10)) % 10;
  // cout << "smsd:" << smsd << endl;
  cout << f(n, digits) << endl;
}

signed main()
{
  fastio();

  solve();

  return 0;
}
