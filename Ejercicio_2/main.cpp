#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <stdlib.h>

using namespace std;

struct candidatos {
  char nombreCandidato[50];
  char apellidoCandidato[50];
  char agrupacionPolitica[70];
  int mesa;
  int votos;
};

struct nodoListaCandidatos {
  candidatos info;
  nodoListaCandidatos *sgte;
};

struct mesa {
  int nroMesa;
  char nombreEscuela[50];
  int comuna;
  nodoListaCandidatos *listaDeCandidatos;
};

struct nodoListaMesa {
  mesa info;
  nodoListaMesa *sgte;
};

void cargarCandidatosPrueba(void) {
  FILE *f;
  f = fopen("archivocandidatos.bin","wb");
  candidatos c;
  if (f) {
    strcpy(c.nombreCandidato,"SERGIO");
    strcpy(c.apellidoCandidato,"MASSA");
    strcpy(c.agrupacionPolitica,"1PAIS");
    c.votos=456;
    c.mesa=315;
    fwrite(&c, sizeof(candidatos),1,f);

    strcpy(c.nombreCandidato,"NESTOR");
    strcpy(c.apellidoCandidato,"KICHNER");
    strcpy(c.agrupacionPolitica,"FRENTE PARA LA VICTORIA");
    c.votos=95;
    c.mesa=212;
    fwrite(&c, sizeof(candidatos),1,f);

    strcpy(c.nombreCandidato,"MAURICIO");
    strcpy(c.apellidoCandidato,"MACRI");
    strcpy(c.agrupacionPolitica,"CAMBIEMOS");
    c.votos=98;
    c.mesa=316;
    fwrite(&c, sizeof(candidatos),1,f);

    strcpy(c.nombreCandidato,"CRISTINA");
    strcpy(c.apellidoCandidato,"FERNANDEZ DE KICHNER");
    strcpy(c.agrupacionPolitica,"UNION CIUDADANA");
    c.votos=655;
    c.mesa=316;
    fwrite(&c, sizeof(candidatos),1,f);

    fclose(f);
  } else {
    cout << "           ERROR: NO SE HA PODIDO CARGAR EL ARCHIVO" << endl;
  }
  return;
}

void cargarMesasPrueba(void) {
  FILE *f;
  f = fopen("archivomesas.bin","wb");
  mesa m;
  if(f) {
    m.nroMesa=212;
    strcpy(m.nombreEscuela,"NUESTRA SRA. DE LA MERCED");
    m.comuna=25;
    fwrite(&m, sizeof(mesa),1,f);

    m.nroMesa=315;
    strcpy(m.nombreEscuela,"ABATE JOSE REY");
    m.comuna=30;
    fwrite(&m, sizeof(mesa),1,f);

    m.nroMesa=316;
    strcpy(m.nombreEscuela,"ABATE JOSE REY 2");
    m.comuna=30;
    fwrite(&m, sizeof(mesa),1,f);

    m.nroMesa=653;
    strcpy(m.nombreEscuela,"JOSE INGENIEROS");
    m.comuna=12;
    fwrite(&m, sizeof(mesa),1,f);

    fclose(f);
  } else {
    cout << "           ERROR: NO SE PUEDE CARGAR EL ARCHIVO" << endl;
  }
  return;
}

nodoListaMesa* obtenerUltimoMesa (nodoListaMesa *m) {
  if(m) {
    while (m->sgte)
    m = m->sgte;
  }
  return m;
}

void listaMesaInsertarSgte (nodoListaMesa *&m, mesa x) {
  nodoListaMesa *nuevo = new nodoListaMesa();
  x.listaDeCandidatos = NULL;
  nuevo->info = x;
  if (m){
    nuevo->sgte = m->sgte;
    m->sgte = nuevo;
  } else {
    nuevo->sgte = m;
    m = nuevo;
  }

  return;
}

void listaMesaInsertarFinal (nodoListaMesa *&m, mesa x) {
  nodoListaMesa *aux=m;
  aux=obtenerUltimoMesa(aux);
  if(aux)
  listaMesaInsertarSgte(aux,x); //SI NO ES EL PRIMER NODO
  else
  listaMesaInsertarSgte(m,x); // SI ES EL PRIMER NODO
  return;
}


int contarNodosMesas (nodoListaMesa *m) {
  int nodos=0;
  while(m) {
    nodos++;
    m=m->sgte;
  }
  return nodos;
}

nodoListaMesa* buscarAnterior (nodoListaMesa *m, nodoListaMesa *antm) {
  nodoListaMesa *p=NULL;
  if (m!=antm) {
    p=m;
    while (p && p->sgte!=antm)
    p= p->sgte;

    return p;
  }
  else
    return NULL;
}

nodoListaMesa* buscarMesaPorComuna (nodoListaMesa * m, int comunaBuscada) {
  nodoListaMesa *p=m;
  while (p && p->info.comuna!=comunaBuscada)
  p = p->sgte;

  return p;
}

nodoListaMesa* buscarMesaPorNro (nodoListaMesa *m, int nroBuscado) {
  nodoListaMesa *p = m;
  while (p && p->info.nroMesa!=nroBuscado)
  p = p->sgte;
  return p;
}

void ordenamientoMesa (nodoListaMesa *&m) {
  nodoListaMesa *proximo=NULL;
  nodoListaMesa *anterior=NULL;
  nodoListaMesa *aux=NULL;
  int j,i,n;
  bool intercambio=false;
  n=contarNodosMesas(m);
  for (i=0;i<=n-1;i++) {
    aux = m;
    for (j=0;j<n-1-i;j++) {
      if ((aux->sgte->info.nroMesa) < (aux->info.nroMesa)) {
        intercambio=true;
        if(aux==m) {
          m=aux->sgte;
          proximo = m->sgte;
          m->sgte = aux;
          aux->sgte = proximo;
        } else {
          anterior=buscarAnterior(m,aux);
          proximo=aux->sgte;
          anterior->sgte = proximo;
          aux->sgte = proximo->sgte;
          proximo->sgte=aux;
        }
      } else
        intercambio=false;

      if(!intercambio)
        aux=aux->sgte;
    }
  }
}

nodoListaMesa *obtenerSiguienteMesa (nodoListaMesa *m) {
  if (m)
    return m->sgte;
  else
    return NULL;
}

void mostrarMesa (mesa m) {
  cout << endl << "               ESCUELA:" << endl;
  cout << endl << "                   NOMBRE: " << m.nombreEscuela << endl;
  cout << "                   NRO. DE COMUNA: " <<  m.comuna << endl;
  cout << "                   NRO. DE MESA: " << m.nroMesa << endl;
  return;
}

nodoListaCandidatos* buscarAnteriorCandidatos (nodoListaCandidatos *c, nodoListaCandidatos *antc) {
  nodoListaCandidatos *k=NULL;
  if (c!=antc){
    k=c;
    while (k && k->sgte!=antc)
    k=k->sgte;
    return k;
  }
  else
    return NULL;
}

nodoListaCandidatos* buscarCandidatosPorNombreYApellido (nodoListaCandidatos *c,char nombreBuscado[50], char apellidoBuscado[50]) {
  nodoListaCandidatos *p=c;
  while (p && strcmp(p->info.nombreCandidato,nombreBuscado) && strcmp(p->info.apellidoCandidato,apellidoBuscado))
    p= p->sgte;
  return p;
}


int contarNodosCandidatos (nodoListaCandidatos *c) {
  int nodos=0;
  while(c) {
    nodos++;
    c=c->sgte;
  }
  return nodos;
}

void ordenamientoCandidatos (nodoListaCandidatos *&c) {
  nodoListaCandidatos *proximo=NULL;
  nodoListaCandidatos *anterior=NULL;
  nodoListaCandidatos *aux=NULL;
  int i,j,p;
  int nodos=0;
  bool intercambio=false;
  nodos=contarNodosCandidatos(c);
  for (i=0;i<=nodos;i++){
    aux=c;
    for (j=0;j<nodos-1-i;j++) {
      if (aux->sgte->info.votos < aux->info.votos) {
        intercambio=true;
        if(aux==c) {
          c=aux->sgte;
          proximo=c->sgte;
          c->sgte=aux;
          aux->sgte=proximo;
        } else {
          anterior=buscarAnteriorCandidatos(c,aux);
          proximo=aux->sgte;
          anterior->sgte = proximo;
          aux->sgte = proximo->sgte;
          proximo->sgte=aux;
        }
      }

      else
        intercambio=false;

      if (!intercambio)
        aux=aux->sgte;
    }
  }

  return;
}

nodoListaCandidatos * obtenerUltimoCandidato (nodoListaCandidatos *c) {
  if(c) {
    while (c->sgte)
    c = c->sgte;
  }
  return c;
}

nodoListaCandidatos *obtenerSiguienteCandidato (nodoListaCandidatos *c) {
  if(c)
    return c->sgte;
  else
    return NULL;
}

void listaCandidatosInsertarSgte (nodoListaCandidatos *&c, candidatos x) {
  nodoListaCandidatos *nuevo = new nodoListaCandidatos;
  nuevo->info = x;
  if (c) {
    nuevo->sgte = c->sgte;
    c->sgte = nuevo;
  } else {
    nuevo->sgte = c;
    c = nuevo;
  }

  return;
}

void listaCandidatosInsertarFinal (nodoListaMesa *&m, candidatos x) {
  nodoListaCandidatos* aux=m->info.listaDeCandidatos;
  aux = obtenerUltimoCandidato(aux);
  if(aux)
    listaCandidatosInsertarSgte(aux,x);
  else
    listaCandidatosInsertarSgte(m->info.listaDeCandidatos,x);
  return;
}

void mostrarCandidatos (nodoListaCandidatos *c) {
  cout << endl << "               CANDIDATOS:" << endl;
  if(c) {
    while(c) {
      cout << endl <<"                   NOMBRE Y APELLIDO: " << c->info.nombreCandidato << " " << c->info.apellidoCandidato << endl;
      cout << "                   AGRUPACION POLITICA CORRESPONDIENTE: " << c->info.agrupacionPolitica << endl;
      cout << "                   CANTIDAD DE VOTOS CORRESPONDIENTE: " << c->info.votos << endl;

      c = c->sgte;
    }
  } else {
    cout << "                   NO TIENEN CANDIDATOS INGRESADOS." << endl;
  }

  return;
}

void levantarArchivos (nodoListaMesa *&p) {
  FILE *f;
  mesa m;
  candidatos c;
  f=fopen("archivomesas.bin","rb");
  fread(&m,sizeof(mesa),1,f);
  while (!feof(f)) {
    listaMesaInsertarSgte(p,m);
    fread(&m,sizeof(mesa),1,f);
  }
  fclose(f);

  f=fopen("archivocandidatos.bin", "rb");
  fread(&c,sizeof(candidatos),1,f);
  while (!feof(f)) {
    nodoListaMesa *aux = buscarMesaPorNro(p,c.mesa);
    if (aux) {
      listaCandidatosInsertarSgte(aux->info.listaDeCandidatos, c);
    }
    fread(&c,sizeof(candidatos),1,f);
  }
  fclose(f);
  return;
}

char mostrarMenu() {
  cout << "*******************************  BIENVENIDO/A  *******************************" << endl << endl;
  cout << "                           SELECCIONE UNA OPCION:" << endl;
  cout << endl << "            '0' PARA BUSCAR UNA MESA POR SU NRO. DE COMUNA CORRESPONDIENTE." << endl;
  cout << "            '1' PARA AGREGAR UNA NUEVA MESA." << endl;
  cout << "            '2' PARA AGREGAR UN NUEVO CANDIDATO." << endl; //ALMOST DONE
  cout << "            '3' PARA ORDENAR POR NUMERO DE MESA." << endl;
  cout << "            '4' PARA ORDENAR POR VOTOS." << endl;
  cout << "            '5' PARA VISUALIZAR LAS MESAS Y LOS CANDIDATOS." << endl;
  cout << endl << "            'ESC' PARA SALIR DEL PROGRAMA." << endl;
  cout << endl << "****************************************************************************" << endl <<endl;

  char opcion;
  do {
    opcion=getch();
  } while ((opcion!='0') && (opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4') && (opcion!='5') && (opcion!=27));

  return opcion;
}

void buscarMesaPorComunaMenu (nodoListaMesa *m) {
  nodoListaMesa *p=NULL;
  int comunaDeseada;
  cout << "**********************  BUSCAR MESA POR NRO. DE COMUNA  ********************" << endl << endl;
  cout << endl << "       INSERTE COMUNA DESEADA:";
  cin >> comunaDeseada;
  p = buscarMesaPorComuna(m,comunaDeseada);
  if (p){
    mostrarMesa(p->info);
    mostrarCandidatos(p->info.listaDeCandidatos);
  }
  else{
    cout << endl << "ERROR: NO SE HAN ENCONTRADO NINGUNA MESA CON EL NRO. DE COMUNA: " << comunaDeseada << "." <<endl << "POR FAVOR, INGRESE UN NRO. VALIDO." << endl;
  }
  return;
}

void insertarNuevaMesaMenu (nodoListaMesa *&m) {
  cout << "*************************  INSERTAR UNA NUEVA MESA  ************************" << endl << endl;
  mesa nuevaMesa;
  nodoListaMesa *aux;
  bool encontrado = false;
  cout << "   INGRESE LOS DATOS CORRESPONDIENTES A LA NUEVA MESA:" << endl << endl;
  cout << "        NRO. DE COMUNA: ";
  cin >> nuevaMesa.comuna;
  cout << "        NRO. DE MESA: ";
  cin >> nuevaMesa.nroMesa;
  aux = buscarMesaPorNro(m,nuevaMesa.nroMesa);
  while(aux && !encontrado) {
    if(aux->info.nroMesa == nuevaMesa.nroMesa && aux->info.comuna == nuevaMesa.comuna) {
      encontrado = true;
    } else {
      aux = aux->sgte;
    }
  }
  if (aux)
    cout << endl <<"            ERROR: YA EXISTE UNA MESA CON EL NUMERO " << nuevaMesa.nroMesa <<" EN LA COMUNA " << nuevaMesa.comuna << endl;
  else {
    cout << "        NOMBRE DE ESCUELA CORRESPONDIENTE: ";
    cin >> nuevaMesa.nombreEscuela;
    listaMesaInsertarFinal(m,nuevaMesa);
    system("cls");
    cout << "*************************  INSERTAR UNA NUEVA MESA  ************************" << endl << endl;
    cout << "                   SE HA CARGADO LA MESA NRO. " << nuevaMesa.comuna << " CORRECTAMENTE." << endl;
  }
  return;
}

void insertarNuevoCandidatoMenu (nodoListaMesa *&m, nodoListaCandidatos *&c) {
  nodoListaMesa *p=NULL;
  nodoListaMesa *k=NULL;
  int comunaDeseada;
  int mesaDeseada;
  cout << "**********************  INSERTAR UN/A NUEVO/A CANDIDATO/A    *********************" << endl << endl;
  cout << "INGRESE NRO. DE COMUNA DE LA MESA CORRESPONDIENTE: ";
  cin >> comunaDeseada;
  p=buscarMesaPorComuna(m,comunaDeseada);
  if(p) {
  cout << "INGRESE NRO. DE MESA CORRESPONDIENTE: ";
  cin >> mesaDeseada;
    k = buscarMesaPorNro(m,mesaDeseada);
    while(k && k->info.comuna != comunaDeseada) {
      k = k->sgte;
      k = buscarMesaPorNro(k, mesaDeseada);
    }
    if(k) {
      candidatos nuevoCandidato;
      cout << endl << "       INGRESE NOMBRE DEL CANDIDATO: ";
      cin >> nuevoCandidato.nombreCandidato;
      cout << "       INGRESE APELLIDO DEL CANDIDATO: ";
      cin >> nuevoCandidato.apellidoCandidato;
      if(buscarCandidatosPorNombreYApellido(p->info.listaDeCandidatos, nuevoCandidato.nombreCandidato, nuevoCandidato.apellidoCandidato))
        cout << endl <<"        ERROR: EL/LA CANDIDAT@ " << nuevoCandidato.nombreCandidato << " " << nuevoCandidato.apellidoCandidato << " YA SE ENCUENTRA INGRESADO." << endl;
      else {
        cout << "       INGRESE AGRUPACION POLITICA: ";
        cin >> nuevoCandidato.agrupacionPolitica;
        cout << "       INGRESE CANTIDAD DE VOTOS EN LA MESA: ";
        cin >> nuevoCandidato.votos;
        nuevoCandidato.mesa = mesaDeseada;
        listaCandidatosInsertarFinal(k, nuevoCandidato);
        system("cls");
        cout << "**********************  INSERTAR UNA NUEVA  CANDIDATO    *********************" << endl << endl;
        cout << "                   SE HA CARGADO EL CANDIDATO " << nuevoCandidato.nombreCandidato << " " << nuevoCandidato.apellidoCandidato << " CORRECTAMENTE." << endl;
      }
    }
    else {
      cout << "          ERROR: NRO. DE MESA NO CORRESPONDE CON EL NRO. DE COMUNA" << endl;
    }
  }
  else
    cout << "          ERROR: NRO. DE COMUNA INEXISTENTE." << endl;
  return;
}

void ordenarMesasMenu (nodoListaMesa *m) {
  int l;
  int nodos=0;
  cout << "*************************  ORDENAR POR NRO. DE MESA   ************************" << endl << endl;
  ordenamientoMesa(m);
  cout << "                         SE HA ORDENADO CORRECTAMENTE.";
  cout << endl << "                    _________________________________________" << endl;
  int p;
  nodos=contarNodosMesas(m);

  for(p=0; p<=nodos;p++) {
    if (m) {
      mostrarMesa(m->info);
      mostrarCandidatos(m->info.listaDeCandidatos);
      m= m->sgte;
    }
  }
  return;
}

void mostrarMesasYCandidatosMenu (nodoListaMesa *m) {
  int i;
  int nodos=0;
  nodos=contarNodosMesas(m);
  for (i=0; i<=nodos;i++) {
    if(m) {
      mostrarMesa(m->info);
      mostrarCandidatos(m->info.listaDeCandidatos);
      m= m->sgte;
    }
  }
  return;
}

void ordenarCandidatosMenu (nodoListaMesa *m) {
  int mesaDeseada;
  cout << "***********************  ORDENAR CANDIDATOS POR VOTOS  ************************" << endl << endl;
  cout << endl << "INGRESE EL NRO. DE LA MESA QUE DESEA ORDENAR LOS CANDIDATOS: ";
  cin >> mesaDeseada;
  m=buscarMesaPorNro(m,mesaDeseada);
  if(m && m->info.listaDeCandidatos) {
    ordenamientoCandidatos(m->info.listaDeCandidatos);
    cout << endl << "                         SE HA ORDENADO CORRECTAMENTE.";
    cout << endl << "                    _________________________________________" << endl;
    mostrarCandidatos(m->info.listaDeCandidatos);
  } else {
    if(!m) {
      cout << "       ERROR: NO FUE INGRESADA LA MESA " << mesaDeseada << " AL PROGRAMA. " << endl;
    } else {
      cout << "       ERROR: NO SE HAN INGRESADO CANDIDATOS EN LA MESA " << mesaDeseada << endl;
    }
  }
  return;
}

void guardarArchivoMenu(nodoListaMesa *m) {
  FILE *archivoMesas;
  FILE *archivoCandidatos;
  nodoListaMesa *auxMesa=NULL;
  nodoListaCandidatos *auxCand=NULL;
  if(archivoMesas= fopen("archivomesas.bin","wb")) {
    if(archivoCandidatos= fopen("archivocandidatos.bin","wb")) {
      auxMesa= m;
      while (auxMesa) {
        fwrite(&(auxMesa->info), sizeof(mesa),1,archivoMesas);
        auxCand= auxMesa->info.listaDeCandidatos;
        while(auxCand) {
          fwrite(&(auxCand->info), sizeof(candidatos),1,archivoCandidatos);
          auxCand= obtenerSiguienteCandidato(auxCand);
        }
        auxMesa= obtenerSiguienteMesa(auxMesa);
      }
      fclose(archivoCandidatos);
    }
    else
      cout << "       ERROR AL INTENTAR GRABAR ARCHIVO DE CANDIDATOS" << endl;

    fclose(archivoMesas);
  } else {
    cout << "       ERROR AL INTENTAR GRABAR ARCHIVO DE MESAS" << endl;
    getch();
  }

  return;
}

int main() {
  nodoListaMesa *m=NULL;
  nodoListaCandidatos *c=NULL;
  //cargarCandidatosPrueba();
  //cargarMesasPrueba();
  levantarArchivos(m);
  char elegida;

  do {

    elegida = mostrarMenu();
    switch(elegida){
      case '0':
      system("cls");
      buscarMesaPorComunaMenu(m);
      break;
      case '1':
      system("cls");
      insertarNuevaMesaMenu(m);
      break;
      case '2':
      system("cls");
      insertarNuevoCandidatoMenu(m,c);
      break;
      case '3':
      system("cls");
      ordenarMesasMenu(m);
      break;
      case '4':
      system("cls");
      ordenarCandidatosMenu(m);
      break;
      case '5':
      system("cls");
      mostrarMesasYCandidatosMenu(m);
      break;
    }

    if(elegida != 27) {
      cout << endl << "****************************************************************************" << endl;
      cout << endl << "           PRESIONE UNA TECLA PARA CONTINUAR." << endl;
      getch();
    }

    system("cls");

  } while (elegida!=27);
  guardarArchivoMenu(m);
  cout << endl << "       GRACIAS POR UTILIZAR NUESTRO PROGRAMA!" << endl;

  return 0;
}
