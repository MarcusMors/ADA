#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;
using std::cout;

//

int main()
{
  // fastio();
  size_t n;
  cin >> n;

  while (n != 0) {
    long long unsigned a = 1;
    long long unsigned b = 1;
    long long unsigned c = 2;

    // 0 1 2 3 4 5 6
    // 0 1 1 2 4 7 13
    long long unsigned tmp;

    for (size_t i = 3; i < n; i++) {
      tmp = a + b + c;
      a = b;
      b = c;
      c = tmp;
    }

    cout << c << " \n";

    cin >> n;
  }

  return 0;
}
