#include <iostream>
#include <ctime> //Para usar time()
#include <stdlib.h>

#define Rango 1000
#define Tam 9
#define Rel 4
#define Vacio -10

using namespace std;

struct Nodo {
  char nombre[3] {'C'};
  int aristas[Rel]{};
  int relacionados[Rel]{};
};

char aChar(int conv) {
  conv += 48;
  return conv;
}

void asignarRel(Nodo grafo[]) {

}



void defAristas(Nodo grafo[]) {
  int j, k, aux;
  int valor;

  for(int i = 0; i < Tam; i++) {

    j = k = 0;

    while(grafo[i].relacionados[j] != Vacio && j < Rel) {
      if(!grafo[i].aristas[j]) {
        aux = grafo[i].relacionados[j];
        cout << "Por favor ingrese el valor de la arista que comunica el Nodo " << grafo[i].nombre << endl;
        cout << "con el Nodo " << grafo[aux].nombre << endl;
        cin >> valor;
        grafo[i].aristas[j] = valor;

        while(grafo[aux].relacionados[k] != i) {
          k++;
        }

        grafo[aux].aristas[k] = valor;
      }

      j++;
    }
  }
  return;
}

void crearGrafo(Nodo grafo[]) {
  int j;
  for(int i = 0; i < Tam; i++) {
    grafo[i].nombre[1] = aChar(i);
    j = 0;
    while(!grafo[i].relacionados[j] && j < Rel) {
      grafo[i].relacionados[j] = Vacio;
      j++;
    }

  }

  grafo[0].relacionados[0] = 1; //Equivalente a decir relacionado con el nodo 1
  grafo[1].relacionados[0] = 0; //Equivalente a decir relacionado con el nodo 0


  return;
}

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
  Nodo grafo[Tam];
  crearGrafo(grafo);
  defAristas(grafo);

  cout << velocidadPromedio() << endl;//Para obtener la velocidad promedio
  return 0;
}
