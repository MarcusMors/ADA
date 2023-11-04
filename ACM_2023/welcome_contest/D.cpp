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


const ui N = 2 * 100000;
bool DP[N]{};
ui arr[N]{};

void solve()
{
  unsigned n;
  cin >> n;

  FOR_N(i, n) { cin >> arr[i]; }


  for (int i = 0; i < n; i++) {
    // check left bound
    // check left
    // check DP
    if (i >= arr[i]) {
      if (arr[i] - i == 0) { DP[i] = true; }
      if (arr[i] - i > 0 and DP[arr[i] - i - 1]) { DP[i] = true; }
    }

    if (i > 0 and DP[i - 1]) {
      // check previous DP
      if (DP[i - 1]) {
        // check right bound
        if (i + arr[i] < n) {
          // check right limit exception
          // check right
          if (n == arr[i] + i + 1) { DP[i + arr[i]] = true; }
        }
      }
    }
  }

  if (arr[n - 1]) {
    cout << "yes\n";
  } else {
    cout << "no\n";
  }
  for (int i = 0; i < n; i++) { DP[i] = false; }
}

signed main()
{
  fastio();

  unsigned t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}

/*
7
9
1 1 2 3 1 3 2 2 3
5
12 1 2 7 5
6
5 7 8 9 10 3
4
4 8 6 2
2
3 1
10
4 6 2 1 9 4 9 3 4 2
1
1

 */
