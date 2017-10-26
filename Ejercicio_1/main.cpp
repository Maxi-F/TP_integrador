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
  float aristas[Rel]{};
  int relacionados[Rel]{};
};

float aleatorio() {
  return rand()%Rango;
}

float calcDemora() {
  float v, demora;
  demora = aleatorio()/Rango;
  cout << endl << "Ingrese la velocidad promedio del m\242vil teniendo en cuenta que la demora har\240 que vaya al " << demora*100 << " \%\ de su velocidad: " << endl;
  cin >> v;

  return v * demora;
}

char aChar(int conv) {
  conv += 48;
  return conv;
}

int caminoMasCorto(float caminos[]) {
    int menor = 0;
    for(int i = 1; i <= 3; i++) {
            if (caminos [i] < caminos[menor])
                menor=i;
        }
    return menor;
}

void caminoOptimo(Nodo grafo[]) {
  int camino1[6], camino2[4];
  float caminosA[4], caminosB[2];

  for(int i = 0; i < 4; i++) {
    caminosA[i] = 0;
    if(i < 2) {
      caminosB[i] = 0;
    }
  }

  caminosA[0] = grafo[0].aristas[1] + grafo[2].aristas[1] + grafo[1].aristas[2] + grafo[3].aristas[2] + grafo[4].aristas[2];
  caminosA[1] = grafo[0].aristas[0] + grafo[1].aristas[1] + grafo[2].aristas[2] + grafo[3].aristas[2] + grafo[4].aristas[2];
  caminosA[2] = grafo[0].aristas[0] + grafo[1].aristas[1] + grafo[2].aristas[3] + grafo[4].aristas[1] + grafo[3].aristas[3];
  caminosA[3] = grafo[0].aristas[0] + grafo[1].aristas[2] + grafo[3].aristas[1] + grafo[2].aristas[3] + grafo[4].aristas[2];

  caminosB[0] = grafo[5].aristas[2] + grafo[6].aristas[2] + grafo[7].aristas[2];
  caminosB[1] = grafo[5].aristas[3] + grafo[7].aristas[1] + grafo[6].aristas[0];

  switch(caminoMasCorto(caminosA)) {
    case 0: cout << endl << "El camino mas corto pasa por: \n" << endl << grafo[0].nombre << endl << grafo[2].nombre << endl
    << grafo[1].nombre << endl << grafo[3].nombre << endl << grafo[4].nombre << endl;
      break;
    case 1: cout << endl << "El camino mas corto pasa por: \n" << endl << grafo[0].nombre << endl << grafo[1].nombre << endl
    << grafo[2].nombre << endl << grafo[3].nombre << endl << grafo[4].nombre << endl;
      break;
    case 2: cout << endl << "El camino mas corto pasa por: \n" << endl << grafo[0].nombre << endl << grafo[1].nombre << endl
    << grafo[2].nombre << endl << grafo[4].nombre << endl << grafo[3].nombre << endl;
      break;
    case 3: cout << endl << "El camino mas corto pasa por: \n" << endl << grafo[0].nombre << endl << grafo[1].nombre << endl
    << grafo[3].nombre << endl << grafo[2].nombre << endl << grafo[4].nombre << endl;
      break;
  }

  if(caminosB[1]<caminosB[0]) {
    cout << grafo[5].nombre << endl << grafo[7].nombre << endl << grafo[6].nombre << endl;
  } else {
    cout << grafo[5].nombre << endl << grafo[6].nombre << endl << grafo[7].nombre << endl;
  }

  cout << grafo[8].nombre << endl;

  return;
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
        float velocidad = calcDemora();
        aux = grafo[i].relacionados[j];
        cout << endl << "Por favor ingrese la distancia de la escuela " << grafo[i].nombre << " con la escuela " << grafo[aux].nombre << endl;
        cin >> peso;
        grafo[i].aristas[j] = peso + velocidad;


        while(grafo[aux].relacionados[k] != i) {
          k++;
        }

        grafo[aux].aristas[k] = peso + velocidad;
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

int main() {
  srand(time(0));

  cout << "Bienvenid@!!" << endl;

  Nodo grafo[Tam];
  crearGrafo(grafo);
  defAristas(grafo);
  caminoOptimo(grafo);

  cout << endl << "Gracias por utilizar el programa!" << endl;
  return 0;
}
