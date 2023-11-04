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
  long long unsigned arr[10000];
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 1;
  arr[3] = 2;
  arr[4] = 4;
  for (int i = 5; i < 10000; i++) { arr[i] = 0; }

  size_t n;
  cin >> n;

  while (n != 0) {
    if (arr[n] != 0) {
      cout << arr[n] << "\n";
      cin >> n;
      continue;
    }
    long long unsigned a = 1;
    long long unsigned b = 1;
    long long unsigned c = 2;

    size_t j = 2;
    for (; j < n + 1; j++) {
      if (arr[j] == 0) {
        a = arr[j - 3];
        b = arr[j - 2];
        c = arr[j - 1];
        j--;
        break;
      }
    }

    // 0 1 2 3 4 5 6
    // 0 1 1 2 4 7 13
    long long unsigned tmp;

    for (size_t i = j; i < n; i++) {
      tmp = a + b + c;
      a = b;
      b = c;
      c = tmp;
      arr[i + 1] = c;
    }

    cout << c << " \n";

    cin >> n;
  }

  return 0;
}
