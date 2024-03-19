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

  string a{};// lower case
  cin >> a;
  string b{};// lower case
  cin >> b;
  string c{};// lower case
  cin >> c;

  string t(n, '_');// lower or upper

  bool to_be_canceled{ true };
  for (int i = 0; i < n; i++) {
    if (!((a[i] == c[i]) or (b[i] == c[i]))) {
      to_be_canceled = false;
      break;
    }
  }
  if (to_be_canceled) {
    cout << "NO\n";
    return;
  }


  bool flag{ true };
  for (int i = 0; i < n; i++) {
    // cout << t << "\n";
    // if ((a[i] == c[i]) or (b[i] == c[i])) {
    //   flag = false;
    //   cout << "no\n";
    //   return;
    // }

    if (a[i] == b[i]) { t[i] = a[i]; }
  }

  cout << "YES\n";
}

signed main()
{
  fastio();

  int t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
