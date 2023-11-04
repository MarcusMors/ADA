
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

  unsigned N, M;
  cin >> N >> M;

  string str;
  cin >> str;

  vector<vector<pair<char, uint>>> colors(M);
  for (int c = 0; c < N; c++) {
    int co;
    cin >> co;
    colors[co - 1].push_back(pair<char, uint>{ str[c], c });
  }

  for (auto &color : colors) {
    if (color.empty()) { continue; }
    int tmp = color[color.size() - 1].first;
    for (size_t i = 1; i < color.size(); i++) {
      uint pos = color[i].second;
      char n_ch = color[i - 1].first;
      str[pos] = n_ch;
    }
    str[color[0].second] = tmp;
  }

  cout << str;


  return 0;
}
