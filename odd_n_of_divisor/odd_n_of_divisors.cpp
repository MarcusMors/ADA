#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL);

#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

unsigned n_of_div(unsigned x)
{
  int i = 2;
  std::ordered_map<int> divs;
  while (i != x) {
    if (x % i == 0) { divs. }
  }
  i++;
}


void solve()
{
  unsigned x;
  cin >> x;
  unsigned n = n_of_div(x);
}

int main()
{
  // fastio();

  unsigned t = 1;
  // cin >> t;

  while (t--) { solve(); }

  return 0;
}
