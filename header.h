#ifndef Tanggal_H
#define Tanggal_H

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

typedef struct Tanggal
{
    int tanggal; // 1--30
    int pekan;   // kita yg kalkulasi
    int bulan;   // 1--12
    int tahun;
} Tanggal;

typedef struct Masuk
{
    Tanggal waktu;   // belum fix
    int sumber_dana; // 1. dompet dig/ 2. bank
    float nominal;
} Masuk;

typedef struct Keluar
{
    Tanggal waktu;
    int sumber_dana;
    float nominal;
    int kategori;
} Keluar;

typedef struct SaldoUser
{
    float dompet_digital = 0;
    float bank = 0;
    float total = this->dompet_digital + this->bank;
} SaldoUser;

typedef struct User
{
    const char *nama = "JAJANG RASING UZUMAKI";
    SaldoUser saldo;
    Masuk transaksi_masuk[365];
    int indeksMasuk = 0;
    Keluar transaksi_keluar[500];
    int indeksKeluar = 0;
} User;

/**
 * @brief Membuat instance dari objek Tanggal
 *
 * @param Tanggal - Alamat dari instance yang akan diinisialisasi
 * @param tanggal - Tanggal dilakukan transaksi
 * @param bulan - Bulan dilakukan transaksi
 * @param tahun - Tahun dilakukan transaksi
 */
void newTanggal(Tanggal *record, int tanggal, int bulan, int tahun);

/**
 * @brief apakah tanggal yang direkam valid
 * 
 * @param tanggal - Tanggal dilakukan transaksi
 * @param bulan - Bulan dilakukan transaksi
 * @param tahun - Tahun dilakukan transaksi
 * @return true - Jika tanggal yang direkam valid
 * @return false - Jika tanggal yang direkam tidak valid
 */
bool isValidTanggal(int tanggal, int bulan, int tahun);

/**
 * @brief Membuat instance tanggal baru berdasarkan input user
 * 
 * @return Tanggal - instance Tanggal yang telah diinput
 */
Tanggal inputTanggal();

/**
 * @brief Menampilkan waktu transaksi
 * 
 * @param tanggal - Waktu transaksi yang ingin ditampilkan
 */
void showTanggal(Tanggal tanggal);

/**
 * @brief Membuat instance dari objek Keluar
 * 
 * @param transaksi_keluar - Alamat dari instance yang akan diinisialisasi
 * @param waktu - Waktu dilakukannya transaksi
 * @param sumber_dana - [1. Dompet Digital], [2. Rekening Bank]
 * @param nominal - Nominal uang yang dideposit
 * @param kategori - [1. Makanan], [2. Transportasi], [3. Hiburan], [4. Tagihan], [5. Lain-lain]
 */
void newKeluar(Keluar *transaksi_keluar, Tanggal waktu, int sumber_dana, float nominal, int kategori);

/**
 * @brief Membuat instance Keluar baru berdasarkan input user
 * 
 * @return Keluar - instance Keluar yang telah diinput
 */
Keluar inputKeluar();

void showKeluar(Keluar transaksi_keluar);

void catatKeuangan(User *user);
void catatTransaksiMasuk(User *user);
void displayTrMasuk(Masuk transaksi_masuk);
void saveToFileMasuk(User *user);
void readFromFileMasuk(User *user);

void catatTransaksiKeluar(User *user);
void displayTrKeluar(Keluar transaksi_keluar);
void saveToFileKeluar(User *user);
void readFromFileMasuk(User *user);

#endif