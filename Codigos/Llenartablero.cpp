#include "Llenartablero.h"
#include "Colocarficha.h"

#include <cstdlib>

void Llenartablero(unsigned char* tablero, int filas, int columnas)
{
    int total = filas * columnas;

    for (int i = 0; i < total; i++)
    {
        int ficha = rand() % 6;

        Colocarficha(tablero, i, ficha);
    }
}