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

const int mod = 1'000'000'000 + 7;

void solve()
{
  int n;
  cin >> n;
  n++;
  vector<int> arr(n);
  vector<int> xorios(n);
  arr[0] = 0;
  xorios[0] = 0;
  for (int i = 1; i < n; i++) {
    cin >> arr[i];
    xorios[i] = xorios[i - 1] xor arr[i];
  }

  // int count = n - 1;
  int count = 0;
  // cout << "init count :" << count << "\n";

  // cout << "xorios: ";
  // for (auto &&x : xorios) { cout << x << ", "; }
  // cout << "\n";
  // cout << "\n";

  for (int l = 0; l < n; l++) {
    for (int r = l + 1; r < n; r++) {
      set<int> s{ 0 };

      int l_count = 1;

      // cout << ">>l: " << l << " , " << r << ":r<< \n";
      // cout << "(i,j]:";
      // for (size_t a = l + 1; a <= r; a++) { cout << arr[a] << ", "; }
      // cout << "\n";

      for (int sz = 1; sz <= r - l; sz++) {
        // cout << "x : ";
        for (int p = l; p <= r - sz; p++) {
          int x = xorios[p] xor xorios[p + sz];
          auto it = s.find(x);
          if (it == s.end()) {// not found
            // cout << x << " , ";
            l_count++;
            s.insert(x);
          }
        }
        // cout << "\n";
      }
      // cout << "\n";
      count += l_count;
      // cout << "count : " << count << "\n";
    }
  }

  cout << count % mod << "\n";
}

signed main()
{
  fastio();

  int t;
  cin >> t;

  while (t--) { solve(); }
  // solve();

  return 0;
}
