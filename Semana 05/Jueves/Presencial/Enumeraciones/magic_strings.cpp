#include <iostream>
#include <string>
using namespace std;

float CalcularDescuento(string formaPago){
    if (formaPago == "E"){
        return 0.10f;
    } else if (formaPago == "TC"){
        return 0.05f;
    } else if (formaPago == "TD"){
        return 0.0f;
    } else if (formaPago == "Q"){
        return 0.15f;
    } else if (formaPago == "C"){
        return 0.0f;
    }
    return 0.0f;
}

int main(){
    float pu, cant, importe;
    string formaPago;

    cout << "Precio unitario: $ ";
    cin >> pu;

    cout << "Cantidad: ";
    cin >> cant;

    importe = pu * cant;

    cout << "Forma pago (Efectivo - E, TarjetaCredito - TC, TarjetaDebito - TD, Qr - Q, Cheque - C): ";
    cin >> formaPago;

    importe = importe * (1 - CalcularDescuento(formaPago));

    cout << "Importe a pagar: " << importe << endl;

    return 0;
}
