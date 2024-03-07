/*
* Penanggung Jawab  : AMR FADHILAH ABIYYU ALIF BASYSYAR
* NIM               : 231524002
* Kelompok          : A1
*/

#ifndef KONVERSI_MATA_UANG_H
#define KONVERSI_MATA_UANG_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Utilities.h"

/* Deklarasi Variabel Global Berupa Informasi Mengenai Mata Uang */
extern char* NAMA_NEGARA[];
extern char* MATA_UANG[];
extern double KURS_MATA_UANG[];

/* Deklarasi Fungsi dan Prosedur yang Digunakan dalam Proses Konversi Kurs Mata Uang */
int searchIndex(char *mata_uang);
double konversiKeRupiah(char *mata_uang, double nominal_mata_uang);
double konversiKeAsing(char *mata_uang, double nominal_rupiah);
void formatMataUang(double nominal);
void cetakHasilKonversi(char *mata_uang, double nominal, bool keRupiah);
void tampilMenuKonversi();

#endif