#include "Obtenerficha.h"

int Obtenerficha(unsigned char* tablero, int posicion)
{
    int bitInicial = posicion * 3;

    int byte = bitInicial / 8;
    int desplazamiento = bitInicial % 8;

    if (desplazamiento <= 5)
    {
        int valor = (tablero[byte] >> desplazamiento) & 7;

        return valor;
    }

    int bitsPrimerByte = 8 - desplazamiento;
    int bitsSegundoByte = 3 - bitsPrimerByte;

    int mascara1 = (1 << bitsPrimerByte) - 1;

    int parte1 =
        (tablero[byte] >> desplazamiento) & mascara1;

    int mascara2 = (1 << bitsSegundoByte) - 1;

    int parte2 =
        tablero[byte + 1] & mascara2;

    int valor =
        parte1 | (parte2 << bitsPrimerByte);

    return valor;
}