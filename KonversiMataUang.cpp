/*
* Penanggung Jawab  : AMR FADHILAH ABIYYU ALIF BASYSYAR
* NIM               : 231524002
* Kelompok          : A1
*/

#include "KonversiMataUang.h"

/* Daftar Negara dari Mata Uang yang Dikonversikan */
char* NAMA_NEGARA[] = {
                        "Australia", "Brunei Darussalam", "Kanada", "Swiss", "Tiongkok (Offshore)", 
                        "Tiongkok (Onshore)", "Denmark", "Eurozone", "Inggris", "Hong Kong", 
                        "Jepang", "Korea Selatan", "Kuwait", "Laos", "Malaysia", 
                        "Norwegia", "Selandia Baru", "Papua Nugini", "Filipina", "Arab Saudi", 
                        "Swedia", "Singapura", "Thailand", "Amerika Serikat", "Vietnam"
                      };

/* Daftar Mata Uang yang Bisa Dikonversikan Kursnya */
char* MATA_UANG[] = {
                        "AUD",  // Australia
                        "BND",  // Brunei Darussalam
                        "CAD",  // Kanada
                        "CHF",  // Swiss
                        "CNH",  // Tiongkok (Offshore)
                        "CNY",  // Tiongkok (Onshore)
                        "DKK",  // Denmark
                        "EUR",  // Eurozone
                        "GBP",  // Inggris
                        "HKD",  // Hong Kong
                        "JPY",  // Jepang
                        "KRW",  // Korea Selatan
                        "KWD",  // Kuwait
                        "LAK",  // Laos
                        "MYR",  // Malaysia
                        "NOK",  // Norwegia
                        "NZD",  // Selandia Baru
                        "PGK",  // Papua Nugini
                        "PHP",  // Filipina
                        "SAR",  // Arab Saudi
                        "SEK",  // Swedia
                        "SGD",  // Singapura
                        "THB",  // Thailand
                        "USD",  // Amerika Serikat
                        "VND"   // Vietnam
                    };


/* Daftar Kura Mata Uang Berdasarkan List Mata Uang di Atas */
/* Diambil pada tanggal 07/03/2024 pada pukul 14:30 dari Website Bank Indonesia */
double KURS_MATA_UANG[] = { 
                            10192.32,     // AUD - Australia
                            11660.99,     // BND - Brunei Darussalam
                            11506.61,     // CAD - Kanada
                            17687.27,     // CHF - Swiss
                            2168.46,      // CNH - Tiongkok (Offshore)
                            2173.01,      // CNY - Tiongkok (Onshore)
                            2279.03,      // DKK - Denmark
                            16986.68,     // EUR - Eurozone
                            19884.02,     // GBP - Inggris
                            1999.77,      // HKD - Hong Kong
                            104.5748,     // JPY - Jepang
                            11.72,        // KRW - Korea Selatan
                            50833.08,     // KWD - Kuwait
                            0.75,         // LAK - Laos
                            3306.78,      // MYR - Malaysia
                            1479.79,      // NOK - Norwegia
                            9530.56,      // NZD - Selandia Baru
                            4042.51,      // PGK - Papua Nugini
                            279.96,       // PHP - Filipina
                            4171.17,      // SAR - Arab Saudi
                            1506.73,      // SEK - Swedia
                            11660.99,     // SGD - Singapura
                            437.85,       // THB - Thailand
                            15644.39,     // USD - Amerika Serikat
                            0.63          // VND - Vietnam

                        };


/**
 * @brief Mencari Index Kurs Mata Uang Sesuai dengan Mata Uang yang Dipilih User
 * 
 * @param mata_uang 
 * @return int 
 */
int searchIndex(char *mata_uang) {
    int i = 0;
    while (i < sizeof(MATA_UANG)/sizeof(MATA_UANG[0])) {
        if (strcmp(mata_uang, MATA_UANG[i]) == 0) {
            return i;
        }
        i++;
    }
    printf("Mata uang tidak ditemukan.");
}


/**
 * @brief Mengkonversi Mata Uang Asing ke Rupiah
 * 
 * @param mata_uang 
 * @param nominal_mata_uang 
 * @return double 
 */
double konversiKeRupiah(char *mata_uang, double nominal_mata_uang) {
    return nominal_mata_uang * KURS_MATA_UANG[searchIndex(mata_uang)];
}


/**
 * @brief Mengkonversi Rupiah ke Mata Uang Asing
 * 
 * @param mata_uang 
 * @param nominal_rupiah 
 * @return double 
 */
double konversiKeAsing(char *mata_uang, double nominal_rupiah) {
    return nominal_rupiah / KURS_MATA_UANG[searchIndex(mata_uang)];
}


/**
 * @brief Mencetak Mata Uang dengan Format Penulisan Mata Uang pada Umumnya
 * 
 * @param nominal 
 */
void formatMataUang(double nominal) {
    unsigned long long int digit[20];
    int i = 0;
    unsigned long long int temp = (unsigned long long int) nominal;
    if (temp == 0) printf("0");
    while (temp != 0) {
        digit[i] = temp % 10;
        temp = temp / 10;
        i++;
    }
    i--;
    while (i >= 0) {
        printf("%lld", digit[i]);
        if (i % 3 == 0 && i != 0) {
            printf(".");
        }
        i--;
    }
    temp = (unsigned long long int) nominal;
    printf(",%.0f", ((nominal - (double) temp)*100));
}


/**
 * @brief Mencetak Hasil Konversi Mata Uang
 * 
 * @param mata_uang 
 * @param nominal 
 * @param keRupiah 
 */
void cetakHasilKonversi(char *mata_uang, double nominal, bool keRupiah) {
    printf("\033[1;34mHasil Konversi: ");
    printf("\033[1;33m");
    if (keRupiah) {
        formatMataUang(nominal);
        printf(" %s = ", mata_uang);
        formatMataUang(konversiKeRupiah(mata_uang, nominal));
        printf(" IDR\n");
    } else {
        formatMataUang(nominal);
        printf(" IDR = ");
        formatMataUang(konversiKeAsing(mata_uang, nominal));
        printf(" %s\n", mata_uang);
    }
    printf("\033[0m");
}


/**
 * @brief Menampilkan Menu untuk Melakukan Konversi Kurs Mata Uang
 * 
 */
void tampilMenuKonversi() {
    printf("\033[1;34m%5s\t%-20s\t%s\033[0m\n", "[ $ ]", "Nama Negara", "Kurs Mata Uang");
    for (int i = 0; i < 25; i++) {
        printf("[%s]\t%-20s\tRp. ", MATA_UANG[i], NAMA_NEGARA[i]);
        formatMataUang(KURS_MATA_UANG[i]);
        printf("\n");
    }

    char *input;
    int pilihan;
    double nominal;
    input = (char *)malloc(3*sizeof(char));
    printf("\033[1;34mMasukkan Mata Uang yang Ingin Dilakukan Konversi: \033[0m");
    scanf(" %s", input);
    printf("\033[1;34m[1]\033[0m Konversi dari Rupiah ke Mata Uang Asing\n\033[1;34m[2]\033[0m Konversi dari Mata Uang Asing ke Rupiah\n");
    printf("\033[1;34mMasukkan Pilihanmu: \033[0m");
    scanf(" %d", &pilihan);
    toUpperCase(input);
    printf("\033[1;34mMasukan Nominal %s yang Ingin Dikonversikan ke %s: \033[0m", (pilihan==1 ? "IDR" : input), (pilihan==1 ? input : "IDR"));
    scanf(" %lf", &nominal);
    cetakHasilKonversi(input, nominal, pilihan==2);
}
