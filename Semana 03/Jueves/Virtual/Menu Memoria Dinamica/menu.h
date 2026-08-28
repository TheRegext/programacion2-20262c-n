#pragma once
#include <string>

class Menu{
public:
  Menu(int cantidadItems); /// constructor -> cuando se crea
  void setItem(int indice, std::string texto);
  void dibujarMenu();
  int obtenerRespuesta();
  ~Menu(); /// destructor -> cuando se destruye
  
private:
  std::string* _vOpciones;
  int _cantItems;
};
