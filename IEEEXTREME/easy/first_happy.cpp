#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define push_back
#define all(v) v.begin(), v.end()

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using ii = std::pair<int, int>;

int limit = 10;
bool is_happy(int a)
{
  int n = a;
  int i = 1;
  while (n != 1 and i < limit) {
    strs ss;
    //
    ss << n;
    string digits = ss.str();

    int new_n = 0;
    for (auto &&d : digits) { new_n += (d - '0') * (d - '0'); }

    n = new_n;
    i++;
  }
  if (n == 1) { return true; }
  return false;
}
void solve()
{
  unsigned a;
  unsigned b;
  cin >> a;
  cin >> b;

  int count = 0;
  for (size_t i = a; i <= b; i++) { count += is_happy(i); }
  cout << count << "\n";
}

signed main()
{
  fastio();

  solve();


  return 0;
}


/*
35 578

*in:
1 35
*out:
9
 */
