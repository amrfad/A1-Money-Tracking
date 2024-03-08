#ifndef Money_H
#define Money_H

// ! Struct Tanggal S T A R T
/**
 * @brief Menampung tanggal transaksi
 * 
 */
typedef struct Tanggal
{
    int tanggal; // 1--30
    int pekan;   // kita yg kalkulasi
    int bulan;   // 1--12
    int tahun;
} Tanggal;

/**
 * @brief Membuat instance dari objek Tanggal
 *
 * @param Tanggal - Alamat dari instance yang akan diinisialisasi
 * @param tanggal - Tanggal dilakukan transaksi
 * @param bulan - Bulan dilakukan transaksi
 * @param tahun - Tahun dilakukan transaksi
 */
void newTanggal(Tanggal *record, int tanggal, int bulan, int tahun);

/**
 * @brief apakah tanggal yang direkam valid
 * 
 * @param tanggal - Tanggal dilakukan transaksi
 * @param bulan - Bulan dilakukan transaksi
 * @param tahun - Tahun dilakukan transaksi
 * @return true - Jika tanggal yang direkam valid
 * @return false - Jika tanggal yang direkam tidak valid
 */
bool isValidTanggal(int tanggal, int bulan, int tahun);

/**
 * @brief Membuat instance tanggal baru berdasarkan input user
 * 
 * @return Tanggal - instance Tanggal yang telah diinput
 */
Tanggal inputTanggal();

/**
 * @brief Menampilkan waktu transaksi
 * 
 * @param tanggal - Waktu transaksi yang ingin ditampilkan
 */
void showTanggal(Tanggal tanggal);

// ! Struct Tanggal  E N D

// ! Struct Masuk S T A R T

/**
 * @brief Menampung data transaksi masuk
 * 
 */
typedef struct Masuk
{
    Tanggal waktu;   // belum fix
    int sumber_dana; // 1. dompet dig/ 2. bank
    float nominal;
} Masuk;

/**
 * @brief Membuat instance dari objek Tanggal
 *
 * @param transaksi_masuk - Alamat dari instance yang akan diinisialisasi
 * @param waktu_transaksi - Waktu dilakukannya transaksi
 * @param sumber_dana - [1. Dompet Digital], [2. Rekening Bank]
 * @param nominal - Nominal uang yang dideposit
 */
void newMasuk(Masuk *transaksi_masuk, Tanggal waktu_transaksi, int sumber_dana, float nominal);

/**
 * @brief Membuat instance Masuk baru berdasarkan input user
 * 
 * @return Masuk - instance Masuk yang telah diinput
 */
Masuk inputMasuk();

/**
 * @brief Menampilkan transaksi yang masuk
 * 
 * @param transaksi_masuk - objek transaksi yang akan ditampilkan
 */
void showMasuk(Masuk transaksi_masuk);

// ! Struct Masuk E N D

#endif