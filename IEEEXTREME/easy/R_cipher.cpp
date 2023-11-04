#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define push_back
#define all(x) (x).begin(), (x).end()

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using ii = std::pair<int, int>;

void solve()
{
  string str;
  getline(cin, str);
  vector<int> arr(26);
  vector<int> ABCDEFG(7);
  vector<pair<char, int>> punc{
    { '.', 0 },
    { ',', 0 },
    { ' ', 0 },
    { '!', 0 },
  };


  for (auto &&ch : str) {
    if ('a' <= ch and ch <= 'z') {
      if ('a' <= ch and ch <= 'g') { ABCDEFG[ch - 'a']++; }
      arr[ch - 'a']++;
    } else {
      for (auto &&p : punc) {
        if (ch == p.first) { p.second++; }
      }
    }
  }

  // for (auto &&ch : str) { cout << ch << " "; }
  // cout << "\n";
  // for (auto &&c : arr) { cout << c << " "; }
  // cout << "\n";
  // for (size_t i = 0; i < arr.size(); i++) { cout << char('a' + i) << " "; }

  // cout << "\n";
  // for (auto &[p, count] : punc) { cout << p << " " << count << "\n"; }
  // cout << "\n";
  // cout << "\n";

  int max = -1;
  char max_ch;
  for (size_t i = 0; i < ABCDEFG.size(); i++) {
    //
    if (ABCDEFG[i] > max) {
      max = ABCDEFG[i];
      max_ch = char(i + 'A');
    }
  }

  cout << max_ch << "\n";
}

/*
5
my cat is so cute.
the baby is crying.
ieeextreme is tricky!
i want to buy a avocado for guacamole.
good grief, this task requires a gigantic genious.

out
C B E A G
*/

signed main()
{
  // fastio();
  unsigned t;
  string s;
  getline(cin, s);
  t = stoi(s);

  while (t--) { solve(); }
  // solve();

  return 0;
}

/* A, B, C, D, E, F, G  */
