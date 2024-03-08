/**
 * @file RekapHarian.cpp
 * @author Penanggung Jawab: AMR FADHILAH ABIYYU ALIF BASYSYAR [ 231524002 ]
 * @brief Berisi implemenetasi fungsi dan prosedur yang akan digunakan pada fitur rekap harian
 * @version 0.2
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024 KELOMPOK A1
 * 
 */


#include "RekapHarian.h"


/**
 * @brief Fungsi untuk membandingkan apa dua tanggal adalah sama
 * 
 * @param tanggal1 
 * @param tanggal2 
 * @return true 
 * @return false 
 */
bool isSameDay(Tanggal tanggal1, Tanggal tanggal2) {
    bool equal;
    equal = (tanggal1.tanggal == tanggal2.tanggal);
    equal = equal && (tanggal1.bulan == tanggal2.bulan);
    equal = equal && (tanggal1.tahun == tanggal2.tahun);
    return equal;
}


/**
 * @brief Prosedur untuk mencetak rekap harian pada transaksi masuk
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
    printf("\033[0m\n\n");
}


/**
 * @brief Prosedur untuk mencetak rekap harian pada transaksi keluar
 * 
 * @param user 
 * @param tanggalRekap 
 */
void rekapHarianKeluar(User user, Tanggal tanggalRekap) {
    char* kategori[] = {"Makanan", "Transportasi", "Hiburan", "Tagihan", "Lain-lain"};
    float totalPengeluaran = 0;
    printf("\033[1;34m%-10s\t%-15s\t%-15s\t%s\033[0m\n", "Tanggal", "Nominal", "Sumber Dana", "Kategori");
    for (int i = 0; i < user.indeksKeluar; i++) {
        if (isSameDay(tanggalRekap, user.transaksi_keluar[i].waktu)) {
            printf("%02d/%02d/%d\t", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
            formatMataUang(user.transaksi_keluar[i].nominal);
            printf("\t%-15s\t%s\n", user.transaksi_keluar[i].sumber_dana == 1 ? "Dompet Digital" : "Bank", kategori[user.transaksi_keluar[i].kategori]);
            totalPengeluaran += user.transaksi_keluar[i].nominal;
        }
    }
    printf("\033[1;34mTotal Pengeluaran pada Tanggal %02d/%02d/%d: \033[1;31m", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
    formatMataUang((double) totalPengeluaran);
    printf("\033[0m\n\n");
}


/**
 * @brief Prosedur untuk mencetak rekap harian pada transaksi keseluruhan
 * 
 * @param user 
 * @param tanggalRekap 
 */
void rekapHarianTotal(User user, Tanggal tanggalRekap) {
    char* kategori[] = {"Makanan", "Transportasi", "Hiburan", "Tagihan", "Lain-lain"};
    float totalPerubahan = 0;
    printf("\033[1;34m%-10s\t%-15s\t%-15s\t%s\033[0m\n", "Tanggal", "Nominal", "Sumber Dana", "Kategori");
    for (int i = 0; i < user.indeksMasuk; i++) {
        if (isSameDay(tanggalRekap, user.transaksi_masuk[i].waktu)) {
            printf("%02d/%02d/%d\t+ ", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
            formatMataUang(user.transaksi_masuk[i].nominal);
            printf("\t%-15s\t-\n", user.transaksi_masuk[i].sumber_dana == 1 ? "Dompet Digital" : "Bank");
            totalPerubahan += user.transaksi_masuk[i].nominal;
        }
    }
    for (int i = 0; i < user.indeksKeluar; i++) {
        if (isSameDay(tanggalRekap, user.transaksi_keluar[i].waktu)) {
            printf("%02d/%02d/%d\t- ", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
            formatMataUang(user.transaksi_keluar[i].nominal);
            printf("\t%-15s\t%s\n", user.transaksi_keluar[i].sumber_dana == 1 ? "Dompet Digital" : "Bank", kategori[user.transaksi_keluar[i].kategori]);
            totalPerubahan -= user.transaksi_keluar[i].nominal;
        }
    }
    printf("\033[1;34mTotal Perubahan pada Tanggal %02d/%02d/%d: ", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
    printf("%s", totalPerubahan < 0 ? "\033[1;31m-" : "\033[1;32m");
    formatMataUang(totalPerubahan < 0 ? ((double) (-1)*totalPerubahan) : ((double) totalPerubahan));
    printf("\033[0m\n\n");
}


/**
 * @brief Menampilan Menu untuk Mencetak Rekap Harian
 * 
 * @param user 
 */
void tampilMenuRekapHarian(User user) {
    void(*tab[3])(User user, Tanggal tanggalRekap) = {&rekapHarianMasuk, &rekapHarianKeluar, &rekapHarianTotal};
    printf("\033[1;34mPilihan Mode Rekap Harian:\033[0m\n");
    printf("\033[1;32m[1]\033[0m Rekap Harian Transaksi Masuk\n");
    printf("\033[1;32m[2]\033[0m Rekap Harian Transaksi Keluar\n");
    printf("\033[1;32m[3]\033[0m Rekap Harian Transaksi Keseluruhan\n");
    printf("\033[1;34mPilih Mode: \033[0m");
    int choice;
    scanf(" %d", &choice);
    Tanggal tanggalRekap;
    printf("\033[1;34mMasukkan Tanggal yang Ingin Direkap \033[30m[Contoh: 23/04/2024]\033[1;34m: \033[0m");
    scanf(" %02d/%02d/%d", &(tanggalRekap.tanggal), &(tanggalRekap.bulan), &(tanggalRekap.tahun));
    system("cls");
    tab[choice - 1](user, tanggalRekap);
    printf("\033[36m[Klik Enter untuk Kembali ke Menu]\033[0m");
    getchar();
    getchar();
    system("cls");
}