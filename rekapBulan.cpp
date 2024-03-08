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

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
 * @brief 
 * 
 * @param tanggal1 
 * @param tanggal2 
 * @return true 
 * @return false 
 */
bool isSameMonth(Tanggal tanggal1, Tanggal tanggal2) {
    bool equal;
    equal = (tanggal1.bulan == tanggal2.bulan);
    equal = equal && (tanggal1.tahun == tanggal2.tahun);
    return equal;
}

/**
 * @brief Mencetak Mata Uang dengan Format Penulisan Mata Uang pada Umumnya
 * 
 * @param nominal 
 */
void formatMataUang(double nominal) {
    unsigned long long int digit[20];
    int i = 0;
    unsigned long long int temp = (unsigned long long int) nominal;
    if (temp == 0) printf("0");
    while (temp != 0) {
        digit[i] = temp % 10;
        temp = temp / 10;
        i++;
    }
    i--;
    while (i >= 0) {
        printf("%lld", digit[i]);
        if (i % 3 == 0 && i != 0) {
            printf(".");
        }
        i--;
    }
    temp = (unsigned long long int) nominal;
    printf(",%02.0f", ((nominal - (double) temp)*100));
}


/**
 * @brief 
 * 
 * @param user 
 * @param tanggalRekap 
 */
void rekapBulananMasuk(User user, Tanggal tanggalRekap) {
    float totalPemasukan = 0;
    printf("\033[1;34m%-10s\t%-10s\t%s\033[0m\n", "Tanggal", "Nominal", "Sumber Dana");
    for (int i = 0; i < user.indeksMasuk; i++) {
        if (isSameMonth(tanggalRekap, user.transaksi_masuk[i].waktu)) {
            printf("%02d/%02d/%d\t", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
            formatMataUang(user.transaksi_masuk[i].nominal);
            printf("\t%s\n", user.transaksi_masuk[i].sumber_dana == 1 ? "Dompet Digital" : "Bank");
            totalPemasukan += user.transaksi_masuk[i].nominal;
        }
    }
    printf("\033[1;34mTotal Pemasukan pada Bulan ");
    switch (tanggalRekap.bulan)
    {
        case 1:
            printf("Januari: \033[1;32m");
            break;
        case 2:
            printf("Februari: \033[1;32m");
            break;
        case 3:
            printf("Maret: \033[1;32m");
            break;
        case 4:
            printf("April: \033[1;32m");
            break;
        case 5:
            printf("Mei: \033[1;32m");
            break;
        case 6:
            printf("Juni: \033[1;32m");
            break;
        case 7:
            printf("Juli: \033[1;32m");
            break;
        case 8:
            printf("Agustus: \033[1;32m");
            break;
        case 9:
            printf("September: \033[1;32m");
            break;
        case 10:
            printf("Oktober: \033[1;32m");
            break;
        case 11:
            printf("November: \033[1;32m");
            break;
        case 12:
            printf("Desember: \033[1;32m");
            break;
    }
    formatMataUang((double) totalPemasukan);
    printf("\033[0m\n");
}


/**
 * @brief 
 * 
 * @param user 
 * @param tanggalRekap 
 */
void rekapBulananKeluar(User user, Tanggal tanggalRekap) {
    char* kategori[] = {"Makanan", "Transportasi", "Hiburan", "Tagihan", "Lain-lain"};
    float totalPengeluaran = 0;
    printf("\033[1;34m%-10s\t%-10s\t%s\t%s\033[0m\n", "Tanggal", "Nominal", "Sumber Dana", "Kategori");
    for (int i = 0; i < user.indeksKeluar; i++) {
        if (isSameMonth(tanggalRekap, user.transaksi_keluar[i].waktu)) {
            printf("%02d/%02d/%d\t", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
            formatMataUang(user.transaksi_keluar[i].nominal);
            printf("\t%s\t%s\n", user.transaksi_keluar[i].sumber_dana == 1 ? "Dompet Digital" : "Bank", kategori[user.transaksi_keluar[i].kategori]);
            totalPengeluaran += user.transaksi_keluar[i].nominal;
        }
    }
    printf("\033[1;34mTotal Pengeluaran pada Bulan ");
    switch (tanggalRekap.bulan)
    {
        case 1:
            printf("Januari: \033[1;32m");
            break;
        case 2:
            printf("Februari: \033[1;32m");
            break;
        case 3:
            printf("Maret: \033[1;32m");
            break;
        case 4:
            printf("April: \033[1;32m");
            break;
        case 5:
            printf("Mei: \033[1;32m");
            break;
        case 6:
            printf("Juni: \033[1;32m");
            break;
        case 7:
            printf("Juli: \033[1;32m");
            break;
        case 8:
            printf("Agustus: \033[1;32m");
            break;
        case 9:
            printf("September: \033[1;32m");
            break;
        case 10:
            printf("Oktober: \033[1;32m");
            break;
        case 11:
            printf("November: \033[1;32m");
            break;
        case 12:
            printf("Desember: \033[1;32m");
            break;
    }
    formatMataUang((double) totalPengeluaran);
    printf("\033[0m\n");
}