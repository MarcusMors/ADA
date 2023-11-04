
// Amplitud, no profundidad, apenas hay solu, output: "possible", else "impossible"
//

#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

using lli = long long unsigned;
using u = unsigned;
using llu = long long unsigned;
using ull = unsigned long long;

#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

const llu max_w = 200000;
// const llu max_h = 1000000;

llu M[max_w];
llu w, h, t;

struct M_c
{
  llu M[max_w];
  llu c = 0;
  ull l_x = 0;
  ull l_min_h = 0;
  M_c(M_c &m_c)
  {
    for (int i = 0; i < w; i++) { M[i] = m_c.M[i]; }
    c = m_c.c;
    l_x = m_c.l_x;
    l_min_h = m_c.l_min_h;
  }

  M_c()
  {
    for (int i = 0; i < w; i++) { this->M[i] = M[i]; }
  }
};

M_c create_M_c()
{
  M_c a;
  for (int i = 0; i < w; i++) { a.M[i] = M[i]; }

  return a;
}


bool BFS(M_c init)
{
  stack<M_c> s;
  s.push(init);
  while (not s.empty()) {
    M_c curr = s.top();
    s.pop();
    ull l_min_h = curr.l_min_h;

    if (t - curr.c == 2) {
      for (ull x = curr.l_x; x < w; x++) {

        if (curr.M[x] > l_min_h) { continue; }
        if (x + 1 < w and curr.M[x] == l_min_h) {
          cout << "possible" << endl;
          return true;
        }

        if (M[x] < h and curr.M[x] == l_min_h) {
          cout << "possible" << endl;
          return true;
        }
      }

      return false;
    } else {
      bool flag = true;
      for (ull min_h = l_min_h; min_h < h; min_h++) {
        for (ull x = curr.l_x; x < w; x++) {

          if (curr.M[x] > l_min_h) { continue; }
          if (x + 2 < w and curr.M[x] == l_min_h and curr.M[x + 1] == l_min_h) {
            M_c neun = curr;
            neun.M[x]++;
            neun.M[x + 1]++;
            neun.c += 2;
            s.push(neun);
            flag = false;
          }

          if (M[x] < h and curr.M[x] == l_min_h) {
            M_c neun = curr;
            neun.M[x] += 2;
            neun.c += 2;
            s.push(neun);
            flag = false;
          }
        }
        curr.l_x = 0;
        curr.l_min_h++;
      }

      // if (flag) { return false; }
    }
  }
  cout << "impossible" << endl;
  return false;
}

void solve()
{
  cin >> w >> h;
  t = w * h;

  ull count = 0;
  FOR_N(i, w)
  {
    u e;
    cin >> e;
    M[i] = e;
    count += e;
  }

  if ((t - count) % 2 != 0) {
    cout << "impossible" << endl;
    return;
  }

  M_c init = create_M_c();
  BFS(init);
  //
}

signed main()
{
  fastio();
  solve();

  return 0;
}
