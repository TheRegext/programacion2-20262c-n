#include <iostream>
using namespace std;

class Incrementador{
    private:
        int _valor; // El valor actual del incrementados
        int _cantidadIncrementos; // La cantidad de veces que incrementó
        int _magnitudIncremento; // De cuanto en cuanto incrementa x vez

    public:
        Incrementador(){
            _valor = 1;
            _magnitudIncremento = 1;
            _cantidadIncrementos = 0;
        }
        Incrementador(int valorInicial, int magnitudIncremento){
            _valor = valorInicial;
            if (magnitudIncremento <= 0){
                magnitudIncremento = 1;
            }
            _magnitudIncremento = magnitudIncremento;
            _cantidadIncrementos = 0;
        }
        ~Incrementador(){
          cout << "Muere el objeto. QEPD" << endl;
        }

        void incrementar(){
            _valor += _magnitudIncremento;
            _cantidadIncrementos++;
        }

        void mostrar(){
            cout << "-------------------------" << endl;
            cout << "Valor: " << _valor << endl;
            cout << "Cantidad incrementos: " << _cantidadIncrementos << endl;
            cout << "Magnitud de incremento: " << _magnitudIncremento << endl;
        }
        int getCantidadIncrementos(){
            return _cantidadIncrementos;
        }
};

int main(){
    Incrementador xp(0, -1000), vida;

    vida.incrementar();
    xp.incrementar();
    xp.incrementar();
    int cantIncrementosXp = xp.getCantidadIncrementos();

    cout << "Exp." << endl;
    cout << "Cant Incrementos: " << cantIncrementosXp << endl;

    cout << "Vida" << endl;
    vida.mostrar();







    return 0;
}
