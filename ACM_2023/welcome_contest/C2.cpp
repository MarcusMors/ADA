#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using cui = const unsigned;
using ui = unsigned;
using strs = std::stringstream;
using namespace std;

// vector<unsigned> arr;
const cui SIZE = 2 * 100000;
// 2560 00000

// 2560 00000

// 25600000000000
// 40000000000

// 40000000000

ui nums[SIZE];
// vector<vector<bool>> DP;
// bool DP[SIZE][SIZE];

bool f(int b, int e) { return nums[b] == (e - b) - 1 or nums[e - 1] == (e - b) - 1; }

void solve()
{
  // arr.clear();
  unsigned n;
  cin >> n;
  // arr(n);
  FOR_N(i, n) { cin >> nums[i]; }

  // for (ui i = 1; i < n; i++) { DP[i - 1][i] = f(i, i + 1); }
  // for (ui i = 1; i < n; i++) { DP[i - 1][i] = f(i, i + 1); }

  //
  for (ui sz = 4; sz <= n; sz++) {
    uint k1 = sz / 2;
    uint k2 = (sz + 1) / 2;
    ui l = (n - sz) + 1;
    printf("size:%d, l:%d\n", sz, l);
    for (ui i = 0; i < l; i++) {
      uint j = i + sz - 1;

      printf("(%d,%d,%d,%d)\n", i, j, k1, k2);
      // bool c1 = DP[i][j - k1];
      // bool c2 = DP[i - k2][j];
      // check if both bool

      // bool c3 = DP[i][j - k];
      // bool c4 = DP[i - k][j];

      // DP[i][j] =
      // sum[i][j] = sum[i][j - k] + sum[j - k + 1][j];
    }
  }


  //
  //
}

signed main()
{
  DP.resize(SIZE, vector<bool>(SIZE));

  // fastio();

  unsigned t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}

/*
1
6
1 2 1 2 7 5

 */
