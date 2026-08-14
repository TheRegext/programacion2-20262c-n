#include <iostream>
using namespace std;

int main(){
    const int TAM = 4'000'000;
    int *lista = nullptr;

    // Pedimos memoria
    lista = new int[TAM];

    if (lista == nullptr){
        cout << "No hay memoria" << endl;
        return 1;
    }

    lista[0] = 1000;
    cout << lista[0] << endl;

    // Liberamos memoria
    delete [] lista;

    return 0;
}
