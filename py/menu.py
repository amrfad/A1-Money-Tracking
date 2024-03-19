from os import system
from msk import Masuk

class Menu:
    def __init__(self):
        self.choice = 0
        pass

    def tampilMenu(self) -> None:
        """
        Menampilkan menu utama dan alur utama program

        Args:
            self

        Returns:
            none
        """
        while (self.choice == 0):
            system("cls")
            self.banner()
            print("\033[1;34mSELAMAT DATANG DI APLIKASI MONEY TRACKING!\033[0m")
            # print("Halo, \033[33m%s\033[0m. Saldo Totalmu Adalah: \033[36mRp. ", user.nama);
            # formatMataUang(user.saldo.total);
            print("\033[0m")
            print("\033[1;32m[1]\033[0m masuk catat keuangan")
            print("\033[1;32m[2]\033[0m cek saldo")
            print("\033[1;32m[3]\033[0m rekap per hari")
            print("\033[1;32m[4]\033[0m rekap per pekan")
            print("\033[1;32m[5]\033[0m rekap per bulan")
            print("\033[1;32m[6]\033[0m load data (tampilin semua entrinya)")
            print("\033[1;32m[7]\033[0m konversi mata uang")
            print("\033[1;32m[8]\033[0m laporan keuangan")
            print("\033[1;32m[0]\033[0m keluar")
            self.choice = int(input("\033[34mPilih Menu: \033[0m"))
            if self.choice == 1:
                aMasuk = Masuk()
                aMasuk.showMasuk()
                list_masuk =[]
                list_masuk.append(aMasuk)
                self.choice = 0
            elif self.choice == 0:
                break
        exit()
    
    def banner(self):
        print(" /$$      /$$                                               /$$$$$$$$                           /$$       /$$                    ")
        print("| $$$    /$$$                                              |__  $$__/                          | $$      |__/                    ")
        print("| $$$$  /$$$$  /$$$$$$  /$$$$$$$   /$$$$$$  /$$   /$$         | $$  /$$$$$$  /$$$$$$   /$$$$$$$| $$   /$$ /$$ /$$$$$$$   /$$$$$$ ")
        print("| $$ $$/$$ $$ /$$__  $$| $$__  $$ /$$__  $$| $$  | $$         | $$ /$$__  $$|____  $$ /$$_____/| $$  /$$/| $$| $$__  $$ /$$__  $$")
        print("| $$  $$$| $$| $$  \\ $$| $$  \\ $$| $$$$$$$$| $$  | $$         | $$| $$  \\__/ /$$$$$$$| $$      | $$$$$$/ | $$| $$  \\ $$| $$  \\ $$")
        print("| $$\\  $ | $$| $$  | $$| $$  | $$| $$_____/| $$  | $$         | $$| $$      /$$__  $$| $$      | $$_  $$ | $$| $$  | $$| $$  | $$")
        print("| $$ \\/  | $$|  $$$$$$/| $$  | $$|  $$$$$$$|  $$$$$$$         | $$| $$     |  $$$$$$$|  $$$$$$$| $$ \\  $$| $$| $$  | $$|  $$$$$$$")
        print("|__/     |__/ \\______/ |__/  |__/ \\_______/ \\____  $$         |__/|__/      \\_______/ \\_______/|__/  \\__/|__/|__/  |__/ \\____  $$")
        print("                                            /$$  | $$                                                                   /$$  \\ $$")
        print("                                           |  $$$$$$/                                                                  |  $$$$$$/")
        print("                                            \\______/                                                                    \\______/ ")