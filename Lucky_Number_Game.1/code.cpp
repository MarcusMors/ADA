#include <iostream>
using namespace std;

int main()
{
  int hora = 0, tolerancia = 0;
  cin >> hora >> tolerancia;
  int c = 0, t = 0, r = 0;
  int md = 0;
  for (int i = 0; i < hora; i++) {
    cin >> c >> t;
    md = t / 60;
    c = c + md;
    t = t - (md * 60);
    // cout << "c:" << c << "t:" << t << endl;
    if (c <= 7 and c <= 23 and t <= 59 and t >= 0 and t <= tolerancia) { r++; }
  }
  cout << r;
}
