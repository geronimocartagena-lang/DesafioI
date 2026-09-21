#include "Llenarespacios.h"
#include "Obtenerficha.h"
#include "Colocarficha.h"

#include <cstdlib>

void Llenarespacios(unsigned char* tablero,
                    int filas,
                    int columnas)
{
    int total = filas * columnas;

    for (int i = 0; i < total; i++)
    {
        if (Obtenerficha(tablero, i) == 6)
        {
            int ficha = rand() % 6;

            Colocarficha(tablero, i, ficha);
        }
    }
}