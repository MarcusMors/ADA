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

#define int long long
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

  // x >= 1
  int const upper_null = 1'000'000'000'0;
  int type_1{ -1 };
  int type_2{ upper_null };
  set<int> type_3{};

  rep(i, 0, n)
  {
    int type;
    cin >> type;
    int x;
    cin >> x;
    switch (type) {
    case 1:// k >= x
      if (x > type_1) { type_1 = x; }
      break;
    case 2:// k <= x
      if (x < type_2) { type_2 = x; }
      break;
    case 3:// k != x
      type_3.insert(x);
      break;
    }
    //
  }

  // cout << "type_1: " << type_1 << "\n";
  // cout << "type_2: " << type_2 << "\n";
  int count = count_if(all(type_3), [&](int e) { return e >= type_1 && e <= type_2; });
  // cout << "count: " << count << "\n";
  if (type_1 > type_2) {
    cout << "0\n";
    return;
  }
  const int rpta = (type_2 - type_1) + 1 - count;
  cout << rpta << "\n";
}

signed main()
{
  fastio();

  int t;
  cin >> t;

  while (t--) { solve(); }
  // solve();
  return 0;
}

/*
4
1 3
2 10
3 1
3 5
out:
7
 */

/*
x <= 10^9

4
k >= 3
k <= 10
k != 1
k != 5

3,4,5,6,7,8,9,10
3,4,6,7,8,9,10

rpta = 7
*/
