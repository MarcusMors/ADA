// #include <iostream>
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

int mod = 998244353;

int main()
{
  long long n;
  int m;
  cin >> n >> m;
  int total = pow(26, n);
  vector<string> ss;

  bool ch_used[26]{ false };
  int used_c = 0;
  for (int i = 0; i < m; i++) {
    cin >> ss[i];
    for (size_t j = 0; j < ss[i].size(); j++) {
      if (ch_used[(ss[i][j] - 'a')]) {
        continue;
      } else {
        ch_used[(ss[i][j] - 'a')] = true;
        used_c++;
      }
    }
  }

  //
  if (n <= 26) {

  } else {
    char d = '*';
    //
  }
  // 26*(N - M) + 1

  do {
    //
  } while (next_permutation());

  return 0;
}
