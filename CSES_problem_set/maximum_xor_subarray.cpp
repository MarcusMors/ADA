#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define pb push_back
#define all(v) v.begin(), v.end()
#define scast static_cast
#define icast implicit_cast
#define pcast pun_cast

// template<class U> U implicit_cast(__cpp_lib_type_identity<>) {}
// template<class U> U implicit_cast(std::type_identity_t<U> val) { return val; }
// template<class U, class T> U implicit_cast(T &val) { return std::bit_cast<U>(val); }

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using ii = std::pair<int, int>;

void solve()
{
  unsigned n;
  cin >> n;

  // pun_cast<>();
  // pun_cast<>();
  FOR_N(i, n)
  {
    int e;
    cin >> e;
  }
}

signed main()
{
  fastio();

  solve();

  return 0;
}
