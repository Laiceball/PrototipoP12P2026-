#include "Equipo.h"

Equipo::Equipo(string nombre)
{
    this->nombre      = nombre;
    this->totalPuntos = 0;

    for (int i = 0; i < NUMERO_JORNADAS; i++)
        puntosPorJornada[i] = 0;
}

void Equipo::agregarPuntos(int jornada, int puntos)
{
    puntosPorJornada[jornada]  = puntos;
    totalPuntos               += puntos;
}

void Equipo::reiniciar()
{
    totalPuntos = 0;
    for (int i = 0; i < NUMERO_JORNADAS; i++)
        puntosPorJornada[i] = 0;
}

string Equipo::getNombre() const
{
    return nombre;
}

int Equipo::getTotalPuntos() const
{
    return totalPuntos;
}

int Equipo::getPuntosJornada(int jornada) const
{
    return puntosPorJornada[jornada];
}
