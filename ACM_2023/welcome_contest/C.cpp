#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

// vector<long long> arr[10]{ { 0 }, { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 9 } };
vector<vector<long long>> arr{ { 0 }, { 1 }, { 2 }, { 3 }, { 4 }, { 5 }, { 6 }, { 7 }, { 8 }, { 9 } };

// vector<string> path{};
using strs = stringstream;

void solve()
{
  long long k;
  int x;
  cin >> k;
  cin >> x;

  long long n = 10;
  auto f = arr[x].size();
  if (f == k) {
    cout << arr[x][f - 1] << "\n";
    return;
  } else {
    // strs b;
    // b << arr[x][f - 1];
    // b >> n;
    n = arr[x][f - 1];
  }

  while (f < k) {

    strs a;
    a << n;
    int v;

    string s{ a.str() };

    bool flag = false;
    while (s.size() > 1) {
      strs ss;
      int sum = 0;
      for (auto c : s) { sum += int(c) - '0'; }
      ss << sum;

      for (size_t i = 0; i < 10; i++) {
        sort(arr[i].begin(), arr[i].end());
        auto it = upper_bound(arr[i].begin(), arr[i].end(), sum);
        if (it != arr[i].end()) {
          flag = true;
          v = i;
          if (i == x) { f++; }
          break;
        }
      }
      if (flag) { break; }
      s = ss.str();
    }

    if (flag) {
      n++;
      continue;
    } else {
      unsigned xi = s[0] - '0';
      if (xi == x) { f++; }
      arr[xi].push_back(n);
    }
    n++;
  }
  cout << n << "\n";
  // search prev ans
  // work according prev answer
  // path.clear();
  // cout << sum_d(k, x) << endl;
}

signed main()
{
  fastio();

  unsigned t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}
