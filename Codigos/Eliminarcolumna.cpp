#include "Eliminarcolumna.h"
#include "Calcularbytes.h"
#include "Creartablero.h"
#include "Obtenerficha.h"
#include "Colocarficha.h"

unsigned char* Eliminarcolumna(unsigned char* tablero,
                               int filas,
                               int& columnas,
                               int posicion,
                               int& bytes)
{
    if (columnas <= 1)
    {
        return tablero;
    }

    int nuevasColumnas = columnas - 1;

    int nuevosBytes =
        Calcularbytes(filas, nuevasColumnas);

    int bitsValidos =
        filas * nuevasColumnas * 3;

    int bitsMemoria =
        bytes * 8;

    bool reducirMemoria =
        bitsValidos * 100 < bitsMemoria * 65;

    int bytesTemporales;

    unsigned char* nuevo =
        Creartablero(
            filas,
            nuevasColumnas,
            bytesTemporales
            );

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < nuevasColumnas; j++)
        {
            int columnaAnterior = j;

            if (j >= posicion)
            {
                columnaAnterior++;
            }

            int posicionNueva =
                i * nuevasColumnas + j;

            int posicionAnterior =
                i * columnas + columnaAnterior;

            int ficha =
                Obtenerficha(
                    tablero,
                    posicionAnterior
                    );

            Colocarficha(
                nuevo,
                posicionNueva,
                ficha
                );
        }
    }

    if (reducirMemoria)
    {
        delete[] tablero;

        columnas = nuevasColumnas;
        bytes = nuevosBytes;

        return nuevo;
    }

    for (int i = 0; i < filas * nuevasColumnas; i++)
    {
        int ficha =
            Obtenerficha(nuevo, i);

        Colocarficha(tablero, i, ficha);
    }

    delete[] nuevo;

    columnas = nuevasColumnas;

    return tablero;
}