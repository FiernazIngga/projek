#include "buku.h"
#define max 100

// user[][] = {nim, fakultas, email, password, buku 1, buku 2, buku 3}

string user[max][7];
string nim, fakultas, password, email, fakul;
char pass[100], konfirmasi, ulang;
int login, pengguna, daftaruser=0;



void daftar(){
	char ulang;
	cout << "Masukkan NIM                            : ";
	cin >> nim;
	cout << "Masukkan Fakultas (FTI/FEB/FISIP/FTM/FP): ";
	cin >> fakul;
	do {
        if (ulang == 'y') {
            cout << "Email yang anda masukkan bukan email kampus.\nGunakan email kampus yang terdapat @student.upnyk.ac.id" << endl;
        }
        ulang = 'n';
        cout << "Masukkan Email Kampus   : ";
        cin >> email;
        cin.ignore();
        // Cek apakah email mengandung @kampus.ac
        if (email.size() >= 20 && email.substr(email.size() - 20) == "@student.upnyk.ac.id") {
            ulang = 'n';
        } else {
            ulang = 'y';
        }
    } while (ulang == 'y');
	do
	{
		if (ulang == 'y') {
            cout << "Isikan password minimal 8 karakter!!" << endl;
        }
        ulang = 'n';
		cout << "Masukkan Password Bebas : ";
		cin.getline(pass,sizeof(pass));
		if (strlen(pass) >= 8)
		{
			user[daftaruser][0] = nim;
			user[daftaruser][1] = fakul;
			user[daftaruser][2] = email;
			user[daftaruser][3] = pass;
            cout << user[daftaruser][0] << " " << user[daftaruser][1] << " "<< user[daftaruser][2] <<  " " << user[daftaruser][3] << endl;
			daftaruser++;
		} else {
			ulang = 'y';
		}
	} while (ulang == 'y');
}


void pinjam(){
	konfirmasi = 'n', ulang = 'n';
	int pilihan;
	string judulBuku;
	cout << "Selamat datang di Perpustakaan IF-C" << endl;
	cout << "Pilih buku anda berdasarkan \1. Judul buku \n2.Genre buku \n3. Tahun terbit buku \n4. Asal Negara \n5. Penulis : ";
	cin >> pilihan;
	switch (pilihan)
	{
	case 1:
		do
		{
			konfirmasi = 'n', ulang = 'n';
			for (int i = 0; i < 99; i++)
			{
				cout << i+1 <<" "<< buku[i][0] << endl;
			}
			cout << "Masukkan nomor dari judul buku yang ingin anda pinjam : ";
			getline(cin, judulBuku);
			for (int i = 0; i < 99; i++)
			{
				if (judulBuku == buku[i][0])
				{
					cout << "Apakah anda ingin meminjam buku " << buku[i][0] << " ? ";
					cin >> konfirmasi;
					if (konfirmasi == 'y')
					{
						user[pengguna][5] = buku[i][0];
					} else {
						ulang = 'y';
					}
				}
			}
		} while (ulang == 'y');
		break;
	// case 2:
	// 	/* code */
	// 	break;
	// case 3:
	// 	/* code */
	// 	break;
	// case 4:
	// 	/* code */
	// 	break;
	// case 5:
	// 	/* code */
	// 	break;
	
	default:
		break;
	}
	// for (int i = 0; i < 6; i++)
	// {
		
	// }
	
}


void tampil(){
	int pilihan;
	cout << user[pengguna][0] << endl;
	cout << user[pengguna][1] << endl;
}



















































void cetakSemuaBuku(){
	char kembali;
	do
	{
		kembali = 'n';
		system("cls");
		cout << "Daftar buku-buku yang terdapat di Perpustakaan IF-C" << endl;
		cout << setw(123) << setfill('=') << "" << endl;
		cout << setfill(' ');
		cout << "NO  |  Judul Buku                                             | Tahun   | Genre                | Negara        | Tersedia  |" << endl;
		cout << setw(124) << setfill('-') << "-" << endl;  
		cout << setfill(' ');
		cout << endl;
		for (int i = 0; i < 99; i++)
		{      
				cout << setw(2) << i + 1 << " | "
							<< setw(55) << left << buku[i][0] << " | "
							<< setw(7) << left << buku[i][3] << " | " 
							<< setw(20) << left << buku[i][4] << " | " 
							<< setw(13) << left << buku[i][5] << " | " 
							<< setw(9) << left << buku[i][6] << " | " << endl;
				cout << setw(124) << setfill('-') << "-" << endl;
				cout << setfill(' ');
		}
		cout << "Tekan y untuk keluar : ";
		cin >> kembali;
	} while (kembali == 'n' || kembali == 'N');
	
}