from os import system

class Tanggal:
    def __init__(self) -> None:
        system("cls")
        temp_tanggal = input("Masukkan Tanggal Transaksi [Contoh: 01 01 2024]: ")
        temp_tanggal = temp_tanggal.split()
        self.tanggal = int(temp_tanggal[0])
        self.bulan = int(temp_tanggal[1])
        self.tahun = int(temp_tanggal[2])
        
        while not self.isValidTanggal():
            temp_tanggal = input("Masukkan Tanggal Transaksi [Contoh: 01 01 2024] : ")
            temp_tanggal = temp_tanggal.split()
            self.tanggal = int(temp_tanggal[0])
            self.bulan = int(temp_tanggal[1])
            self.tahun = int(temp_tanggal[2])
            if not self.isValidTanggal():
                system("cls")
                print("ERROR INPUT: Tanggal yang dimasukkan tidak valid.\n")
                continue
            if self.tanggal >= 1 and self.tanggal <=7:
                self.pekan = 1
            elif self.tanggal >=8 and self.tanggal <= 14:
                self.pekan = 2
            elif self.tanggal >= 15 and self.tanggal <= 21:
                self.pekan = 3
            else:
                self.pekan = 4
    
    def isValidTanggal(self):
        daysInMonth = [31, 28 + (self.tahun % 4 == 0 and (self.tahun % 100 != 0 or self.tahun % 400 ==0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if self.tahun < 0 or self.bulan < 1 or self.bulan > 12 or self.tanggal < 1:
            return False
        elif self.tanggal <= daysInMonth[self.bulan-1]:
            return True
    
    def showTanggal(self):
        print("Tanggal Transaksi:       ", self.tanggal, self.bulan, self.tahun)