#include <iostream>
#include <ctime> //Para usar time()
#include <stdlib.h>

#define Rango 1000

using namespace std;

struct Nodo {
  int id;
  Nodo *sgt;
  Nodo *ady;
};

struct Arista {
  Nodo *dst;
  Arista *sgt;
};

float aleatorio() {
    return rand()%Rango;
}

float velocidadPromedio() {
    float v;
    cout << "Ingrese la velocidad promedio del m\242vil." << endl;
    cin >> v;
    srand(time(0));

    return v * aleatorio()/Rango;
}

int main() {

  cout << velocidadPromedio() << endl;//Para obtener la velocidad promedio
  return 0;
}
