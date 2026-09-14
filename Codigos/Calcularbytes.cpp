#include "Calcularbytes.h"

int Calcularbytes(int filas, int columnas)
{
    int cantidadBits = filas * columnas * 3;

    int bytes = (cantidadBits + 7) / 8;

    return bytes;
}