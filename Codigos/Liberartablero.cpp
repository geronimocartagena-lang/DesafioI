#include "Liberartablero.h"

void Liberartablero(unsigned char*& tablero)
{
    delete[] tablero;

    tablero = nullptr;
}