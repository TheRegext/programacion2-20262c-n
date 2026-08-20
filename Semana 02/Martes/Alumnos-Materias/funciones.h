#pragma once

void pedirDatosMaterias(int *numeroMateria, char nombreMateria[][50], int *alumnos, int *profesores, int cantMaterias);
void pedirDatosAccesos(int *numeroMateria, int *cantAccesos, float *horas, int accesosAlumnos[][31]);
void materiasSinAccesos(int *numeroMateria, char nombreMateria[][50], int *cantidadAccesos,int cantMaterias);
void materiasMasHorasAcceso(int *numeroMateria, char nombreMateria[][50], float *horasMateria, int cantMaterias);
void accesosPorDiaPorAlumno(int *numeroMateria, char nombreMateria[][50], int accesosMarzo[][31], int cantMaterias);


