#include "function.h"
main(){
	do
	{
		system("cls");
		pinjam();
		cout << "Apakah anda ingin kembali? y / n : ";
		cin >> kembali_anggota;
	} while (kembali_anggota == 'n' || kembali_anggota == 'N');

	ketAnggota();
	
}