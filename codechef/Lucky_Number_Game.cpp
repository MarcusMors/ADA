// problem: https://www.codechef.com/problems/HP18
#include <bits/stdc++.h>

#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)
// #define unsigned unsigned
// #define FOR_FROM(it, start, limit) for (unsigned it = (start); it < lim it; it++)
#define FOR_N(it, limit) for (unsigned it = 0; it < (limit); it++)

using namespace std;

struct n_freq
{
  unsigned n{ 0 };
  mutable unsigned f{ 1 };
  void increment() { f++; }
};

bool operator<(const n_freq &lhs, const n_freq &rhs) { return lhs.n < rhs.n; }

void solve()
{
  unsigned n, a, b;
  cin >> n >> a >> b;

  unsigned A{}, B{}, AB{};
  FOR_N(i, n)
  {
    unsigned e;
    cin >> e;
    const bool A_flag = e % a == 0;
    const bool B_flag = e % b == 0;
    A += A_flag;
    B += B_flag;
    AB += A_flag and B_flag;
  }

  if (AB % 2 == 0) {
    if (B > A) {
      cout << "BOB\n";
    } else {
      cout << "ALICE\n";
    }
  } else {
    if (A > B) {
      cout << "ALICE\n";
    } else {
      cout << "BOB\n";
    }
  }
}

signed main()
{
  // fastio();

  unsigned t;
  cin >> t;
  while (t--) { solve(); }

  return 0;
}
