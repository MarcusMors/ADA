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

void solve()
{
  int n;
  cin >> n;

  vi v(n);

  rep(i, 0, n) { cin >> v[i]; }
  //

  int l = v[0];
  int pl = v[0];
  int l_sz = 1;
  int pl_sz = 1;
  int g = v[0];

  vi sol{ v[0] };
  bool flag = false;
  bool flag2 = false;

  //
  // deque<ii> SOL{ { v[0], { 1 } } };
  map<int, int> SOL;
  SOL[v[0]] = 1;
  // vii SOL{ { v[0], 1 } };
  //


  for (int i = 1; i < n; i++) {
    if (v[i] < l) {
      if (pl_sz > 0) { pl_sz--; }

      if (not sol.empty()) { sol.pop_back(); }

      if (v[i] <= pl) {
        l = v[i];
        pl = v[i];
        sol.resize(pl_sz);
      } else {
        l = pl;
        sol.resize(l_sz);
      }
      flag2 = true;
      continue;
    }

    if (v[i] == l) { continue; }

    if (flag2 and v[i] == g) {
      sol.push_back(v[i]);
      // SOL.push_back({v[i],});
      flag2 = false;
      continue;
      // debería aumentar el 2
    }

    if (v[i] > g) {
      g = v[i];
      l = v[i];
      sol.push_back(v[i]);
      l_sz = sol.size();

      flag = true;
      continue;
    }


    // if (flag and v[i] > l and v[i] < g) {
    //   l = l;
    //   sol.pop_back();
    //   flag = false;
    //   continue;
    // }
    //
  }

  cout << sol.size() << " " << sol << "\n";

  /*
  17 2 2 2 2 1 0 2 3 4 5 5 5 5 9 6 8 7

  18 2 2 2 2 1 0 2 3 4 0 5 5 5 5 9 6 8 7


  19 2 2 2 2 1 0 2 3 4 0 5 5 5 5 6 10 7 9 8 5
   */
}

signed main()
{
  fastio();

  solve();

  return 0;
}
