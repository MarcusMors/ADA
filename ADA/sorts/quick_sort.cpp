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

#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
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


template<class It, class F> void quick_sort(It b, It e, F cmp)
{
  if (e - b <= 1) { return; }

  auto pivot = *b;

  It r_it = e - 1;
  It l_it = b + 1;
  while (true) {
    bool d_break = false;
    while (r_it > b and cmp(pivot, *r_it)) { r_it--; }

    if (l_it > r_it) { break; }

    while (l_it < e and cmp(*l_it, pivot)) {
      l_it++;
      if (l_it > r_it) {
        d_break = true;
        break;
      }
    }

    if (d_break) { break; }
    swap(*l_it, *r_it);

    l_it++;
    r_it--;
  }

  swap(*r_it, *b);

  quick_sort(b, r_it, cmp);
  quick_sort(r_it + 1, e, cmp);
}

template<class It> void quick_sort(It b, It e)
{
  quick_sort(b, e, [](auto lhs, auto rhs) { return lhs < rhs; });
}

/*
in:
11
5 9 1 3 5 0 4 2 6 8 7
*/


void solve()
{
  int n;
  cin >> n;

  vi v(n);

  FOR_N(i, n) { cin >> v[i]; }

  cout << "v: " << v << "\n";
  // quick_sort(all(v));
  quick_sort(all(v), [](auto lhs, auto rhs) { return lhs > rhs; });
  cout << "v: " << v << "\n";
}

signed main()
{
  // fastio();

  solve();

  return 0;
}
