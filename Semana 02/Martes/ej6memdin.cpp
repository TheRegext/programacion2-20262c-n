///Fecha:
///Autor:
///Comentario:resolución sin analizar los pares distintos. Se copiaran en el vector
///dinámico todos los pares ingresados

#include <iostream>

using namespace std;

void cargarVector(int *v,int tam);
int contarPares(int v[],int tam);
int *copiarPares(int *v,int tam);
void mostrarVector(int *v,int tam);

int main(){
    const int TAM=10;
    int vec[10], *pPares;
    cout<<"INGRESAR LOS NUMEROS "<<endl;
    cargarVector(vec,TAM);
    int cantPares=contarPares(vec,TAM);
    if(cantPares==0){
        cout<<"NO SE INGRESARON VALORES PARES"<<endl;
        return 0;
    }
    system("pause");
    system("cls");
    pPares=copiarPares(vec,TAM);
    if(pPares==nullptr){
        cout<<"SE PRODUJO UN ERROR DE ASIGNACION DE MEMORIA"<<endl;
        return -1;
    }
    cout<<"LOS NUMEROS PARES SON "<<endl;
    mostrarVector(pPares,cantPares);
    delete []pPares;
	system("pause");
	return 0;

}

void cargarVector(int *v,int tam){
    int i;
    for(i=0;i<tam;i++){
        cin>>v[i];
    }
}

int contarPares(int v[],int tam){
    int i, cantPares=0;
    for(i=0;i<tam;i++){
        if(v[i]%2==0){
            cantPares++;
        }
    }
    return cantPares;
}


int *copiarPares(int *v,int tam){
    int cant=contarPares(v,tam);
    int *pAux=new int[cant];
    if(pAux==nullptr){
        return nullptr;
    }
    int i, j=0;
    for(i=0;i<tam;i++){
        if(v[i]%2==0){
            pAux[j]=v[i];
            j++;
        }
    }
    return pAux;
}

void mostrarVector(int *v,int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }
}
