#pragma once
#include "Menu.h"
#include "MovimientoManager.h"

class MovimientoMenu: public Menu
{
    public:
        MovimientoMenu();
        void run();

    protected:

    private:
        MovimientosManager _movimientoManager;
};

