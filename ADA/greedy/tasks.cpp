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

int DFS(vii c, int t, int l, vii &path)
{
  if (c.empty()) { return kg; }

  int best_w_until_now = kg;
  vi best_path_until_now{ path };

  for (int i = c.size() - 1; i != -1U; i--) {
    // filter c
    if (kg + c[i] > l) { continue; }

    vi n_c{ c };
    swap(n_c[i], n_c.back());

    n_c.pop_back();

    vi n_path{ path };
    n_path.pb(c[i]);
    int n_kg = DFS(c, kg + c[i], l, n_path);
    if (n_kg > best_w_until_now) {
      best_w_until_now = n_kg;
      best_path_until_now = n_path;
    }
  }

  return best_w_until_now;
}


void solve()
{
  int n;
  cin >> n;

  vii v(n);

  rep(i, 0, n)
  {
    int a;
    int b;
    cin >> a;
    cin >> b;
    v[i] = { a, b };
  }

  vii path{};

  // cout << DFS(v, 0, l, path) << endl;
}

/*
5
50 10 15 30
2  1  2  1

*/

/*
4 30
3 7 8 20

*/

signed main()
{
  fastio();

  // int t;
  // cin >> t;

  // while (t--) { solve(); }
  solve();

  return 0;
}
