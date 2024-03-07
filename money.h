#ifndef money_h
#define money_h

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "Tanggal.h"


typedef struct SaldoUser
{
    /* data */
    float dompet_digital;
    float bank;
    float total;
} SaldoUser;

typedef struct Masuk
{
    /* data */
    Tanggal waktu; // belum fix
    int sumber_dana; // 1. dompet dig/ 2. bank
    float nominal;
} Masuk;

typedef struct Keluar
{
    /* data */
    Tanggal waktu;
    int sumber_dana; // 1. dompet dig/ 2. bank
    float nominal;
    int kategori; // (1. Makanan, 2. Trans, 3. hiburan)
} Keluar;

typedef struct User
{
    /* data */
    const char * nama;
    SaldoUser saldo;
    Masuk transaksi_masuk[365];
    Keluar transaksi_keluar[730];
    int jumlahTransaksiMasuk;
    int jumlahTransaksiKeluar;
} User;

void catatTransaksiMasuk(User *user);
void catatTransaksiKeluar(User *user);
void displayTrMasuk();
void displayTrKeluar();

/*
Fitur Sejauh Ini
Money Tracking App		
- Catat Data Keuangan ke file		
- Sisa Saldo di Dompet (In-Out)		
- Rekap Perbulan		
- Rekap perhari		
- Rekap perpekan		
- Load Data		
3 Fitur Lain Bebas.		
- Pengkategorian		
- Konversi Mata Uang		
- laporan keuangan
*/

/*
Daftar Modul
- menu
- rekapBulan
- rekapPekan
- rekapHari
- inputEntri
- tampilSaldo
- loadData
...
*/

#endif
