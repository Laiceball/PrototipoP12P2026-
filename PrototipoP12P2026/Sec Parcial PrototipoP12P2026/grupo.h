#ifndef GRUPO_H
#define GRUPO_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Equipo.h"

using namespace std;

#define NUMERO_EQUIPOS 6
#define GOLES_MAX      5
#define GOLES_MIN      0

class Grupo // la clase grupo nos sirvio para poder clasificar los equipos por grupos de manera aleatoria
{
private:
    string nombre;
    Equipo* equipos[NUMERO_EQUIPOS];

    int  aleatorio(int minimo, int maximo);
    void imprimirLinea();

public:
    Grupo(string nombre, string nombresEquipos[NUMERO_EQUIPOS]);
    ~Grupo();

    void  simular();
    float imprimir();

    string getNombre() const;
};

#endif
