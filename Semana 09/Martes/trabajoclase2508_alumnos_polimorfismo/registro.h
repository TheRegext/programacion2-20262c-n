#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

class Registro{
  public:
      virtual void cargar(int codigo)=0;
      virtual void mostrar()=0;
      virtual int getTamanio()=0;//DEVUELVE EL SIZEOF DEL OBJETO
      virtual Registro& operator = (Registro *) =0;//SOBRECARGA PARA ASIGNAR UN PUNTERO REGISTRO A UNA REFERENCIA A UN OBJETO DE
      virtual int getID()=0;
};

#endif // REGISTRO_H_INCLUDED
