#include "Agregarfila.h"
#include "Calcularbytes.h"
#include "Creartablero.h"
#include "Obtenerficha.h"
#include "Colocarficha.h"

#include <cstdlib>

unsigned char* Agregarfila(unsigned char* tablero,
                           int& filas,
                           int columnas,
                           int posicion,
                           int& bytes)
{
    int nuevasFilas = filas + 1;

    int nuevosBytes =
        Calcularbytes(nuevasFilas, columnas);

    unsigned char* nuevo =
        Creartablero(
            nuevasFilas,
            columnas,
            nuevosBytes
            );

    for (int i = 0; i < nuevasFilas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            int nuevaPosicion =
                i * columnas + j;

            if (i == posicion)
            {
                Colocarficha(
                    nuevo,
                    nuevaPosicion,
                    rand() % 6
                    );
            }
            else
            {
                int filaAnterior = i;

                if (i > posicion)
                {
                    filaAnterior--;
                }

                int posicionAnterior =
                    filaAnterior * columnas + j;

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

    filas = nuevasFilas;
    bytes = nuevosBytes;

    return nuevo;
}