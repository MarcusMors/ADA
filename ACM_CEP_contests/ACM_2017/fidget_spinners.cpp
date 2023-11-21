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

// 999983

const unsigned N = 100000;
//             0  1  2  3  4   5   6   7
int primes[N]{ 2, 3, 5, 7, 11, 13, 17, 19 };

void solve()
{
  int n;
  cin >> n;
  int m;
  cin >> m;

  if (m == 2) {
    cout << "1\n";
    return;
  }

  int *pit_end = primes + 8;
  // find greatest prime before m;

  for (int i = 18; i <= m + 1; i += 6) {
    const int prev = i - 1;
    const int next = i + 1;

    bool is_prime = true;
    auto e = upper_bound(primes, pit_end, sqrt(prev + 4));

    for (int *it = &(primes[0]); it != e; it++) {
      if (prev % *it == 0) {
        is_prime = false;
        break;
      }
    }

    if (is_prime) {
      *pit_end = prev;
      pit_end++;
    }

    is_prime = true;

    e = upper_bound(primes, pit_end, sqrt(prev + 4));

    for (int *it = &(primes[0]); it != e; it++) {
      if (next % *it == 0) {
        is_prime = false;
        break;
      }
    }

    if (is_prime) {
      *pit_end = next;
      pit_end++;
    }
  }

  int target = m;
  auto it = lower_bound(primes, pit_end, target);

  int p;
  if (it == pit_end) {
    p = *(pit_end - 1);
  } else {
    if (target == *it) {
      p = *(it);
    } else {
      p = *(it - 1);
    }
  }

  cout << m - p << "\n";
}

signed main()
{
  // fastio();

  solve();

  return 0;
}
