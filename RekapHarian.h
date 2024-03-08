/**
 * @file RekapHarian.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef REKAP_HARIAN_H
#define REKAP_HARIAN_H

#include "User.h"
#include "KonversiMataUang.h"

bool isSameDay(Tanggal tanggal1, Tanggal tanggal2);
void rekapHarianMasuk(User user, Tanggal tanggalRekap);
void rekapHarianKeluar(User user, Tanggal tanggalRekap);
void rekapHarianTotal(User user, Tanggal tanggalRekap);
void tampilMenuRekapHarian(User user);

#endif