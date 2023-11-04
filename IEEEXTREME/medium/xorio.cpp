#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using ii = std::pair<int, int>;

const int mod = 1'000'000'000 + 7;

void solve()
{
  int n;
  cin >> n;
  n++;
  vector<int> arr(n);
  vector<int> xs(n);
  arr[0] = 0;
  xs[0] = 0;
  for (int i = 1; i < n; i++) {
    cin >> arr[i];
    xs[i] = xs[i - 1] xor arr[i];
  }

  int count = 0;

  vector<set<int>> v1(n);
  vector<set<int>> v2(n);
  vector<vector<set<int>>> v{ v1, v2 };
  bool check_v = true;
  for (int i = 1; i < n; i++) {
    // v[check_v][0] means order sz 1
    // v[check_v][1] means order sz 2
    // v[check_v][2] means order sz 3
    if (arr[i]) { v[check_v][0].insert(arr[i]); }
    v[check_v][0].insert(0);
    count += v[check_v][0].size();

    // exception size 1?, just add it
    for (int sz = 2; sz <= i; sz++) {

      int x = xs[i - sz] xor xs[i];
      // int x = arr[i - (sz - 1)] xor arr[i];

      set<int> s;
      set_union(all(v[!check_v][sz - 2]), all(v[check_v][sz - 2]), inserter(s, s.begin()));
      s.insert(x);
      v[check_v][sz - 1] = s;
      v[!check_v][sz - 2].clear();
      count += s.size();
    }
    // check_v
    check_v = !check_v;
  }

  cout << count % mod << "\n";
}

/*
1
3
3 3 2
 */

signed main()
{
  fastio();

  int t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}

/*
3
2
1 0
2
1 1
3
3 3 2
 */
