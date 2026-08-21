#pragma once

class Personaje{
private: /// solo los metodos de la clase pueden ver la parte privada
  int _vida;
  int _fuerza;
  
  void setVida(int vida);  
public:
  /// constructor
  Personaje();
  Personaje(int vida, int fuerza);
  
  /// getter setter
  int getVida();
  int getFuerza();
  
  void setFuerza(int fuerza);
  
  void recibirDano(int dano);
  void atacar(Personaje &objetivo);
};
