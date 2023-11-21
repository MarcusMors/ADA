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

// void solve()
// {
//   int n;
//   cin >> n;
//   int k;
//   cin >> k;

//   vi v(n);

//   int count = 0;
//   rep(i, 0, n)
//   {
//     int e;
//     cin >> e;
//     count += e / k;
//     v[i] = e % k;
//   }

//   for (int i = 0; i < n - 1; i++) {
//     int a = v[i];
//     int b = v[i + 1];

//     if (a + b >= k) {
//       v[i] = 0;
//       v[i + 1] = (a + b) - k;
//       count++;
//     } else {
//       if (a != 0 or b != 0) {
//         v[i] = 0;
//         v[i + 1] = 0;
//         count++;
//       }
//     }
//   }

//   if (v[n - 1] != 0) { count++; }

//   cout << count << endl;
// }

void solve()
{
  int n;
  cin >> n;
  int k;
  cin >> k;

  int count = 0;
  int e;
  cin >> e;
  count += e / k;

  if (n == 1) {
    count += (e + k - 1) / k;
    cout << count;
    return;
  }

  int a = e % k;
  int b;
  rep(i, 1, n)
  {
    cin >> e;
    b = e % (2 * k);
    count += 2 * (e / (2 * k));

    if (a + b >= k) {
      count++;
      a = (a + b) - k;
    } else if (a + b == 0) {
      a = 0;
    } else {
      a = 0;
      count++;
    }
  }

  if (a != 0) { count++; }

  cout << count;
}

/*
4 3
2 2 0 1

4 3
1 0 2 2

3 3
3 2 1

 */

signed main()
{
  fastio();

  solve();

  return 0;
}
