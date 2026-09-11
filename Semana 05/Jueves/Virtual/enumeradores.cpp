#include <iostream>
using namespace std;

enum class Dia
{
  LUNES,
  MARTES,
  MIERCOLES,
  JUEVES,
  VIERNES,
  SABADO,
  DOMINGO
};

enum class Color
{
  NEGRO,
  ROJO,
  AZUL
};

enum class Semaforo
{
  ROJO,
  AMARILLO,
  VERDE
};

enum class Mascota
{
  GATO,
  PERRO,
  CERDO
};

enum class Color2
{
  ROJO = 3,
  AMARILLO,
  VERDE

};

string mostrarColor(Color color)
{
  switch(color)
  {
  case Color::ROJO:
    return "Rojo";
    break;
  case Color::VERDE:
    return "Verde";
    break;
  case Color::AMARILLO:
    return "Amarillo";
    break;
  default:
    return "S/D";
  }

}


int main()
{
  //Mascota miMascota = ROJO;
  Color camisa = Color::ROJO;


  cout << mostrarColor(Color::AMARILLO) << endl;

  /*
      Dia hoy;

      hoy = JUEVES;

      cout << hoy << endl;
  */
  return 0;
}
