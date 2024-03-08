#include <stdio.h>
#include "header.h"

#define MAX_MASUK 365
#define MAX_KELUAR 730

/*KELUAR*/
void newKeluar(Keluar *transaksi_keluar, Tanggal waktu, int sumber_dana, float nominal, int kategori) {
    transaksi_keluar->waktu = waktu;
    transaksi_keluar->sumber_dana = sumber_dana;
    transaksi_keluar->nominal = nominal;
    transaksi_keluar->kategori = kategori;
}

Keluar inputKeluar() {
    Keluar transaksi_keluar;

    Tanggal waktu;
    int sumber_dana = 0;
    float nominal = -999;
    int kategori = 0;

    waktu = inputTanggal();

    while(true) {
        printf("Masukkan Sumber Dana: \n");
        printf("1) Dompet Digital\n");
        printf("2) Rekening Bank\n");
        printf("Input: ");
        scanf("%d", &sumber_dana);

        if (sumber_dana != 1 && sumber_dana != 2)
        {
            // todo HEADER
            system("cls");
            printf("ERROR INPUT: Input yang dimasukkan tidak valid.\n");
            continue;
        }

        break;
    }

    fflush(stdin);

    while (true)
    {
        printf("Kategori Pengeluaran:\n");
        printf("1) Makanan\n");
        printf("2) Transportasi\n");
        printf("3) Hiburan\n");
        printf("4) Tagihan\n");
        printf("5) Lain-lain\n");
        printf("Input: ");
        scanf("%d", &kategori);

        if (kategori != 1 && kategori != 2 && kategori != 3 && kategori != 4 && kategori != 5) {
            // todo HEADER
            system("cls");
            printf("ERROR INPUT: Input yang dimasukkan tidak valid.\n");
        }
        break;
    }

    fflush(stdin);
    
    while (nominal < 0)
    {
        printf("Masukkan Nominal Deposit: ");
        scanf("%f", &nominal);

        if (nominal < 0) {
            // todo HEADER
            system("cls");
            printf("ERROR INPUT: Input yang dimasukkan tidak valid.\n");
        }
    }

    newKeluar(&transaksi_keluar, waktu, sumber_dana, nominal, kategori);
    return transaksi_keluar;
}

void showKeluar(Keluar transaksi_keluar) {
    printf("TRANSAKSI KELUAR\n");
    printf("***************\n");
    showTanggal(transaksi_keluar.waktu);
    (transaksi_keluar.sumber_dana == 1)
    ? printf("Dompet Digital:\n")
    : printf("Rekening Bank:\n");
    (transaksi_keluar.kategori == 1)
    ? printf("Kategori: Makanan\n")
    : (transaksi_keluar.kategori == 2)
    ? printf("Kategori: Transportasi\n")
    : (transaksi_keluar.kategori == 3)
    ? printf("Kategori: Hiburan\n")
    : (transaksi_keluar.kategori == 4)
    ? printf("Kategori: Tagihan\n")
    : printf("Kategori: Lain-lain\n");
    printf("-Rp. %.2f\n", transaksi_keluar.nominal);
    printf("***************\n");
}

void catatTransaksiKeluar(User *user) {
	if (user->indeksKeluar < MAX_KELUAR)
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
		
		
		user->transaksi_keluar[user->indeksKeluar] = transaksi;
		user->indeksKeluar++;
		
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
		displayTrKeluar(transaksi);
	}
}

void displayTrKeluar(Keluar transaksi_keluar) {
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