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
  vi v(3);
  rep(i, 0, 3) { cin >> v[i]; }

  sort(all(v));
  // for (int i = 2; i >= 0; i--) {
  //   // v[i] = v[i]- v[0];
  // }


  if (v[0] == v[1] and v[1] == v[2]) {
    cout << "YES\n";
    return;
  }


  if (v[1] % v[0] != 0 or v[2] % v[0] != 0) {
    cout << "NO\n";
    return;
  }
  // if (v[0] + v[1] > v[2]) {
  //   cout << "NO\n";
  //   return;
  // }

  // if (2 * (v[0] + v[1]) > v[2]) {
  //   cout << "NO\n";
  //   return;
  // }

  if (v[1] / v[0] == 2) {
    if (v[2] / v[0] <= 3) {
      cout << "YES\n";
      return;
    }
  }

  if (v[1] == v[0]) {
    if (v[2] / v[0] <= 4) {
      cout << "YES\n";
      return;
    }
  }

  if (v[2] == v[1]) {
    if (v[1] / v[0] <= 2) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
  return;

  //
}

/*
1 3 2
YES
5 5 5
YES
6 3 3
YES
4 4 12
YES
1000000000 1000000000 1000000000
YES
9 3 6
YES
2 8 2
YES
8 4 8
YES


6 36 12
NO
7 8 7
NO
12 6 8
NO
3 7 1
NO
9 9 1
NO
5 3 10
NO
2 8 4
NO
 */

signed main()
{
  fastio();

  int t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
