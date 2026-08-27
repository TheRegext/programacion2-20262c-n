///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring>

using namespace std;


class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(int d=0,int m=0, int a=0);
    void Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }
    void Mostrar();

    void setDia(int d);
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void MostrarThis(){cout<<this;}
    ~Fecha(){
        cout<<"SE MURIO EL OBJETO :-("<<endl;
    }
};

void Fecha::setDia(int d){
        if(d>=1 && d<=31) dia=d;
        else dia=0;
}

///

void Fecha::Mostrar(){
        cout<<"DIA "<<dia<<endl;
        cout<<"MES "<<mes<<endl;
        cout<<"ANIO "<<anio<<endl;
}



///this: es un puntero que contiene la dirección del objeto que llama al método.
///this EXISTE SOLO DENTRO DE LA CLASE, dentro de cada método.
///se dice que es un puntero oculto, poruque no es impresindible hacerlo visible.
///Podemos usarlo cuando nos resuelva algún problema-

Fecha::Fecha(int d,int mes, int a){
    ///dia=d;
    this->setDia(d);
    this->mes=mes;
    anio=a;
}


int main(){
    /*Fecha hoy(1,1,1),ayer;

    hoy.Mostrar();
    cout<<endl;

    ayer.Mostrar();
    cout<<endl;

    ayer.setDia(25);
    ayer.setMes(8);
    ayer.setAnio(2026);

    ayer.Mostrar();
    cout<<endl;

    cout<<"&hoy "<<&hoy<<endl;
    hoy.MostrarThis();*/

    Fecha obj,vFecha[5];
    obj.Mostrar();
    cout<<endl;
	system("pause");
	return 0;

}



