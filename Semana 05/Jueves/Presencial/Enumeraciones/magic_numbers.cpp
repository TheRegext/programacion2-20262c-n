#include <iostream>
using namespace std;

float CalcularDescuento(int formaPago){
    switch(formaPago){
        case 1: //Efectivo
            return 0.10f;
        case 2:
            return 0.05f;
        case 3:
            return 0.0f;
        case 4:
            return 0.15f;
        case 5: // Cheque
            return 0.0f;
        default:
            return 0.0f;
    }
}

int main(){
    float pu, cant, importe;
    int formaPago;

    cout << "Precio unitario: $ ";
    cin >> pu;

    cout << "Cantidad: ";
    cin >> cant;

    importe = pu * cant;

    cout << "Forma pago (1 - Efectivo, 2 - Tarjeta Credito, 3 - Tarjeta Debito, 4 - Qr, 5 - Cheque): ";
    cin >> formaPago;

    importe = importe * (1 - CalcularDescuento(formaPago));

    cout << "Importe a pagar: " << importe << endl;

    return 0;
}
