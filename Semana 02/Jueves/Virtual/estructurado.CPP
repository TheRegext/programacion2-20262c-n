#include <iostream>

using namespace std;

void atacar(int &vida, int dano){
  vida -= dano;
}

int main()
{
  int pj_vida, pj_fuerza, en_vida, en_fuerza;
  /// establecer la vida del personaje
  pj_vida = 100;
  en_vida = 100;
  
  en_fuerza = 30; 
  pj_fuerza = 30;
  cout << "La vida del personaje es: " << pj_vida << endl;
  
  /// atacan al personje (resta la vida al personje)
  atacar(pj_vida, en_fuerza);
  cout << "Atacan al personaje!" << endl;
  
  /// mostramos la vida el personaje
  cout << "La vida del personaje es: " << pj_vida << endl;

  return 0;
}
