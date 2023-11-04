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

void solve(int t)
{
  using bearing = pair<int, int>;
  vector<vector<bearing>> ts{};
  vector<vector<bearing>> l_ts{};
  vector<vector<bearing>> r_ts{};

  FOR_N(i, t)
  {
    vector<bearing> lt_b{};// left
    vector<bearing> rt_b{};// right
    unsigned n_c;
    cin >> n_c;

    vector<bearing> b{};
    int j = 2;
    int x;
    int y;
    cin >> x;
    cin >> y;
    rt_b.push_back({ x, y });
    cin >> x;
    cin >> y;
    lt_b.push_back({ x, y });
    bearing prev{ x, y };
    for (; j < n_c; j++) {
      cin >> x;
      cin >> y;
      bearing curr{ x, y };
      if (prev.second == curr.second) {
        // we are at top
        rt_b.push_back({ x, y });
        break;
      }
      lt_b.push_back({ x, y });
      prev = curr;
    }
    j++;
    for (; j < n_c; j++) {
      cin >> x;
      cin >> y;
      rt_b.push_back({ x, y });
    }
    // cout << "i = " << i << "\n";
    // cout << "lt_b = " << i << "\n";
    // for (auto &&e : lt_b) { cout << "(" << e.first << "," << e.second << "),"; }
    // cout << "\n";
    // cout << "rt_b = " << i << "\n";
    // for (auto &&e : rt_b) { cout << "(" << e.first << "," << e.second << "),"; }
    // cout << "\n";

    ts.push_back(b);
    l_ts.push_back(lt_b);
    r_ts.push_back(rt_b);
  }

  vector<vector<bearing>> left_ts_sorted_by_x{ ts };
  for (auto &&e : left_ts_sorted_by_x) { sort(e.begin(), e.end()); }

  vector<vector<bearing>> left_ts_sorted_by_y{ ts };
  for (auto &&e : left_ts_sorted_by_y) {
    sort(e.begin(), e.end(), [](auto lhs, auto rhs) {
      if (rhs.second > lhs.second) { return true; }
      return false;
    });
  }

  vector<vector<bearing>> right_ts_sorted_by_x{ ts };
  for (auto &&e : right_ts_sorted_by_x) { sort(e.begin(), e.end()); }
  vector<vector<bearing>> right_ts_sorted_by_y{ ts };
  for (auto &&e : right_ts_sorted_by_y) { sort(e.begin(), e.end()); }

  // left min in  x compare with right max in y.
  // then
  // for the sorted y's in left and right to 0:
  // check pairs this and next, if there is an overlapping, find the maximum they can be together by that.
  // if (left y > right y):
  // else :
  //
  //
  //
}

signed main()
{
  fastio();

  int t;
  cin >> t;

  solve(t);

  return 0;
}
