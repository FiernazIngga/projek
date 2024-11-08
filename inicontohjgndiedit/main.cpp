#include "functions.cpp"
using namespace std;

int main() {
    int hasil;
    char pilihan1, pilihan2, pilihan_kembali, pilihan_kembali2;

label_logout:
    do {
        // Tampilan Utama
        system("cls");
        cout << "Selamat datang di Perpustakaan Kelas C for Cakep" << endl;
        cout << "1. Tampilkan Buku \n2. Pinjam Buku \n3. Kembalikan Buku \n4. Bayar Denda \n5. Login" << endl;
        cout << "Masukkan pilihan anda (isikan pilihan anda dengan memasukkan angka 1/2/3/4/5) : "; 
        cin >> pilihan1;

        switch (pilihan1) {
            case '1':
                tamp_buku();
                cout << "Apakah anda ingin kembali? y / n : ";
                cin >> pilihan_kembali; 
                break;

            case '2':
                pinjam_buku();
                cout << "Apakah anda ingin kembali? y / n : ";
                cin >> pilihan_kembali; 
                break;

            case '3':
                kembalikan_buku();
                cout << "Apakah anda ingin kembali? y / n : ";
                cin >> pilihan_kembali; 
                break;

            case '4':
                cout << "Apakah anda ingin kembali? y / n : ";
                cin >> pilihan_kembali; 
                break;

            case '5':
                // Tampilan Login
                system("cls");
                cout << setw(19) << setfill('=') << "" << endl;
                cout << "|  Halaman Login  |" << endl;
                cout << setw(19) << setfill('=') << "" << endl;
                cout << "Masukkan username anda : " ;
                cin >> username;
                cout << "Masukkan password anda : ";
                cin >> pass;

                if (username == user[0]) {
                    if (pass == user[1]) {
                        do {
                            do {
                                // Tampilan Setelah Login
                                system("cls");
                                cout << "1. Tambah Daftar Buku \n2. Edit Daftar Buku \n3. Kurangi Daftar Buku \n4. Tampilkan Data Peminjam \n5. Tambah Data Peminjam \n6. Ubah Data Peminjam \n7. Hapus Data Peminjam \n8. Log Out" << endl;
                                cout << "Pilihan : ";
                                cin >> pilihan2;

                                switch (pilihan2) {
                                    case '1':
                                        do {
                                            cout << "Apakah anda ingin kembali? y / n : ";
                                            cin >> pilihan_kembali2;
                                        } while (pilihan_kembali2 != 'y');
                                        break;

                                    case '2':
                                        do {
                                            edit_buku();
                                            cout << "Apakah anda ingin kembali? y / n : ";
                                            cin >> pilihan_kembali2;
                                        } while (pilihan_kembali2 != 'y');
                                        break;

                                    case '3':
                                        do {
                                            cout << "Apakah anda ingin kembali? y / n : ";
                                            cin >> pilihan_kembali2;
                                        } while (pilihan_kembali2 != 'y');
                                        break;

                                    case '4':
                                        do {
                                            tamp_anggota();
                                            cout << "Apakah anda ingin kembali? y / n : ";
                                            cin >> pilihan_kembali2;
                                        } while (pilihan_kembali2 != 'y');
                                        break;

                                    case '5':
                                        do {
                                            tambah();
                                            cout << "Apakah anda ingin kembali? y / n : ";
                                            cin >> pilihan_kembali2;
                                        } while (pilihan_kembali2 != 'y');
                                        break;

                                    case '6':
                                        ubah();
                                        break;

                                    case '7':
                                        do {
                                            hapus();
                                            cout << "Apakah anda ingin menghapus data lagi? (y / n) : "; 
                                            cin >> pilihan_hapus;
                                        } while (pilihan_hapus == 'y');
                                        break;

                                    case '8':
                                        goto label_logout;
                                        break;

                                    default:
                                        cout << "Pilihan yang anda masukkan salah. \nMasukkan lagi pilihan anda dengan benar." << endl;
                                        break;
                                }
                            } while (pilihan_kembali2 == 'y');
                        } while (pilihan2 != ('1', '2', '3', '4', '5', '6', '7'));
                        
                    } else {
                        cout << "Password yang anda masukkan salah!!!" << endl;
                    }
                } else {
                    cout << "Username yang anda masukkan salah!!!" << endl;
                }

                break;

            default:
                break;
        }
    } while (pilihan_kembali == 'y');

    system("pause");
    return 0;
}

//kontol
