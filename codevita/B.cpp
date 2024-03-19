#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// __gcd(value1, value2)
// append ll to get the long long version
// __builtin_ffs(x)// returns 1+ index of least significant bit else returns cero.
// __builtin_ffs(10) = 2 // because 10: "1010", 2 is 1 + the index of the least significant bit from right to left
// __builtin_clz(x) // returns number of leading 0-bits of x which starts from most significant bit position.
// __builtin_clz(16) = 27// int has 32 bits, because 16: "1 0000", has 5 bits, 32 - 5 = 27.
// __builtin_popcount(x) // returns number of 1-bits of x. x is unsigned int
// __builtin_popcount(14) = 3// because 14: "1110", has three 1-bits.

// #define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
// #define type typename

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

template<class It> void print(It begin, It end)
{
  while (begin != end) {
    cout << *begin << " ";
    begin++;
  }
}
template<class It> void print(It it, int n) { print(it, it + n); }
template<class T> void print(vector<T> v, int n) { print(v.begin(), v.begin() + n); }


template<class It> void fill(It it, int n)
{
  It limit = it + n;
  auto val = *it;
  if (n == 0) { return; }
  cin >> val;
  *it = val;
  ++it;

  while (it != limit) {
    char coma;
    cin >> coma;
    cin >> val;
    *it = val;
    ++it;
  }
}

template<class T> void fill(vector<T> &v) { fill(v.begin(), v.size()); }
template<class T> void fill(vector<T> &v, int n) { fill(v.begin(), n); }

void solve()
{

  string str;
  getline(cin, str);
  strs ss{ str };
  vi v{};
  int e{};
  while (ss >> e) { v.push_back(e); }

  // cout << "v: " << v << "\n";

  int w;
  string w_str;
  getline(cin, w_str);
  w = stoi(w_str);
  // cout << "w: " << w << "\n";

  int c = 0;
  map<int, int> m;

  for (auto &&e : v) {
    if (e == w) {
      c++;
      continue;
    }

    if (m[w - e] > 0) {
      m[w - e]--;
      c++;
    } else {
      m[e]++;
    }
  }

  v.clear();
  for (const auto &p : m) {
    for (int i = 0; i < p.second; i++) { v.push_back(p.first); }
  }

  sort(all(v));
  int lit = 0;
  int rit = v.size() - 1;
  while (true) {
    if (lit == rit) {
      c++;
      break;
    } else if (lit > rit) {
      break;
    }
    if (v[rit] + v[lit] > w) {
      c++;
      rit--;
    } else {
      c++;
      lit++;
      rit--;
    }
  }
  cout << c;
}

/*
input:
4 2 8 5 1 3 6
8
output:
4

input:
4 7 9 11 6 8 3
12
output:
5

 */

signed main()
{
  fastio();

  solve();

  return 0;
}
