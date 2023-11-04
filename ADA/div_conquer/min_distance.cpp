#include <bits/stdc++.h>

#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long float float
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using namespace std;

using ii = pair<float, float>;
using vii = vector<ii>;

float x_d(ii a, ii b) { return abs(a.first - b.first); }
float y_d(ii a, ii b) { return abs(a.second - b.second); }
float d(ii a, ii b)
{
  return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

float f(vii &v, int b, int e)
{
  if (e - b == 2) { return d(v[b], v[b + 1]); }
  if (e - b == 3) {
    float min_a = min(d(v[b + 1], v[b + 2]), d(v[b + 2], v[b]));
    return min(d(v[b], v[b + 1]), min_a);
  }

  int m = b + (e - b) / 2;
  float L = (v[m - 1].first + v[m].first) / 2;

  float l1 = f(v, b, m);
  float l2 = f(v, m, e);
  float la = min(l1, l2);

  ii p = { L - la, 0 };
  auto lla = lower_bound(v.begin(), v.end(), p);
  p = { L + la, 0 };
  auto rla = lower_bound(v.begin(), v.end(), p);

  vii nv(lla, rla);

  sort(nv.begin(), nv.end(), [](ii a, ii b) {
    if (a.second > b.second) {
      return true;
    } else {
      return false;
    }
  });

  for (size_t i = 0; i < nv.size(); i++) {
    for (size_t j = i + 1; j < i + 7 and j < nv.size(); j++) { la = min(la, d(nv[i], nv[j])); }
  }

  return la;
}

void solve()
{
  unsigned n;
  cin >> n;

  vii v;

  FOR_N(i, n)
  {
    float x, y;
    cin >> x;
    cin >> y;
    v.push_back({ x, y });
  }

  sort(v.begin(), v.end());
  float b = 0;
  float e = v.size();
  cout << f(v, b, e) << "\n";
}

signed main()
{
  fastio();
  solve();

  return 0;
}

/*
8
1 1
2 8
3 4
6 4
7 7
9 7
10 7
9 10
 */

/*
8
1 1
2 8
3 4
6 4
7 7
9.5 7
10 7
9 10

 */
