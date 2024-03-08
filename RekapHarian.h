/**
 * @file RekapHarian.h
 * @author Penanggung Jawab: AMR FADHILAH ABIYYU ALIF BASYSYAR [ 231524002 ]
 * @brief Berisi deklarasi fungsi dan prosedur yang akan digunakan pada fitur rekap harian
 * @version 0.3
 * @date 2024-03-07
 * 
 * @copyright Copyright (c) 2024 KELOMPOK A1
 * 
 */

#ifndef REKAP_HARIAN_H
#define REKAP_HARIAN_H

#include "Money.h"
#include "KonversiMataUang.h"

bool isSameDay(Tanggal tanggal1, Tanggal tanggal2);
void rekapHarianMasuk(User user, Tanggal tanggalRekap);
void rekapHarianKeluar(User user, Tanggal tanggalRekap);
void rekapHarianTotal(User user, Tanggal tanggalRekap);
void tampilMenuRekapHarian(User user);

#endif