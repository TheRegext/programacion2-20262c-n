#pragma once
#include "Fecha.h"

class FechaHora: public Fecha
{
    public:
        FechaHora();
        FechaHora(int d, int m, int a, int h, int min);

        int getHora();
        int getMinutos();

        void setHora(int hora);
        void setMinutos(int minutos);

    protected:

    private:
        int _hora;
        int _minutos;
};

