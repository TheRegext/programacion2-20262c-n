#include <iostream>
#include "funciones.h"

///Las autoridades de la carrera TUP estan realizando un analisis de los cursos virtuales de las distintas materias.

///Por cada una de las 20 materias de la carrera tiene la siguiente informacion:
///NUMERO DE MATERIA (entre 1 y 20) , NOMBRE, CANTIDAD DE ALUMNOS INSCRIPTOS, CANTIDAD DE PROFESORES.
/// 15  PROGRA2     20      3

///Ademas por cada ingreso de los estudiantes al aula virtual se registra los siguiente:
///LEGAJO - FECHA DE ACCESO (DIA Y MES) - NUMERO DE LA MATERIA A LA QUE INGRESO - CANTIDAD DE HORAS (NUMERO REAL).
///1234     12  04      5       3.5

///El fin de los datos se indica con un numero de legajo igual a 0.

///Hacer un programa en el marco de un proyecto de codeblock con un menu con opciones para cargar
///   los datos, mostrar cada punto y salir del programa.

///Se quiere responder las siguientes preguntas :
///a) Las materias que no tuvieron acceso de alumnos nunca.
///b) La materia que mas cantidad de horas registro de acceso de alumnos.
///c) Por cada materia y dia de marzo, la cantidad de accesos de alumnos a las aulas virtuales.

using namespace std;

int main()
{
    const int CANTMATERIAS=20;

    char nombreMateria[CANTMATERIAS][50]={};
    int nroMateria[CANTMATERIAS]={};
    int alumnos[CANTMATERIAS]={};
    int profesores[CANTMATERIAS]={};
    int cantAccesos[CANTMATERIAS]={};
    float horas[CANTMATERIAS]={};

    int accesosAlumnos[CANTMATERIAS][31]={};

    //LLAMADOS A LAS FUNCIONES
    pedirDatosMaterias(nroMateria, nombreMateria, alumnos, profesores,  CANTMATERIAS);
    pedirDatosAccesos(nroMateria, cantAccesos, horas, accesosAlumnos);
    materiasSinAccesos(nroMateria, nombreMateria, cantAccesos, CANTMATERIAS);
    materiasMasHorasAcceso(nroMateria, nombreMateria, horas, CANTMATERIAS);
    accesosPorDiaPorAlumno(nroMateria, nombreMateria, accesosAlumnos, CANTMATERIAS);


    return 0;
}
