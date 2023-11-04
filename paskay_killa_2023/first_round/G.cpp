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

const int max_o = 4;
const int v_i = 0;

bool BFS(vector<int> v)
{
  queue<int> s;
  s.push(v[0]);

  int max_e = 1 + 3 + 9 + 27 + 81;

  int i = 0;
  int it = 1;
  int u_l = pow(3, 0);

  while (it < max_e) {
    auto c = s.front();
    s.pop();
    if (it >= u_l) {
      ++i;
      u_l = u_l + pow(3, i);
    }
    s.push(c - v[i]);
    s.push(c + v[i]);
    s.push(c * v[i]);

    it++;
  }

  for (int j = 0; j < 243; j++) {
    int c = s.front();
    s.pop();
    if (c == 23) { return true; }
  }
  return false;
}

void solve()
{
  std::vector<int> v(5);
  FOR_N(i, 5) { cin >> v[i]; }

  do {
    if (BFS(v)) {
      cout << "Posible" << endl;
      return;
    }
  } while (std::next_permutation(v.begin(), v.end()));

  cout << "Imposible" << endl;
}

signed main()
{
  fastio();
  solve();

  return 0;
}
