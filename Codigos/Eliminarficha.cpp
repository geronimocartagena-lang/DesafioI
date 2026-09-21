#include "Eliminarficha.h"
#include "Colocarficha.h"

void Eliminarficha(unsigned char* tablero, int posicion)
{
    // 6 = 110 = espacio vacio

    Colocarficha(tablero, posicion, 6);
}