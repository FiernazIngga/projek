#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//nbl
//raihan
//kontol
//fiernazanjing
#define max 10
string mhs[max][4], user[2] = {"admin","123"}, username, pass, nim_baru, nama_baru, jurusan_baru, buku[10][5] = {{"The Pragmatic Programmer: Your Journey to Mastery","Andrew Hunt, David Thomas","Addison-Wesley Professional","1999","Tersedia"},{"Clean Code: A Handbook of Agile Software Craftsmanship","Robert C. Martin","Prentice Hall","2008","Tersedia"},{"Code Complete: A Practical Handbook of Software Construction","Steve McConnell","Microsoft Press","2004","Tersedia"},{"Introduction to Algorithms","Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein","MIT Press","2009","Tersedia"},{"Structure and Interpretation of Computer Programs","Harold Abelson, Gerald Jay Sussman, Julie Sussman","MIT Press","1996","Tersedia"},{"Sang Pemimpi","Andrea Hirata","Bentang Pustaka","2006","Tersedia"},{"Daun yang Jatuh Tak Pernah Membenci Angin","Tere Liye","Gramedia Pustaka Utama","2010","Tersedia"},{"Jejak Langkah","Pramoedya Ananta Toer","Hasta Mitra","1985","Tersedia"},{"Cantik Itu Luka","Eka Kurniawan","Gramedia Pustaka Utama", "2002","Tersedia"},{"Laskar Pelangi","Andrea Hirata", "Bentang Pustaka","2005","Tersedia"}};
string nim_peminjam, temp1, temp2, temp3, temp4;
char pilihan_ubah, loop, pilihan_hapus, pilihanpinjam, pilihan_kembalikan, pilubah_buku, koreksi_data, ulangi_isi;
int pos = 1, dis = 0, ubah_data, data_baru, hapus_data, array_hapus, pilihanBuku, buku_pinjam, data_pinjam = 0, no_buku_peminjam, ubah_buku, buku_baru;

void pinjam_buku();
void tamp_anggota();

void tambah(){
    do
    {
        system("cls");
        if(pos < max){
            for (int i = 0; i < pos ; i++)
            {
                do
                {
                    ulangi_isi = 'n';
                    system("cls");
                    cin.ignore();
                    cout << "Tambah data : " << endl;
                    cout << "NIM = " ;
                    getline(cin, temp1); 
                    cout << "Nama = " ;
                    getline(cin, temp2); 
                    cout << "Jurusan = " ;
                    getline(cin, temp3); 
                    cout << "No buku yang akan dipinjam 1/2/3/4/... : ";
                    cin >> pilihanBuku;
                    if (buku[pilihanBuku - 1][4] == "Dipinjam")
                    {
                        cout << "Buku telah dipinjam, silahkan pinjam buku yang lain." << endl;
                        cout << "Apakah anda ingin memilih buku yang lain? (y/n): ";
                        cin >> loop;
                        cin.ignore();
                    } else {
                        cout << "Apakah data yang anda masukkan sudah benar? y / n : ";
                        cin >> koreksi_data;
                        if (koreksi_data == 'y')
                        {
                            mhs[i][0] = temp1;
                            mhs[i][1] = temp2;
                            mhs[i][2] = temp3;
                            mhs[i][3] = buku[pilihanBuku-1][0];
                            buku[pilihanBuku - 1][4] = "Dipinjam";
                            dis++;
                            system("cls");
                            cout << "Data tersimpan" << endl;
                            tamp_anggota();
                            cout << "Ulangi Program y/n : ";
                            cin >> loop;
                            ++pos;
                        } else {
                            ulangi_isi = 'y';
                        }
                    }
                } while (ulangi_isi == 'y');
            }
        } else {
            cout << "Memori penuh" << endl;
            cout << "Ketikkan n untuk kembali : ";
            cin >> loop;
        }
    } while (loop == 'y');
}

void tamp_buku(){     
    system("cls");
    cout << "Daftar buku-buku yang terdapat di Perpustakaan IF-C" << endl;
    for (int i = 0; i < 10; i++)
    {      
        cout << "\n" << i+1 << ". Judul buku = " << buku[i][0] << "\n   Pengarang =  " << buku[i][1] << "\n   Penerbit = " << buku[i][2] << "\n   Tahun terbit = " << buku[i][3] << "\n   Status : " << buku[i][4] << endl; 
    }
}

void tamp_anggota(){
    system("cls");
    if (dis > 0)
    {
        cout << "Data tersimpan" << endl;
        for (int i = 0; i < dis; i++)
        {
            cout << i + 1 << ". ";
            cout << "Nim: " << mhs[i][0] << ", Nama: ";
            cout << mhs[i][1] << ", Jurusan: ";
            cout << mhs[i][2] << ", Buku yang dipinjam: ";
            cout << mhs[i][3] << endl;
        }
    } else {
        cout << "Data kosong" << endl;
    }
    
}

void tamp_buku2(){
    system("cls");
    cout << "Daftar buku-buku yang terdapat di Perpustakaan IF-C" << endl;
    cout << setw(86) << setfill('=') << "" << endl;
    cout << setfill(' ');
    for (int i = 0; i < 10; i++)
    {      
        cout << setw(2) << i + 1 << ". | "
             << setw(60) << left << buku[i][0] << " | "
             << setw(15) << right << buku[i][4] << " |" << endl;
        cout << setw(86) << setfill('-') << "-" << endl;
        cout << setfill(' ');
    }
}

void ubah(){
    do
    {
        do
        {
            system("cls");
            tamp_anggota();
            ulangi_isi = 'n';
            cout << "Data mahasiswa no berapa yang ingin anda rubah : ";
            cin >> ubah_data;
            data_baru = ubah_data - 1;
            system("cls");
            cin.ignore();
            cout << "Nim awal '" << mhs[data_baru][0] << "' Nim baru : ";
            getline(cin, nim_baru);
            cout << "Nama awal '" << mhs[data_baru][1]<< "' Nama baru : ";
            getline(cin, nama_baru);
            cout << "Jurusan awal '" << mhs[data_baru][2] << "' Jurusan baru : ";
            getline(cin, jurusan_baru);
            cout << "Buku yang telah dipinjam '" << mhs[data_baru][3] << "'" << endl;
            cout << "No buku yang akan dipinjam 1/2/3/4/... : ";
            cin >> pilihanBuku;
            system("cls");
            cout << "Data lama : " << endl;
            cout << "NIM                :" << mhs[data_baru][0] << endl;
            cout << "Nama               :" << mhs[data_baru][1] << endl;
            cout << "Jurusan            :" << mhs[data_baru][2] << endl;
            cout << "Buku yang dipinjam :" << mhs[data_baru][3] << endl << endl;
            cout << "Apakah anda yakin? y / n : ";
            cin >> koreksi_data;
            if (koreksi_data == 'y')
            {
                mhs[data_baru][0] = nim_baru;
                mhs[data_baru][1] = nama_baru;
                mhs[data_baru][2] = jurusan_baru;
                mhs[data_baru][3] = buku[pilihanBuku-1][0];
            } else {
                ulangi_isi = 'y';
            }
        } while (ulangi_isi == 'y');
        tamp_anggota();
        cout << "Apakah ada data yang ingin anda ubah lagi? (y / n) : ";
        cin >> pilihan_ubah;
    } while (pilihan_ubah == 'y');
}

void hapus(){
    system("cls");
    tamp_anggota();
    do
    {
        ulangi_isi = 'n';
        if (dis > 0)
        {
            cout << "Data no berapa yang ingin anda hapus : "; 
            cin >> hapus_data;
            array_hapus = hapus_data - 1;
            
            for (int i = array_hapus; i < dis; i++){
                cout << "Apakah anda yakin ingin menghapus data mahasiswa dengan nim " << mhs[i][0] << " atas nama " << mhs[i][1] << "? y / n ";
                cin >> pilihan_hapus; 
                if (pilihan_hapus == 'y')
                {
                    mhs[i][0] = mhs[i+1][0];
                    mhs[i][1] = mhs[i+1][1];
                    mhs[i][2] = mhs[i+1][2];
                    for (int j = 0; j < 10; j++)
                    {
                        if (buku[j][0] == mhs[i][3])
                        {
                            buku[j][4] = "Tersedia";
                        }
                        
                    }
                    mhs[i][3] = mhs[i+1][3];
                    data_pinjam--;
                    dis--;
                } else {
                    ulangi_isi = 'y';
                }
            }
        } else
        {
            cout << "Data kosong" << endl;
        }
    } while (ulangi_isi == 'y');
    
    tamp_anggota();
}

void pinjam_buku() {
    system("cls");
    do {
        loop = 'n';
        if (pos < max) {
            do {    
                ulangi_isi = 'n'; 
                system("cls");
                tamp_buku2();
                cout << "No buku yang akan dipinjam (1/2/3/4/...): ";
                cin >> pilihanBuku;

                if (buku[pilihanBuku - 1][4] == "Dipinjam") {
                    cout << "Buku telah dipinjam, silahkan pinjam buku yang lain." << endl;
                    cout << "Apakah anda ingin memilih buku yang lain? (y/n): ";
                    cin >> loop;
                    cin.ignore();
                } else {
                    mhs[data_pinjam][3] = buku[pilihanBuku - 1][0];
                    cin.ignore();       
                        // ulangi_isi = 'n';
                        cout << "Tambah data: " << endl;
                        cout << "NIM = ";
                        getline(cin, temp1);
                        cout << "Nama = ";
                        getline(cin, temp2);
                        cout << "Jurusan = ";
                        getline(cin, temp3);
                        cout << "Apakah data yang anda masukkan sudah benar? y / n : ";
                        cin >> koreksi_data;
                        cin.ignore();
                        if (koreksi_data == 'y')
                        {
                            buku[pilihanBuku - 1][4] = "Dipinjam";
                            mhs[data_pinjam][0] = temp1;
                            mhs[data_pinjam][1] = temp2;
                            mhs[data_pinjam][2] = temp3;
                            dis++;
                            system("cls");
                            cout << "Data tersimpan" << endl;
                            tamp_anggota();
                            cout << "Ulangi Program? (y/n): ";
                            cin >> loop;
                            data_pinjam++;
                            pos++;
                        }else {
                            ulangi_isi = 'y';
                        }
                }
            } while (ulangi_isi == 'y');
        } else {
            cout << "Telah memenuhi kapasitas maksimum peminjaman." << endl;
        }
    } while (loop == 'y');
}

void kembalikan_buku() {
    system("cls");
    cout << "NIM = " ;
    cin >> nim_peminjam;
    for (int i = 0; i < 10; i++)
    {
        if (nim_peminjam == mhs[i][0])
        {
            cout << mhs[i][0] << " " << mhs[i][1] << " " << mhs[i][2] << " " << mhs[i][3] << endl;
            cout << "Apakah buku '" << mhs[i][3] << "' ingin anda kembalikan? ( y / n ) : ";
            cin >> pilihan_kembalikan;
                if (pilihan_kembalikan == 'y')
                {
                    mhs[i][0] = mhs[i+1][0];
                    mhs[i][1] = mhs[i+1][1];
                    mhs[i][2] = mhs[i+1][2];
                    for (int k = 0; k < 10; k++)
                    {
                        if (buku[k][0] == mhs[i][3])
                        {
                            buku[k][4] = "Tersedia";
                        }
                        
                    }
                    mhs[i][3] = mhs[i+1][3];
                    data_pinjam--;
                    dis--;
                    cout << "Buku berhasil dikembalikan." << endl;
                    break;
                }              
        } else {
            cout << "Data tidak ditemukan / anda tidak sedang meminjam buku" << endl;
        }   
    }
}

void edit_buku() {
    do
    {
        tamp_buku();
        cout << "Data buku berapa yang ingin anda ubah? : ";
        cin >> ubah_buku;
        buku_baru = ubah_buku - 1;
        cout << "Judul buku baru : ";
        cin.ignore();
        getline(cin, buku[buku_baru][0]);
        cout << "Nama pengarang buku baru : ";
        getline(cin, buku[buku_baru][1]);
        cout << "Nama penerbit buku baru : ";
        getline(cin, buku[buku_baru][2]);
        cout << "Tahun penerbitan buku baru : ";
        getline(cin, buku[buku_baru][3]);
        cout << "Status buku baru : ";
        getline(cin, buku[buku_baru][4]);
        tamp_buku();
        cout << "Apakah anda ingin mengubah buku lagi? ( y / n ) : ";
        cin >> pilubah_buku;
    } while (pilubah_buku == 'y');
    
}
