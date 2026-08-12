///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring>
using namespace std;

///void cambiarValor(int x);///paso por valor
void cambiarValor(int &x);///paso por referencia
void cambiarValor(char x[]);///paso por referencia
void cartel(int valor=1);

///SOBRECARGA DE FUNCIONES: funciones distintas con un mismo nombre
///Se diferencia por los parámetros que reciben
///una referencia es una alias de una variable
int main(){
    /*int var=0;
    char palabra[5];
    //cout<<"DIRECCION DE var "<<&var<<endl;
    cambiarValor(var);
    cout<<var<<endl;
    cambiarValor(palabra);
    cout<<palabra<<endl;*/
    int x=2;
    cartel();
    cartel(x);
	system("pause");
	return 0;

}

/*void cambiarValor(int x){
    cout<<x<<endl;
    x=10;
}*/

void cambiarValor(int &x){
    //cout<<"DIRECCION DE x "<<&x<<endl;
    //cout<<x<<endl;
    x=10;
}

void cambiarValor(char *x){
    strcpy(x,"HOLA");
}


void cartel(int valor){
    if(valor==1){
        cout<<"HOLA"<<endl;
    }
    else{
        cout<<"CHAU"<<endl;
    }

}
