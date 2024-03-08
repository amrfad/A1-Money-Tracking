/**
 * @file Driver.cpp
 * @author Kelompok A1
 * @brief Driver untuk menjalankan program utama
 * @version 0.1
 * @date 2024-03-08
 * 
 * @copyright Copyright (c) 2024 Kelompok A1
 * 
 */

#include "KonversiMataUang.h"
#include "RekapHarian.h"

int main() {
    /////////////////////////////////////////////////////////////////// DUMMY DATA
    Tanggal tanggal1 = {23, 4, 4, 2024};
    Tanggal tanggal2 = {23, 4, 4, 2024};
    User user;
    user.transaksi_masuk[0] = {tanggal1, 1, 500000};
    user.transaksi_masuk[1] = {tanggal2, 0, 450000};
    user.indeksMasuk += 2;

    user.transaksi_keluar[0] = {tanggal1, 1, 350000, 2};
    user.transaksi_keluar[1] = {tanggal2, 0, 150000, 3};
    user.indeksKeluar += 2;

    user.saldo.total = 450000;
    /////////////////////////////////////////////////////////////////// DUMMY DATA

    int i = 5;
    while(i != 0) {
        printf("\033[1;34mSELAMAT DATANG DI APLIKASI MONEY TRACKING!\033[0m\n");
        printf("Halo, \033[33m%s\033[0m. Saldo Totalmu Adalah: \033[36mRp. ", user.nama);
        formatMataUang(user.saldo.total);
        printf("\033[0m\n");
        printf("\033[1;32m[1]\033[0m masuk catat keuangan\n");
        printf("\033[1;32m[2]\033[0m cek saldo\n");
        printf("\033[1;32m[3]\033[0m rekap per hari\n");
        printf("\033[1;32m[4]\033[0m rekap per pekan\n");
        printf("\033[1;32m[5]\033[0m rekap per bulan\n");
        printf("\033[1;32m[6]\033[0m load data (tampilin semua entrinya)\n");
        printf("\033[1;32m[7]\033[0m konversi mata uang\n");
        printf("\033[1;32m[8]\033[0m laporan keuangan\n");
        printf("\033[1;32m[0]\033[0m keluar\n");
        printf("\033[34mPilih Menu: \033[0m");
        scanf(" %d", &i);
        if(i == 1){
            system("cls");
            // TODO : panggil menu catat keuangan
        } else if (i == 2) {
            system("cls");
            // TODO : panggil menu cek saldo
        } else if (i == 3) {
            system("cls");
            tampilMenuRekapHarian(user);
        } else if (i == 4) {
            system("cls");
            // TODO : panggil menu rekap per pekan
        } else if (i == 5) {
            system("cls");
            // TODO : panggil menu rekap per bulan
        } else if (i == 6) {
            system("cls");
            // TODO : panggil menu load data
        } else if (i == 7) {
            system("cls");
            tampilMenuKonversi();
        } else if (i == 8) {
            system("cls");
            // TODO : panggil menu laporan keuangan
        } else {
            system("cls");
        }
    }

    return 0;
}