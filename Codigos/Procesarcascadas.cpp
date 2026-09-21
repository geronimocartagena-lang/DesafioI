#include "Procesarcascadas.h"
#include "Detectarcombinaciones.h"
#include "Reorganizartablero.h"
#include "Llenarespacios.h"

int Procesarcascadas(unsigned char* tablero,
                     int filas,
                     int columnas)
{
    int cascadas = 0;

    while (true)
    {
        int eliminadas =
            Detectarcombinaciones(
                tablero,
                filas,
                columnas
                );

        if (eliminadas == 0)
        {
            break;
        }

        cascadas++;

        Reorganizartablero(
            tablero,
            filas,
            columnas
            );

        Llenarespacios(
            tablero,
            filas,
            columnas
            );
    }

    return cascadas;
}