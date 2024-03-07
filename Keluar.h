#ifndef Keluar_H
#define Keluar_H

#include <stdio.h>
#include "Tanggal.h"

typedef struct Keluar
{
    Tanggal waktu;
    int sumber_dana;
    float nominal;
    int kategori;
} Keluar;
#endif