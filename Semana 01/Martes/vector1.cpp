///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;

void cargarVector(int *v,int tam);
void mostrarVector(int *v,int tam);


int main(){
    const int TAM=5;
    int vec[TAM]={0}, var, *pInt;
    /*cout<<vec<<endl;
    cout<<&vec[0]<<endl;
    cout<<&vec[1]<<endl;
    cout<<&vec[2]<<endl;*/
    /*pInt=&var;///pInt va a contener la dirección de la variable var
    pInt=vec;
    cout<<pInt[0]<<endl;
    pInt[1]=10;
    cout<<vec[1]<<endl;
    system("pause");*/
    //return 0;
    cargarVector(vec, TAM);///LLAMADA A LA FUNCION
    mostrarVector(vec, TAM);
    //cargarVector(pInt, TAM);///LLAMADA A LA FUNCION
    //mostrarVector(pInt, TAM);

    cout<<endl;
	system("pause");
	return 0;

}

void cargarVector(int v[],int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=i+1;
    }


}

void mostrarVector(int v[],int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}

