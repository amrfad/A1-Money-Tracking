#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "Money.h"

// ! Struct Tanggal S T A R T

void newTanggal(Tanggal *record, int tanggal, int bulan, int tahun)
{
    record->tanggal = tanggal;
    record->bulan = bulan;
    record->tahun = tahun;
    
    if (tanggal >= 1 && tanggal <= 7)
        record->pekan = 1;
    else if (tanggal >= 8 && tanggal <= 14)
        record->pekan = 2;
    else if (tanggal >= 15 && tanggal <= 21)
        record->pekan = 3;
    else if (tanggal >= 22 && tanggal <= 31)
        record->pekan = 4;
}

bool isValidTanggal(int tanggal, int bulan, int tahun)
{
    if (tahun < 0 || bulan < 1 || bulan > 12 || tanggal < 1)
        return false;

    int daysInMonth[] = {31, 28 + (tahun % 4 == 0 && (tahun % 100 != 0 || tahun % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return tanggal <= daysInMonth[bulan-1];
}

/**
 * @brief Membuat instance tanggal baru berdasarkan input user
 * 
 * @return Tanggal - instance Tanggal yang telah diinput
 */
Tanggal inputTanggal() {
    int tanggal = 0, bulan = 0, tahun = 0;
    Tanggal new_tanggal;
    while (!isValidTanggal(tanggal, bulan, tahun))
    {
        printf("Masukkan Tanggal Transaksi: ");
        scanf("%d %d %d", &tanggal, &bulan, &tahun);

        if (!isValidTanggal(tanggal, bulan, tahun)) {
            // todo PUT HEADER
            system("cls");
            printf("ERROR INPUT: Tanggal yang dimasukkan tidak valid.\n");
        }
    }

    newTanggal(&new_tanggal, tanggal, bulan, tahun);

    return new_tanggal;
}

/**
 * @brief Menampilkan waktu transaksi
 * 
 * @param tanggal - Waktu transaksi yang ingin ditampilkan
 */
void showTanggal(Tanggal tanggal) {
    printf("Tanggal Transaksi: %d %d %d\n", tanggal.tanggal, tanggal.bulan, tanggal.tahun);
}

// ! Struct Tanggal S T A R T

// ! Struct Masuk S T A R T

/**
 * @brief Membuat instance dari objek Tanggal
 *
 * @param transaksi_masuk - Alamat dari instance yang akan diinisialisasi
 * @param waktu_transaksi - Waktu dilakukannya transaksi
 * @param sumber_dana - [1. Dompet Digital], [2. Rekening Bank]
 * @param nominal - Nominal uang yang dideposit
 */
void newMasuk(Masuk *transaksi_masuk, Tanggal waktu_transaksi, int sumber_dana, float nominal);

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

// ! Struct Masuk E N D