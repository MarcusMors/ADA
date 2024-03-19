#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// __gcd(value1, value2)
// append ll to get the long long version
// __builtin_ffs(x)// returns 1+ index of least significant bit else returns cero.
// __builtin_ffs(10) = 2 // because 10: "1010", 2 is 1 + the index of the least significant bit from right to left
// __builtin_clz(x) // returns number of leading 0-bits of x which starts from most significant bit position.
// __builtin_clz(16) = 27// int has 32 bits, because 16: "1 0000", has 5 bits, 32 - 5 = 27.
// __builtin_popcount(x) // returns number of 1-bits of x. x is unsigned int
// __builtin_popcount(14) = 3// because 14: "1110", has three 1-bits.

// #define int long long
#define rep(i, begin, end) \
  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
#define all(x) (x).begin(), (x).end()
// #define type typename

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using vi = std::vector<int>;
using ii = std::pair<int, int>;

template<class T, class U> std::ostream &operator<<(ostream &os, pair<T, U> v)
{
  return os << "(" << v.first << "," << v.second << ")";
}
template<class T> std::ostream &operator<<(ostream &os, vector<T> v)
{
  for (auto &&e : v) { os << e << " "; }
  return os;
}

// vi v{};
vi v(200000);

void solve()
{
  int n;
  cin >> n;

  int p = 1;

  v.resize(n);

  rep(i, 0, n) { cin >> v[i]; }

  vi ks{};
  for (int k = 2; k <= n / 2; k++) {
    if (n % k == 0) { ks.pb(k); }
  }

  for (auto &&k : ks) {
    for (int i = 0; i < k; i++) {
      //  0, k , 2k ... n/k - k
      int gcd = __gcd(v[0], v[k]);
      for (int j = k; j < n; j += k) {
        // i + j
        gcd = __gcd(gcd, v[i + j] == 0 ? gcd : v[i + j]);
      }

      if (gcd != 1) { p++; }
    }
  }


  cout << p << "\n";
  // if next is 0, it counts as the max gcd

  //

  //
}

/*

8
4
1 2 1 4
3
1 2 3
5
1 1 1 1 1
6
1 3 1 1 3 1
6
6 2 6 2 2 2
6
2 6 3 6 6 6
10
1 7 5 1 4 3 1 3 1 4
1
1





 */

signed main()
{
  // v.reserve()
  // v.resize()
  fastio();

  int t;
  cin >> t;

  while (t--) {
    solve();
    v.clear();
  }

  return 0;
}
