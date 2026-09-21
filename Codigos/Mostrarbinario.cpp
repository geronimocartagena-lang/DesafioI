#include "Mostrarbinario.h"
#include "Calcularbytes.h"

#include <iostream>

using namespace std;

void Mostrarbinario(unsigned char* tablero, int filas, int columnas)
{
    int bytes = Calcularbytes(filas, columnas);

    int bitsValidos = filas * columnas * 3;

    cout << "\nBits del tablero:\n";

    int contador = 0;

    for (int i = 0; i < bytes; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (contador < bitsValidos)
            {
                int bit = (tablero[i] >> j) & 1;

                cout << bit;

                contador++;
            }
        }

        cout << " ";
    }

    cout << "\n";
}