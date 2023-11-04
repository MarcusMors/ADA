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

const int N = 10000;
int arr[N];

vi join(vi l, vi r, int k)
{
  int aa = l.size();
  int bb = r.size();
  int cc = aa + bb;

  int sz;
  if (cc > k) {
    sz = k;
  } else {
    sz = cc;
  }

  vi n(sz);

  auto lit = l.begin();
  auto rit = r.begin();
  auto nit = n.begin();

  auto tmp = n.begin();
  while (nit < n.end()) {
    if (lit == l.end()) {
      tmp = rit;
      break;
    }
    if (rit == r.end()) {
      tmp = lit;
      break;
    }

    if (*lit < *rit) {
      *nit = *lit;
      lit++;
    } else {
      *nit = *rit;
      rit++;
    }
    nit++;
  }

  while (nit < n.end()) {
    *nit = *tmp;
    tmp++;
    nit++;
  }

  return n;
}

vi k_min(vi v, int b, int e, int k)
{
  // if (e - b == 0) { return vi{}; }
  if (e - b == 1) {
    vi tmp{ v[b] };
    return tmp;
  }

  int m = b + (e - b) / 2;
  vi l = k_min(v, b, m, k);
  vi r = k_min(v, m, e, k);

  return join(l, r, k);
}

int k_min(vi v, int k)
{
  auto rpta = k_min(v, 0, v.size(), k);
  cout << "rpta: " << rpta << "\n";
  return rpta[k - 1];
}

void solve()
{
  int n;
  int k;
  cin >> n;
  cin >> k;

  vi v(n);

  rep(i, 0, n) { cin >> v[i]; }

  cout << k_min(v, k) << "\n";
}
/*
9 5
1 6 2 7 11 3 7 2 3
 */

/*
 8 4
 1 6 2 7   3 7 2 3
  */

signed main()
{
  // fastio();
  solve();

  return 0;
}
