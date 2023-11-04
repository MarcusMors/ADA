#include <iostream>

using namespace std;

int main()
{
  // int a = 1'000'000'000;// ./test.out  2.42s user 0.02s system 99% cpu 2.438 total
  // int a = 100'000'000; //./test.out  0.26s user 0.00s system 99% cpu 0.263 total
  // int a = 10'000'000; // ./test.out  0.04s user 0.00s system 99% cpu 0.038 total
  int a = 1'000'000;//./test.out  0.01s user 0.00s system 97% cpu 0.013 total
  for (int i = 0; i < a; i++)
    ;


  cout << "Hello world\n";
  return 0;
}
