
// Amplitud, no profundidad, apenas hay solu, output: "possible", else "impossible"
//

#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

using lli = long long int;
using u = int;
using llu = long long int;
using ull = int long long;

#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

const llu max_w = 200000;
const llu max_h = 1000000;


// bool M[max_w][max_h];
std::vector<bool> M[max_w];
llu w;
llu h;

void f()
{
  bool break_all = false;

  for (ull y = 0; y < h; y++) {
    for (ull x = 0; x < w; x++) {
      if (M[x][y] == 1) { continue; }

      bool next = true;
      if (x + 1 < w) { next = M[x + 1][y]; }

      bool prev = true;
      if (x - 1 != -1ULL) { prev = M[x - 1][y]; }
      if (prev and next) {
        M[x][y] = true;
        if (y + 1 < h) {
          M[x][y + 1] = true;
          continue;
        }
        cout << "impossible" << endl;
        break_all = true;
        break;
      }

      bool up = true;
      if (y + 1 < h) { up = M[x][y + 1]; }

      bool down = true;
      if (y - 1 != -1ULL) { down = M[x][y - 1]; }

      if (up and down) {
        if (prev and next) {
          cout << "impossible" << endl;
          break_all = true;
          break;
        }

        M[x][y] = true;
        llu p;
        if (prev) { p = x + 1; }
        if (next) { p = x - 1; }
        M[p][y] = true;
      }
    }
    if (break_all) { break; }
  }
}

void solve()
{
  cin >> w >> h;
  ull t = w * h;

  for (int i = 0; i < w; i++) { M[i].resize(h, false); }


  ull count = 0;
  FOR_N(i, w)
  {
    u e;
    cin >> e;
    count += e;
    for (u j = 0; j < e; j++) { M[i][j] = 1; }
  }

  // for (ull x = 0; x < w; x++) {
  //   for (ull y = 0; y < h; y++) {
  //     if (M[x][y]) {
  //       cout << "*";
  //     } else {
  //       cout << "-";
  //     }
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  // cout << endl;
  // f();
  // cout << endl;
  // cout << endl;

  // for (ull x = 0; x < w; x++) {
  //   for (ull y = 0; y < h; y++) {
  //     if (M[x][y]) {
  //       cout << "*";
  //     } else {
  //       cout << "-";
  //     }
  //   }
  //   cout << endl;
  // }
}

signed main()
{
  fastio();
  solve();

  return 0;
}
