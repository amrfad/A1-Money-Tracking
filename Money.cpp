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

// ! Struct Masuk E N D

// ! Struct Keluar S T A R T

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
    switch (transaksi_keluar.sumber_dana)
    {
    case 1:
        printf("Dompet Digital: \n");
        break;
    case 2:
        printf("Rekening Bank: \n");
        break;
    default:
        break;
    }
    switch (transaksi_keluar.kategori)
    {
    case 1:
        printf("Kategori: Makanan\n");
        break;
    case 2:
        printf("Kategori: Transportasi\n");
        break;
    case 3:
        printf("Kategori: Hiburan\n");
        break;
    case 4:
        printf("Kategori: Tagihan\n");
        break;
    case 5:
        printf("Kategori: Lain-lain\n");
        break;
    default:
        break;
    }
    printf("-Rp. %.2f\n", transaksi_keluar.nominal);
    printf("***************\n");
}

float cekSaldo(SaldoUser saldo, int sumber_dana) {
    if (sumber_dana == 1) 
        return saldo.dompet_digital;
    else 
        return saldo.bank;
}

void saldoMasuk(SaldoUser *saldo, Masuk transaksi_masuk) {
    (transaksi_masuk.sumber_dana == 1)
    ? saldo->dompet_digital += transaksi_masuk.nominal
    : saldo->bank += transaksi_masuk.nominal;
    saldo->total = saldo->bank + saldo->dompet_digital;
}

void saldoKeluar(SaldoUser *saldo, Keluar transaksi_keluar) {
    if (transaksi_keluar.sumber_dana == 1) {
        if (saldo->dompet_digital - transaksi_keluar.nominal >= 0) {
            saldo->dompet_digital -= transaksi_keluar.nominal;
            saldo->total = saldo->bank + saldo->dompet_digital;
        } 
    }
    else {
        if (saldo->bank - transaksi_keluar.nominal >= 0) {
            saldo->dompet_digital -= transaksi_keluar.nominal;
            saldo->total = saldo->bank + saldo->dompet_digital;
        }
    }
}

void showSaldoUser(SaldoUser saldoUser) {
    printf("SALDO USER\n");
    printf("***************\n");
    printf("Dompet Digital: %.2f\n", saldoUser.dompet_digital);
    printf("Rekening Bank: %.2f\n", saldoUser.bank);
    printf("***************\n");
    printf("TOTAL: %.2f\n", saldoUser.total);
}

// ! Struct Keluar E N D

// ! Struct User S T A R T

void transaksiMasuk(User *user)
{
    Masuk transaksiMasuk = inputMasuk();
    saldoMasuk(&user->saldo, transaksiMasuk);
    user->transaksi_masuk[user->indeksMasuk] = transaksiMasuk;
    user->indeksMasuk = (user->indeksMasuk + 1) % 365;
    showMasuk(transaksiMasuk);
}

void transaksiKeluar(User *user)
{
    Keluar transaksiKeluar = inputKeluar();
    if (cekSaldo(user->saldo, transaksiKeluar.kategori) - transaksiKeluar.nominal >= 0)
    {
        user->transaksi_keluar[user->indeksKeluar] = transaksiKeluar;
        user->indeksKeluar = (user->indeksKeluar + 1) % 500;
        saldoKeluar(&user->saldo, transaksiKeluar);
        showKeluar(transaksiKeluar);
    }
    else {
        printf("SALDO TIDAK MENCUKUPI");
    }
}

void showRiwayatMasuk(User user)
{
    printf("RIWAYAT TRANSAKSI MASUK\n");
    printf("***************\n");
    for (int i = 0; i < user.indeksMasuk; i++)
    {
        showMasuk(user.transaksi_masuk[i]);
    }
}

void showRiwayatKeluar(User user)
{
    printf("RIWAYAT TRANSAKSI KELUAR\n");
    printf("***************\n");
    for (int i = 0; i < user.indeksKeluar; i++)
    {
        showKeluar(user.transaksi_keluar[i]);
    }
}

// ! Struct User E N D