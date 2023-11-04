#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define int long long

#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using ii = std::pair<int, int>;

int limit = 1'000'000;
map<int, short> m;

bool descendingOrder(char a, char b) { return a > b; }

bool is_happy(int a)
{
  set<int> lm;
  int n = a;
  int i = 1;

  lm.insert(n);
  // while (n != 1 and i < limit) {
  while (n != 1) {
    strs ss;

    ss << n;
    string digits = ss.str();
    sort(all(digits));
    ss.clear();
    ss << digits;

    int t;
    ss >> t;
    if (m[t] == 1) {
      // mark all the path as happy  = 1;
      for (auto &&i : lm) { m[i] = 1; }
      return true;
    }
    if (m[t] == 2) {
      // mark all the path as halt = 2;
      for (auto &&i : lm) { m[i] = 2; }
      return false;
    }

    int new_n = 0;
    for (auto &&d : digits) { new_n += (d - '0') * (d - '0'); }

    n = new_n;
    auto it = lm.find(n);
    if (it != lm.end()) {// found, mark all the path as halt = 2;
      for (auto &&i : lm) { m[i] = 2; }
      return false;
    } else {// not found, it is new, we keep searching
      lm.insert(n);
    }
    i++;
  }

  if (n == 1) {
    // mark all the path as happy  = 1;
    for (auto &&i : lm) { m[i] = 1; }
    return true;
  }

  // mark all the path as halt = 2;
  for (auto &&i : lm) { m[i] = 2; }

  return false;
}

int happy_count[16]{
  1,// 0
  3,// 1
  20,// 2
  143,// 3
  1442,// 4
  14377,// 6
  143071,// 7
  1418854,// 8
  14255667,// 9
  145674808,// 10
  1492609148,// 11
  15091199357,// 12
  149121303586,// 13
  1443278000870,// 14
  13770853279685,// 15
  130660965862333,// 16
  /*
  9223372036854775807
  */
};// 17

void solve()
{
  strs ssa;
  strs ssb;
  int a;
  int b;
  cin >> a;
  cin >> b;

  ssa << a;
  ssb << b;
  int count = 0;

  int asz = ssa.str().size();
  int bsz = ssb.str().size();

  int botb = pow(10, bsz - 1);
  int topb = pow(10, bsz);
  if (b == botb) { topb = botb; }
  int bmid = (botb + topb) / 2;
  int bcount = 0;

  if (b > bmid) {
    for (int i = b + 1; i <= topb; i++) { bcount += is_happy(i); }
    bcount = happy_count[bsz + 1] - bcount;
  } else if (b == botb) {
    bcount = happy_count[bsz - 1];
  } else {
    for (int i = b; i > botb; i--) { bcount += is_happy(i); }
    bcount = happy_count[bsz - 1] + bcount;
  }

  int bota = pow(10, asz - 1);
  int topa = pow(10, asz);
  if (a == bota) { topa = bota; }
  int amid = (bota + topa) / 2;
  int acount = 0;
  if (a > amid) {
    for (int i = a; i <= topa; i++) { acount += is_happy(i); }
    acount = happy_count[asz] - acount;
  } else if (a == bota) {
    acount = happy_count[asz - 1] - 1;
  } else {
    for (int i = a - 1; i >= bota; i--) { acount += is_happy(i); }
    acount = happy_count[asz - 1] + acount;
  }

  cout << bcount - acount << "\n";
}

signed main()
{
  fastio();

  solve();

  return 0;
}
