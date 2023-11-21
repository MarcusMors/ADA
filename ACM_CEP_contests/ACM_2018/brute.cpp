#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define int long long

using namespace std;

signed main()
{
  int d;
  cin >> d;
  int k;
  cin >> k;

  int cont = 0;
  int sobra = 0;
  bool manana = false;
  bool hoy = false;

  for (int i = 0; i < d; i++) {
    int b;
    cin >> b;
    cont = cont + ((sobra + b) / k);
    sobra = (sobra + b) % k;
    if (sobra != 0 && hoy) { manana = true; }
    if (sobra != 0) { hoy = true; }
    if ((sobra + b) / k != 0 && hoy && manana) { manana = false; }
    if (manana && hoy) {
      cont = cont + 1;
      sobra = 0;
      manana = false;
      hoy = false;
    }
    if (sobra == 0) { hoy = false; }
  }

  if (hoy) { cont = cont + 1; }

  cout << cont;

  return 0;
}
