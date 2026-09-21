#include "Agregarcolumna.h"
#include "Calcularbytes.h"
#include "Creartablero.h"
#include "Obtenerficha.h"
#include "Colocarficha.h"

#include <cstdlib>

unsigned char* Agregarcolumna(unsigned char* tablero,
                              int filas,
                              int& columnas,
                              int posicion,
                              int& bytes)
{
    int nuevasColumnas = columnas + 1;

    int nuevosBytes =
        Calcularbytes(filas, nuevasColumnas);

    unsigned char* nuevo =
        Creartablero(
            filas,
            nuevasColumnas,
            nuevosBytes
            );

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < nuevasColumnas; j++)
        {
            int nuevaPosicion =
                i * nuevasColumnas + j;

            if (j == posicion)
            {
                Colocarficha(
                    nuevo,
                    nuevaPosicion,
                    rand() % 6
                    );
            }
            else
            {
                int columnaAnterior = j;

                if (j > posicion)
                {
                    columnaAnterior--;
                }

                int posicionAnterior =
                    i * columnas + columnaAnterior;

                int ficha =
                    Obtenerficha(
                        tablero,
                        posicionAnterior
                        );

                Colocarficha(
                    nuevo,
                    nuevaPosicion,
                    ficha
                    );
            }
        }
    }

    delete[] tablero;

    columnas = nuevasColumnas;
    bytes = nuevosBytes;

    return nuevo;
}