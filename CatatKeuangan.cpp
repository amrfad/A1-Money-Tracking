#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "money.h"
#include "Tanggal.h"

#define MAX_MASUK 365
#define MAX_KELUAR 730


void CatatKeuangan(){
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
		catatTransaksiMasuk(&user);
		system("cls");
		displayTrMasuk();
		break;
		
		case 2: //Pengeluaran
		catatTransaksiKeluar(&user);
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
	}
		
}


