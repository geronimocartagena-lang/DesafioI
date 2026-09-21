#include "Colocarficha.h"

void Colocarficha(unsigned char* tablero, int posicion, int valor)
{
    int bitInicial = posicion * 3;

    int byte = bitInicial / 8;
    int desplazamiento = bitInicial % 8;

    valor = valor & 7;

    if (desplazamiento <= 5)
    {
        int mascara = 7 << desplazamiento;

        tablero[byte] =
            (tablero[byte] & ~mascara) |
            (valor << desplazamiento);

        return;
    }

    int bitsPrimerByte = 8 - desplazamiento;
    int bitsSegundoByte = 3 - bitsPrimerByte;

    int mascara1 =
        ((1 << bitsPrimerByte) - 1) << desplazamiento;

    tablero[byte] =
        tablero[byte] & ~mascara1;

    tablero[byte] =
        tablero[byte] |
        ((valor & ((1 << bitsPrimerByte) - 1))
         << desplazamiento);

    int mascara2 =
        (1 << bitsSegundoByte) - 1;

    tablero[byte + 1] =
        tablero[byte + 1] & ~mascara2;

    tablero[byte + 1] =
        tablero[byte + 1] |
        ((valor >> bitsPrimerByte) & mascara2);
}