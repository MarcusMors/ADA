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
1
32
-18 -17 18 12 13 -19 -18 -24 2 10 24 -22 -25 -6 7 -11 9 2 -8 -4 -3 -18 -19 1 -9 -20 18 6 -9 19 17 -23

*/

using namespace std;
using cint = const int;

void solve()
{

  int n;
  cin >> n;
  std::vector<int> v(n);
  std::vector<int> d(n - 1);

  int max_diff_index = -1;
  cin >> v[0];
  int last_one = v[0];
  // d[0] =

  int average = v[0];
  int valid_n = n;
  int highest{ std::numeric_limits<int>::min() };
  int highest_i{ 0 };
  int lowest{ std::numeric_limits<int>::max() };
  int lowest_i{ 0 };

  bool new_max_diff{ false };

  bool local_min{ false };
  bool local_max{ false };

  FROM_TO(i, 1, n)
  {
    int e;
    cin >> e;
    if (e == last_one) {
      valid_n--;
      continue;
    }
    if (e > highest) {
      highest_i = i;
      highest = e;
    } else if (e < lowest) {
      lowest_i = i;
      lowest = e;
    }

    v[i] = e;
    average += e;

    cint diff = last_one - v[i];
    d[i - 1] = diff;
    if (abs(diff) > abs(max_diff_index)) {
      max_diff_index = i;
      new_max_diff = true;
    }

    if (new_max_diff) {
      new_max_diff = false;
      //! BUG: CORRECT THE BOUNDS
      local_min = v[i - 2] > last_one and v[i + 1] > last_one;
      local_max = v[i - 2] < last_one and v[i + 1] < last_one;
    }

    last_one = v[i];
  }

  average = average / valid_n;

  if (local_max) {
    v[max_diff_index] = v[max_diff_index + 1];

  } else if (local_min) {
    v[max_diff_index] = v[max_diff_index - 1];

  } else {// saddle point, mid point.
    v[max_diff_index] = v[max_diff_index];// do nothing?
    // set to the lowest diff;
  }

  int steps = 0;
  int left_h_it = highest_i - 1;
  int right_h_it = highest_i + 1;
  while (true) {
    //! BUG: CORRECT THE BOUNDS (¿highest_i = n-1?)
    if (d[left_h_it] + d[right_h_it] > 0) {
      // right < left, you can go at least left diff steps.
      steps += d[left_h_it];
    }
    left_h_it--;
    right_h_it++;
    d[highest_i];
  }

  // from highest and lowest points, sum abs(diffs) until average.

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
