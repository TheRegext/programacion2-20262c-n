#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

#include <string>

class Domicilio{
    private:
        std::string  _calle;
        std::string  _numero;
        std::string  _piso;
        std::string  _departamento;
        std::string  _localidad;
        std::string  _codigoPostal;
    public:
        Domicilio(){}
        Domicilio(std::string , std::string, std::string, std::string, std::string, std::string);
        void mostrar();
        void setCalle(std::string calle);
        void setNumero(std::string numero);
        void setPiso(std::string piso);
        void setDepartamento(std::string departamento);
        void setLocalidad(std::string localidad);
        void setCodigoPostal(std::string codigoPostal);
        std::string getCalle();
        std::string getNumero();
        std::string getPiso();
        std::string getDepartamento();
        std::string getLocalidad();
        std::string getCodigoPostal();
};

#endif // DOMICILIO_H_INCLUDED
