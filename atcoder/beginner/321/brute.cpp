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

  unsigned k;
  cin >> k;

  std::map<string, bool> m;

  int count = 0;
  string answer;
  string n;
  for (int i = 1; count < k; i++) {
    stringstream ss;
    ss << i;
    n = ss.str();

    bool is_321 = true;
    for (int j = 1; j < n.size(); j++) {
      if (n[j - 1] > n[j]) {
        continue;
      } else {
        is_321 = false;
        break;
      }
    }

    if (is_321) { count++; }
  }
  answer = n;
  cout << answer << endl;
}

signed main()
{
  fastio();

  solve();
  return 0;
}
