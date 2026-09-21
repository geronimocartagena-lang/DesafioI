#include "Calcularbytes.h"

int Calcularbytes(int filas, int columnas)
{
    //Fichas que tenemos filo * colum y 3 bits que puede utilizar
    int cantidadBits = filas * columnas * 3;

    //convertir bit a byte
    int bytes = (cantidadBits + 7) / 8;

    return bytes;
}