#ifndef SaldoUser_H
#define SaldoUser_H

#include <stdio.h>
#include "Masuk.h"
#include "Keluar.h"

typedef struct SaldoUser
{
    float dompet_digital = 0;
    float bank = 0;
    float total = this->dompet_digital + this->bank;
} SaldoUser;

float cekSaldo(SaldoUser saldo, int sumber_dana) {
    if (sumber_dana == 1) 
        return saldo.dompet_digital;
    else 
        return saldo.bank;
}

void saldoMasuk(SaldoUser *saldo, Masuk transaksi_masuk) {
    (transaksi_masuk.sumber_dana == 1)
    ? saldo->dompet_digital += transaksi_masuk.nominal
    : saldo->bank += transaksi_masuk.nominal;
    saldo->total = saldo->bank + saldo->dompet_digital;
}

void saldoKeluar(SaldoUser *saldo, Keluar transaksi_keluar) {
    if (transaksi_keluar.sumber_dana == 1) {
        if (saldo->dompet_digital - transaksi_keluar.nominal >= 0) {
            saldo->dompet_digital -= transaksi_keluar.nominal;
            saldo->total = saldo->bank + saldo->dompet_digital;
        } 
    }
    else {
        if (saldo->bank - transaksi_keluar.nominal >= 0) {
            saldo->dompet_digital -= transaksi_keluar.nominal;
            saldo->total = saldo->bank + saldo->dompet_digital;
        }
    }
}

void showSaldoUser(SaldoUser saldoUser) {
    printf("SALDO USER\n");
    printf("***************\n");
    printf("Dompet Digital: %.2f\n", saldoUser.dompet_digital);
    printf("Rekening Bank: %.2f\n", saldoUser.bank);
    printf("***************\n");
    printf("TOTAL: %.2f\n", saldoUser.total);
}

#endif