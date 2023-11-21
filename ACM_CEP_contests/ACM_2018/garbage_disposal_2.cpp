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

using namespace std;
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
  int k;
  cin >> k;

  int count = 0;
  vi v(n);

  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;

    v[i] = e % (2 * k);
    count += 2 * (e / (2 * k));
  }

  for (int i = 0; i < n - 1; i++) {
    // use the necessary.
    if (v[i] >= k) {
      v[i] -= k;
      count++;
    }

    // share the extra
    int a_extra = v[i] % k;
    int b_extra = v[i + 1] % k;

    if (a_extra == 0) { continue; }

    int extra = a_extra + b_extra;
    if (extra >= k) {
      int c_extra = extra - k;
      count++;
      v[i] = 0;
      v[i + 1] = (v[i + 1] + c_extra) - b_extra;
    } else {
      v[i] = 0;
      count++;
      // a+b en la bolsa
      // k - extra, es lo que tengo para poner lo de v[i+1]
      v[i + 1] -= b_extra;
      int more = k - extra;
      if (v[i + 1] > 0) {
        if ((v[i + 1] - more) < 0) {
          v[i + 1] = 0;
        } else {
          v[i + 1] = v[i + 1] - more;
        }
      }
    }
  }

  count += (v.back() + (k - 1)) / k;


  cout << count;
}


signed main()
{
  fastio();

  solve();

  return 0;
}
