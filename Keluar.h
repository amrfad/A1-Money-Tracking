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

/**
 * @brief Membuat instance dari objek Keluar
 * 
 * @param transaksi_keluar - Alamat dari instance yang akan diinisialisasi
 * @param waktu - Waktu dilakukannya transaksi
 * @param sumber_dana - [1. Dompet Digital], [2. Rekening Bank]
 * @param nominal - Nominal uang yang dideposit
 * @param kategori - [1. Makanan], [2. Transportasi], [3. Hiburan], [4. Tagihan], [5. Lain-lain]
 */
void newKeluar(Keluar *transaksi_keluar, Tanggal waktu, int sumber_dana, float nominal, int kategori) {
    transaksi_keluar->waktu = waktu;
    transaksi_keluar->sumber_dana = sumber_dana;
    transaksi_keluar->nominal = nominal;
    transaksi_keluar->kategori = kategori;
}

/**
 * @brief Membuat instance Keluar baru berdasarkan input user
 * 
 * @return Keluar - instance Keluar yang telah diinput
 */
Keluar inputKeluar() {
    Keluar transaksi_keluar;

    Tanggal waktu;
    int sumber_dana = 0;
    float nominal = -999;
    int kategori = 0;

    waktu = inputTanggal();

    while(true) {
        printf("Masukkan Sumber Dana: \n");
        printf("1) Dompet Digital\n");
        printf("2) Rekening Bank\n");
        printf("Input: ");
        scanf("%d", &sumber_dana);

        if (sumber_dana != 1 && sumber_dana != 2)
        {
            // todo HEADER
            system("cls");
            printf("ERROR INPUT: Input yang dimasukkan tidak valid.\n");
            continue;
        }

        break;
    }

    fflush(stdin);

    while (true)
    {
        printf("Kategori Pengeluaran:\n");
        printf("1) Makanan\n");
        printf("2) Transportasi\n");
        printf("3) Hiburan\n");
        printf("4) Tagihan\n");
        printf("5) Lain-lain\n");
        printf("Input: ");
        scanf("%d", &kategori);

        if (kategori != 1 && kategori != 2 && kategori != 3 && kategori != 4 && kategori != 5) {
            // todo HEADER
            system("cls");
            printf("ERROR INPUT: Input yang dimasukkan tidak valid.\n");
        }
        break;
    }

    fflush(stdin);
    
    while (nominal < 0)
    {
        printf("Masukkan Nominal Deposit: ");
        scanf("%f", &nominal);

        if (nominal < 0) {
            // todo HEADER
            system("cls");
            printf("ERROR INPUT: Input yang dimasukkan tidak valid.\n");
        }
    }

    newKeluar(&transaksi_keluar, waktu, sumber_dana, nominal, kategori);
    return transaksi_keluar;
}

void showKeluar(Keluar transaksi_keluar) {
    printf("TRANSAKSI KELUAR\n");
    printf("***************\n");
    showTanggal(transaksi_keluar.waktu);
    (transaksi_keluar.sumber_dana == 1)
    ? printf("Dompet Digital:\n")
    : printf("Rekening Bank:\n");
    (transaksi_keluar.kategori == 1)
    ? printf("Kategori: Makanan\n")
    : (transaksi_keluar.kategori == 2)
    ? printf("Kategori: Transportasi\n")
    : (transaksi_keluar.kategori == 3)
    ? printf("Kategori: Hiburan\n")
    : (transaksi_keluar.kategori == 4)
    ? printf("Kategori: Tagihan\n")
    : printf("Kategori: Lain-lain\n");
    printf("-Rp. %.2f\n", transaksi_keluar.nominal);
    printf("***************\n");
}

#endif