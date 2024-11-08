#include "function.h"

using namespace std;

main(){
    system("cls");
    do
    {
        ulang = 'n';
        pinjam();
        cin.ignore();
        cout << "Ulang? ";
        cin >> ulang;
    } while (ulang == 'y');
    
    tampil();
}     

