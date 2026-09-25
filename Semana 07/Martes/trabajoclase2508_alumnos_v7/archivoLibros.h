#ifndef ARCHIVOLIBROS_H_INCLUDED
#define ARCHIVOLIBROS_H_INCLUDED

///Agregar un método que devuelva la cantidad de registos del archivo.
///Analizar qué uso/s se le podría dar a ese método en el actual proyecto

class ArchivoLibro{
    char _nombreArchivo[20];
public:
    ArchivoLibro(const char *nombreArchivo="libros.dat");
    bool agregarRegistroLibro();
    bool mostrarRegistroLibro(int estado = 0);
    int buscarRegistroLibro(int isbn);
    bool borradoLogicoRegistro();
    Libro leerRegistro(int pos);
    bool sobreEscribirRegistro(Libro reg,int pos);
    bool modificarCantidad();
    int contarRegistros();
};
#endif // ARCHIVOLIBROS_H_INCLUDED
