#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using namespace std;

int swaps = 0;

vector<int> Merge_and_Count(vector<int> l, vector<int> r)
{
  vector<int> s;
  int i = 0;
  int j = 0;
  int s_i = 0;

  bool left_rem = false;
  while (true) {
    if (i == l.size()) {
      left_rem = false;
      break;
    }
    if (j == r.size()) {
      left_rem = true;
      break;
    }
    if (l[i] > r[j]) {
      // s[s_i] = l[i];
      s.push_back(r[j]);
      swaps += l.size() - i;
      j++;
    } else {
      // swaps++;
      // s[s_i] = r[j];
      s.push_back(l[i]);
      i++;
    }
    s_i++;
  }

  if (left_rem) {
    while (i < l.size()) {
      // while (s_i < s.size()) {
      // s[s_i] = l[i];
      s.push_back(l[i]);
      // swaps++;
      i++;
      s_i++;
    }
  } else {
    while (j < r.size()) {
      // s[s_i] = r[i];
      s.push_back(r[j]);
      // swaps++;
      j++;
      s_i++;
    }
  }

  return s;
}

vector<int> Sort_and_Count(vector<int> L, int b, int e)
{
  if ((e - b) <= 1) { return vector<int>{ L[b] }; }

  // Dividir la lista en dos mitades A y B
  int m = b + ((e - b) / 2);
  vector<int> A = Sort_and_Count(L, b, m);
  vector<int> B = Sort_and_Count(L, m, e);

  vector<int> merged = Merge_and_Count(A, B);
  return merged;
}


void solve()
{
  unsigned n;
  cin >> n;
  vector<int> v(n);
  FOR_N(i, n) { cin >> v[i]; }
  vector<int> sorted = Sort_and_Count(v, 0, v.size());
  cout << swaps << endl;
  for (auto &&e : sorted) { cout << e << " "; }
  cout << "\n";
}

signed main()
{
  fastio();
  solve();
  return 0;
}

/*
in:
12
1 5 4 8 10 2 6 9 12 11 3 7
out:
22
 */
