#include <iostream>

#include "Calcularbytes.h"
#include "Creartablero.h"

using namespace std;

int main()
{
    int filas;
    int columnas;
    int bytes;

    cout << "Ingrese la cantidad de filas: ";
    cin >> filas;

    cout << "Ingrese la cantidad de columnas: ";
    cin >> columnas;

    bytes = Calcularbytes(filas, columnas);

    unsigned char* tablero =
        Creartablero(filas, columnas, bytes);

    cout << "\nCantidad de filas: " << filas << endl;
    cout << "Cantidad de columnas: " << columnas << endl;
    cout << "Bytes necesarios: " << bytes << endl;

    delete[] tablero;

    return 0;
}