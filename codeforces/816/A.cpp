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
  int h{};
  cin >> h;
  char c{};
  cin >> c;
  int m{};
  cin >> m;

  //
  int cont = 0;
  do {
    if (m == 60) {
      h++;
      m = 0;
    }
    if (h == 24) { h = 0; }

    strs ss_h;
    ss_h << h;
    strs ss_m;
    ss_m << m;

    string l = ss_h.str();
    string r = ss_m.str();

    if (l.size() == 1) { l = '0' + l; }
    if (r.size() == 1) { r = '0' + r; }

    string r_reversed(r.rbegin(), r.rend());

    if (l == r_reversed) {
      cout << cont << "\n";
      return;
    } else {
      cont++;
      m++;
    }

  } while (true);
  //
}

signed main()
{
  fastio();

  solve();

  return 0;
}
