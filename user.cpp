#include <stdio.h>
#include "header.h"

void showInfo(User user)
{
    printf("%s\n", user.nama);
    printf("***************\n");
    showSaldoUser(user.saldo);
}

void transaksiMasuk(User *user)
{
    // Masuk transaksiMasuk = inputMasuk();
    catatTransaksiMasuk(user);
    saldoMasuk(&user->saldo, transaksiMasuk);
    user->transaksi_masuk[user->indeksMasuk] = transaksiMasuk;
    user->indeksMasuk = (user->indeksMasuk + 1) % 365;
    showMasuk(transaksiMasuk);
}

void transaksiKeluar(User *user)
{
    Keluar transaksiKeluar = inputKeluar();
    if (cekSaldo(user->saldo, transaksiKeluar.kategori) - transaksiKeluar.nominal >= 0)
    {
        user->transaksi_keluar[user->indeksKeluar] = transaksiKeluar;
        user->indeksKeluar = (user->indeksKeluar + 1) % 500;
        saldoKeluar(&user->saldo, transaksiKeluar);
        showKeluar(transaksiKeluar);
    }
    else {
        printf("SALDO TIDAK MENCUKUPI");
    }
}

void showRiwayatMasuk(User user)
{
    printf("RIWAYAT TRANSAKSI MASUK\n");
    printf("***************\n");
    for (int i = 0; i < user.indeksMasuk; i++)
    {
        showMasuk(user.transaksi_masuk[i]);
    }
}

void showRiwayatKeluar(User user)
{
    printf("RIWAYAT TRANSAKSI KELUAR\n");
    printf("***************\n");
    for (int i = 0; i < user.indeksKeluar; i++)
    {
        showKeluar(user.transaksi_keluar[i]);
    }
}