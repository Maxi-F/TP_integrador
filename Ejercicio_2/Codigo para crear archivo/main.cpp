#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;

struct Candidatos
{
    char nombreCandidato[50];
    char apellidoCandidato[50];
    char agrupacionPolitica[70];
    int Comuna;
    int Votos;
};

struct nodoCandidatos
{
    Candidatos info;
    nodoCandidatos *sgte;
};

struct Mesa
{
    int nroMesa;
    char NombreEscuela[50];
    int Comuna;
    nodoCandidatos *listacandidatos;
};

struct nodoMesa
{
    Mesa info;
    nodoMesa *sgte;
};

void ListaMesaInsertarSiguiente (nodoMesa  *&n, Mesa x)
{
    nodoMesa *nuevo= new nodoMesa();
    x.listacandidatos=NULL;
    nuevo->info=x;
    if (n!=NULL)
    {
        nuevo->sgte= n->sgte;
        n->sgte = nuevo;
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
    }

    return;
}

nodoMesa *ObtenerUltimaMesa(nodoMesa *p)
{
    if (p)
    {
        while (p->sgte)
        {
            p = p->sgte;
        }
    }
    return p;
}

void ListaMesaInsertarAlFinal(nodoMesa *&lista, Mesa x)
{
    nodoMesa *aux;
    aux=ObtenerUltimaMesa(lista);
    if (aux)
    {
        ListaMesaInsertarSiguiente (aux,x);
    }
    else
    {
        ListaMesaInsertarSiguiente(lista,x);
    }
    return;
}

void ListaCandidatosInsertarSiguiente (nodoCandidatos  *&n, Candidatos x)
{
    nodoCandidatos *nuevo= new nodoCandidatos();
    nuevo->info=x;
    if (n)
    {
        nuevo->sgte= n->sgte;
        n->sgte = nuevo;
    }
    else
    {
        nuevo->sgte= n;
        n= nuevo;
    }
    return;
}

nodoCandidatos *ListaCandidatosObtenerSiguiente(nodoCandidatos *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

nodoCandidatos *ObtenerUltimoCandidato(nodoCandidatos *p)
{
    if (p)
    {
        while (p->sgte)
        {
            p = p->sgte;
        }
    }
    return p;
}

nodoMesa *ListaMesasObtenerSiguiente(nodoMesa *n)
{
    if (n)
        return n->sgte;
    else
        return NULL;
}

void ListaCandidatosInsertarAlFinal(nodoCandidatos *&lista, Candidatos x)
{
    nodoCandidatos *aux;
    aux=ObtenerUltimoCandidato(lista);
    if (aux)
    {
        ListaCandidatosInsertarSiguiente(aux,x);
    }
    else
    {
        ListaCandidatosInsertarSiguiente(lista,x);
    }
    return;
}

void ListaCandidatosaListar(nodoCandidatos *lista)
{
    while (lista)
    {
        cout << "           -CANDIDATOS-" << endl;
        cout << "Nombre y apellido: " << lista->info.nombreCandidato << " " << lista->info.apellidoCandidato <<  endl;
        cout << "Agrupacion politica: " << lista->info.agrupacionPolitica<< endl;
        cout << "Comuna: " << lista->info.Comuna << endl;
        cout << "Votos: "  << lista->info.Votos << endl;
        lista = lista->sgte;
    }
}

void ListaMesaListar(nodoMesa *lista)
{
    while (lista)
    {
        cout << "           -DATOS DE LA MESA- " << endl;
        cout << "Nro de la mesa: " << lista->info.nroMesa << endl;
        cout << "En la escuela: " << lista->info.NombreEscuela << endl;
        cout << "En la comuna: " << lista->info.Comuna << endl;
        if (lista->info.listacandidatos)
        {
                ListaCandidatosaListar(lista->info.listacandidatos);
        }
        else
            cout << "La mesa no posee candidatos cargados." << endl  << endl;
        lista = lista->sgte;
    }
}

nodoMesa *BuscarMesaPorComuna(nodoMesa *raiz, int nroComuna)
{
    nodoMesa *p=raiz;
    while (p && p->info.Comuna!=nroComuna)
    {
        p = p->sgte;
    }
    return p;
}

void CargarMesasPrueba()
{
    FILE *f;
    f=fopen("archivomesas.data","wb");
    Mesa x;
    if (f)
    {
     strcpy(x.NombreEscuela,"Manuel Belgrano");
        x.nroMesa=227;
        x.Comuna=13;
        fwrite(&x, sizeof(Mesa),1,f);

    strcpy(x.NombreEscuela,"Patria Grande");
        x.nroMesa=116;
        x.Comuna=9;
        fwrite(&x, sizeof(Mesa),1,f);

    strcpy(x.NombreEscuela,"Norbridge");
        x.nroMesa=214;
        x.Comuna=12;
        fwrite(&x, sizeof(Mesa),1,f);

    strcpy(x.NombreEscuela,"Instituto Lecanne");
        x.nroMesa=117;
        x.Comuna=15;
        fwrite(&x, sizeof(Mesa),1,f);
    fclose(f);
        cout << "El archivo ha sido cargado con exito" << endl;
    }
    else
        cout << "Error: no se pudo crear el archivo" << endl;
    return;
}

void CargarMateriasPrueba()
{
    FILE *f;
    f=fopen("archivocandidatos.data","wb");
    Candidatos x;
    if (f)
    {
    strcpy(x.nombreCandidato,"Enrique");
        strcpy(x.apellidoCandidato,"Viale");
        strcpy(x.agrupacionPolitica,"Sur en Marcha");
        x.Comuna=3;
        x.Votos=3742;
        fwrite(&x, sizeof(Candidatos),1,f);

    strcpy(x.nombreCandidato,"Pablo");
        strcpy(x.apellidoCandidato,"Baque");
        strcpy(x.agrupacionPolitica,"Partido Humanista");
        x.Comuna=13;
        x.Votos=4980 ;
        fwrite(&x, sizeof(Candidatos),1,f);

    strcpy(x.nombreCandidato,"Adrian");
        strcpy(x.apellidoCandidato,"Camps");
        strcpy(x.agrupacionPolitica,"Partido Socialista");
        x.Comuna= 12;
        x.Votos=1860;
        fwrite(&x, sizeof(Candidatos),1,f);
    fclose(f);

        cout << "El archivo ha sido cargado con exito" << endl;
    }
    else
        cout << "Error: no se pudo crear el archivo" << endl;
    return;
}

void levantarArchivos(nodoMesa *&a)
{
    FILE *f;
    Mesa r;
    Candidatos m;
    f=fopen("archivomesas.data","r");
    fread(&r,sizeof(Mesa),1,f);
    while (!feof(f))
    {
        ListaMesaInsertarSiguiente(a,r);
        fread(&r,sizeof(Mesa),1,f);
    }
    fclose(f);
    f=fopen("archivocandidatos","r");
    fread(&m,sizeof(Candidatos),1,f);
    while (!feof(f))
    {
        nodoMesa *aux= BuscarMesaPorComuna(a, m.Comuna);
        if (aux)
        {
                    ListaCandidatosInsertarSiguiente(aux->info.listacandidatos,m);
        }
        fread(&m,sizeof(Candidatos),1,f);
    }
    fclose(f);
    return;
}

void guardarMesas(nodoMesa *la)
{
    FILE *arch_mesas;
    FILE *arch_candidatos;
    nodoMesa *auxMesa=NULL;
    nodoCandidatos *auxCand=NULL;
    if (arch_mesas= fopen("archivomesas.data","wb"))
    {
        if (arch_candidatos= fopen("archivocandidatos.data","wb"))
        {
            auxMesa= la;
            while (auxMesa)
            {
                fwrite(&(auxMesa->info), sizeof(Mesa),1,arch_mesas);
                auxCand= auxMesa->info.listacandidatos;
                while(auxCand)
                {
                    fwrite(&(auxCand->info), sizeof(Candidatos),1,arch_candidatos);
                    auxCand= ListaCandidatosObtenerSiguiente(auxCand);
                }
                auxMesa= ListaMesasObtenerSiguiente(auxMesa);
            }
            fclose(arch_candidatos);
        }
        else
            cout << "ERROR AL INTENTAR GRABAR ARCHIVO DE CANDIDATOS" << endl;
        fclose(arch_mesas);
    }
    else
        cout << "ERROR AL INTENTAR GRABAR ARCHIVO DE MESAS" << endl;
    return;
}

int main()
{
    nodoMesa *lMesa=NULL;
    nodoMesa *x=NULL;
    CargarMateriasPrueba();
    CargarMesasPrueba();
    guardarMesas(lMesa);
    return 0;
}
