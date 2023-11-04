#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

#define FOR_N(i, limit) for (unsigned(i) = 0; (i) < (limit); (i)++)
#define FOR(i, a, b) for (unsigned i = a; i < (b); i++)

using namespace std;


void solve()
{
  unsigned n;
  // 1<= n<= 100'000
  //
  cin >> n;

  vector<unsigned> arr(n);
  // unsigned xorios[n - 1];
  // for(unsigned i = 0; i < )

  for (unsigned i = 0; i < n; i++) { cin >> arr[i]; }
  // 0 <= arr[i] < 2^8
  std::map<unsigned, unsigned> m;
  unsigned max = 0;
  for (unsigned i = 0; i < n; i++) {
    unsigned aux = arr[i];
    for (unsigned j = i + 1; j < n; j++) {//
      aux = aux xor arr[j];
    }

    if (aux > max) {//
      max = aux;
    }
  }
  cout << max << endl;
  //
}

int main()
{
  // fastio();

  unsigned t;
  cin >> t;

  while (t--) { solve(); }

  return 0;
}

/*
1
5
8 2 4 12 1
*/

/*
3
4
0 2 5 1
3
1 2 3
5
8 2 4 12 1

 */
