#ifndef CLSALUMNO_H_INCLUDED
#define CLSALUMNO_H_INCLUDED

class Alumno{
    private:
        int legajo;///4
        char nombreApellido[50];///50
        int dni;///4
        int diaNacimiento;///4
        int mesNacimiento;///4
        int anioNacimiento;///4
        char domicilio[50];///50
    public:
        Alumno(int l=1, const char *nA="S/N", int d=0, int dN=1, int mN=1, int aN=1900, const char *dom="S/D");
        void Cargar();
        void Mostrar();
        void setLegajo(int l);
        void setNombreApellido(const char *nA);
        int getLegajo();
        const char *getNombreApellido();
        ~Alumno();
};

#endif // CLSALUMNO_H_INCLUDED
