#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using ii = std::pair<int, int>;


//

void solve()
{
  unsigned n;
  cin >> n;
  enum dir {
    what = 2,
    to = 1,
    from = 0,
  };

  using edges = vector<pair<string, dir>>;

  map<string, edges> tree;

  // map
  vector<string> names;


  FOR_N(i, n)
  {
    string source;
    string rel;
    string dest;
    cin >> source;
    cin >> rel;
    cin >> dest;

    dir d;
    if (rel == "??") {
      d = what;
      // manage except?
    } else if (rel ==)
      // verify both ends don't have a what relation;
      pair<string, dir> p{ dest, rel };
    tree[source].push_back(p);
    tree[dest].push_back(p);
    // if(what)
    //
  }
}

signed main()
{
  fastio();

  solve();

  return 0;
}
