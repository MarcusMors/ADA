#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

char c[20][20];

void solve()
{
  unsigned n, m;
  cin >> n >> m;

  FOR_N(i, n)
  {
    FOR_N(j, m)
    {
      char ch;
      cin >> ch;
      c[i][j] = tolower(ch);
    }
  }

  string name{ "vika" };
  unsigned ch = 0;
  bool found{ false };
  FOR_N(j, m)
  {
    FOR_N(i, n)
    {
      if (c[i][j] == name[ch]) {
        ch++;
        if (ch == name.size()) {
          found = true;
          cout << "YES\n";
          return;
        }
        break;
      }
    }
    // cout << "\n";
  }

  if (not found) { cout << "NO\n"; }
}

signed main()
{
  fastio();

  unsigned t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
