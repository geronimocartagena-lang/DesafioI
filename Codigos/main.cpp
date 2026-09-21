#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Creartablero.h"
#include "Liberartablero.h"
#include "Obtenerficha.h"
#include "Llenartablero.h"
#include "Mostrartablero.h"
#include "Mostrarbinario.h"
#include "Eliminarficha.h"
#include "Procesarcascadas.h"
#include "Agregarfila.h"
#include "Eliminarfila.h"
#include "Agregarcolumna.h"
#include "Eliminarcolumna.h"
#include "Mostrarmenu.h"

using namespace std;

int main()
{
    srand(time(0));

    int filas;
    int columnas;

    cout << "==============================\n";
    cout << "         SWEET CRUSH\n";
    cout << "==============================\n";

    cout << "\nIngrese filas: ";
    cin >> filas;

    cout << "Ingrese columnas: ";
    cin >> columnas;

    if (filas <= 0 || columnas <= 0)
    {
        cout << "Dimensiones invalidas.\n";
        return 0;
    }

    int bytes;

    unsigned char* tablero =
        Creartablero(
            filas,
            columnas,
            bytes
            );

    Llenartablero(
        tablero,
        filas,
        columnas
        );

    int eliminacionesUsuario = 0;
    int fichasEliminadas = 0;
    int combinaciones = 0;
    int cascadas = 0;
    int puntuacion = 0;

    int opcion;

    do
    {
        Mostrartablero(
            tablero,
            filas,
            columnas
            );

        Mostrarmenu();

        cin >> opcion;

        if (opcion == 1)
        {
            int fila;
            int columna;

            cout << "\nFila: ";
            cin >> fila;

            cout << "Columna: ";
            cin >> columna;

            fila--;
            columna--;

            if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas)
            {
                int posicion =
                    fila * columnas + columna;

                if (Obtenerficha(tablero, posicion) != 6)
                {
                    Eliminarficha(
                        tablero,
                        posicion
                        );

                    eliminacionesUsuario++;
                    fichasEliminadas++;
                    puntuacion += 10;

                    int nuevasCascadas =
                        Procesarcascadas(
                            tablero,
                            filas,
                            columnas
                            );

                    cascadas += nuevasCascadas;

                    puntuacion +=
                        nuevasCascadas * 50;

                    cout << "\nMovimiento realizado.\n";
                    cout << "Cascadas: "
                         << nuevasCascadas << "\n";
                }
                else
                {
                    cout << "\nLa posicion esta vacia.\n";
                }
            }
            else
            {
                cout << "\nPosicion invalida.\n";
            }
        }

        else if (opcion == 2)
        {
            int posicion;

            cout << "\nPosicion de la nueva fila (1-"
                 << filas + 1 << "): ";

            cin >> posicion;

            posicion--;

            if (posicion >= 0 && posicion <= filas)
            {
                tablero =
                    Agregarfila(
                        tablero,
                        filas,
                        columnas,
                        posicion,
                        bytes
                        );

                Procesarcascadas(
                    tablero,
                    filas,
                    columnas
                    );

                cout << "\nFila agregada.\n";
            }
            else
            {
                cout << "\nPosicion invalida.\n";
            }
        }

        else if (opcion == 3)
        {
            if (filas <= 1)
            {
                cout << "\nNo puede eliminar la ultima fila.\n";
            }
            else
            {
                int posicion;

                cout << "\nFila a eliminar (1-"
                     << filas << "): ";

                cin >> posicion;

                posicion--;

                if (posicion >= 0 && posicion < filas)
                {
                    tablero =
                        Eliminarfila(
                            tablero,
                            filas,
                            columnas,
                            posicion,
                            bytes
                            );

                    Procesarcascadas(
                        tablero,
                        filas,
                        columnas
                        );

                    cout << "\nFila eliminada.\n";
                }
                else
                {
                    cout << "\nPosicion invalida.\n";
                }
            }
        }

        else if (opcion == 4)
        {
            int posicion;

            cout << "\nPosicion de la nueva columna (1-"
                 << columnas + 1 << "): ";

            cin >> posicion;

            posicion--;

            if (posicion >= 0 && posicion <= columnas)
            {
                tablero =
                    Agregarcolumna(
                        tablero,
                        filas,
                        columnas,
                        posicion,
                        bytes
                        );

                Procesarcascadas(
                    tablero,
                    filas,
                    columnas
                    );

                cout << "\nColumna agregada.\n";
            }
            else
            {
                cout << "\nPosicion invalida.\n";
            }
        }

        else if (opcion == 5)
        {
            if (columnas <= 1)
            {
                cout << "\nNo puede eliminar la ultima columna.\n";
            }
            else
            {
                int posicion;

                cout << "\nColumna a eliminar (1-"
                     << columnas << "): ";

                cin >> posicion;

                posicion--;

                if (posicion >= 0 && posicion < columnas)
                {
                    tablero =
                        Eliminarcolumna(
                            tablero,
                            filas,
                            columnas,
                            posicion,
                            bytes
                            );

                    Procesarcascadas(
                        tablero,
                        filas,
                        columnas
                        );

                    cout << "\nColumna eliminada.\n";
                }
                else
                {
                    cout << "\nPosicion invalida.\n";
                }
            }
        }

        else if (opcion == 6)
        {
            Mostrartablero(
                tablero,
                filas,
                columnas
                );
        }

        else if (opcion == 7)
        {
            Mostrarbinario(
                tablero,
                filas,
                columnas
                );
        }

        else if (opcion == 8)
        {
            cout << "\n==============================\n";
            cout << "         ESTADISTICAS\n";
            cout << "==============================\n";

            cout << "Tablero final: "
                 << filas << " x "
                 << columnas << "\n";

            cout << "Eliminaciones del usuario: "
                 << eliminacionesUsuario << "\n";

            cout << "Fichas eliminadas: "
                 << fichasEliminadas << "\n";

            cout << "Combinaciones: "
                 << combinaciones << "\n";

            cout << "Cascadas: "
                 << cascadas << "\n";

            cout << "Puntuacion: "
                 << puntuacion << "\n";
        }

        else
        {
            cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 8);

    Liberartablero(tablero);

    return 0;
}