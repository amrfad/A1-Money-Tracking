#ifndef Masuk_H
#define Masuk_H

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "Tanggal.h"

typedef struct Masuk
{
    Tanggal waktu;   // belum fix
    int sumber_dana; // 1. dompet dig/ 2. bank
    float nominal;
} Masuk;

/**
 * @brief Membuat instance dari objek Tanggal
 *
 * @param transaksi_masuk - Alamat dari instance yang akan diinisialisasi
 * @param waktu_transaksi - Waktu dilakukannya transaksi
 * @param sumber_dana - [1. Dompet Digital], [2. Rekening Bank]
 * @param nominal - Nominal uang yang dideposit
 */
void newMasuk(Masuk *transaksi_masuk, Tanggal waktu_transaksi, int sumber_dana, float nominal)
{
    transaksi_masuk->waktu = waktu_transaksi;
    transaksi_masuk->sumber_dana = sumber_dana;
    transaksi_masuk->nominal = nominal;
}

/**
 * @brief Membuat instance Masuk baru berdasarkan input user
 * 
 * @return Masuk - instance Masuk yang telah diinput
 */
Masuk inputMasuk()
{
    Masuk transaksi_masuk;

    int sumber_dana = 0;
    float nominal = -999;
    Tanggal waktu_transaksi;

    waktu_transaksi = inputTanggal();

    while (true)
    {
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

    newMasuk(&transaksi_masuk, waktu_transaksi, sumber_dana, nominal);
    return transaksi_masuk;
}

/**
 * @brief Menampilkan transaksi yang masuk
 * 
 * @param transaksi_masuk - objek transaksi yang akan ditampilkan
 */
void showMasuk(Masuk transaksi_masuk) {
    printf("TRANSAKSI MASUK\n");
    printf("***************\n");
    showTanggal(transaksi_masuk.waktu);
    (transaksi_masuk.sumber_dana == 1)
    ? printf("Dompet Digital:\n")
    : printf("Rekening Bank:\n");
    printf("+Rp. %.2f\n", transaksi_masuk.nominal);
    printf("***************\n");
}

#endif