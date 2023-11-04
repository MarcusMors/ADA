
#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;


signed main()
{
  fastio();
  vector<vector<pair<int, int>>> g_bets(37);

  unsigned N;
  cin >> N;

  FOR_N(i, N)
  {
    uint nb;
    cin >> nb;
    FOR_N(j, nb)
    {
      int bet;
      cin >> bet;
      g_bets[bet].push_back({ nb, i + 1 });
    }
  }

  int X;
  cin >> X;
  sort(g_bets[X].begin(), g_bets[X].end());
  if (g_bets[X].empty()) {
    cout << 0;
    return 0;
  }
  int min_n_of_bets = g_bets[X][0].first;
  int n = 0;
  //
  stringstream rpta;
  for (auto e : g_bets[X]) {
    if (e.first != min_n_of_bets) { break; }
    rpta << e.second << " ";
    n++;
  }
  cout << n << "\n";
  cout << rpta.str();

  return 0;
}
