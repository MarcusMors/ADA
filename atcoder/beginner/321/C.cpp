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

  int k;
  cin >> k;

  if (k < 10) {
    cout << k << endl;
    return;
  }

  // std::map<string, bool> m;

  int count = 9;
  string answer;
  string n;
  // int mod
  for (int i = 10; count < k; i++) {
    stringstream ss;
    ss << i;
    n = ss.str();

    int index_321_break;
    bool is_321 = true;

    for (int j = 1; j < n.size(); j++) {
      if (n[j - 1] > n[j]) {
        continue;
      } else {
        is_321 = false;
        index_321_break = j;
        break;
      }
    }

    if (is_321) {
      /* count += n[n.size()-2]-1 */;
      // n[n.size()-2];
    } else {
      for (int o = index_321_break; o < n.size(); o++) { n[o] = '0'; }
      int aux = stoi(n);
      const int plus_juan = (n.size()) - index_321_break;
      i = aux + pow(10, plus_juan) - 1;
    }
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
