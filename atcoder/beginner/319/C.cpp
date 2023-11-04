#include <algorithm>
#include <array>
// #include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

void solve()
{
  unsigned arr[9];
  FOR_N(i, 3)
  {
    FOR_N(j, 3) { cin >> arr[i]; }
  }

  std::vector<tuple<int, int, int>> view{
    { 0, 1, 2 },
    { 3, 4, 5 },
    { 6, 7, 8 },
    { 0, 3, 6 },
    { 1, 4, 7 },
    { 2, 8, 9 },
    { 0, 4, 8 },
    { 2, 4, 6 },
  };

  array<int, 9> order;
  std::iota(order.begin(), order.end(), 0);

  int all = 0;
  int dissapointed = 0;
  do {
    all++;
    dissapointed = false;
    if (true) {
      //
    }

    //
  } while (next_permutation(order.begin(), order.end()));
}

signed main()
{
  fastio();

  solve();

  return 0;
}
