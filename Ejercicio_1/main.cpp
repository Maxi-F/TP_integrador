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

void asignarRel(Nodo grafo[], int i, int j) {
  int k = 0;
  while(grafo[i].relacionados[k] != Vacio) {
    k++;
  }
  grafo[i].relacionados[k] = j;
  k = 0;
  while(grafo[j].relacionados[k] != Vacio) {
    k++;
  }
  grafo[j].relacionados[k] = i;
  return;
}

void defAristas(Nodo grafo[]) {
  int j, k, aux, peso;
  k = 0;

  for(int i = 0; i < Tam; i++) {

    j = 0;

    while(grafo[i].relacionados[j] != Vacio && j < Rel) {

      k = 0;

      if(!grafo[i].aristas[j]) {
        aux = grafo[i].relacionados[j];
        cout << "Por favor ingrese el peso de la arista que comunica el Nodo " << grafo[i].nombre << " con el Nodo " << grafo[aux].nombre << endl;
        cin >> peso;
        grafo[i].aristas[j] = peso;


        while(grafo[aux].relacionados[k] != i) {
          k++;
        }

        grafo[aux].aristas[k] = peso;
      }

      j++;
    }
  }
  return;
}

void crearGrafo(Nodo grafo[]) {
  for(int i = 0; i < Tam; i++) {
    grafo[i].nombre[1] = aChar(i);

    for(int j = 0; j < Rel; j++) {
      grafo[i].relacionados[j] = Vacio;
    }

  }

  asignarRel(grafo, 0, 1);//Asigna la relacion entre C0 y C1
  asignarRel(grafo, 0, 2);//Asigna la relacion entre C0 y C2
  asignarRel(grafo, 1, 2);//Asigna la relacion entre C1 y C2
  asignarRel(grafo, 1, 3);//Asigna la relacion entre C1 y C3
  asignarRel(grafo, 2, 3);//Asigna la relacion entre C2 y C3
  asignarRel(grafo, 2, 4);//Asigna la relacion entre C2 y C4
  asignarRel(grafo, 3, 4);//Asigna la relacion entre C3 y C4
  asignarRel(grafo, 3, 5);//Asigna la relacion entre C3 y C5
  asignarRel(grafo, 4, 5);//Asigna la relacion entre C4 y C5
  asignarRel(grafo, 5, 6);//Asigna la relacion entre C5 y C6
  asignarRel(grafo, 5, 7);//Asigna la relacion entre C5 y C7
  asignarRel(grafo, 6, 7);//Asigna la relacion entre C6 y C7
  asignarRel(grafo, 6, 8);//Asigna la relacion entre C6 y C8
  asignarRel(grafo, 7, 8);//Asigna la relacion entre C7 y C8


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
