#include <bits/stdc++.h>

using namespace std;

//
/*
1 5
5 3 2 1 4
 */
/*
1 5
1 5 4 3 2
 */

/*
3 3
4 1 3
8 5 9
7 2 6
 */

unsigned width;
unsigned height;

unsigned get_max(const unsigned init, unsigned arr[], const unsigned n)
{
  bool M[width][height];
  for (unsigned x = 0; x < width; x++) {
    for (unsigned y = 0; y < height; y++) { M[x][y] = false; }
  }

  unsigned counter = 1;
  {
    const unsigned x = arr[init] / height;
    const unsigned y = arr[init] % height;
    if (x > 0) { M[x - 1][y] = true; }
    if (x < width - 1) { M[x + 1][y] = true; }
    if (y > 0) { M[x][y - 1] = true; }
    if (y < height - 1) { M[x][y + 1] = true; }
  }

  for (unsigned *it = (arr + init + 1); it < arr + n; it++) {
    const unsigned x = *it / height;
    const unsigned y = *it % height;
    if (M[x][y]) {
      counter++;
      // one up, down, right and left
      if (x > 0) {
        M[x - 1][y] = true;
      } else if (x < width - 1) {
        M[x + 1][y] = true;
      }
      if (y > 0) {// true down
        M[x][y - 1] = true;

      } else if (y < height - 1) {// true up
        M[x][y + 1] = true;
      }
    }
  }


  return counter;
}

unsigned f(unsigned arr[], const unsigned n)
{
  unsigned max_until_now = std::numeric_limits<unsigned>::min();
  for (unsigned *it = arr; it < arr + n; it++) {
    unsigned max = get_max(it - arr, arr, n);
    if (max > max_until_now) { max_until_now = max; }
  }

  return max_until_now;
}

int main()
{
  // std::ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);

  cin >> width;
  cin >> height;

  const unsigned n = width * height;
  unsigned arr[n];
  for (unsigned *it = arr; it < arr + n; it++) {
    //
    int elem;
    cin >> elem;
    arr[elem - 1] = it - arr;
    // *it =
  }
  // for (unsigned *it = arr; it < arr + n; it++) { cout << *it << ", "; }
  // cout << endl;

  cout << f(arr, n) << endl;
  //

  return 0;
}
