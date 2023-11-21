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

  vi v(n, 0);
  vi diffs(n, 0);

  cin >> v[0];

  for (int i = 1; i < n; i++) {
    cin >> v[i];

    diffs[i - 1] = v[i] > v[i - 1] ? v[i] - v[i - 1] : v[i - 1] - v[i];
    // diffs[i - 1] = abs(v[i] - v[i - 1]);
  }

  vi prefix(n, 0);
  vi sufix(n, 0);

  for (int i = 1; i < n; i++) { prefix[i] += prefix[i - 1] + diffs[i - 1]; }
  for (int i = n - 2; i >= 0; i--) { sufix[i] += sufix[i + 1] + diffs[i]; }
  //

  // int min = 1'000'000'000;
  int min = numeric_limits<int>::max();
  for (int i = 1; i < n - 1; i++) {
    int rpta = prefix[i - 1] + sufix[i + 1] + abs(v[i - 1] - v[i + 1]);
    if (rpta < min) { min = rpta; }
  }

  if (prefix.back() < min) { min = prefix.back(); }
  if (sufix.front() < min) { min = sufix.front(); }

  if (prefix[n - 2] < min) { min = prefix[n - 2]; }
  if (sufix[1] < min) { min = sufix[1]; }

  cout << min << "\n";

  // check end and start;
}

signed main()
{
  fastio();

  int t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
