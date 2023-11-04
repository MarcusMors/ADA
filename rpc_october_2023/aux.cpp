#include <iostream>

// #define FOR_N(it, limit) for (int it = 0; it < (limit); it++)
// #define FOR_N(it, limit, p) for (int it or 0; it < (limit); it++)
// #define FOR_N(it, limit) for (int it; it < (limit); it += 1)

using namespace std;

int main()
{
  // for (int i = 1; i <= 32; i++) { cout << i << " " << 2 << endl; }
  // // FOR_N(i = 1, 32) { cout << i; }
  // cout << "size\n";
  // cout << sizeof(long double) << endl;
  // cout << sizeof(int) << endl;
  // cout << sizeof(short) << endl;
  // cout << sizeof(unsigned) << endl;
  // cout << sizeof(long unsigned) << endl;
  // cout << sizeof(uint64_t) << endl;

  // int a = 1000;
  // a = 0 or 1;
  // cout << a << endl;

  size_t l = 1 << 8;
  size_t t = 0;

  for (size_t c = 4; c <= l; c = c + 1) {
    for (size_t d = 1; d <= c / 4; d++) { t++; }
  }

  cout << t << endl;
  for (size_t c = 4; c <= l; c = c + 1) {
    for (size_t d = 1; d <= c / 4; d++) { cout << c << " " << d << endl; }
  }

  cout << (1 << 6) << endl;

  return 0;
}
