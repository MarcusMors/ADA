#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define pb push_back
#define all(v) v.begin(), v.end()

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using ii = std::pair<int, int>;

int limit = 1'000'000;
map<int, short> m;

bool is_happy(int a)
{
  set<int> lm;
  int n = a;
  int i = 1;

  lm.insert(n);
  // while (n != 1 and i < limit) {
  while (n != 1) {
    if (m[n] == 1) {
      // mark all the path as happy  = 1;
      for (auto &&i : lm) { m[i] = 1; }
      return true;
    }
    if (m[n] == 2) {
      // mark all the path as halt = 2;
      for (auto &&i : lm) { m[i] = 2; }
      return false;
    }

    strs ss;

    ss << n;
    const string digits = ss.str();

    int new_n = 0;
    for (auto &&d : digits) { new_n += (d - '0') * (d - '0'); }

    n = new_n;
    auto it = lm.find(n);
    if (it != lm.end()) {// found, mark all the path as halt = 2;
      for (auto &&i : lm) { m[i] = 2; }
      return false;
    } else {// not found, it is new, we keep searching
      lm.insert(n);
    }
    i++;
  }

  if (n == 1) {
    // mark all the path as happy  = 1;
    for (auto &&i : lm) { m[i] = 1; }
    return true;
  }
  // mark all the path as halt = 2;
  for (auto &&i : lm) { m[i] = 2; }

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
