
#include <bitset>
#include <iostream>

using namespace std;

int main()
{
  int mask = 0;
  mask = mask | 0x1000;
  // int a = 0x1000;
  int a = 0B10;
  cout << a << endl;

  cout << mask << endl;
  int mask_2 = 0;

  mask_2 = mask_2 | 1 << 4;
  cout << mask_2 << endl;

  return 0;
}
