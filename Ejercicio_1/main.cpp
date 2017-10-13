#include <iostream>
#include <ctime> //Para usar time()
#include <stdlib.h>

#define Rango 1000

using namespace std;

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
    //Para obtener la velocidad promedio velocidadPromedio();
    return 0;
}
