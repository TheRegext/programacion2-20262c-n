/*
    Programación II - Actividad: Incrementador
    Versión con PROGRAMACIÓN ESTRUCTURADA (funciones + parámetros por referencia)

    Idea: el "estado" del incrementador (valor actual, valor de incremento y
    cantidad de veces que se incrementó) son variables declaradas en main.
    Las funciones que necesitan MODIFICAR ese estado lo reciben POR REFERENCIA (&).
    Las que sólo necesitan LEERLO lo reciben por valor.
*/

#include <iostream>

using namespace std;

// ----------------------------------------------------------------------
// Operaciones del incrementador
// ----------------------------------------------------------------------

// Deja el incrementador listo para usar.
// valor, incremento y cantidadIncrementos se modifican -> van por referencia.
void inicializar(int &valor, int &incremento, int &cantidadIncrementos,
                 int valorInicial, int valorIncremento)
{
    valor = valorInicial;

    // Restricción: el valor nunca puede disminuir.
    // Por lo tanto el incremento tiene que ser positivo.
    if (valorIncremento <= 0)
    {
        cout << "El valor de incremento debe ser mayor a 0. Se usara 1." << endl;
        valorIncremento = 1;
    }
    incremento = valorIncremento;

    cantidadIncrementos = 0;
}

// Incrementa una vez.
// valor y cantidadIncrementos cambian -> por referencia.
// incremento sólo se lee -> por valor.
void incrementar(int &valor, int incremento, int &cantidadIncrementos)
{
    valor = valor + incremento;          // siempre aumenta la MISMA cantidad
    cantidadIncrementos = cantidadIncrementos + 1;  // siempre de uno en uno
}

// Incrementa "veces" veces reutilizando la función anterior.
void incrementarVariasVeces(int &valor, int incremento, int &cantidadIncrementos, int veces)
{
    for (int i = 0; i < veces; i++)
    {
        incrementar(valor, incremento, cantidadIncrementos);
    }
}

// Funciones de consulta: no modifican nada, reciben por valor.
int obtenerValor(int valor)
{
    return valor;
}

int obtenerCantidadIncrementos(int cantidadIncrementos)
{
    return cantidadIncrementos;
}

void mostrarEstado(int valor, int incremento, int cantidadIncrementos)
{
    cout << "-----------------------------------------" << endl;
    cout << "Valor actual        : " << valor << endl;
    cout << "Valor de incremento : " << incremento << endl;
    cout << "Veces incrementado  : " << cantidadIncrementos << endl;
    cout << "-----------------------------------------" << endl;
}

void mostrarMenu()
{
    cout << endl;
    cout << "1 - Incrementar una vez" << endl;
    cout << "2 - Incrementar N veces" << endl;
    cout << "3 - Mostrar estado" << endl;
    cout << "0 - Salir" << endl;
    cout << "Opcion: ";
}

// ----------------------------------------------------------------------
// Programa principal
// ----------------------------------------------------------------------
int main()
{
    // El estado vive acá, en main.
    int valor;
    int incremento;
    int cantidadIncrementos;

    int valorInicial, valorIncremento;

    cout << "Valor inicial del incrementador: ";
    cin >> valorInicial;
    cout << "Valor de incremento: ";
    cin >> valorIncremento;

    // Se pasan por referencia: la función carga las variables de main.
    inicializar(valor, incremento, cantidadIncrementos, valorInicial, valorIncremento);

    mostrarEstado(valor, incremento, cantidadIncrementos);

    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            incrementar(valor, incremento, cantidadIncrementos);
            cout << "Nuevo valor: " << obtenerValor(valor)
                 << " (incremento numero " << obtenerCantidadIncrementos(cantidadIncrementos) << ")" << endl;

            incremento = -25;
            break;

        case 2:
        {
            int veces;
            cout << "Cuantas veces? ";
            cin >> veces;
            if (veces > 0)
            {
                incrementarVariasVeces(valor, incremento, cantidadIncrementos, veces);
                cout << "Nuevo valor: " << obtenerValor(valor) << endl;
            }
            else
            {
                cout << "La cantidad de veces debe ser mayor a 0." << endl;
            }
            break;
        }

        case 3:
            mostrarEstado(valor, incremento, cantidadIncrementos);
            break;

        case 0:
            cout << "Fin del programa." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);

    return 0;
}
