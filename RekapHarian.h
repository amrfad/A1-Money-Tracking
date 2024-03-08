/**
 * @file RekapHarian.h
 * @author Penanggung Jawab: AMR FADHILAH ABIYYU ALIF BASYSYAR [ 231524002 ]
 * @brief Berisi deklarasi fungsi dan prosedur yang akan digunakan pada fitur rekap harian
 * @version 0.2
 * @date 2024-03-08
 * 
 * @copyright Copyright (c) 2024 AMR FADHILAH ABIYYU ALIF BASYSYAR
 * 
 */

#ifndef REKAP_HARIAN_H
#define REKAP_HARIAN_H

#include <windows.h>
#include "User.h"
#include "KonversiMataUang.h"

/* Prototype Prosedur dan Fungsi yang Akan Digunakan */
bool isSameDay(Tanggal tanggal1, Tanggal tanggal2);
void rekapHarianMasuk(User user, Tanggal tanggalRekap);
void rekapHarianKeluar(User user, Tanggal tanggalRekap);
void rekapHarianTotal(User user, Tanggal tanggalRekap);
void tampilMenuRekapHarian(User user);

#endif