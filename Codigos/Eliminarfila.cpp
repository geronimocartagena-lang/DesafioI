#include "Eliminarfila.h"
#include "Calcularbytes.h"
#include "Creartablero.h"
#include "Obtenerficha.h"
#include "Colocarficha.h"

unsigned char* Eliminarfila(unsigned char* tablero,
                            int& filas,
                            int columnas,
                            int posicion,
                            int& bytes)
{
    if (filas <= 1)
    {
        return tablero;
    }

    int nuevasFilas = filas - 1;

    int nuevosBytes =
        Calcularbytes(nuevasFilas, columnas);

    int bitsValidos =
        nuevasFilas * columnas * 3;

    int bitsMemoria =
        bytes * 8;

    bool reducirMemoria =
        bitsValidos * 100 < bitsMemoria * 65;

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
            int filaAnterior = i;

            if (i >= posicion)
            {
                filaAnterior++;
            }

            int posicionNueva =
                i * columnas + j;

            int posicionAnterior =
                filaAnterior * columnas + j;

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

        filas = nuevasFilas;
        bytes = nuevosBytes;

        return nuevo;
    }

    for (int i = 0; i < nuevasFilas * columnas; i++)
    {
        int ficha =
            Obtenerficha(nuevo, i);

        Colocarficha(tablero, i, ficha);
    }

    delete[] nuevo;

    filas = nuevasFilas;

    return tablero;
}