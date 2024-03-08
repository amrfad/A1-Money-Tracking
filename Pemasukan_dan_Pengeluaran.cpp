#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Money.h"


#define MAX_MASUK 365
#define MAX_KELUAR 730


void catatKeuangan(User *user){
	printf("-------------------------------\n");
	printf("\033[32mAyo Catat Keuangan Anda \033[34mdisini\033[0m\n");
	printf("-------------------------------\n");
	
	printf("(1) Pemasukan\n");
	printf("(2) Pengeluaran\n");
	
	printf("Masukkan pilihan anda: ");
	int pilihan;
	scanf("%d", &pilihan);
	
	switch (pilihan){
		case 1: //Pemasukan
		catatTransaksiMasuk(user);
		saveToFile(user);
		// system("cls");
		return;
		
		case 2: //Pengeluaran
		catatTransaksiKeluar(user);
		saveToFile(user);
		// system("cls");
		return;
	}
	
}

void catatTransaksiMasuk(User *user){
	if (user->indeksMasuk < MAX_MASUK)
	{
		Tanggal waktu_transaksi;
		Masuk transaksi;
		
		waktu_transaksi = inputTanggal();
		transaksi.waktu = waktu_transaksi;
		while (true)
		{
			printf("\n\033[34mSumber Dana 	:	\n");
			printf("(1) Dompet digital\n");
			printf("(2) Bank\n\n");
			printf("\033[32mInput	: ");
			scanf(" %d", &transaksi.sumber_dana);
			
			if ((transaksi.sumber_dana != 1) && (transaksi.sumber_dana) != 2)
			{
				printf("Masukkan angka yang sesuai!\n");
				continue;
			}
			
			break;
		}
		fflush(stdin);		
		printf("\n\033[32mMasukkan Nominal	:	Rp. ");
		scanf("%f", &transaksi.nominal);
		
		
		user->transaksi_masuk[user->indeksMasuk] = transaksi;
		
		if(transaksi.sumber_dana == 1 )	//Dompet digital
		{
			user->saldo.dompet_digital += transaksi.nominal;
		} 
		else if (transaksi.sumber_dana == 2) //Bank
		{
			user->saldo.bank += transaksi.nominal;
		}
		
		user->saldo.total += transaksi.nominal;	

		system("cls");
		displayTrMasuk(user->transaksi_masuk[user->indeksMasuk]);

		user->indeksMasuk++;
	}
}

void displayTrMasuk(Masuk transaksi_masuk){
	printf("\033[0m------------------\n");
	printf("Transaksi Berhasil\n");
	printf("------------------\n\n");

	showTanggal(transaksi_masuk.waktu);
	
	if (transaksi_masuk.sumber_dana == 1)
	{
		printf("Sumber dana		:	Dompet Digital\n");
	} 
	else 
	{
		printf("Sumber dana		:	Bank\n");
	}
	
	printf("Nominal			:	%.2f\n", transaksi_masuk.nominal);
	
	printf("\n=======Menabung agar Untung======\n");
	getchar();
}

void catatTransaksiKeluar(User *user){
	if (user->indeksKeluar < MAX_KELUAR)
	{
		Tanggal waktu_transaksi;
		Keluar transaksi;
		
		waktu_transaksi = inputTanggal();
		transaksi.waktu = waktu_transaksi;
		while (true)
		{
			printf("\n\033[34mSumber Dana 	:	\n");
			printf("(1) Dompet digital\n");
			printf("(2) Bank\n");
			printf("\n\033[32mInput		:	");
			scanf(" %d", &transaksi.sumber_dana);
			
			if ((transaksi.sumber_dana != 1) && (transaksi.sumber_dana) != 2)
			{
				printf("Masukkan angka yang sesuai!\n");
				continue;
			}
			
			break;
		}
		fflush(stdin);
		
		printf("\n\033[32mMasukkan Nominal	:	Rp. ");
		scanf("%f", &transaksi.nominal);
		
		while (true)
		{
			printf("\n\033[34mMasukkan Kategori	:\n");
			printf("(1) Makanan\n");
			printf("(2) Transportasi\n");
			printf("(3) Hiburan\n");
			printf("(4) Tagihan\n");
			printf("(5) Lain-lain\n");
			printf("\n\033[32mInput	:	");
			scanf("%d", &transaksi.kategori);
			
			if ((transaksi.kategori < 1) || (transaksi.kategori > 5))
			{
				printf("Masukkan angka yang valid");
				continue;
			}
			break;
		}
		fflush(stdin);
		
		user->transaksi_keluar[user->indeksKeluar] = transaksi;
		
		if(transaksi.sumber_dana == 1 )	//Dompet digital
		{
			user->saldo.dompet_digital -= transaksi.nominal;
		} 
		else if (transaksi.sumber_dana == 2) //Bank
		{
			user->saldo.bank -= transaksi.nominal;
		}
		user->saldo.total -= transaksi.nominal;	

		system("cls");
		displayTrKeluar(user->transaksi_keluar[user->indeksKeluar]);

		user->indeksKeluar++;
	}
}

void displayTrKeluar(Keluar transaksi_keluar){
	printf("\033[0m------------------\n");
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
	
	printf("Nominal			:	%.2f\n", transaksi_keluar.nominal);
	
	switch (transaksi_keluar.kategori){
		case 1 :
			printf("Kategori		:	Makanan\n");
			break;
		case 2 :
			printf("Kategori		:	Transportasi\n");
			break;
		case 3 :
			printf("Kategori		:	Hiburan\n");
			break;
		case 4 :
			printf("Kategori		:	Tagihan\n");
			break;
		case 5 :
			printf("Kategori		:	Lain-lain");
			break;
	}
	
	printf("=======Hemat Pangkal Kaya======\n");
}

void saveToFile(User *user)
{
    FILE *file = fopen("User.DAT", "wb");
    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }

    fwrite(user, sizeof(User), 1, file);

    fclose(file);
}


