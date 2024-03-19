#include <iostream>
#include <vector>

using namespace std;
int main()
{
  using ll = long long;
  ll reg, amig, aux;/// n>k regalos>amigos
  cin >> reg >> amig;
  vector<ll> sec;
  vector<ll> valor;


  for (ll i = 0; i < reg; i++) {
    cin >> aux;
    sec.push_back(aux);
    /// aux solo puede ser de TRES TIPOS 1, 2 o 3
  }
  ll reboot = 0;
  ll cont = 0;
  ll record = 0;
  for (ll i = 0; i <= reg + 1 - amig; i++) {/// mueve la banda
    for (ll o = 0; o < amig; o += 3) {
      if (sec[i + (o)] == 1) { cont++; }
    }
    for (ll o = 0; (o) + 1 < amig; o += 3) {
      if (sec[i + 1 + (o)] == 2) { cont++; }
    }
    for (ll o = 0; (o) + 2 < amig; o += 3) {
      if (sec[i + 2 + (o)] == 3) { cont++; }
    }
    if (cont >= record) {
      record = cont;
      if (record == amig) { break; }
    }
    cont = 0;
  }
  cout << amig - record;


  return 0;
}
