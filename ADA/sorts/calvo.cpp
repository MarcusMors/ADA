#include <iostream>
#include <vector>

using namespace std;

struct mochila
{
  float valor{};
  float peso{};
  float indice{};
};

int resolver(int capacidad, vector<mochila> mochilas, int n)
{
  int max, j;
  float wmax, valmax = 0;

  cout << "Numero de elementos que quieren entrar en la mochila: " << n;
  std::vector<mochila> elemento(n);
  mochila aux;
  cout << "\n Ingresar elemento en la mochila : \n";

  for (int i = 0; i < n; i++) {
    cout << "valor " << i + 1 << " : ";
    // mochilas[i] = elemento[i].valor;
    // mochilas.at(i).
    // mochilas[i] = elemento[i];
    mochilas[i].valor = elemento[i].valor;
    cout << "Peso " << i + 1 << " : ";
    cin >> elemento[i].peso;
    elemento[i].indice = elemento[i].valor / elemento[i].peso;

    // ordenamientoS
    for (i = 0; i < n; i++) {
      max = i;
      for (j = i + 1; j < n; j++) {
        if (elemento[j].indice > elemento[max].indice) { max = j; }
      }
      aux = elemento[i];
      elemento[i] = elemento[max];
      elemento[max] = aux;
    }

    // Verificamos los objetos
    for (i = 0; i < n; i++) {
      cout << i + 1 << " : ";
      cout << elemento[i].indice << " , ";
      cout << elemento[i].peso << " , ";
      cout << elemento[i].valor << endl;
    }
    cout << endl;
    cout << "Peso max de la mochila; \n";
    cin >> wmax;
    i = 0;
    while (wmax > 0) {
      if (wmax > elemento[i].peso) {
        wmax = wmax - elemento[i].peso;
        valmax = valmax + elemento[i].valor;
      } else {
        valmax = valmax + (elemento[i].valor * (wmax / elemento[i].peso));
        wmax = 0;
      }
      i++;
    }
    return valmax;
  }
}

int main()
{
  int n;
  int capacidad = 100;
  std::vector<mochila> mochilas{ { 60, 50 }, { 20, 10 }, { 66, 30 }, { 30, 20 }, { 40, 40 } };
  int numMochilas = mochilas.size();

  cout << "El valor max de la mochila es: " << resolver(capacidad, mochilas, numMochilas);

  return 0;
}
