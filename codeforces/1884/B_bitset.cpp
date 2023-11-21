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
#define rep(i, begin, end) \
  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

const int N = 100'000;

void solve()
{
  int n;
  cin >> n;

  string num;
  cin >> num;

  vector<int> my_bitset{ 0 };

  if (num[0] == '0') {
    my_bitset.front()++;
  } else {
    my_bitset.push_back(1);
  }

  for (int i = 1; i < n; i++) {
    if (my_bitset.size() % 2 == 0) {
      if (num[i] == '1') {
        my_bitset.back()++;
      } else {
        my_bitset.push_back(1);
      }

    } else {
      if (num[i] == '1') {
        my_bitset.push_back(1);
      } else {
        my_bitset.back()++;
      }
    }
  }

  if (my_bitset.size() % 2 == 0) { my_bitset.push_back(0); }

  int last_index = my_bitset.size() - 1;

  bool flag = false;
  int moves = 0;

  for (int i = 1; i <= n; i++) {
    // cout << "my_bitset: " << my_bitset << "\n";
    if (my_bitset.back() >= i) {
      cout << '0' << " ";
      continue;
    } else {
      int diff = 0;
      if (my_bitset[last_index - 2] >= 1) {// check if possible shift

        moves += my_bitset[last_index - 1];
        // do shift
        my_bitset[last_index - 2]--;
        my_bitset[last_index]++;
        // cout << moves << "\n";
        cout << moves << " ";
      } else {
        flag = true;
      }

      // check repeated cero's to join
      if (my_bitset.size() > 2 and my_bitset[last_index - 1] == 0) {
        my_bitset[last_index - 2] += my_bitset[last_index];
        my_bitset.resize(my_bitset.size() - 2);
        last_index -= 2;

        if (flag) {
          flag = false;
          i--;
          continue;
        }
      }

      // check repeated ones to join
      if (my_bitset.size() > 3 and my_bitset[last_index - 2] == 0) {
        my_bitset[last_index - 3] += my_bitset[last_index - 1];
        my_bitset[last_index - 2] = my_bitset[last_index];

        my_bitset.resize(my_bitset.size() - 2);
        last_index -= 2;
        if (flag) {
          i--;
          flag = false;
          continue;
        }
      }

      if (flag) {
        // indeed, it is impossible
        for (int j = i; j <= n; j++) { cout << -1 << " "; }
        break;
      }
    }
  }


  cout << "\n";
}

signed main()
{
  fastio();

  int t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
