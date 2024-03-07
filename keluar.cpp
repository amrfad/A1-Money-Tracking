#ifndef Keluar_H
#define Keluar_H

#include <stdio.h>
#include "Tanggal.h"

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

void showTanggal(Tanggal tanggal) {
    printf("Tanggal Transaksi: %d %d %d\n", tanggal.tanggal, tanggal.bulan, tanggal.tahun);
}


/*KELUAR*/
void newKeluar(Keluar *transaksi_keluar, Tanggal waktu, int sumber_dana, float nominal, int kategori) {
    transaksi_keluar->waktu = waktu;
    transaksi_keluar->sumber_dana = sumber_dana;
    transaksi_keluar->nominal = nominal;
    transaksi_keluar->kategori = kategori;
}

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