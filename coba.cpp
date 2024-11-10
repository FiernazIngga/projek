#include "function.h"

using namespace std;

main(){
    system("cls");
    ketAnggota();
    bacaBuku();
}     

void pinjam(){
	system("cls");
	char konfirmasi;
	int pilihan;
	if (user[pengguna][7].empty())
	{
		cout << "Selamat datang di Perpustakaan IF-C" << endl;
		do
			{
				if (user[pengguna][7].empty())
				{
					konfirmasi = 'n', ulang = 'n';
					for (int i = 0; i < 99; i++)
					{
						cout << i+1 <<" "<< buku[i][0] << " Keterangan Buku : " << buku[i][6] << endl;
					}
					cout << "Masukkan nomor dari judul buku yang ingin anda pinjam : ";
					cin >> pilihan;
					if (buku[pilihan-1][6] == "Tersedia")
					{
						system("cls");
						cout << "Judul        : " << buku[pilihan-1][0] << endl;
						cout << "Penulis      : " << buku[pilihan-1][1] << endl;
						cout << "Penerbit     : " << buku[pilihan-1][2] << endl;
						cout << "Tahun terbit : " << buku[pilihan-1][3] << endl;
						cout << "Genre        : " << buku[pilihan-1][4] << endl;
						cout << "Asal         : " << buku[pilihan-1][5] << endl;
						cout << "Apakah anda yakin ingin meminjam buku " << buku[pilihan-1][0] << " y/n : ";
						cin >> konfirmasi;
						if (konfirmasi == 'y')
						{
							buku[pilihan-1][6] = "Dipinjam";
							user[pengguna][indeksBuku] = buku[pilihan-1][0];
							indeksBuku++; 
						} else {
							cout << "Apakah anda ingin meminjam buku yang lain? y/n : ";
							cin >> ulang;
						}
					} else {
						cout << "Buku " << buku[pilihan-1][0] << " telah dipinjam. \nSilahkan pinjam buku yang lain!" << endl;
						system("pause");
						ulang = 'y';
					}
				} else {
					cout << "Anda telah memenuhi batasan peminjaman. \nSilahkan kembalikan buku yang anda pinjam untuk meminjam buku lainnya!" << endl;
				}
			} while (ulang == 'y');
	} else {
		cout << "Anda telah memenuhi batasan peminjaman. \nSilahkan kembalikan buku yang anda pinjam untuk meminjam buku lainnya!" << endl;
	}
}