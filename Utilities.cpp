#include <string.h>
#include "Money.h"

/**
 * @brief Prosedur untuk mengubah semua huruf kata menjadi uppercase
 * 
 * @param kata 
 */
void toUpperCase(char *kata) {
    for (int i = 0; i < strlen(kata); i++) {
        kata[i] = (kata[i] > 96 && kata[i] < 123) ? kata[i] - 32 : kata[i];
    }
}