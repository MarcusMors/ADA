/*
L meters (1≤L≤106).
John rF seconds per meter (1<=rF<=106). no stops.

N rest stops(1<=N<=105);
the i-th stop is xi meters from the start of the trail (0<xi<L) and has a tastiness value ci (1≤ci≤106).
If Bessie rests at stop i for t seconds, she receives ci*t tastiness units.

When not resting, Bessie will be hiking at a fixed travel rate of rB seconds per meter (1≤rB≤106).
Since Bessie is young and fit, rB < rF.

Bessie must not be behind John
Bessie, maximize her consumption of tasty grass. Find the maximum tastiness she can get.


INPUT FORMAT (file reststops.in):
L N rF rB.
i in N: rest stops.
For each i between 1 and N,
has: xi and ci, position and tastiness.

It is guaranteed that rF>rB, and 0<x1<⋯<xN<L. Note that rF and rB are given in seconds per meter!

SAMPLE OUTPUT:

15
 */

#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

// #define DEBUGGING

#ifdef DEBUGGING
#define LOG(var) std::cout << #var << ": " << var << std::endl
#else
#define LOG(var)
#endif
using namespace std;

template<class in_stream = std::istream, class out_stream = std::ostream> void solve(in_stream &is, out_stream &os)
{
  unsigned L, N, j_s_per_m, b_s_per_m;

  is >> L;
  is >> N;
  is >> j_s_per_m;
  is >> b_s_per_m;

  std::vector<std::pair<unsigned, unsigned>> tasty_pos(N);

  for (unsigned i = 0; i < N; i++) {
    unsigned a;
    is >> a;// distance;
    tasty_pos[i].second = a;
    is >> a;// tastyness
    tasty_pos[i].first = a;
    // cin >> positions[i].second;
    // cin >> tastyness[i].first;
  }
  std::sort(tasty_pos.rbegin(), tasty_pos.rend());// sort a vector decrementaly


  unsigned actual_stop = 0;
  unsigned tastyness_counter = 0;

  unsigned j_h = 0;
  unsigned b_h = 0;
  unsigned time_stopped = 0;
  // unsigned s = 0;
  unsigned s = 0;
  // while (s != (L * j_s_per_m)) {
  while (s != (L * j_s_per_m)) {
    LOG(b_h);
    LOG(j_h);
    // if (((s - time_stopped) + b_s_per_m) / j_s_per_m > b_h) {
    if (j_h == b_h) {
      // don't stop, go next
      s++;
      b_h = (s - time_stopped) / b_s_per_m;
      j_h = s / j_s_per_m;
      continue;
    } else {
      // you can stop and eat grass
      while ((actual_stop + 1) < tasty_pos.size() and tasty_pos[actual_stop].second < b_h) {
        LOG(actual_stop);
        actual_stop++;
      }

      if (tasty_pos[actual_stop].second >= j_h and tasty_pos[actual_stop].second == b_h) {
        tastyness_counter += tasty_pos[actual_stop].first;
        LOG(tastyness_counter);

        s++;
        j_h = s / j_s_per_m;
        time_stopped++;
        continue;
      }
    }
    s++;
    b_h = (s - time_stopped) / b_s_per_m;
    j_h = s / j_s_per_m;
  }

  os << tastyness_counter;
  os << endl;

  // for()
}

int main()
{
  fastio();
  std::ifstream ifs{ "reststops.in" };
  std::ofstream ofs{ "reststops.out" };
  solve(ifs, ofs);
  // solve(std::cin, std::cout);
  ifs.close();
  ofs.close();

  return 0;
}
