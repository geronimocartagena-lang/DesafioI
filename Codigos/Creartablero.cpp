#include "Creartablero.h"
#include "Calcularbytes.h"

unsigned char* Creartablero(int filas, int columnas, int& bytes)
{
    bytes = Calcularbytes(filas, columnas);

    unsigned char* tablero = new unsigned char[bytes];

    for (int i = 0; i < bytes; i++)
    {
        tablero[i] = 0;
    }

    return tablero;
}