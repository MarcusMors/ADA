#include <iostream>

using namespace std;

int mod(int a, int b) { return a % b; }
int mod2(int a, int b)
{
  while (a * 2 > b) { a -= b; }
  return a;
}

int main()
{
  cout << "     | % |2*<" << endl;
  for (size_t v13 = 1; v13 < 10; v13++) {
    for (size_t v1 = 1; v1 < 10; v1++) {
      //
      int a = mod(v13, v1);
      int b = mod2(v13, v1);
      if (a != b) { cout << "(" << v13 << "," << v1 << ")| " << a << "  |" << b << "\n"; }
    }
  }


  return 0;

  //
}
