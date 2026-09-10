#include <iostream>
#include <string>
using namespace std;

enum class FormasPago{
    Efectivo = 1,
    TarjetaCredito = 2,
    Debito = 3,
    Qr = 4,
    Cheque = 5
};


string obtenerNombreFormaPago(FormasPago fp){
    switch(fp){
        case FormasPago::Efectivo:
            return "Efectivo";
        case FormasPago::Cheque:
            return "Cheque";
        case FormasPago::Qr:
            return "QR";
        case FormasPago::TarjetaCredito:
            return "Tarjeta de Crédito";
        case FormasPago::Debito:
            return "Tarjeta de Débito";
        default:
            return "";
    }
}

float CalcularDescuento(FormasPago fp){
    switch(fp){
        case FormasPago::Efectivo:
            return 0.10f;
        case FormasPago::TarjetaCredito:
            return 0.05f;
        case FormasPago::Debito:
            return 0.0f;
        case FormasPago::Qr:
            return 0.15f;
        case FormasPago::Cheque:
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



    importe = importe * (1 - CalcularDescuento((FormasPago) formaPago));

    cout << "Importe a pagar: " << importe << endl;

    return 0;
}
