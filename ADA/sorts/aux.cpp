#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
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
  // int n = 14;
  // int n = ;
  // int n = 1;
  // bitset<6> b{ "110100" };
  bitset<6> b{ "011111" };
  unsigned n = b.to_ulong();
  // unsigned n = 32;

  cout << "n: " << n << "\n";
  cout << "n: " << bitset<32>(n) << "\n";
  cout << __builtin_ffs(n) << "\n";// because 10: "1010", 2 is the least significant bit.

  cout << "n: " << bitset<32>(n) << "\n";
  cout << __builtin_clz(n) << "\n";// because 132: "1 0000", 4 trailing ceros.

  cout << "n: " << bitset<32>(n) << "\n";
  cout << __builtin_popcount(n) << "\n";// returns number of 1-bits of n. n is unsigned int

  cout << "n: " << bitset<32>(n) << "\n";
  cout << __builtin_popcount(n) << "\n";
}

signed main()
{
  fastio();
  solve();

  return 0;
}
