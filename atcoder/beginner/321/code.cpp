#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

void solve()
{
  int n;
  int x;
  cin >> n;
  cin >> x;

  // int highest = std::numeric_limits<int>::min();
  int highest = -10000;
  int lowest = 10000;

  int sum = 0;
  FOR_N(i, n - 1)
  {
    int e;
    cin >> e;
    sum += e;
    if (e < lowest) { lowest = e; }
    if (e > highest) { highest = e; }
  }
  //
  int grade = sum - lowest - highest;
  if (grade > x) {
    cout << 0 << endl;
    return;
  }

  if (grade == x) {
    cout << 0 << endl;
    return;
  }

  if (grade < x) {
    int needed = x - grade;
    // if i just be between them
    if (needed > 100) {
      cout << -1 << endl;

    } else if (needed <= lowest) {
      cout << 0 << endl;
    } else if (needed > highest) {
      cout << -1 << endl;
    } else if (needed == 0) {
      cout << 0 << endl;
    } else if (lowest == needed) {
      cout << 0 << endl;
    } else if (lowest <= needed and needed <= highest) {
      cout << needed << endl;
    } else if (needed == highest) {
      cout << highest << endl;
    } else if (needed == lowest) {
      cout << lowest << endl;
    }
  }
}

/*
in:
3 65
65 13
out:
65
 */
/*
in:
5 127
85 4 48 79
out:
0
*/

signed main()
{
  // fastio();

  solve();
  return 0;
}
