// #include <bits/stdc++.h>
#include <iostream>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define int long long
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve()
{
  int v0;
  int v1;
  int v2;
  cin >> v0;
  cin >> v1;
  cin >> v2;
  int v6 = 1;
  int v9 = v0 + v1;


  int v10 = 0;
  // l0
  int v13;
  int v17;
  for (int i = 1; i <= v2; i++) {// L0

    v10 += v0;

    v13 = v10;

    while (2 * v13 > v1) {// L1
      v13 -= v1;
    }

    // l2
    // v13 = v13 + v13 * -1(v13 <= 0)
    // v13 = -v13* (v13 <= 0)
    if (v13 <= 0) { v13 = -v13; }
    // L3

    v17 = v13 * v6;
    // v17 = v13 * v6 - v9 *i;
    // l5
    v17 -= v9 * i;

    if (v17 < 0) {// else L6
      v6 = i;
      v9 = v13;
    }
  }
  cout << v6 << "\n";
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
