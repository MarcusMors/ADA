#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

void solve()
{
  unsigned n;
  cin >> n;

  FOR_N(i, n)
  {
    int e;
    cin >> e;
  }
}

signed main()
{
  unsigned a = 0b10101;
  unsigned one = -1U;
  unsigned cero = 0;

  // std::bitset<sizeof(unsigned)> a;
  unsigned x5 = 5;
  unsigned x1 = 1;
  unsigned x9 = 9;

  cout << bitset<sizeof(unsigned) * 8>{ a } << endl;
  cout << bitset<sizeof(unsigned) * 8>{ one } << endl;
  cout << bitset<sizeof(unsigned) * 8>{ cero } << endl;
  cout << bitset<sizeof(unsigned) * 8>{ one xor a } << endl;
  cout << bitset<sizeof(unsigned) * 8>{ cero xor a } << endl;
  cout << bitset<sizeof(unsigned) * 8>{ a xor a } << endl;
  cout << "-----------------------------" << endl;
  cout << (x5 xor x1) << endl;
  cout << (x5 xor x1 xor x5) << endl;
  cout << (x5 xor x1 xor x5 xor x9) << endl;
  cout << (x1 xor x5 xor x9) << endl;
  cout << (x5 xor x9) << endl;
  cout << "-----------------------------" << endl;
  //
  return 0;
}
