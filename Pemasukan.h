#ifndef Pemasukan_h
#define Pemasukan_h

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "money.h"
#include "Tanggal.h"

#define MAX_MASUK 365
#define MAX_KELUAR 730

void catatKeuangan(User *user);
void catatTransaksiMasuk(User *user);
void displayTrMasuk(Masuk transaksi_masuk);
void saveToFileMasuk(User *user);

void catatTransaksiKeluar(User *user);
void displayTrKeluar(Keluar transaksi_keluar);
void saveToFileKeluar(User *user);

#endif
