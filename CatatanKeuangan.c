#include <stdio.h>
#include <stdlib.h>
#include "money.h"
#include "Tanggal.h"


//void layoutCatatKeuangan(){
//	printf("-------------------------------\n");
//	printf("Catat Keuangan Anda Hari Ini\n");
//	printf("-------------------------------\n");
//	
//	printf("(1) Pemasukan\n");
//	printf("(2) Pengeluaran\n");
//	
//	printf("Masukkan pilihan anda: ");
//	int pilihan;
//	scanf("%d", &pilihan);
//	
//	switch (pilihan){
//		case 1: //Pemasukan
//		printf("")
//	}
//	
//}

void catatTransaksiMasuk(){
	Masuk transaksi;
	
	transaksi.waktu = inputTanggal();
	
	printf("Masukkan Nominal)			:	");
	scanf("%f", &transaksi.nominal);
	
	printf("Sumber Dana 	:	");
	scanf("%d", &transaksi.sumber_dana);
	
	showTanggal(transaksi.waktu);
}
