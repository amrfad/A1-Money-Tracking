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
 * @brief Menampung data saldo user
 * 
 */
 
typedef struct SaldoUser
{
    float dompet_digital = 0;
    float bank = 0;
    float total = this->dompet_digital + this->bank;
} SaldoUser;

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


/**Transaksi Masuk*/
void catatKeuangan(User *user);
void catatTransaksiMasuk(User *user);
void displayTrMasuk(Masuk transaksi_masuk);
void saveToFileMasuk(User *user);

/**Transaksi Keluar*/

void catatTransaksiKeluar(User *user);
void displayTrKeluar(Keluar transaksi_keluar);
void saveToFileKeluar(User *user);

/**Data_Load**/
void readFromFileMasuk(User *user);
void readFromFileKeluar(User *user);
void displayDetailTransaksi(User *user);


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
