#include "Detectarcombinaciones.h"
#include "Obtenerficha.h"
#include "Colocarficha.h"

int Detectarcombinaciones(unsigned char* tablero,
                          int filas,
                          int columnas)
{
    int cantidad = 0;

    // Horizontales

    for (int fila = 0; fila < filas; fila++)
    {
        int columna = 0;

        while (columna < columnas)
        {
            int posicion =
                fila * columnas + columna;

            int ficha =
                Obtenerficha(tablero, posicion);

            if (ficha == 6)
            {
                columna++;
            }
            else
            {
                int inicio = columna;

                while (columna < columnas)
                {
                    int posicionActual =
                        fila * columnas + columna;

                    int actual =
                        Obtenerficha(tablero, posicionActual);

                    if (actual != ficha)
                    {
                        break;
                    }

                    columna++;
                }

                int total = columna - inicio;

                if (total >= 3)
                {
                    for (int j = inicio; j < columna; j++)
                    {
                        int pos =
                            fila * columnas + j;

                        if (Obtenerficha(tablero, pos) != 6)
                        {
                            Colocarficha(tablero, pos, 6);
                            cantidad++;
                        }
                    }
                }
            }
        }
    }

    // Verticales

    for (int columna = 0; columna < columnas; columna++)
    {
        int fila = 0;

        while (fila < filas)
        {
            int posicion =
                fila * columnas + columna;

            int ficha =
                Obtenerficha(tablero, posicion);

            if (ficha == 6)
            {
                fila++;
            }
            else
            {
                int inicio = fila;

                while (fila < filas)
                {
                    int posicionActual =
                        fila * columnas + columna;

                    int actual =
                        Obtenerficha(tablero, posicionActual);

                    if (actual != ficha)
                    {
                        break;
                    }

                    fila++;
                }

                int total = fila - inicio;

                if (total >= 3)
                {
                    for (int i = inicio; i < fila; i++)
                    {
                        int pos =
                            i * columnas + columna;

                        if (Obtenerficha(tablero, pos) != 6)
                        {
                            Colocarficha(tablero, pos, 6);
                            cantidad++;
                        }
                    }
                }
            }
        }
    }

    return cantidad;
}