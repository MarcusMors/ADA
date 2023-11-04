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

bool arr[1000];

void solve()
{
  string raw;
  string s;
  string n_raw;
  //

  getline(cin, raw);

  for (size_t i = 0; i < raw.size(); i++) {
    char c = raw[i];
    if (c == ' ') {
      n_raw = raw.substr(i + 1);
      s = raw.substr(0, i);
      break;
    }
  }
  int n = stoi(n_raw);
  cout << n << "\n";
  cout << s << "\n";

  //
}

signed main()
{
  fastio();

  solve();

  return 0;
}
