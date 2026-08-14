#include <iostream>
using namespace std;

bool EsIngresoValido(int sucursal, int producto){
    if (sucursal < 1 || sucursal > 3){
        return false;
    }
    if (producto < 1 || producto > 4){
        return false;
    }
    return true;
}

void cargarVentas(int matriz[3][4]){
    int sucursal, producto;

    // Cargar datos
    cout << "Número de sucursal: ";
    cin >> sucursal;

    while (sucursal != 0){
        cout << "Código de producto: ";
        cin >> producto;

        if (!EsIngresoValido(sucursal, producto)){
            cout << "No se puede procesar el registro." << endl;
        }
        else{
            matriz[sucursal-1][producto-1]++;
        }

        cout << "--------------------" << endl;
        cout << "Número de sucursal: ";
        cin >> sucursal;
    }
}

void informeVentas(int matriz[3][4]){
    int i, j;
    for (i=0; i<3; i++){
        cout << "Sucursal " << (i+1) << ": " << endl;
        cout << "--------------------------" << endl;
        for(j=0; j<4; j++){
            cout << "Producto " << (j+1) << ": ";
            cout << matriz[i][j] << " unidades" << endl;
        }
        cout << endl;
    }
}

void informeProductosNoVendidos(int matriz[3][4]){
    bool huboVenta;
    //int cantVentasProducto;
    int cantProductosSinVentas = 0, i, j;

    for(j=0; j<4; j++){
        huboVenta = false;
        //cantVentasProducto = 0;

        for(i=0; i<3; i++){
            if (matriz[i][j] > 0){
                huboVenta = true;
                //cantVentasProducto++;
            }
        }

        if (!huboVenta){
            cantProductosSinVentas++;
        }

        /*if (cantVentasProducto == 0){
            cantProductosSinVentas++;
        }*/

    }

    cout << "Cantidad de productos sin ventas: " << cantProductosSinVentas << endl;

}

int main(){
    int matriz[3][4] = {};

    cargarVentas(matriz);
    informeVentas(matriz);
    informeProductosNoVendidos(matriz);


    return 0;
}
