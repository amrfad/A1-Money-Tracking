#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Money.h"

#define MAX_MASUK 365
#define MAX_KELUAR 730

void readFromFileMasuk(User *user)
{
	FILE *file = fopen("Pemasukan.DAT", "rb");
	if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }
    
    fread(user, sizeof(User), 1, file);
    
    fclose(file);
}

void readFromFileKeluar(User *user)
{
	FILE *file = fopen("Pengeluaran.DAT", "rb");
	if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }
    
    fread(user, sizeof(User), 1, file);
    
    fclose(file);
}

void displayDetailTransaksi(User *user)
{
    printf("\n========= DETAIL TRANSAKSI =========\n");
    printf("Jumlah Transaksi Masuk: %d\n", user->indeksMasuk);
    printf("Jumlah Transaksi Keluar: %d\n\n", user->indeksKeluar);

    printf("===== Transaksi Masuk =====\n");
    for (int i = 0; i < user->indeksMasuk; i++)
    {
        printf("Transaksi ke-%d\n", i + 1);
		showTanggal(user->transaksi_masuk[i].waktu);
        printf("Sumber Dana	: %s\n", user->transaksi_masuk[i].sumber_dana == 1 ? "Dompet Digital" : "Bank");
        printf("Nominal		: %.2f\n\n", user->transaksi_masuk[i].nominal);
    }

    printf("===== Transaksi Keluar =====\n");
    for (int i = 0; i < user->indeksKeluar; i++)
    {
        printf("Transaksi ke-%d\n", i + 1);
        showTanggal(user->transaksi_keluar[i].waktu);
        printf("Sumber Dana: %s\n", user->transaksi_keluar[i].sumber_dana == 1 ? "Dompet Digital" : "Bank");
        printf("Nominal: %.2f\n", user->transaksi_keluar[i].nominal);
        printf("Kategori: ");
        switch (user->transaksi_keluar[i].kategori)
        {
        case 1:
            printf("Makanan\n\n");
            break;
        case 2:
            printf("Transportasi\n\n");
            break;
        case 3:
            printf("Hiburan\n\n");
            break;
        case 4:
        	printf("Tagihan\n\n");
        	break;
        case 5:
        	printf("Lain-lain\n\n");
        	break;
        default:
            printf("Tidak Diketahui\n\n");
            break;
        }
    }
}
