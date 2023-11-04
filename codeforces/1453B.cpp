#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

using llint = long long int;
#define FOR_N(it, limit) for (int(it) = 0; (it) < (limit); (it)++)

#define FROM_TO(it, from, to) for (int(it) = (from); (it) < (to); (it)++)

/*

-1 0 2
answer: 1
99 96 97 95
answer: 3
-3 -5 -2 1
answer: 4
1 4 3 2 4 1
answer: 6
5 0 0 0 5
answer: 5
-367741579 319422997 -415264583 -125558838 -300860379 420848004 294512916 -383235489 425814447
answer: 2847372102

17 10 5 20 25 26 25 26

---------


*/

using namespace std;

void solve()
{

  int n;
  cin >> n;
  std::vector<int> v(n);

  int max_diff_index = -1;
  cin >> v[0];
  int last_one = v[0];
  FROM_TO(i, 1, n)
  {
    cin >> v[i];
    int diff = last_one - v[i];
    last_one = v[i];
    if (abs(diff) > abs(max_diff_index)) { max_diff_index = i; }
  }
  max_diff_index--;
  //
}

signed main()
{
  fastio();

  unsigned t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
