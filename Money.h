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

// ! Struct Keluar S T A R T

/**
 * @brief Menampung data transaksi keluar
 * 
 */
typedef struct Keluar
{
    Tanggal waktu;
    int sumber_dana;
    float nominal;
    int kategori;
} Keluar;

/**
 * @brief Membuat instance dari objek Keluar
 * 
 * @param transaksi_keluar - Alamat dari instance yang akan diinisialisasi
 * @param waktu - Waktu dilakukannya transaksi
 * @param sumber_dana - [1. Dompet Digital], [2. Rekening Bank]
 * @param nominal - Nominal uang yang dideposit
 * @param kategori - [1. Makanan], [2. Transportasi], [3. Hiburan], [4. Tagihan], [5. Lain-lain]
 */
void newKeluar(Keluar *transaksi_keluar, Tanggal waktu, int sumber_dana, float nominal, int kategori);

/**
 * @brief Membuat instance Keluar baru berdasarkan input user
 * 
 * @return Keluar - instance Keluar yang telah diinput
 */
Keluar inputKeluar();

/**
 * @brief Menampilkan objek Keluar
 * 
 * @param transaksi_keluar - Objek Keluar yang akan ditampilkan
 */
void showKeluar(Keluar transaksi_keluar);

// ! Struct Keluar E N D

// ! Struct SaldoUser S T A R T

/**
 * @brief Menampung Saldo uang yang dimiliki
 * 
 */
typedef struct SaldoUser
{
    float dompet_digital = 0;
    float bank = 0;
    float total = this->dompet_digital + this->bank;
} SaldoUser;

/**
 * @brief Mengecek saldo yang dimiliki user dari sumber dana tertentu
 * 
 * @param saldo - Objek saldo yang ingin dicek
 * @param sumber_dana - [1) Dompet Digital] / [2) Rekening Bank]
 * @return float 
 */
float cekSaldo(SaldoUser saldo, int sumber_dana);

/**
 * @brief Menambah saldo user berdasarkan transaksi_masuk
 * 
 * @param saldo - Objek saldo yang akan ditambah
 * @param transaksi_masuk - Objek transaksi masuk
 */
void saldoMasuk(SaldoUser *saldo, Masuk transaksi_masuk);

/**
 * @brief Mengurangi saldo user berdasarkan transaksi_keluar
 * 
 * @param saldo - Objek saldo yang akan dikurang
 * @param transaksi_keluar - Objek transaksi keluar
 */
void saldoKeluar(SaldoUser *saldo, Keluar transaksi_keluar);

/**
 * @brief Menampilkan informasi saldo user
 * 
 * @param saldoUser - saldo user yang akan ditampilkan
 */
void showSaldoUser(SaldoUser saldoUser);

// ! Struct SaldoUser E N D

// ! Struct User S T A R T

/**
 * @brief Menampung objek user
 * 
 */
typedef struct User
{
    const char *nama = "JAJANG RASING UZUMAKI";
    SaldoUser saldo;
    Masuk transaksi_masuk[365];
    int indeksMasuk = 0;
    Keluar transaksi_keluar[500];
    int indeksKeluar = 0;
} User;

/**
 * @brief Melakukan transaksi masuk untuk menambah saldo user
 * 
 * @param user - Objek user
 */
void transaksiMasuk(User *user);

/**
 * @brief Melakukan transaksi keluar yang akan mengurangi saldo user
 * 
 * @param user - Objek user
 */
void transaksiKeluar(User *user);

/**
 * @brief Menampilkan riwayat transaksi masuk
 * 
 * @param user - Objek user
 */
void showRiwayatMasuk(User user);

/**
 * @brief Menampilkan riwayat transaksi keluar
 * 
 * @param user - Objek user
 */
void showRiwayatKeluar(User user);

// ! Struct User E N D

#endif