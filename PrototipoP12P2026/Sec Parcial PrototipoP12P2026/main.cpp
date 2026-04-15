#include "Torneo.h"

int main()
{
    srand(getpid());

    Torneo torneo;
    torneo.ejecutar(); //solo es necesario llamar a la clase torneo ya que contiene toda la logica

    return 0;
}
