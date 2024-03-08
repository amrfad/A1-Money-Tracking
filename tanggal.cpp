#include <stdio.h>
#include "header.h"

/**
 * @brief Membuat instance dari objek Tanggal
 *
 * @param Tanggal - Alamat dari instance yang akan diinisialisasi
 * @param tanggal - Tanggal dilakukan transaksi
 * @param bulan - Bulan dilakukan transaksi
 * @param tahun - Tahun dilakukan transaksi
 */
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

/**
 * @brief apakah tanggal yang direkam valid
 * 
 * @param tanggal - Tanggal dilakukan transaksi
 * @param bulan - Bulan dilakukan transaksi
 * @param tahun - Tahun dilakukan transaksi
 * @return true - Jika tanggal yang direkam valid
 * @return false - Jika tanggal yang direkam tidak valid
 */
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