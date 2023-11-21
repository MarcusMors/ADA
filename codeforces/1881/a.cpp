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
  int m;
  cin >> m;
  string str_n;
  cin >> str_n;
  string str_m;
  cin >> str_m;

  vector<bool> v(str_m.size(), false);
  for (int i = 0; i < str_m.size(); i++) {
    //
    // for (size_t i = 0; i < count; i++)
    // {
    //   /* code */
    // }

    // v[i] =
  }


  string str_n_max{ str_n };
  for (int i = 0; i < 25; i++) { str_n_max += str_n_max; }

  cout << str_n_max << "\n";

  int counter = 0;
  int upper = n * 1;

  for (int i = 0; i < 25 - m; i++) {
    bool found = str_m.size() <= i;
    for (int j = str_m.size() - 1; found and j >= 0; j--) {
      if (str_n_max[i - j] != str_m[(str_m.size() - 1) - j]) {
        found = false;
        break;
      }
    }

    if (i == upper) {
      if (found) {
        cout << counter << "\n";
        return;
      }
      counter++;
      upper = upper * 2;
    }
  }

  cout << -1 << "\n";
}

/*
1
1 19
m
mmmmmmmmmmmmmmmmmmm
 */

signed main()
{
  fastio();

  int t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
