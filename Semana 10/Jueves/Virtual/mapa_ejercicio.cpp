#include <iostream>
#include <map>
#include <vector>
using namespace std;

/// crear una programa donde se ingresen el legajo y las notas 
/// de un curso 
/// Mostrar para cada alumno las notas que se cargaron
/// el fin de la carga es cuando una legajo es igual a "0000"
/// 3449
/// 3260
/// El legajo es alfanumerico de 4 caracteres.


/***
   Key: legajo - string
   Value: notas - vector <int>
*/

int main(int argc, char *argv[]) {
   map<string, vector<int>> notas;
   
   string legajo;
   int nota;
   
   cout << "Ingrese legajo: ";
   cin >> legajo;
   
   while(legajo != "0000"){
      cout << "Ingrese nota: ";
      cin >> nota;
      
      notas[legajo].push_back(nota);
      
      cout << "Ingrese legajo: ";
      cin >> legajo;
   }
   
   for(const auto &par : notas){
      cout << par.first << ": " << endl;
      
      for(const auto &nota : par.second){
         cout << " >" << nota << endl;
      }
   }
	
	return 0;
}

