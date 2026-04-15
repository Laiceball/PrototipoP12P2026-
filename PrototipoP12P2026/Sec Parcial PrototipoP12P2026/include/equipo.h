#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>

using namespace std;

#define NUMERO_JORNADAS 5

class Equipo
{
private:
    string nombre;
    int    puntosPorJornada[NUMERO_JORNADAS];
    int    totalPuntos;

public:
    Equipo(string nombre);

    void agregarPuntos(int jornada, int puntos);
    void reiniciar();

    string getNombre()           const;
    int    getTotalPuntos()      const;
    int    getPuntosJornada(int jornada) const;
};

#endif
