#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

void solve()
{
  int n, k;
  cin >> n >> k;


  int arr[n];
  FOR_N(i, n) { cin >> arr[i]; }

  int count = 0;

  // 2^n-1 max

  for (int f = n - 1; f > -1; f--) {

    for (int i = 0; i < n - f; i++) {
      for (int j = i; j < n - f; j++) {
        int mask = 0;
        for (int o = 0; o < f; o++) { mask &= arr[o]; }

        if (__builtin_popcount(mask) == k) { count++; }
      }
    }
  }


  cout << count << "\n";
  // cout << 10^9 + 7;
}

int main()
{
  fastio();

  unsigned t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
