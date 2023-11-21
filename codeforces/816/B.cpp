// https://codeforces.com/contest/816/problem/B

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

// 2147483647
const int N = 210'000;// 2147483647
int DP[N]{};

void solve()
{
  int n;
  cin >> n;
  int k;
  cin >> k;
  int q;
  cin >> q;

  rep(i, 0, n)
  {
    int a;
    int b;
    cin >> a;
    cin >> b;
    DP[a]++;
    DP[b + 1]--;
  }

  int sum = DP[0];
  if (sum < k) { DP[0] = 0; }

  for (int i = 1; i < N; i++) {
    sum += DP[i];
    if (sum < k) {
      DP[i] = DP[i - 1];
    } else {
      DP[i] = 1 + DP[i - 1];
    }
  }

  rep(i, 0, q)
  {
    int a;
    int b;
    cin >> a;
    cin >> b;

    if (DP[b] - DP[a - 1] >= k) {
      cout << DP[b] - DP[a - 1] << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
}

signed main()
{
  fastio();

  solve();

  return 0;
}

/*
3 2 4
91 94
92 97
95 99
92 97
93 97
95 96
90 100

 */
