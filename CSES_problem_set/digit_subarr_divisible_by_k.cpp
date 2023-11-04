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

const int N = 100000;
char arr[N];
void solve()
{
  int n;
  cin >> n;
  map<int, int> m;
  m[0] = 1;
  FOR_N(i, n) { cin >> arr[i]; }

  int sum = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i] - '0';
    count += m[sum % 3];
    m[sum % 3]++;
  }
  cout << count << "\n";
  //
}
/*
5
6 192021
4 1234
1 3
2 34
10 1234560070

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
