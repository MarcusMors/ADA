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
  int n1;
  cin >> n1;
  int n2;
  cin >> n2;

  ii n{ n1, n2 };

  int t;
  cin >> t;
  // vii v(t);
  // vii v(t);
  vector<std::pair<int, int>> v(t);

  rep(i, 0, t)
  {
    int a;
    cin >> a;
    int b;
    cin >> b;
    v[i] = { a, b };
    // cout << (abs(a - n1) == abs(b - n2)) << "\n";

    if (a == n1 or b == n2 or (abs(a - n1) == abs(b - n2))) {
      // if (a == n1 or b == n2 or ((a - n1) == (b - n2))) {
      cout << "Algebraico!\n";
    } else {
      cout << ":(\n";
    }
  }
  //
}

/*
3 3
4
1 1
5 5
1 5
5 1

 */

/*
Un golpe certero puede ser dado si esta posición (x,y)
está en la misma línea(horizontal o vertical) o en una de las
diagonales de la posición  (i,j) .

Si Finn esta en la misma posición que el Lich, se considerará como golpe certero.

 */

signed main()
{
  fastio();

  solve();

  return 0;
}
