#include <iostream>

using namespace std;

/**
  PascalCase
*/
class Personaje{
private:
  int _vida;
  int _fuerza;
  
public:
  /// getter setter
  int getVida(){
    return _vida;
  }
  
  void setVida(int vida){
    _vida = vida;
  }
  
  int getFuerza(){
    return _fuerza;
  }
  
  void setFuerza(int fuerza){
    _fuerza = fuerza;  
  }  
};

int main()
{
  Personaje pj;
  
  pj.setVida(100);
  pj.setFuerza(30);
    
  cout << "La vida del personaje es: " << pj.getVida() << endl;
  
  return 0;
}
