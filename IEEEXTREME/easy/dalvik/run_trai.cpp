#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
// #define int long long
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define push_back
#define all(x) (x).begin(), (x).end()

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using ii = std::pair<int, int>;

void solve()
{
  int v0;
  cin >> v0;
  int v1;
  cin >> v1;
  int v2;
  cin >> v2;
  int v3 = 1;
  int v4 = 0;
  int v5 = 0 - v3;
  int v6 = v3;
  int v7 = -v1;
  int v8 = v0;
  int v9 = v0 + v1;
  int v10 = 0;
  int v11 = 0;
  int v12 = v3;
  while (true) {
    v11 += v1;
    v10 += v0;
    int v13 = v10;
    int v14 = v4;
    int v15 = v4;
    while (true) {
      int v16 = v13 + v13;

      if (v16 <= v1) { break; }

      v13 = v13 - v1;
      v14 = v14 + v3;
      v15 = v15 + v1;
      continue;
    }

    int v17 = v4;
    int v18 = v3;
    if (v13 <= v4) { v13 = v4 - v13; }

    while (true) {
      v17 = v17 + v13;
      v18 = v18 + v3;

      if (v18 <= v6) { continue; }
      break;
    }

    v18 = v3;

    while (true) {
      v17 = v17 - v9;
      v18 = v18 + v3;
      if (v18 <= v12) { continue; }
      break;
    }

    if (v17 >= v4) {
      v12 = v12 + v3;
    } else {
      v5 = v14;
      v6 = v12;
      v7 = v15;
      v8 = v10;
      v9 = v13;
    }

    if (v12 <= v2) { continue; }
    cout << v6 << "\n";
    break;
  }
}

signed main()
{
  fastio();

  int t;
  cin >> t;

  while (t--) { solve(); }
  // solve();

  return 0;
}

/*

4
10 3 5
987 654 321
2023 1028 321
1229276485 555555555 3565
 */
