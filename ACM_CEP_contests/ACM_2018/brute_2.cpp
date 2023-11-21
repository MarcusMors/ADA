#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define int long long

using namespace std;

signed main()
{
  int d;
  int CPB;
  cin >> d;
  cin >> CPB;
  int cont = 0;
  int sobra = 0;
  bool manana = false;
  bool hoy = false;
  for (int i = 0; i < d; i++) {
    int bxd;
    cin >> bxd;
    cont = cont + ((sobra + bxd) / CPB);
    sobra = (sobra + bxd) % CPB;
    if (sobra != 0 && hoy == true) { manana = true; }
    if (sobra != 0) { hoy = true; }
    if ((sobra + bxd) / CPB != 0 && hoy == true && manana == true) { manana = false; }
    if (manana == true && hoy == true) {
      cont = cont + 1;
      sobra = 0;
      manana = false;
      hoy = false;
    }
    if (sobra == 0) { hoy = false; }
  }
  if (hoy == true) { cont = cont + 1; }
  cout << cont;

  return 0;
}
