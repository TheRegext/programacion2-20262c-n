#include "personaje.h"

void Personaje::setVida(int vida)
{
  if(vida < 0)
  {
    _vida = 0;
  }
  else
  {
    _vida = vida;
  }
}

Personaje::Personaje()
{
  _vida = 100;
  _fuerza = 30;
}

Personaje::Personaje(int vida, int fuerza)
{
  setVida(vida);
  setFuerza(fuerza);
}

/// getter setter
int Personaje::getVida()
{
  return _vida;
}

int Personaje::getFuerza()
{
  return _fuerza;
}

void Personaje::setFuerza(int fuerza)
{
  _fuerza = fuerza;
}

void Personaje::recibirDano(int dano)
{
  setVida(_vida - dano);
}

void Personaje::atacar(Personaje &objetivo)
{
  objetivo.recibirDano(_fuerza);
}
