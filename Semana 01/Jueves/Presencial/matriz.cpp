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

int main(){
    int matriz[3][4] = {};

    cargarVentas(matriz);
    informeVentas(matriz);
    // Agregar cuántos productos no se vendieron en ninguna sucursal.

    return 0;
}
