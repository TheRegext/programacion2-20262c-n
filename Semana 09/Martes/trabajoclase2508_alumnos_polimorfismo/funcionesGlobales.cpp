///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
#include <cstring>

using namespace std;

#include "socio.h"
#include "libro.h"
#include "prestamo.h"
#include "funcionesGlobales.h"
#include "informes.h"
void generarArchivos() {
    /// Listas de datos reales para la carga automática
    Libro vLibros[10];
   // Prestamo vPrestamos[10];
   // Socio vSocios[10];
    int cantPrestamos=10;

    string nombresLibros[10] = {
        "Don Quijote de la Mancha", "Cien anos de soledad", "El principito",
        "Ficciones", "Pedro Paramo", "La ciudad y los perros",
        "Rayuela", "El aleph", "La casa de los espiritus", "Crónica de una muerte anunciada"
    };

    string autoresLibros[10] = {
        "Miguel de Cervantes", "Gabriel Garcia Marquez", "Antoine de Saint-Exupery",
        "Jorge Luis Borges", "Juan Rulfo", "Mario Vargas Llosa",
        "Julio Cortazar", "Jorge Luis Borges", "Isabel Allende", "Gabriel Garcia Marquez"
    };

    string nombresSocios[10] = {
        "Juan", "Maria", "Carlos", "Ana", "Luis", "Laura", "Diego", "Sofia", "Javier", "Elena"
    };

    string apellidosSocios[10] = {
        "Gonzalez", "Rodriguez", "Lopez", "Martinez", "Gomez", "Perez", "Sanchez", "Fernandez", "Romero", "Diaz"
    };

    /// 1. Cargar el vector de Libros con datos reales
    for (int i = 0; i < 10; i++) {
        vLibros[i].setIsbn(1000 + i); // ISBNs del 1000 al 1009
        vLibros[i].setNombre(nombresLibros[i].c_str());
        vLibros[i].setAutor(autoresLibros[i].c_str());
        vLibros[i].setFechaPublicacion(Fecha(1, 1, 1950 + (i * 5))); // Fechas de publicación variadas
        vLibros[i].setCantEjemplares(3 + i);
        vLibros[i].setEstado(true);
    }

    /// 2. Cargar el vector de Socios con datos reales
/*    for (int i = 0; i < 10; i++) {
        vSocios[i].setId(100 + i); // IDs del 100 al 109
        vSocios[i].setDni(40000000 + (i * 1234)); // DNIs ficticios pero con formato real
        vSocios[i].setNombre(nombresSocios[i].c_str());
        vSocios[i].setApellido(apellidosSocios[i].c_str());

        // Genera emails realistas basados en sus nombres
        string emailMuestra = nombresSocios[i] + "." + apellidosSocios[i] + "@email.com";
        vSocios[i].setEmail(emailMuestra.c_str());

        vSocios[i].setNumTelefono(15400000 + i);
        vSocios[i].setFechaNacimiento(Fecha(15, 6, 1985 + i));
        vSocios[i].setEstado(true);
    }

    /// 3. Cargar el vector de Prestamos respetando las relaciones (ISBN e ID existentes)
    for (int i = 0; i < cantPrestamos; i++) {
        vPrestamos[i].setNumLibro(vLibros[rand() % 10].getIsbn());   /// Toma un ISBN válido del vector en forma aleatoria
        vPrestamos[i].setIdSocio(vSocios[rand() % 10].getId());     /// Toma un ID válido del vector en forma aleatoria
        vPrestamos[i].setPrestamo(Fecha((rand()%31)+1,(rand()%12)+1, 2026));
        if(i%2==0)vPrestamos[i].setDevolucion(Fecha((rand()%31)+1,(rand()%12)+1, 2026));
        vPrestamos[i].setEstado(true);
    }
*/
    ///generar archivo de libros
    FILE *pArchi;
    pArchi=fopen("libros.dat", "wb");
    if(pArchi==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    fwrite(vLibros,sizeof(Libro), 10, pArchi);
    fclose(pArchi);
    ///generar archivo de socios
  /*  pArchi=fopen("socios.dat", "wb");
    if(pArchi==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    fwrite(vSocios,sizeof(Socio), 10, pArchi);
    fclose(pArchi);
    ///generar archivo de prestamos
    pArchi=fopen("prestamos.dat", "wb");
    if(pArchi==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    fwrite(vPrestamos,sizeof(Prestamo), 10, pArchi);
    fclose(pArchi);*/
}


/*void cargarVectores(Libro *vLibros, Prestamo *vPrestamos, Socio *vSocios, int cantPrestamos) {
    /// Listas de datos reales para la carga automática

    string nombresLibros[10] = {
        "Don Quijote de la Mancha", "Cien anos de soledad", "El principito",
        "Ficciones", "Pedro Paramo", "La ciudad y los perros",
        "Rayuela", "El aleph", "La casa de los espiritus", "Crónica de una muerte anunciada"
    };

    string autoresLibros[10] = {
        "Miguel de Cervantes", "Gabriel Garcia Marquez", "Antoine de Saint-Exupery",
        "Jorge Luis Borges", "Juan Rulfo", "Mario Vargas Llosa",
        "Julio Cortazar", "Jorge Luis Borges", "Isabel Allende", "Gabriel Garcia Marquez"
    };

    string nombresSocios[10] = {
        "Juan", "Maria", "Carlos", "Ana", "Luis", "Laura", "Diego", "Sofia", "Javier", "Elena"
    };

    string apellidosSocios[10] = {
        "Gonzalez", "Rodriguez", "Lopez", "Martinez", "Gomez", "Perez", "Sanchez", "Fernandez", "Romero", "Diaz"
    };

    /// 1. Cargar el vector de Libros con datos reales
    for (int i = 0; i < 10; i++) {
        vLibros[i].setIsbn(1000 + i); // ISBNs del 1000 al 1009
        vLibros[i].setNombre(nombresLibros[i]);
        vLibros[i].setAutor(autoresLibros[i]);
        vLibros[i].setFechaPublicacion(Fecha(1, 1, 1950 + (i * 5))); // Fechas de publicación variadas
        vLibros[i].setCantEjemplares(3 + i);
    }

    /// 2. Cargar el vector de Socios con datos reales
    for (int i = 0; i < 10; i++) {
        vSocios[i].setId(100 + i); // IDs del 100 al 109
        vSocios[i].setDni(40000000 + (i * 1234)); // DNIs ficticios pero con formato real
        vSocios[i].setNombre(nombresSocios[i]);
        vSocios[i].setApellido(apellidosSocios[i]);

        // Genera emails realistas basados en sus nombres
        string emailMuestra = nombresSocios[i] + "." + apellidosSocios[i] + "@email.com";
        vSocios[i].setEmail(emailMuestra);

        vSocios[i].setNumTelefono(15400000 + i);
        vSocios[i].setFechaNacimiento(Fecha(15, 6, 1985 + i));
    }

    /// 3. Cargar el vector de Prestamos respetando las relaciones (ISBN e ID existentes)
    for (int i = 0; i < cantPrestamos; i++) {
        vPrestamos[i].setNumLibro(vLibros[rand() % 10].getIsbn());   /// Toma un ISBN válido del vector en forma aleatoria
        vPrestamos[i].setIdSocio(vSocios[rand() % 10].getId());     /// Toma un ID válido del vector en forma aleatoria
        vPrestamos[i].setPrestamo(Fecha(1, 9, 2026));
        vPrestamos[i].setDevolucion(Fecha(15, 9, 2026));
    }
    vPrestamos[cantPrestamos-2].setNumLibro(vLibros[0].getIsbn());
    vPrestamos[cantPrestamos-2].setDevolucion(Fecha(0, 0, 0));

    cout<<"Vectores cargados"<<endl<<endl;
}

void mostrarVectores(Libro *vLibros, Prestamo *vPrestamos, Socio *vSocios, int cantPrestamos){
    cout<<endl<<"***LIBROS***"<<endl;
    cout<<"***************************"<<endl;
    for(int i=0;i<10;i++){
        vLibros[i].mostrar();
    }

    cout<<endl;
    system("pause");
    cout<<endl<<"***SOCIOS***"<<endl;
    cout<<"***************************"<<endl;
    for(int i=0;i<10;i++){
        vSocios[i].mostrar();
    }
    system("pause");

    cout<<endl<<"***PRESTAMOS***"<<endl;
    cout<<"***************************"<<endl;

    cout<<"ISBN "<<"\t"<<"SOCIO "<<endl;

    for(int i=0;i<cantPrestamos;i++){
        vPrestamos[i].mostrar(1);
    }

    cout<<endl;
}
*/

void menuInformes(){
    Informes obj;
    int opc;
    while(true){
        system("cls");
        cout<<"*********************MENU INFORMES***********************"<<endl;
        cout<<"1. INFORMAR CANTIDAD DE LIBROS POR CANTIDAD DE EJEMPLARES"<<endl;
        cout<<"2. INFORMAR LA CANTIDAD DE LIBROS ELIMINADOS"<<endl;
        cout<<"3. INFORMAR EL LIBRO CON MAS CANTIDAD DE EJEMPLARES DISPONIBLES"<<endl;
        cout<<"4. INFORMAR EL LIBRO CON MENOS CANTIDAD DE EJEMPLARES DISPONIBLES"<<endl;
        cout<<"5. LISTAR LOS LIBROS ORDENADOS POR NOMBRE ALFABETICAMENTE"<<endl;
        cout<<"6. INFORMAR EL LIBRO MAS ANTIGUO"<<endl;
        cout<<"0. VOLVER AL MENU ANTERIOR"<<endl;
        cout<<"***********************************************************"<<endl;
        cout<<"INGRESAR OPCION ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1: obj.punto1();
                break;
        case 5: obj.punto5();
                break;

        case 0: return;
                break;


        }
        system("pause");
    }
}














