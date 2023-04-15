#include <iostream>

using namespace std;

int main()
{
  unsigned n;
  cin >> n;
  if (n < 4) {
    cout << "NO SOLUTION";
    return 0;
  }

  cout << 3;
  for (unsigned i = 5; i < n + 1; i += 2) { cout << " " << i; }

  // change the last bit of a number;
  // n &= ;
  cout << " 1";
  for (unsigned i = n & ~(1UL << 0); i > 2 - 1; i -= 2) { cout << " " << i; }


  return 0;
}
