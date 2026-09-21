#include "Mostrartablero.h"
#include "Obtenerficha.h"

#include <iostream>

using namespace std;

void Mostrartablero(unsigned char* tablero, int filas, int columnas)
{
    cout << "\n    ";

    for (int j = 0; j < columnas; j++)
    {
        cout << j + 1 << " ";
    }

    cout << "\n";

    for (int i = 0; i < filas; i++)
    {
        cout << i + 1 << "   ";

        for (int j = 0; j < columnas; j++)
        {
            int posicion = i * columnas + j;

            int ficha = Obtenerficha(tablero, posicion);

            if (ficha == 0)
                cout << "A ";
            else if (ficha == 1)
                cout << "B ";
            else if (ficha == 2)
                cout << "C ";
            else if (ficha == 3)
                cout << "D ";
            else if (ficha == 4)
                cout << "E ";
            else if (ficha == 5)
                cout << "F ";
            else
                cout << "- ";
        }

        cout << "\n";
    }
}