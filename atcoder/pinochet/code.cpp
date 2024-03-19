
// https://atcoder.jp/contests/abc295/tasks/abc295_d?lang=en

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
  string num;
  cin >> num;
  int sz = num.size();
  // vector<vi> DP(9, vi(sz + 1));
  //                         0123456789
  // vector<string> DP(sz + 1, "0000000000");

  map<string, ii> m;
  // map<string, vi> m;
  // map<string, map<int,int> > m;
  string state = "0000000000";
  // m[state].push_back(0);
  m[state].first++;// first even

  int c = 0;
  for (int i = 0; i < sz; i++) {

    int e = num[i] - '0';
    state[e]++;
    state[e] = '0' + state[e] % 2;

    // search previous indexes
    // for (auto &&e : m[state]) {
    //   if ((i + 1 - e) % 2 == 0) { c++; }
    // }

    if ((i + 1) % 2 == 0) {// it's even
      c += m[state].first;
      m[state].first++;
    } else {// it's odd
      c += m[state].second;
      m[state].second++;
    }

    // m[state].push_back(i + 1);
  }

  cout << c << "\n";
}

signed main()
{
  fastio();

  solve();

  return 0;
}
