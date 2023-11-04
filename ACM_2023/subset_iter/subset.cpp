#include <iostream>

using namespace std;

int main()
{
  int a[] = { 2, 3, 4, 6 };

  for (int i = 0; i < (1 << 2); i++) {
    for (int bit = 0; bit < 4; bit++) {
      if (i & (1 << bit)) {//
        cout << a[bit] << ", ";
      }
    }
    cout << "\n";
  }

  return 0;
}
