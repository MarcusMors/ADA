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

int DFS(vii &path, vii ops, int l, int kg)
{
  if (ops.empty()) { return kg; }
  if (kg == l) { return kg; }
  if (kg > l) { return 1000000; }

  vii best_path_until_now{ path };
  int best_kg_until_now{ kg };

  for (int i = 0; i < ops.size(); i++) {
    // valid candidate
    const ii c = ops[i];
    if (kg + c.first > l) { continue; }

    vii parsed_ops{ ops };
    parsed_ops[i] = parsed_ops.back();

    // if (parsed_ops.size() != 0) {

    // }

    parsed_ops.pop_back();
    vii t_path{ path };
    t_path.pb(c);
    int t_kg = DFS(t_path, parsed_ops, l, kg + c.first);

    if (t_kg > best_kg_until_now) {
      best_kg_until_now = t_kg;
      best_path_until_now = t_path;
    }
  }

  return best_kg_until_now;
}

void solve()
{
  int n;
  cin >> n;
  int l;
  cin >> l;

  vii v(n);

  rep(i, 0, n)
  {
    int a;
    int b;
    cin >> a;
    cin >> b;
    v[i] = { a, b };
  }

  // rep(i, 0, n)
  // {
  //   int a;
  //   cin >> a;
  //   v[i].first = a;
  // }
  // rep(i, 0, n)
  // {
  //   int a;
  //   cin >> a;
  //   v[i].second = a;
  // }

  vii path{};
  int max = DFS(path, v, l, 0);

  cout << max << "\n";
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
