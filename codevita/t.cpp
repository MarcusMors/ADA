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

template<class It> void print(It begin, It end)
{
  while (begin != end) {
    cout << *begin << " ";
    begin++;
  }
}
template<class It> void print(It it, int n) { print(it, it + n); }
template<class T> void print(vector<T> v, int n) { print(v.begin(), v.begin() + n); }


template<class It> void fill(It it, int n)
{
  It limit = it + n;
  auto val = *it;
  if (n == 0) { return; }
  cin >> val;
  *it = val;
  ++it;

  while (it != limit) {
    char coma;
    cin >> coma;
    cin >> val;
    *it = val;
    ++it;
  }
}

template<class T> void fill(vector<T> &v) { fill(v.begin(), v.size()); }
template<class T> void fill(vector<T> &v, int n) { fill(v.begin(), n); }

void solve()
{
  int n;
  cin >> n;
  vi v(n);
  fill(v, n);
  print(v, n);
}

/*
1
5
1,2,3,4,5
 */

signed main()
{
  fastio();
  int t;
  cin >> t;

  while (t--) { solve(); }
  // solve();


  return 0;
}
