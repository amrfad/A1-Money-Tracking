#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "money.h"
#include "Tanggal.h"

#define MAX_MASUK 365
#define MAX_KELUAR 730


void catatKeuangan(User *user){
	printf("-------------------------------\n");
	printf("Ayo Catat Keuangan Anda di Sini\n");
	printf("-------------------------------\n");
	
	printf("(1) Pemasukan\n");
	printf("(2) Pengeluaran\n");
	
	printf("Masukkan pilihan anda: ");
	int pilihan;
	scanf("%d", &pilihan);
	
	switch (pilihan){
		case 1: //Pemasukan
		catatTransaksiMasuk(user);
		system("cls");
		//saveToFileMasuk(user);
		displayTrMasuk();
		break;
		
		case 2: //Pengeluaran
		catatTransaksiKeluar(user);
		system("cls");
		displayTrKeluar();
	}
	
}

void catatTransaksiMasuk(User *user){
	if (user->jumlahTransaksiMasuk < MAX_MASUK)
	{
		Tanggal waktu_transaksi;
		Masuk transaksi;
		
		waktu_transaksi = inputTanggal();
		while (true)
		{
			printf("Sumber Dana 	:	\n");
			printf("(1) Dompet digital\n");
			printf("(2) Bank\n");
			printf("Input			:	");
			scanf("%d", &transaksi.sumber_dana);
			
			if ((transaksi.sumber_dana != 1) || (transaksi.sumber_dana) != 2)
			{
				printf("Masukkan angka yang sesuai!\n");
				continue;
			}
			
			break;
		}
		fflush(stdin);
		
		printf("Masukkan Nominal)	:	Rp. ");
		scanf("%f", &transaksi.nominal);
		
		
		user->transaksi_masuk[user->jumlahTransaksiMasuk] = transaksi;
		user->jumlahTransaksiMasuk++;
		
		if(transaksi.sumber_dana == 1 )	//Dompet digital
		{
			user->saldo.dompet_digital += transaksi.nominal;
		} 
		else if (transaksi.sumber_dana == 2) //Bank
		{
			user->saldo.bank += transaksi.nominal;
		}
		
		user->saldo.total += transaksi.nominal;	
	}
}

void displayTrMasuk(Masuk transaksi_masuk){
	printf("------------------\n");
	printf("Transaksi Berhasil\n");
	printf("------------------\n");

	showTanggal(transaksi_masuk.waktu);
	
	if (transaksi_masuk.sumber_dana == 1)
	{
		printf("Sumber dana		:	Dompet Digital\n");
	} 
	else 
	{
		printf("Sumber dana		:	Bank\n");
	}
	
	printf("Nominal			:	%f\n", transaksi_masuk.nominal);
	
	printf("=======Menabung agar Untung======");
}

void saveToFileMasuk(User *user)
{
    FILE *file = fopen("Pemasukan.DAT", "wb");
    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }

    fwrite(user, sizeof(User), 1, file);

    fclose(file);
}

void catatTransaksiKeluar(User *user){
	if (user->jumlahTransaksiKeluar < MAX_KELUAR)
	{
		Tanggal waktu_transaksi;
		Keluar transaksi;
		
		waktu_transaksi = inputTanggal();
		while (true)
		{
			printf("Sumber Dana 	:	\n");
			printf("(1) Dompet digital\n");
			printf("(2) Bank\n");
			printf("Input			:	");
			scanf("%d", &transaksi.sumber_dana);
			
			if ((transaksi.sumber_dana != 1) || (transaksi.sumber_dana) != 2)
			{
				printf("Masukkan angka yang sesuai!\n");
				continue;
			}
			
			break;
		}
		fflush(stdin);
		
		printf("Masukkan Nominal)	:	Rp. ");
		scanf("%f", &transaksi.nominal);
		
		while (true)
		{
			printf("Masukkan Kategori)	:\n");
			printf("(1) Makanan\n");
			printf("(2) Transportasi\n");
			printf("(3) Hiburan\n");
			printf("(4) Tagihan\n");
			printf("(5) Lain-lain\n");
			printf("Input	:	");
			scanf("%d", &transaksi.kategori);
			
			if ((transaksi.kategori < 1) || (transaksi.kategori > 5))
			{
				printf("Masukkan angka yang valid");
				continue;
			}
			break;
		}
		fflush(stdin);
		
		
		user->transaksi_keluar[user->jumlahTransaksiKeluar] = transaksi;
		user->jumlahTransaksiKeluar++;
		
		if(transaksi.sumber_dana == 1 )	//Dompet digital
		{
			user->saldo.dompet_digital -= transaksi.nominal;
		} 
		else if (transaksi.sumber_dana == 2) //Bank
		{
			user->saldo.bank -= transaksi.nominal;
		}
		user->saldo.total -= transaksi.nominal;	
	}
}

void displayTrKeluar(Keluar transaksi_keluar){
	printf("------------------\n");
	printf("Transaksi Berhasil\n");
	printf("------------------\n");

	showTanggal(transaksi_keluar.waktu);
	
	if (transaksi_keluar.sumber_dana == 1)
	{
		printf("Sumber dana		:	Dompet Digital\n");
	} 
	else 
	{
		printf("Sumber dana		:	Bank\n");
	}
	
	printf("Nominal			:	%f\n", transaksi_keluar.nominal);
	
	switch (transaksi_keluar.kategori){
		case 1 :
			printf("Kategori	:	Makanan\n");
			break;
		case 2 :
			printf("Kategori	:	Hiburan\n");
			break;
		case 3 :
			printf("Kategori	:	Hiburan\n");
			break;
		case 4 :
			printf("Kategori	:	Tagihan\n");
			break;
		case 5 :
			printf("Kategori	:	Lain-lain");
			break;
	}
	
	printf("=======Hemat Pangkal Kaya======");
}

void saveToFileKeluar(User *user)
{
    FILE *file = fopen("Pengeluaran.DAT", "wb");
    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }

    fwrite(user, sizeof(User), 1, file);

    fclose(file);
}

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
    printf("Jumlah Transaksi Masuk: %d\n", user->jumlahTransaksiMasuk);
    printf("Jumlah Transaksi Keluar: %d\n\n", user->jumlahTransaksiKeluar);

    printf("===== Transaksi Masuk =====\n");
    for (int i = 0; i < user->jumlahTransaksiMasuk; i++)
    {
        printf("Transaksi ke-%d\n", i + 1);
		showTanggal(user->transaksi_masuk[i].waktu);
        printf("Sumber Dana	: %s\n", user->transaksi_masuk[i].sumber_dana == 1 ? "Dompet Digital" : "Bank");
        printf("Nominal		: %.2f\n\n", user->transaksi_masuk[i].nominal);
    }

    printf("===== Transaksi Keluar =====\n");
    for (int i = 0; i < user->jumlahTransaksiKeluar; i++)
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
            printf("Transaksi\n\n");
            break;
        case 3:
            printf("Hiburan\n\n");
            break;
        default:
            printf("Tidak Diketahui\n\n");
            break;
        }
    }
}
