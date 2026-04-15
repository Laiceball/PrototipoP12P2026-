#include "Grupo.h"

Grupo::Grupo(string nombre, string nombresEquipos[NUMERO_EQUIPOS])
{
    this->nombre = nombre;

    for (int i = 0; i < NUMERO_EQUIPOS; i++)
        equipos[i] = new Equipo(nombresEquipos[i]);
}

Grupo::~Grupo()
{
    for (int i = 0; i < NUMERO_EQUIPOS; i++)
        delete equipos[i];
}

int Grupo::aleatorio(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void Grupo::simular()
{
    // Reiniciar puntos de jornadas anteriores
    for (int i = 0; i < NUMERO_EQUIPOS; i++)
        equipos[i]->reiniciar();

    int emparejamiento[NUMERO_EQUIPOS] = {0, 1, 2, 3, 4, 5};

    for (int j = 0; j < NUMERO_JORNADAS; j++)
    {
        // Barajar emparejamientos
        for (int i = NUMERO_EQUIPOS - 1; i > 0; i--)
        {
            int r   = aleatorio(0, i);
            int tmp = emparejamiento[i];
            emparejamiento[i] = emparejamiento[r];
            emparejamiento[r] = tmp;
        }

        // Jugar 3 partidos por jornada
        for (int p = 0; p < 3; p++)
        {
            int local     = emparejamiento[p * 2];
            int visitante = emparejamiento[p * 2 + 1];

            int golesLocal     = aleatorio(GOLES_MIN, GOLES_MAX);
            int golesVisitante = aleatorio(GOLES_MIN, GOLES_MAX);

            if (golesLocal > golesVisitante)
            {
                equipos[local]->agregarPuntos(j, 3);
                equipos[visitante]->agregarPuntos(j, 0);
            }
            else if (golesLocal == golesVisitante)
            {
                equipos[local]->agregarPuntos(j, 1);
                equipos[visitante]->agregarPuntos(j, 1);
            }
            else
            {
                equipos[local]->agregarPuntos(j, 0);
                equipos[visitante]->agregarPuntos(j, 3);
            }
        }
    }
}

void Grupo::imprimirLinea()
{
    cout << "+---------------------";
    for (int x = 0; x < NUMERO_JORNADAS + 1; x++)
        cout << "+--------";
    cout << "+" << endl;
}

float Grupo::imprimir()
{
    int    puntosMayor = equipos[0]->getTotalPuntos();
    int    puntosMenor = equipos[0]->getTotalPuntos();
    string equipoMayor = equipos[0]->getNombre();
    string equipoMenor = equipos[0]->getNombre();
    float  totalPuntos = 0;

    cout << nombre << endl;
    cout << "(J1-J5) Puntos por Jornada  |  PTS = Puntos acumulados" << endl;
    imprimirLinea();

    cout << setw(22) << left << "| Equipo";
    for (int j = 0; j < NUMERO_JORNADAS; j++)
        cout << "| J" << j + 1 << "    ";
    cout << "| PTS    |" << endl;

    imprimirLinea();

    for (int i = 0; i < NUMERO_EQUIPOS; i++)
    {
        cout << "| " << setw(20) << left << equipos[i]->getNombre();

        for (int j = 0; j < NUMERO_JORNADAS; j++)
            cout << "| " << setw(6) << equipos[i]->getPuntosJornada(j) << " ";

        int pts = equipos[i]->getTotalPuntos();
        cout << "| " << setw(6) << pts << " |" << endl;

        totalPuntos += pts;

        if (pts > puntosMayor)
        {
            puntosMayor = pts;
            equipoMayor = equipos[i]->getNombre();
        }
        if (pts < puntosMenor)
        {
            puntosMenor = pts;
            equipoMenor = equipos[i]->getNombre();
        }

        imprimirLinea();
    }

    float promedio = totalPuntos / NUMERO_EQUIPOS;

    cout << " Lider       : " << setw(20) << equipoMayor << " Puntos: " << puntosMayor << endl;
    cout << " Ultimo      : " << setw(20) << equipoMenor << " Puntos: " << puntosMenor << endl;
    cout << " Prom. grupo : " << fixed << setprecision(2) << promedio << " pts" << endl << endl;

    return promedio;
}

string Grupo::getNombre() const
{
    return nombre;
}
