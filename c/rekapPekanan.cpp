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
#include "Money.h"

/**
 * @brief 
 * 
 * @param tanggal1 
 * @param tanggal2 
 * @return true 
 * @return false 
 */
bool isSameWeek(Tanggal tanggal1, Tanggal tanggal2) {
    bool equal;
    equal = (tanggal1.pekan == tanggal2.pekan);
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
void rekapPekananMasuk(User user) {
    Tanggal tanggalRekap;

    printf("Masukkan tahun yang ingin ditampilkan data rekapnya. (Contoh: 2023)\n>> ");
    scanf("%d", &(tanggalRekap.tahun));
    printf("Masukkan bulan yang ingin ditampilkan data rekapnya. (Silakan masukkan angkanya saja)\n");
    printf("1. Januari\n");
    printf("2. Februari\n");
    printf("3. Maret\n");
    printf("4. April\n");
    printf("5. Mei\n");
    printf("6. Juni\n");
    printf("7. Juli\n");
    printf("8. Agustus\n");
    printf("9. September\n");
    printf("10. Oktober\n");
    printf("11. November\n");
    printf("12. Desember\n");
    printf(">> ");
    scanf("%d", &(tanggalRekap.bulan));
    while (tanggalRekap.bulan < 1 || tanggalRekap.bulan > 12) {
        printf("Tolong masukkan angka yang valid\n>> ");
        scanf("%d", &(tanggalRekap.bulan));
    }
    printf("Masukkan pekan yang ingin direkap dari bulan tersebut (1-4)\n>> ");
    scanf("%d", &(tanggalRekap.pekan));
    while (tanggalRekap.pekan != 1 && tanggalRekap.pekan != 2 && tanggalRekap.pekan != 3 && tanggalRekap.pekan != 4) {
        printf("Tolong masukkan angka yang valid\n>> ");
        scanf("%d", &(tanggalRekap.pekan));
    }
    tanggalRekap.tahun=user.transaksi_masuk->waktu.tahun;

    float totalPemasukan = 0;
    bool ada_pemasukan=false;
    printf("\033[1;34m%-10s\t%-10s\t%s\033[0m\n", "Tanggal", "Nominal", "Sumber Dana");
    for (int i = 0; i < user.indeksMasuk; i++) {
        if (isSameWeek(tanggalRekap, user.transaksi_masuk[i].waktu)) {
            printf("%02d/%02d/%d\t", user.transaksi_masuk[i].waktu.tanggal, user.transaksi_masuk[i].waktu.bulan, user.transaksi_masuk[i].waktu.tahun);
            formatMataUang(user.transaksi_masuk[i].nominal);
            printf("\t%s\n", user.transaksi_masuk[i].sumber_dana == 1 ? "Dompet Digital" : "Bank");
            totalPemasukan += user.transaksi_masuk[i].nominal;
            ada_pemasukan=true;
        }
    }
    if (ada_pemasukan==true) {
        printf("\033[1;34mTotal Pemasukan pada Pekan ke-%d, Bulan ", tanggalRekap.pekan);
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
    } else {
        printf("\033[1;32mData Kosong\033[0m\n");
    }
    printf("Ketik apapun untuk kembali ke menu awal.");
    getchar();
}


/**
 * @brief 
 * 
 * @param user 
 * @param tanggalRekap 
 */
void rekapPekananKeluar(User user) {
    Tanggal tanggalRekap;

    printf("Masukkan tahun yang ingin ditampilkan data rekapnya. (Contoh: 2023)\n>> ");
    scanf("%d", &(tanggalRekap.tahun));
    printf("Masukkan bulan yang ingin ditampilkan data rekapnya. (Silakan masukkan angkanya saja)\n");
    printf("1. Januari\n");
    printf("2. Februari\n");
    printf("3. Maret\n");
    printf("4. April\n");
    printf("5. Mei\n");
    printf("6. Juni\n");
    printf("7. Juli\n");
    printf("8. Agustus\n");
    printf("9. September\n");
    printf("10. Oktober\n");
    printf("11. November\n");
    printf("12. Desember\n");
    printf(">> ");
    scanf("%d", &(tanggalRekap.bulan));
    
    while (tanggalRekap.bulan < 1 || tanggalRekap.bulan > 12) {
        printf("Tolong masukkan angka yang valid\n>> ");
        scanf("%d", &(tanggalRekap.bulan));
    }
    printf("Masukkan pekan yang ingin direkap dari bulan tersebut (1-4)\n>> ");
    
    scanf("%d", &(tanggalRekap.pekan));
    while (tanggalRekap.pekan != 1 && tanggalRekap.pekan != 2 && tanggalRekap.pekan != 3 && tanggalRekap.pekan != 4) {
        printf("Tolong masukkan angka yang valid\n>> ");
        scanf("%d", &(tanggalRekap.pekan));
    }
    
    tanggalRekap.tahun=user.transaksi_keluar->waktu.tahun;

    const char* kategori[] = {"Makanan", "Transportasi", "Hiburan", "Tagihan", "Lain-lain"};
    float totalPengeluaran = 0;
    bool ada_pengeluaran=false;
    printf("\033[1;34m%-10s\t%-10s\t%s\t%s\033[0m\n", "Tanggal", "Nominal", "Sumber Dana", "Kategori");
    for (int i = 0; i < user.indeksKeluar; i++) {
        if (isSameWeek(tanggalRekap, user.transaksi_keluar[i].waktu)) {
            printf("%02d/%02d/%d\t", tanggalRekap.tanggal, tanggalRekap.bulan, tanggalRekap.tahun);
            formatMataUang(user.transaksi_keluar[i].nominal);
            printf("\t%s\t%s\n", user.transaksi_keluar[i].sumber_dana == 1 ? "Dompet Digital" : "Bank", kategori[user.transaksi_keluar[i].kategori]);
            totalPengeluaran += user.transaksi_keluar[i].nominal;
            ada_pengeluaran=true;
        }
    }
    if (ada_pengeluaran==true) {
        printf("\033[1;34mTotal Pengeluaran pada pekan ke-%d, bulan ", tanggalRekap.pekan);
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
    } else {
        printf("\033[1;32mData Kosong\033[0m\n");
    }
    printf("Ketik apapun untuk kembali ke menu awal.");
    getchar();
}

void tampilMenuRekapPekanan(User user) {
    // void(*tab[2])(User user, Tanggal tanggalRekap) = {&rekapPekananMasuk, &rekapPekananKeluar};
    printf("\033[1;34mPilihan Mode Rekap Pekanan:\033[0m\n");
    printf("\033[1;32m[1]\033[0m Rekap Pekanan Transaksi Masuk\n");
    printf("\033[1;32m[2]\033[0m Rekap Pekanan Transaksi Keluar\n");
    printf("\033[1;34mPilih Mode: \033[0m");
    int choice;
    scanf(" %d", &choice);

    switch (choice)
    {
        case 1:
            rekapPekananMasuk(user);
            break;
        case 2:
            rekapPekananKeluar(user);
            break;
    }
}