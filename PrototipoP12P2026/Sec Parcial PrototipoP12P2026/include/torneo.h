#ifndef TORNEO_H
#define TORNEO_H

#include "Grupo.h"

#define NUMERO_GRUPOS 3

class Torneo
{
private:
    Grupo* grupos[NUMERO_GRUPOS];

    void compararGrupos(float promedios[NUMERO_GRUPOS]); // inicializamos la funcion de comparar grupos, implemnetando los promedios, recorriendo NUMERO_GRUPOS

public:
    Torneo();
    ~Torneo();

    void ejecutar();
};

#endif
