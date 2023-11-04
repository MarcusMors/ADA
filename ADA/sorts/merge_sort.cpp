#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define type typename

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using vi = std::vector<int>;
using ii = std::pair<int, int>;

template<class T, class U> std::ostream &operator<<(ostream &os, pair<T, U> v)
{
  return os << "(" << v.first << "," << v.second << ")";
}
template<class T> std::ostream &operator<<(ostream &os, vector<T> v)
{
  for (auto &&e : v) { os << e << " "; }
  return os;
}

template<class It, class F> void merge(It b, It m, It e, F cmp)
{
  // vector<type It::value_type> t(b, e);
  // cout << "bef: " << t << "\n";
  vector<type It::value_type> tmp(e - b);
  // vector<decltype(*b)> tmp(e - b);
  auto i = b;
  auto j = m;
  auto it = tmp.begin();
  It rem_it;
  while (true) {
    if (i == m) {
      rem_it = j;
      break;
    }
    if (j == e) {
      rem_it = i;
      break;
    }

    if (cmp(*i, *j)) {
      *it = *i;
      i++;
    } else {
      *it = *j;
      j++;
    }
    it++;
  }

  while (it < tmp.end()) {
    *it = *rem_it;
    rem_it++;
    it++;
  }


  copy(all(tmp), b);
  // cout << "aft: " << t << "\n";
}


template<type It, type F> void merge_sort(It b, It e, F f)
{
  if (e - b <= 1) { return; }

  It m = b + (e - b) / 2;

  merge_sort(b, m, f);
  merge_sort(m, e, f);

  merge(b, m, e, f);
}

template<type It> void merge_sort(It b, It e)
{
  return merge_sort(b, e, [](auto lhs, auto rhs) { return lhs < rhs; });
}

void solve()
{
  int n;
  cin >> n;

  vi v(n);
  FOR_N(i, n) { cin >> v[i]; }

  cout << "v: " << v << "\n";
  // merge_sort(all(v));
  merge_sort(all(v), [](auto lhs, auto rhs) { return lhs > rhs; });
  cout << "v: " << v << "\n";
}

/*
in:
10
9 1 3 5 0 4 2 6 8 7
 */

signed main()
{
  fastio();

  // int t;
  // cin >> t;

  // while (t--) { solve(); }
  solve();

  return 0;
}
