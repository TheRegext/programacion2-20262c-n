#include <iostream>
#include "personaje.h"

using namespace std;

/***
  Hacer que el personaje tenga una defensa... 
  Ahora cuando le hacen da¤o, la defensa proboca que sea menor el da¤o
*/

int main()
{
  Personaje pj, en(50, 15);
  
  /// pj.setVida(1000);
  /*
  pj.setVida(100);
  pj.setFuerza(30);
  
  en.setVida(100);
  en.setFuerza(30);
    */
  cout << "La vida del personaje es: " << pj.getVida() << endl;
  
  for(int i=0; i<10; i++){
    cout << "Atacan al personaje!" << endl;
    en.atacar(pj); 
    pj.atacar(en);
    cout << "La vida del personaje es: " << pj.getVida() << endl;  
  }
  
  
  return 0;
}
