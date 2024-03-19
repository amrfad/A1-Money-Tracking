from msvcrt import getch
from os import system
from tgl import Tanggal

class Masuk:
    def __init__(self):
        self.tanggal = Tanggal()
        self.nominal = 0
        self.sumber_dana = 0
        self.inputMasuk()

    def inputMasuk(self):
        system("cls")
        while True:
            print("Masukkan Sumber Dana:")
            print("1) Dompet Digital")
            print("2) Rekening Bank")
            self.sumber_dana = int(input("Input: "))
            if self.sumber_dana != 1 and self.sumber_dana != 2:
                system("cls")
                print("ERROR INPUT: Input yang dimasukkan tidak valid.")
                continue
            break
        self.nominal = -1
        while self.nominal < 0:
            self.nominal = int(input("Masukkan Nominal Deposit: "))
            if self.nominal < 0:
                system("cls")
                print("ERROR INPUT: Input yang dimasukkan tidak valid.")
    
    def showMasuk(self):
        print("TRANSAKSI MASUK")
        print("***************")
        self.tanggal.showTanggal()
        print("Dompet Digital:") if (self.sumber_dana == 1) else print("Rekening Bank:")
        print("+Rp", self.nominal)
        print("***************")
        print("Tekan apapun untuk kembali ke menu awal")
        getch()