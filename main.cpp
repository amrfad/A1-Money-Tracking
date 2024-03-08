#include <stdio.h>
#include "header.h"

int main() {
    User aUser1;
    Tanggal rekap = {8, 2, 4, 2024};
    Tanggal tanggal1 = {23, 4, 4, 2024};
    Tanggal tanggal2 = {24, 4, 4, 2024};
    Tanggal tanggal3 = {25, 4, 4, 2024};

    Tanggal tanggal4 = {12, 2, 4, 2024};
    Tanggal tanggal5 = {13, 2, 4, 2024};
    Tanggal tanggal6 = {14, 2, 4, 2024};
    
    Tanggal tanggal7 = {14, 2, 5, 2024};

    aUser1.transaksi_masuk[0] = {tanggal4, 1, 650000};
    aUser1.transaksi_masuk[1] = {tanggal2, 0, 450000};
    aUser1.transaksi_masuk[2] = {tanggal1, 1, 500000};
    aUser1.transaksi_masuk[3] = {tanggal6, 0, 900000};
    aUser1.transaksi_masuk[4] = {tanggal5, 0, 1000000};
    aUser1.transaksi_masuk[5] = {tanggal3, 0, 450000};
    aUser1.transaksi_masuk[6] = {tanggal7, 0, 1000000}; 
    aUser1.indeksMasuk += 7;

    aUser1.transaksi_keluar[0] = {tanggal1, 1, 350000, 2};
    aUser1.transaksi_keluar[1] = {tanggal2, 0, 150000, 3};
    aUser1.indeksKeluar += 2;
    
    // rekapBulananMasuk(aUser1, rekap);
    // rekapPekananMasuk(aUser1, rekap);
    banner();
}