#include <iostream>
#include "menu.h"

using namespace std;

Menu::Menu(int cantidadItems){
  _vOpciones = new string[cantidadItems];
  
  if(_vOpciones == nullptr){
    cout << "No se pudo pedir memoria... " << endl;
    exit(-100);  
  }
  
  _cantItems = cantidadItems;
}

void Menu::setItem(int indice, std::string texto){
  if(indice>0 && indice<=_cantItems){
    _vOpciones[indice - 1] = texto;
  }
}

void Menu::dibujarMenu(){
  cout << "----- MENU -----" << endl;
  for(int i=0; i<_cantItems; i++){
    cout << i+1 << ". " << _vOpciones[i] << endl; 
  }
  cout << "0. Salir" << endl;
  cout << "----------------" << endl;
}

int Menu::obtenerRespuesta(){
  int opcion;
  
  do{
    cout << "Opcion: ";
    cin>> opcion;
    
    if(opcion<0 || opcion >_cantItems){
      cout << "opcion incorrecta..." <<endl;    
    }
  }while(opcion<0 || opcion >_cantItems);
  
  return opcion;  
}

Menu::~Menu(){
  delete [] _vOpciones;
}

