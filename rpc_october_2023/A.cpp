#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
// using ui_6 = unsigned : 6;

using ui = long long unsigned;
using uint = unsigned;
using cui = const unsigned;
using strs = std::stringstream;

using namespace std;

#define FOR_N(it, limit) for (ui it = 0; it < (limit); it++)

ui pow_2(ui p) { return 1ULL << p; }

ui c(ui d, ui p)
{
  if (p == 0) { return 1; }
  if (p == 1) { return d + 1; }
  if (d == 1) { return pow_2(p); }
  //  segment + sigma;
  ui sigma = c(d - 1, p);
  ui exclusive_self = p * c(d - 1, p - 1);
  ui interseccion_p = 0;

  ui a = 0;
  for (ui i = p - 2; i > 0; i--) {//
    interseccion_p += c(d - 1, i) * (p - a);
    a++;
  }
  interseccion_p += 1;

  return exclusive_self + interseccion_p + sigma;
}

bool first = true;

void solve()
{
  ui min_c;
  ui d;
  cin >> min_c;
  cin >> d;

  if (d + 1 >= min_c) {
    cout << 1 << "\n";
    return;
  }

  ui a = min_c;
  ui b = (min_c << 1);

  ui exp = 0;
  while (a > 1) {
    a = (a >> 1);
    b = (b >> 1);
    exp++;
  }

  ui l = (1ULL << exp);

  ui sup_exp;
  if (l == min_c) {
    sup_exp = exp;
  } else {
    sup_exp = exp + 1;
  }


  if ((1 << 6) < d and d >= powl(2, float(exp) / 2)) {
    cout << 2 << "\n";
    return;
  }

  ui p = 0;
  ui comp = c(d, p);

  while (comp < min_c) {
    p++;
    comp = c(d, p);
  }


  if (p == 2) {
    if (first) {
      cout << "(" << min_c << "," << d << ") => ";
      cout << p << "\n";
      first = false;
    }
  } else {
    first = true;
  }
}

signed main()
{
  fastio();

  unsigned t;
  cin >> t;
  // ui a = 1;
  // ui i = 0;
  while (t--) {
    // if (i == a - 1) {
    //   a = a << 1;
    //   cout << "\n";
    //   i = 0;
    // }
    solve();
    // i++;
  }

  return 0;
}


/*
1
1073741824
32768

 */
