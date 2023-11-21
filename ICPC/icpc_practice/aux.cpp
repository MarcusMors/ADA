#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using namespace std;

void solve()
{
  unsigned n;
  cin >> n;

  vector<pair<int, int>> bearings{};
  FOR_N(i, n)
  {
    int x;
    cin >> x;
    int y;
    cin >> y;
    bearings.push_back({ x, y });
  }

  sort(bearings.begin(), bearings.end());
  for (auto [x, y] : bearings) { cout << "(" << x << "," << y << ") "; }
  cout << "\n";

  sort(bearings.begin(), bearings.end(), [](auto lhs, auto rhs) {
    if (rhs.second > lhs.second) { return true; }
    return false;
  });
  for (auto [x, y] : bearings) { cout << "(" << x << "," << y << ") "; }
  cout << "\n";
}

signed main()
{
  fastio();

  unsigned t = 1;

  while (t--) { solve(); }

  return 0;
}
