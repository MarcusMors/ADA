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
  unsigned n;
  unsigned k;
  cin >> n;
  cin >> k;

  vector<int> ps(n);
  FOR_N(i, n) { cin >> ps[i]; }
  sort(ps.begin(), ps.end());


  vector<int> sgs{};
  for (size_t i = 0; i < n - 1; i++) {
    if ((ps[i + 1] - ps[i]) > k) { sgs.push_back(i); }
  }
  // sgs.push_back(n);
  sgs.push_back(n - 1);

  // cout << "sgs: ";
  // for (auto &&s : sgs) { cout << s; }
  // cout << "\n";

  unsigned it = 0;
  unsigned max = 0;
  for (size_t i = 0; i < sgs.size(); i++) {
    // const unsigned d = (sgs[i + 1] - (sgs[i] + 1));
    const unsigned d = (sgs[i] - it) + 1;
    if (d > max) { max = d; }
    it = sgs[i] + 1;
  }
  // const unsigned d = (sgs[ + 1] - sgs[i]);
  // if (d > max) { max = d; }

  // cout << "max: " << max << "\n";
  // cout << "n - max: " << n - max << "\n";
  cout << n - max << "\n";
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
3
5 3
2 3 19 10 8
3 4
1 10 5
8 1
8 3 1 4 5 10 7 3
 */
