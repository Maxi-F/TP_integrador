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
    nodoCandidatos *listacandidatos; //sublista
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
    if (n!=NULL) //si inicio no es NULL
    {
        nuevo->sgte= n->sgte; //se pasan los valores de n->sgte a nuevo->sgte para luego
        n->sgte = nuevo;     //insertar, justamente, el nodo nuevo en n->sgte, entonces ahora queda n->sgte apunta a nuevo y
                            //nuevo->sgte apunta a lo que antes apuntaba n->sgte, metiendose asi en el medio de dos nodos.
    }
    else
    {
        nuevo->sgte= n;     //si n es NULL, se le insertara el valor de n a nuevo->sgte, y a n, el valor de nuevo, quedando asi nuevo->sgte
        n= nuevo;          //apuntando a n, que se supone que es NULL.
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
    aux=ObtenerUltimaMesa(lista);               //obtiene ultimo para, si aux es != NULL, utilizar insertarSiguiente con ese valor,
                                               //cosa de que se agregue el nodo al final de la lista, x es la info a agregar.
    if (aux)
    {
        ListaMesaInsertarSiguiente (aux,x);  //usa aux aca porque, ademas de que justamente tiene el valor de ultimo nodo,
     }                                      //no es necesario usar lista (ya que si se utiliza lista erroneamente, puede modificarla por el &
    else
    {
        ListaMesaInsertarSiguiente(lista,x); //en ese caso sí se usa lista, ya que deja de ser NULL para pasar a tener un nodo.
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
                ListaCandidatosaListar(lista->info.listacandidatos); //si la sublista "listacandidator" no es NULL, se mostraran los candidatos.
        }
        else
            cout << "La mesa no posee candidatos cargados." << endl  << endl;
        lista = lista->sgte;
    }
}

nodoMesa *BuscarMesaPorComuna(nodoMesa *raiz, int nroComuna) //borrar o dejar? that is the question (quiza se puede usar como onda, busquemos primero la comuna y de ahi sacamos la mesa?? idk.
{
    nodoMesa *p=raiz;
    while (p && p->info.Comuna!=nroComuna)
    {
        p = p->sgte;
    }
    return p;
}

nodoMesa *BuscarMesaPorNro(nodoMesa *raiz, int nroMesa)
{
    nodoMesa *p=raiz;
    while (p && p->info.nroMesa!=nroMesa)
    {
        p = p->sgte;
    }
    return p;
}

void CargarMesasPrueba()
{
    FILE *f;
    f=fopen("archivomesas.bin","wb");
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

void CargarCandidatosPrueba()
{
    FILE *f;
    f=fopen("archivocandidatos.bin","wb");
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

nodoCandidatos *BuscarNodoAnterior(nodoCandidatos *raiz, nodoCandidatos * anterior_a)
{
    nodoCandidatos *p =NULL;
    if (raiz != anterior_a)
    {
        p = raiz;
        while (p && (p->sgte!= anterior_a) )
        {
            p = p->sgte;
        }
        return p;
    }
    else
        return NULL;
}

int ContarNodos(nodoCandidatos *lista)  //para burbujeo
{
    int cont=0;
    while (lista)
    {
        cont++;
        lista = ListaCandidatosObtenerSiguiente(lista);
    }
    return cont;
}

void burbujaListas(nodoCandidatos *&lista)
{
    int n,i,j;
    nodoCandidatos *aux;
    nodoCandidatos *anterior;
    nodoCandidatos *proximo;
    bool inter; //Para ver si hubo intercambio  o no
    n= ContarNodos(lista);
    for (i=0;i<=n-2;i++)
    {
        aux= lista;//Arranca desde el principio
        for (j=0;j<=n-2-i;j++)
        {
            if ((aux->sgte->info.Votos) < (aux->info.Votos))
            {
                inter= true;
                if (aux==lista)
                {
                    lista= aux->sgte;
                    proximo= lista->sgte;
                    lista->sgte=aux;
                    aux->sgte=proximo;
                }
                else
                {
                    anterior=BuscarNodoAnterior(lista,aux);
                    proximo=aux->sgte;
                    anterior->sgte= proximo;
                    aux->sgte= proximo->sgte;
                    proximo->sgte= aux;
                }
            }
            else
                inter=false;
            if (!inter)
            {
                aux= aux->sgte;
            }
        }
    }
    return;
}

void levantarArchivos(nodoMesa *&a)
{
    FILE *f;
    Mesa r;
    Candidatos m;
    f=fopen("archivomesas.bin","rb");
    fread(&r,sizeof(Mesa),1,f);
    while (!feof(f))
    {
        ListaMesaInsertarSiguiente(a,r);   //inserta los daots del archivo a la lista
        fread(&r,sizeof(Mesa),1,f);
    }
    fclose(f);
    f=fopen("archivocandidatos.bin","rb");
    fread(&m,sizeof(Candidatos),1,f);
    while (!feof(f))
    {
        nodoMesa *aux= BuscarMesaPorComuna(a, m.Comuna);  //hay que cambiar por numero de mesa. o no?
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
    if (arch_mesas= fopen("archivomesas.bin","ab"))
    {
        if (arch_candidatos= fopen("archivocandidatos.bin","ab"))
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
    CargarCandidatosPrueba();
    CargarMesasPrueba();
    return 0;
}
