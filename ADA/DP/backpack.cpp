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
struct trio
{
  int first{};
  int second{};
  int third{};
};

using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using viii = std::vector<trio>;
using vii = std::vector<std::pair<int, int>>;
using vi = std::vector<int>;
using ii = std::pair<int, int>;
using iii = trio;

int INF = 1'000'000;

template<class T, class U> std::ostream &operator<<(ostream &os, pair<T, U> v)
{
  return os << "(" << v.first << "," << v.second << ")";
}
template<class T> std::ostream &operator<<(ostream &os, vector<T> v)
{
  for (auto &&e : v) { os << e << " "; }
  return os;
}

struct iivi
{
  int first{ 0 };
  int second{ 0 };
  vi v{};
};

int f(vii v, int l)
{
  // v[x] = {value, weight};

  vector<vi> DP(v.size() + 1, vi(l + 1, 0));

  for (int item = 1; item < v.size() + 1; item++) {
    for (int w = 0; w <= l; w++) {
      int best_prev_w = (w - v[item - 1].second) < 0 ? -INF : DP[item - 1][w - v[item - 1].second] + v[item - 1].first;
      int upper = DP[item - 1][w];

      DP[item][w] = max(best_prev_w, upper);
    }
  }

  return DP.back().back();
}

/*
6 15
3 12
7 3
4 7
2 4
1 3
6 8


6 255
51 204
119 51
68 119
34 68
17 51
102 136


6 1000
130 120
570 300
140 570
200 423
360 300
400 800
 */

void solve()
{
  int n;
  cin >> n;
  int l;
  cin >> l;
  vii v(n);
  // first: val
  // second: wei
  rep(i, 0, n)
  {
    int val;
    int wei;
    cin >> val;
    cin >> wei;
    v[i] = { val, wei };
  }
  // rep(i, 0, n)
  // {
  //   int val;
  //   cin >> val;
  //   v[i].first = val;
  // }
  // rep(i, 0, n)
  // {
  //   int wei;
  //   cin >> wei;
  //   v[i].second = wei;
  // }

  cout << f(v, l) << "\n";
}

/*
5 7
2 3
2 1
4 3
5 4
3 2
 */


signed main()
{
  fastio();
  solve();

  return 0;
}
