#include "buku.h"
#define max 100

// user[][] = {nim, fakultas, email, password, buku 1, buku 2, buku 3}

string user[max][7];
string nim, fakultas, password, email, fakul, genreBuku, negaraBuku;
char pass[100], konfirmasi, ulang;
int login, pengguna, daftaruser=0, indeksBuku = 4;



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

void genreSemuaBuku(){
    for (int i = 0; i < 99; i++)
    {
        for (int j = 0; j < 99; j++)
        {
            if (buku[i][4] != buku[i++][4]){
                if ( buku[j][4] != buku[j++][4])
                {
                    cout << buku[i][4] << endl;
                }
            }
        }
    }
}

void negaraSemuaBuku(){
    for (int i = 0; i < 99; i++)
    {
        for (int j = 0; j < 99; j++)
        {
            if (buku[i][5] != buku[i++][5]){
                if ( buku[j][5] != buku[j++][5])
                {
                    cout << buku[i][5] << endl;
                }
            }
        }
    }
}

void pinjam(){
	konfirmasi = 'n', ulang = 'n';
	int pilihan;
	string judulBuku;
	cout << "Selamat datang di Perpustakaan IF-C" << endl;
	cout << "Pilih buku anda berdasarkan \n1. Judul buku \n2.Genre buku \n3. Asal Negara : ";
	cin >> pilihan;
    cin.ignore();
	switch (pilihan)
	{
	case 1:
		do
		{
			konfirmasi = 'n', ulang = 'n';
            bool cekBuku = false;
			for (int i = 0; i < 99; i++)
			{
				cout << i+1 <<" "<< buku[i][0] << ". Keterangan Buku : " << buku[i][6] << endl;
			}
			cout << "Masukkan judul buku yang ingin anda pinjam : ";
			getline(cin, judulBuku);
			for (int i = 0; i < 99; i++)
			{
				if (judulBuku == buku[i][0])
				{
                    cekBuku = true;
					if (buku[i][6] == "Tersedia")
                    {
                        cout << "Apakah anda ingin meminjam buku " << buku[i][0] << " ? ";
                        cin >> konfirmasi;
                        if (konfirmasi == 'y')
                        {
                            if (indeksBuku > 6)
                            {
                                cout << "Anda telah memenuhi batasan peminjaman buku.\nSilahkan kembalikan buku terlebih dahulu." << endl;
                            } else {
                                user[pengguna][indeksBuku] = buku[i][0];
                                buku[i][6] = "Dipinjam";
                                indeksBuku++;
                            }
                        } else {
                            ulang = 'y';
                        }
                    } else {
                        cout << "Buku telah dipinjam, silahkan pinjam buku yang lain." << endl;
                        cout << "Apakah anda ingin memilih buku yang lain? (y/n): ";
                        cin >> ulang;
                    }
				}
			}
            if (!cekBuku)
            {
                system("cls");
                cout << "Buku yang anda cari tidak ada. \nPastikan anda mengetiknya dengan benar!!" << endl;
                ulang = 'y';
                system("pause");
            }
		} while (ulang == 'y');
		break;
	case 2:
    do
    {
        konfirmasi = 'n', ulang = 'n';
        bool cekBuku = false;
        int noBuku = 1;
        genreSemuaBuku();
        cin.ignore();
        cout << "Masukkan genre buku yang ingin anda pinjam : ";
        getline(cin, genreBuku);
        for (int i = 0; i < 99; i++)
        {
            if (buku[i][4] == genreBuku)
            {
                cout << setw(2) << noBuku << " | "
							<< setw(55) << left << buku[i][0] << " | "
							<< setw(7) << left << buku[i][4] << endl;
                            noBuku++;
            }   
        }
        cout << "Masukkan judul buku yang ingin anda pinjam : ";
        getline(cin, judulBuku); 
        for (int i = 0; i < 99; i++)
        {
            if (judulBuku == buku[i][0])
            {
                cekBuku = true;
                if (buku[i][6] == "Tersedia")
                {
                    cout << "Apakah anda ingin meminjam buku " << buku[i][0] << " ? ";
                    cin >> konfirmasi;
                    if (konfirmasi == 'y')
                    {
                        if (indeksBuku > 6)
                        {
                            cout << "Anda telah memenuhi batasan peminjaman buku.\nSilahkan kembalikan buku terlebih dahulu." << endl;
                        } else {
                            user[pengguna][indeksBuku] = buku[i][0];
                            buku[i][6] = "Dipinjam";
                            indeksBuku++;
                        }
                    } else {
                        ulang = 'y';
                    }
                } else {
                    cout << "Buku telah dipinjam, silahkan pinjam buku yang lain." << endl;
                    cout << "Apakah anda ingin memilih buku yang lain? (y/n): ";
                    cin >> ulang;
                }
                
            }
        }
        if (!cekBuku)
            {
                system("cls");
                cout << "Buku yang anda cari tidak ada. \nPastikan anda mengetiknya dengan benar!!" << endl;
                ulang = 'y';
                system("pause");
            }
    } while (ulang == 'y');
		break;
	case 3:
	do
    {
        system("cls");
        konfirmasi = 'n', ulang = 'n';
        bool cekBuku = false;
        int noBuku = 1;
        negaraSemuaBuku();
        cout << "Masukkan negara buku yang ingin anda pinjam : ";
        getline(cin, negaraBuku);
        for (int i = 0; i < 99; i++)
        {
            if (buku[i][5] == negaraBuku)
            {
                cout << setw(2) << noBuku << " | "
							<< setw(55) << left << buku[i][0] << " | "
							<< setw(7) << left << buku[i][5] << endl;
                            noBuku++;
            }   
        }
        cout << "Masukkan judul buku yang ingin anda pinjam : ";
        getline(cin, judulBuku); 
        for (int i = 0; i < 99; i++)
        {
            if (judulBuku == buku[i][0])
            {
                cekBuku = true;
                if (buku[i][6] == "Tersedia")
                {
                    cout << "Apakah anda ingin meminjam buku " << buku[i][0] << " ? ";
                    cin >> konfirmasi;
                    if (konfirmasi == 'y')
                    {
                        if (indeksBuku > 6)
                        {
                            cout << "Anda telah memenuhi batasan peminjaman buku.\nSilahkan kembalikan buku terlebih dahulu." << endl;
                        } else {
                            user[pengguna][indeksBuku] = buku[i][0];
                            buku[i][6] = "Dipinjam";
                            indeksBuku++;
                        }
                    } else {
                        ulang = 'y';
                    }
                } else {
                    cout << "Buku telah dipinjam, silahkan pinjam buku yang lain." << endl;
                    cout << "Apakah anda ingin memilih buku yang lain? (y/n): ";
                    cin >> ulang;
                }
                
            }
        }
        if (!cekBuku)
            {
                system("cls");
                cout << "Buku yang anda cari tidak ada. \nPastikan anda mengetiknya dengan benar!!" << endl;
                ulang = 'y';
                system("pause");
            }
    } while (ulang == 'y');
		break;
	default:
		break;
	}
}


void tampil(){
	int pilihan;
    cout << endl;
	cout << user[pengguna][0] << "0" << endl;
	cout << user[pengguna][1] << "1"  << endl;
	cout << user[pengguna][2] << "2"  << endl;
	cout << user[pengguna][3] << "3"  << endl;
	cout << user[pengguna][4] << "4"  << endl;
	cout << user[pengguna][5] << "5"  << endl;
	cout << user[pengguna][6] << endl;
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
		cout << "NO |  Judul Buku                                             | Tahun   | Genre                | Negara        | Tersedia  |" << endl;
		cout << setw(124) << setfill('-') << "-" << endl;  
		cout << setfill(' ');
		for (int i = 0; i < 99; i++)
		{      
				cout <<setw(2)<<setfill(' ') << i + 1 << " | "
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