#include <iostream>

using namespace std;

int main()
{
  long long unsigned a, b, h;
  cin >> a;
  cin >> b;
  cin >> h;

  const long long unsigned sum = a + b;
  if (h % 2 == 0) {
    cout << (h / 2) * sum;
    return 0;
  }

  if (sum % 2 == 0) {
    cout << (sum / 2) * h;
    return 0;
  }

  const long long unsigned rpta = sum * h;// both sum and h are odd
  cout << rpta / 2 << ".5";

  return 0;
}
