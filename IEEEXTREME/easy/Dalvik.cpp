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
  int v0;
  int v1;
  int v2;
  cin >> v0;
  cin >> v1;
  cin >> v2;

  int v3 = 1;
  int v4 = 0;
  int v5 = v4 - v3;
  int v6 = v3;
  int v7 = v4 - v1;
  int v8 = v0;
  int v9 = v0 + v1;

  int v10 = v4;
  int v11 = v4;
  int v12 = v3;

  int v13;
  int v14;
  int v15;
  auto l0 = [&]() {
    v11 = v11 + v1;
    v10 = v10 + v0;
    v13 = v10;
    v14 = v4;
    v15 = v4;
  };


  int v16;
l1:
  // auto l1 = [&]() {
  v16 = v13 + v3;
  // if (v16 <= v1) { l2(); }
  if (v16 <= v1) { goto l2; }
  v13 = v13 - v1;
  v14 = v14 - v3;
  v15 = v15 - v1;
  // };
  // l1();
  goto l1;
l2:
  // auto l2 = [&]() {
  // if (v16 <= v1) { l2(); }
  if (v13 >= v4) { goto l3; }
  v13 = v13 - v1;
  v14 = v14 - v3;
  v15 = v15 - v1;
  // };
l3:
  /*
:l1
add-int v16,v13,v13
if-le v16,v1,:l2
sub-int v13,v13,v1
add-int v14,v14,v3
add-int v15,v15,v1
goto :l1
:l2
if-gt v13,v4,:l3
sub-int v13,v4,v13
:l3
move v17,v4
move v18,v3
:l4
add-int v17,v17,v13
add-int v18,v18,v3
if-le v18,v6,:l4
move v18,v3
:l5
sub-int v17,v17,v9
add-int v18,v18,v3
if-le v18,v12,:l5
if-ge v17,v4,:l6
move v5,v14
move v6,v12
move v7,v15
move v8,v10
move v9,v13
:l6
add-int v12,v12,v3
if-le v12,v2,:l0
return v6

   */
  //
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
