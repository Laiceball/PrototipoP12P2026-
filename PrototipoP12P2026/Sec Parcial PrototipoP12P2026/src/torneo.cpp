#include "Torneo.h"

Torneo::Torneo()
{
    string nombresGrupoA[NUMERO_EQUIPOS] = {
        "Inter de Milan", "AC Milan", "Juventus",
        "Napoli", "Como 1907", "AS Roma"
    };
    string nombresGrupoB[NUMERO_EQUIPOS] = {
        "Atalanta", "Lazio", "Fiorentina",
        "Bologna", "Torino", "Udinese"
    };
    string nombresGrupoC[NUMERO_EQUIPOS] = {
        "Monza", "Genoa", "Parma",
        "Cagliari", "Empoli", "Hellas Verona"
    };

    grupos[0] = new Grupo("GRUPO A", nombresGrupoA);
    grupos[1] = new Grupo("GRUPO B", nombresGrupoB);
    grupos[2] = new Grupo("GRUPO C", nombresGrupoC);
}

Torneo::~Torneo()
{
    for (int i = 0; i < NUMERO_GRUPOS; i++)
        delete grupos[i];
}

void Torneo::ejecutar()
{
    char opcion;
    bool repetir = true;

    do
    {
        system("cls");

        cout << "*** Torneo Serie A - Fase de Grupos ***" << endl << endl;

        float promedios[NUMERO_GRUPOS];

        for (int i = 0; i < NUMERO_GRUPOS; i++)
        {
            grupos[i]->simular();
            promedios[i] = grupos[i]->imprimir();
        }

        compararGrupos(promedios);

        cout << endl << "Desea otra simulacion (s/n)? ";
        cin >> opcion;

        if (opcion == 'n')
            repetir = false;

    } while (repetir);
}

void Torneo::compararGrupos(float promedios[NUMERO_GRUPOS])
{
    int indiceMayor = 0;

    for (int i = 1; i < NUMERO_GRUPOS; i++)
    {
        if (promedios[i] > promedios[indiceMayor])
            indiceMayor = i;
    }

    // Verificar empate entre grupos
    int empates = 0;
    for (int i = 0; i < NUMERO_GRUPOS; i++)
        if (promedios[i] == promedios[indiceMayor])
            empates++;

    if (empates > 1)
    {
        cout << " Algunos grupos tienen el mismo promedio de puntos." << endl;
    }
    else
    {
        cout << " El grupo con mejor promedio es: "
             << grupos[indiceMayor]->getNombre()
             << "  Promedio: " << fixed << setprecision(2)
             << promedios[indiceMayor] << endl;
    }
}
