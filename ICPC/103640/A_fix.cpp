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

  if (n <= 1) {
    cout << 1 << " " << v[0] << "\n";
    return;
  }

  vi prefix_max(n);
  vi suffix_min(n);

  prefix_max[0] = v[0];
  for (int i = 1; i < n; ++i) { prefix_max[i] = max(v[i], prefix_max[i - 1]); }

  suffix_min[n - 1] = v[n - 1];
  for (int i = n - 2; i >= 0; --i) { suffix_min[i] = min(v[i], suffix_min[i + 1]); }

  vi sol{};
  for (int i = 1; i < n - 1; ++i) {
    if (prefix_max[i - 1] <= v[i] and v[i] < suffix_min[i + 1]) { sol.push_back(v[i]); }
  }

  if (v[0] < suffix_min[1]) { sol.push_back(v[0]); }

  if (prefix_max[n - 2] <= v[n - 1]) { sol.push_back(v[n - 1]); }

  sort(all(sol));

  // if (sol.size() == 0) {
  //   cout << 0 << "\n";
  // } else
  if (sol.size() <= 100) {
    cout << sol.size() << " ";
    for (int i = 0; i < sol.size(); i++) { cout << sol[i] << " "; }
    cout << "\n";
  } else {
    cout << sol.size() << " ";
    for (int i = 0; i < 100; i++) { cout << sol[i] << " "; }
    cout << "\n";
  }
}

/*
1 1

5 2 3 4 5 2

2 2 2

2 1 2

3 1 2 2

3 1 2 5

16 2 2 2 2 1 0 3 4 5 5 5 5 9 6 8 7

17 2 2 2 2 1 0 3 4 5 5 5 5 9 6 8 7 100

18 -1 2 2 2 2 1 0 3 4 5 5 5 5 9 6 8 7 100
 */

signed main()
{
  fastio();

  solve();

  return 0;
}
