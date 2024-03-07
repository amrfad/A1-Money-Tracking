/**
 * @file RekapHarian.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "RekapHarian.h"


/**
 * @brief 
 * 
 * @param tanggal1 
 * @param tanggal2 
 * @return true 
 * @return false 
 */
bool isSameDay(Tanggal tanggal1, Tanggal tanggal2) {
    bool equal;
    equal = (tanggal1.tanggal == tanggal2.tanggal);
    equal = equal && (tanggal1.pekan == tanggal2.pekan);
    equal = equal && (tanggal1.bulan == tanggal2.bulan);
    equal = equal && (tanggal1.tahun == tanggal2.tahun);
    return equal;
}


/**
 * @brief 
 * 
 * @param user 
 * @param tanggalRekap 
 */
void rekapHarianMasuk(User user, Tanggal tanggalRekap) {
    float totalPemasukan = 0;
    printf("\033[1;34m%-10s\t%-10s\t%s\033[0m\n", "Tanggal", "Nominal", "Sumber Dana");
    for (int i = 0; i < user.indeksMasuk; i++) {
        if (isSameDay(tanggalRekap, user.transaksi_masuk[i].waktu)) {
            printf("%02d/%02d/%d\t", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
            formatMataUang(user.transaksi_masuk[i].nominal);
            printf("\t%s\n", user.transaksi_masuk[i].sumber_dana == 1 ? "Dompet Digital" : "Bank");
            totalPemasukan += user.transaksi_masuk[i].nominal;
        }
    }
    printf("\033[1;34mTotal Pemasukan pada Tanggal %02d/%02d/%d: \033[1;32m", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
    formatMataUang((double) totalPemasukan);
    printf("\033[0m\n");
}


/**
 * @brief 
 * 
 * @param user 
 * @param tanggalRekap 
 */
void rekapHarianKeluar(User user, Tanggal tanggalRekap) {
    char* kategori[] = {"Makanan", "Transportasi", "Hiburan", "Tagihan", "Lain-lain"};
    float totalPengeluaran = 0;
    printf("\033[1;34m%-10s\t%-10s\t%s\t%s\033[0m\n", "Tanggal", "Nominal", "Sumber Dana", "Kategori");
    for (int i = 0; i < user.indeksKeluar; i++) {
        if (isSameDay(tanggalRekap, user.transaksi_keluar[i].waktu)) {
            printf("%02d/%02d/%d\t", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
            formatMataUang(user.transaksi_keluar[i].nominal);
            printf("\t%s\t%s\n", user.transaksi_keluar[i].sumber_dana == 1 ? "Dompet Digital" : "Bank", kategori[user.transaksi_keluar[i].kategori]);
            totalPengeluaran += user.transaksi_keluar[i].nominal;
        }
    }
    printf("\033[1;34mTotal Pengeluaran pada Tanggal %02d/%02d/%d: \033[1;31m", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
    formatMataUang((double) totalPengeluaran);
    printf("\033[0m\n");
}


/**
 * @brief 
 * 
 * @param user 
 * @param tanggalRekap 
 */
void rekapHarianTotal(User user, Tanggal tanggalRekap) {

}