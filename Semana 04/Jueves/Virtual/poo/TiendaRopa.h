#include "tienda.h"

/**
  base      private       protected      public
  public    inaccesible   protected      public 
  protected inaccesible   protected      protected
  private   inaccesible   private        private
*/




class TiendaRopa: private Tienda{
public:
  TiendaRopa();
  void cargarArticulos();
};
