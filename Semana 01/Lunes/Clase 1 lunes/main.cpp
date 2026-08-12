#include <iostream>

using namespace std;

/**
Hacer una funcion que me permita cargar valores manualmente en un vector de 10 elementos.

Hacer una funcion que cargue los siguientes 10 valores pares a partir de un valor que se le pasa como parametro.

Hacer una funcion para mostrar los valores de mi vector.
*/

void cambiaValor(int *valor){
    *valor = 10;
    cout<<"DIRECCION DE VALOR: "<<&valor<<endl;
    cout<<"VALOR ALMACENA: "<<valor<<endl;
}

void cargarVector(int vec[], int tam){
    for(int i=0; i<tam; i++){
        cout<<"INGRESE UN VALOR PARA LA POSICION "<<i<<": ";
        cin>>vec[i];
    }
}

void asignarPares(int vec[], int tam, int valor){
    if(valor % 2 != 0){
        valor++;//valor += 1; valor = valor + 1;
    }
    for(int i=0; i<tam; i++){
        vec[i]=valor+2*i;
    }
}

void mostrarVector(int vec[], int tam);

int main()
{
    const int var=10;
    int nombreVector[var]{};
    //cargarVector(nombreVector, var);
    asignarPares(nombreVector, var, 10);
    mostrarVector(nombreVector, var);
    cout<<nombreVector<<endl;
    return 0;
    int num;
    num = 50;
    cout<<"Direccion de num del main: "<<&num<<endl;
    cout<<"Num del main: "<<num<<endl;
    cambiaValor(&num);
    cout<<"Num del main: "<<num<<endl;
    return 0;
}

void mostrarVector(int *vec, int tam){
    cout<<vec<<endl;
    for(int i=0; i<tam; i++){
        cout<<i<<": "<<vec[i]<<endl;
    }
}
