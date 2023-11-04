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

//

bool BFS(vector<int> v)
{
  //
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
