
#include <bitset>
#include <iostream>

using namespace std;

bitset<100000> b;

int main()
{
  long long mask = 0;
  b[63] = 1;
  // __builtin_popcount(mask);//32 bits
  // __builtin_popcountll(mask);//64 bits

  // __builtin_clz(mask);//32 bits
  // __builtin_clzll(mask);//64 bits // 0000000000000100000000000000001*000000*
  // __builtin_clzll(mask);//64 bits // *0000000000000*100000000000000001*000000*


  return 0;
}
