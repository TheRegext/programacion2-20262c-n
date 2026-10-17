#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

class Archivo{
  private:
    int _tamanioRegistro;
    char *pRegistro;
    char _nombreArchivo[30];
    int _cantRegistros;
    int _estado;
  public:
    Archivo(const char *nombre, int tam){///
      strcpy(_nombreArchivo,nombre);
      _tamanioRegistro=tam;
      pRegistro=new char[_tamanioRegistro];
      }
    ~Archivo(){///
           delete [](Registro *) pRegistro;
      }

      int leerRegistro(Registro &,int );
      int buscarRegistro(Registro &, int );
      int grabarRegistro( Registro & , int);//

      const char *getNombreArchivo(){return _nombreArchivo;}//
      bool listarArchivo(Registro &aux);//

      int cantidadRegistros();///
  };

//leerRegistro(Registro &var, int pos)
//LEE EL REGISTRO UBICADO EN LA POSICION pos, Y LO ESCRIBE EN LA REFERENCIA var
//DEVUELVE 1 SI LEYO; 0 SI NO LEYO; -1 SI EL ARCHIVO NO EXISTE
int  Archivo::leerRegistro(Registro &var, int pos){
        FILE *pF;
        pF=fopen(_nombreArchivo,"rb");
        if(pF==nullptr) return -1;
        fseek(pF,pos*_tamanioRegistro,0);
        int leyo=fread(pRegistro,_tamanioRegistro,1,pF);
        var=(Registro *)pRegistro;
        fclose(pF);
        return leyo;
       }

//grabarRegistro( Registro &dato, int pos).
//ESCRIBE EN EL DISCO LOS DATOS EXISTENTES EN LA REFERENCIA dato
//SI EL VALOR DE POS ES -1 AGREGA UN REGISTRO NUEVO
// SI EL VALOR ES 0 O POSITIVO SOBREESCRIBE EL REGISTRO UBICADO EN ESA POSICION
//DEVUELVE 1 SI GRABO; -1 SI NO EXISTE; 0 SI NO PUDO GRABAR
int Archivo::grabarRegistro( Registro &dato, int pos){
    int grabo;
    FILE *pF;
    if(pos==-1){
        pF=fopen(_nombreArchivo,"ab");
        if(pF==nullptr) return -1;
    }
    else{
        if((pF=fopen(_nombreArchivo,"rb+"))==nullptr) return -1;
        fseek(pF,pos*_tamanioRegistro,0);
    }
    grabo=fwrite(&dato,_tamanioRegistro,1,pF);
    fclose(pF);
    return grabo;
}


//LISTA EL ARCHIVO COMPLETO
bool Archivo::listarArchivo(Registro &aux){
       FILE *pF;
       if(cantidadRegistros()==0)return false;
       if(!(pF=fopen(_nombreArchivo,"rb"))){
         return false;
       }
      while(fread(pRegistro,_tamanioRegistro,1,pF)){
        aux=(Registro *)pRegistro;
        aux.mostrar();
        cout<<endl;
       }
       fclose(pF);
       return true;
    }


//buscarRegistro(Registro &obj)
//COMPARA EL CAMPO CLAVE DEL REGISTRO RECIBIDO COMO PARAMETRO
//CON LOS REGISTROS DEL ARCHIVO.
//SI YA EXISTE EL VALOR DEL CAMPO CLAVE DEVUELVE LA POSICION QUE OCUPA EN EL ARCHIVO
//SI NO LO ENCUENTRA DEVUELVE -1, Y SI NO PUDO ABRIR EL ARCHIVO DEVUELVE -2

int Archivo::buscarRegistro(Registro &obj, int id){
       FILE *pF=fopen(_nombreArchivo,"rb");
       if(pF==nullptr){
         return -2;
       }
       while(fread(pRegistro,_tamanioRegistro,1,pF)){
            obj=(Registro *)pRegistro;
            if(id==obj.getID()){
              int pos=(ftell(pF)-_tamanioRegistro)/_tamanioRegistro;
              fclose(pF);
              return pos;
            }
         };
       fclose(pF);
       return -1;
      }

int Archivo::cantidadRegistros(){
    FILE *pF;
    pF=fopen(_nombreArchivo,"rb");
    if(pF==nullptr) return 0;
    fseek(pF,0,2);
    int cantByte=ftell(pF);
    fclose(pF);
    return cantByte/_tamanioRegistro;

}


#endif // ARCHIVO_H_INCLUDED
