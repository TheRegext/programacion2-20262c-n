#include <iostream>
#include <vector>
using namespace std;

/***
/// crear una programa donde se ingresen las notas un curso
/// y muestre al final todas las notas aprobadas.
/// el fin de la carga es cuando una nota es igual a -1

*/

int main(int argc, char *argv[]) {
	vector<int> aprobados;
   int nota;
   
   cout << "Ingrese nota: ";
   cin >> nota;
   
   while(nota != -1){
      if(nota >= 6){
         aprobados.push_back(nota);
      }
      
      cout << "Ingrese nota: ";
      cin >> nota;   
   }
   
   if(!aprobados.empty()){
      cout << "Notas aprobadas:" << endl;
      for(const int&nota : aprobados){
         cout << nota << endl;
      }
   }
   else{
      cout << "No hay notas aprobadas." << endl;
   }
   
	return 0;
}

