///Fecha:
///Autor:
///Comentario:

#include <iostream>

using namespace std;


///Hacer un programa para mostrar la recaudación diaria en cada una de las sucursales de un comercio.
///El comercio tiene 4 sucursales, identificadas del 1 al 4.
///Por cada venta se dispone del importe, el día (1 a 7), y el número de sucursal.
///Para finalizar el ingreso de datos se ingresa un número de sucursal igual a 0
void cargarDatos(float m[7][4]);
void mostrarRecaudacion(float m[7][4]);
void mostrarRecaudacionPorSuc(float m[7][4]);

int main(){
    float mat[7][4]={0};
    cargarDatos(mat);
    system("cls");
    ///mostrarRecaudacion(mat);
    mostrarRecaudacionPorSuc(mat);

	system("pause");
	return 0;

}


void cargarDatos(float m[7][4]){
    int dia, sucursal;
    float importe;
    cout<<"INGRESAR SUCURSAL ";
    cin>>sucursal;
    while(sucursal!=0){
        cout<<"INGRESAR DIA ";
        cin>>dia;
        cout<<"INGRESAR IMPORTE ";
        cin>>importe;
        m[dia-1][sucursal-1]+=importe;
        cout<<"INGRESAR SUCURSAL ";
        cin>>sucursal;
    }
}


void mostrarRecaudacion(float m[7][4]){
    int i, j;
    for(i=0;i<7;i++){
        cout<<"DIA "<<i+1<<endl;
        for(j=0;j<4;j++){
            cout<<"SUCURSAL "<<j+1<<" IMPORTE "<<m[i][j]<<endl;
        }
    }
}

void mostrarRecaudacionPorSuc(float m[7][4]){
    int i, j;
    for(i=0;i<4;i++){
        cout<<"SUCURSAL "<<i+1<<endl;
        for(j=0;j<7;j++){
            cout<<"DIA "<<j+1<<" IMPORTE "<<m[i][j]<<endl;
        }
    }
}
