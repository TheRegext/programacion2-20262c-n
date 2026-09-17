#include <iostream>
#include <cstring>
#include "clsAlumno.h"

using namespace std;

/**
Crear un programa con un menú con las siguientes opciones:
1-Agregar un registro al archivo.
2-Listar los registros del archivo.
EXTRA:
Hacer una opción que reciba una posición y liste el registro de esa posición (el primer registro de mi archivo ocupa la posición 0).

TAREA:
Agregar una opción al menú que me permita listar un alumno que tenga un legajo que se ingresa por teclado.

DIFICIL:
Listar a todos los alumnos que tengan una fecha de nacimiento anterior a una fecha que se ingresa por teclado.
*/

void agregarAlumno();
void listarAlumnos();
Alumno leerPosicion(int pos);
void listarAlumnoPosicion();
void listarAlumnosModificada();

int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1 - AGREGAR ALUMNO"<<endl;
        cout<<"2 - LISTAR ALUMNOS"<<endl;
        cout<<"3 - LISTAR ALUMNO POR POSICION"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"=============="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregarAlumno();
                break;
            case 2:
                listarAlumnosModificada();
                break;
            case 3:
                listarAlumnoPosicion();
                break;
            case 0:
                return 0;
        }
        system("pause");
    }
    return 0;
}


Alumno leerPosicion(int pos){
    Alumno obj;
    int cont = 0;
    FILE *p = fopen("Alumnos.dat","rb");
    if(p == nullptr){
        obj.setLegajo(0);
        return obj;
    }
    while(cont <= pos and fread(&obj, sizeof obj, 1, p) == 1){
        cont++;
    }
    fclose(p);
    if(cont <= pos){
        obj.setLegajo(0);
        return obj;
    }
    return obj;
}

void listarAlumnoPosicion(){
    int pos;
    cout<<"INGRESE LA POSICION DEL ALUMNO EN EL ARCHIVO: ";
    cin>>pos;
    if(pos<0){
        cout<<"LA POSICION NO PUEDE SER NEGATIVA"<<endl;
        return;
    }
    Alumno obj = leerPosicion(pos);
    if(obj.getLegajo() == 0){
        return;
    }
    obj.Mostrar();
}

void agregarAlumno(){
    Alumno obj;
    obj.Cargar();
    FILE *p;
    p = fopen("Alumnos.dat", "ab");
    if(p == nullptr){
        cout<<"ERROR DE APERTURA DEL ARCHIVO"<<endl;
        return;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void listarAlumnos(){
    Alumno obj;
    FILE *p;
    p = fopen("Alumnos.dat", "rb");
    if(p == nullptr){
        cout<<"ERROR DE APERTURA DEL ARCHIVO"<<endl;
        return;
    }
    while(fread(&obj, sizeof obj, 1, p)){
        obj.Mostrar();
        cout<<"==================="<<endl;
    }
    fclose(p);
}

void listarAlumnosModificada(){
    Alumno obj;
    int pos = 0;
    obj = leerPosicion(pos);
    pos++;
    while(obj.getLegajo() != 0){
        obj.Mostrar();
        obj = leerPosicion(pos);
        pos++;
        cout<<"==================="<<endl;
    }
}

int mainViejo()
{
//    Alumno obj[2];
    Alumno obj;
//    obj.Cargar();
    FILE *pArchivo;
    ///ABRO EL ARCHIVO EN EL MODO QUE YO NECESITO. CREA UN VINCULO CON EL ARCHIVO EN EL PUNTERO FILE.
    pArchivo = fopen("alumnos.dat", "rb");
    /**
    MODOS DE APERTURA:
    r (read): ABRE EL ARCHIVO EN MODO LECTURA. SI NO EXISTE EL ARCHIVO, NO LO CREA.
    a (append): ABRE EL ARCHIVO EN MODO ESCRITURA. SI NO EXISTE EL ARCHIVO, LO CREA. SIEMPRE ESCRIBE AL FINAL DEL ARCHIVO.
    w (write): ABRE EL ARCHIVO EN MODO ESCRITURA. SIEMPRE CREA UN ARCHIVO VACIO.
    b (binary): INDICA QUE TRABAJAMOS CON ARCHIVOS BINARIOS.
    */
    if(pArchivo == nullptr){
        cout<<"ERROR DE APERTURA DEL ARCHIVO"<<endl;
        return -1;
    }
//    fwrite(&obj, sizeof obj, 1, pArchivo);
    /**
    Primer argumento: dirección de memoria donde está la información que quiero copiar a mi archivo.
    Segundo argumento: cantidad de bytes que quiero copiar a mi archivo (peso de un objeto/tipo de datos).
    Tercer argumento: cantidad de registros que quiero copiar a mi archivo.
    Cuarto argumento: vínculo con mi archivo (puntero FILE sobre el que hice la apertura).
    */
///    fread(&obj, sizeof (Alumno), 1, pArchivo)<<endl;
    /**
    Primer argumento: dirección de memoria donde quiero copiar la información leo de mi archivo.
    Segundo argumento: cantidad de bytes que quiero leer de mi archivo (peso de un objeto/tipo de datos).
    Tercer argumento: cantidad de registros que quiero leer de mi archivo.
    Cuarto argumento: vínculo con mi archivo (puntero FILE sobre el que hice la apertura).
    */
    while(fread(&obj, sizeof obj, 1, pArchivo) == 1){
        cout<<"========================"<<endl;
        obj.Mostrar();
    }
    fclose(pArchivo);
    return 0;
}

