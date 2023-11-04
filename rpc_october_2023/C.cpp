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


vector<int> arr{};

void solve()
{
  ui n;
  ui k;
  cin >> n;
  cin >> k;

  FOR_N(i, n) { cin >> arr[i]; }
  sort(arr.begin(), arr.end());

  int valid_c = 0;

  int perms = n - k;

  for (size_t i = 0; i < perms; i++) {
    bool valid = true;
    for (size_t j = 0; j < n - 2; j++) {
      if (arr[j + 2] > arr[j] + arr[j + 1]) {
        valid = false;
        break;
      }
    }

    if (valid) { valid_c++; }
  }

  cout << valid_c << "\n";
}

signed main()
{
  arr.reserve(50);
  fastio();
  solve();

  return 0;
}


/*
5 4
2 1 4 3 5
*/

/*
8 5
1 2 3 5 8 13 21 34
 */
