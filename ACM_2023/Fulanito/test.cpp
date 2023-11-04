#include <iostream>

using namespace std;

int main()
{
  cout << "Hello world\n";
  int n = 1;
  for (size_t i = 0; i < 10; i++) {
    //
    cout << n << endl;
    n = n << 1;
  }

  return 0;
}
