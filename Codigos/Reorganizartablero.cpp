#include "Reorganizartablero.h"
#include "Obtenerficha.h"
#include "Colocarficha.h"

void Reorganizartablero(unsigned char* tablero,
                        int filas,
                        int columnas)
{
    for (int columna = 0; columna < columnas; columna++)
    {
        int destino = filas - 1;

        for (int fila = filas - 1; fila >= 0; fila--)
        {
            int posicion =
                fila * columnas + columna;

            int ficha =
                Obtenerficha(tablero, posicion);

            if (ficha != 6)
            {
                int nuevaPosicion =
                    destino * columnas + columna;

                Colocarficha(
                    tablero,
                    nuevaPosicion,
                    ficha
                    );

                destino--;
            }
        }

        while (destino >= 0)
        {
            int posicion =
                destino * columnas + columna;

            Colocarficha(tablero, posicion, 6);

            destino--;
        }
    }
}