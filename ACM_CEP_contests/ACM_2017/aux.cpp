#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> v = { 1, 2, 4, 4, 4, 5, 7, 9 };

  cout << "i: ";
  for (size_t i = 0; i < v.size(); i++) { cout << i << " "; }
  cout << endl;

  cout << "v: ";
  for (auto &&e : v) { cout << e << " "; }
  cout << endl;


  int x = 4;
  auto l = lower_bound(v.begin(), v.end(), x);
  auto u = upper_bound(v.begin(), v.end(), x);

  cout << "Lower de " << x << ": " << *l << " en [" << (l - v.begin()) << "]" << endl;
  cout << "Upper de " << x << ": " << *u << " en [" << (u - v.begin()) << "]" << endl;


  x = 100;
  l = lower_bound(v.begin(), v.end(), x);
  u = upper_bound(v.begin(), v.end(), x);

  if (l == v.end()) {// l es v.end() cuando no lo encuentra
    cout << "Lower no encontrado" << endl;
  } else {
    cout << "Lower de " << x << ": " << *l << " en [" << (l - v.begin()) << "]" << endl;
  }

  if (u == v.end()) {// u es v.end() cuando no lo encuentra
    cout << "Upper no encontrado" << endl;
  } else {
    cout << "Upper de " << x << ": " << *u << " en [" << (u - v.begin()) << "]" << endl;
  }

  return 0;
}
