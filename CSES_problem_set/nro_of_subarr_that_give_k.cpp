#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define push_back
#define all(v) v.begin(), v.end()

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using ii = std::pair<int, int>;

cui N = 1'000'000;
ui arr[N]{};

void solve()
{
  int n;
  int k;
  cin >> n;
  cin >> k;

  FOR_N(i, n) { cin >> arr[i]; }
  std::map<int, int> m;
  m[0] = 1;

  int count = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum = sum xor arr[i];
    count += m[sum xor k];
    m[sum] += 1;
  }
  cout << count << "\n";
}


signed main()
{
  fastio();

  // int t;
  // cin >> t;

  // while (t--) { solve(); }
  solve();

  return 0;
}

/*
5 1
1 2 4 7 2

*/
