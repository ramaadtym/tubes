#include <iostream>
#include <stdlib.h>
#include "parent.h"
//#include "child.h"
#include "parkir.h"
using namespace std;
void menu(ListP &L);
void isiDataAwal(ListP &L);
//long hargaperjam;
Harga hargaparkir;
/**
=============================OBJECTIVE==================================
1. insert data
    untuk parent dan child,terurut berdasar ID, ID unik, non generated
2. search and view
    untuk parent dan child, search by ID (atau atribut lain, terserah)
    view detail data jika ditemukan
3. search and delete
    untuk parent dan child, search by ID
    delete elemen jika ditemukan
    hati-hati untuk jika yang didelete adalah parent
4. view all
    cukup tampilkan ID dan 1 atribut untuk setiap data parent dan child
5. reporting
    menampilkan rangkuman data yang telah diinputkan
    minimal 3 informasi yang bisa diberikan (rata-rata, total, dll)
6. search and edit
    untuk parent dan child, search by ID
    edit data kecuali ID jika ditemukan
7. sort
    mengurutkan berdasarkan suatu atribut (terserah)
**/

int main()
{
    time_t timenow = time(0);
    struct tm * now = localtime( &timenow );
    cout << "Waktu sekarang adalah " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << endl;
    cout << "Hello world!" << endl;
    ListP L;
    createList(L);
    hargaparkir.mobil = 5000;
    hargaparkir.motor = 2000;
    isiDataAwal(L);
    menu(L);
    return 0;
}

void menu(ListP &L)
{
    addressc P;
    addressP Q;
    string nopols;
    string plat;
    int pilihan = NULL;
    do
    {
        clrscr;
        cout << "Main Menu" << endl;
        cout << "1. Insert Lantai" << endl;
        cout << "2. Insert Kendaraan Parkir" << endl;//insert child
        cout << "3. Bayar Parkir" << endl;//search and delete and bayar dong jelas masa ngutang :3
        cout << "4. Cari Kendaraan" << endl;//search and view
        cout << "5. Menampilkan Semua Kendaraan Parkir" << endl;//printAll
        cout << "6. Reporting" << endl;//reporting dibagi 2
        cout << "7. Edit Data" << endl;
        cout << "8. Sorting data" << endl;
        cout << "9. Setting Biaya Parkir" << endl;
        cout << "0. Keluar" << endl;
        cout << "Input : ";
        cin >> pilihan;
        clrscr;
        switch(pilihan)
        {
        case 1:
            inputParent(L);
            break;
        case 2:
            insertChild(L);
            break;
        case 3:
            P = CariKendaraan(L,Q);
            BayarParkir(P,hargaparkir,Q);
            break;
        case 4:
            P = CariKendaraan(L,Q);
            detilKendaraan(info(P));
            break;
        case 5:
            printAll(L);
            break;
        case 6:
            reporting(L);
            break;
        case 7:
            ubahdata(L);
            break;
        case 8:
            SortingAll(L);
            cout<<"Tersorting!"<<endl;
            break;
        case 9:
            BiayaParkir(hargaparkir);
            break;
        case 0:
            cout << "Terima kasih sudah menggunakan aplikasi kami\nAplikasi ini dibuat oleh\n1. Faishal Rachman (1301154160)\n2. Rama Aditya Maulana (1301150034)\n\nUntuk memenuhi Tugas Besar matakuliah Algoritma dan Struktur Data\n";
            break;
        default:
            cout << "Input salah" << endl;
            break;
        }
        pause;
    }
    while(pilihan != 0);
}
void isiDataAwal(ListP &L)
{
    infotypeP x;
    x = DMLParent(6,"Lantai Dasar","Sukapura, Telkom University","Ipat","Reguler");
    insertAscendingID(L,alokasi(x));

    x = DMLParent(3,"Lantai Satu","Sukapura, Telkom University","Vatana","Reguler");
    insertAscendingID(L,alokasi(x));
    DMLChild(L,3,10,"B 1 RI","Mobil","Nissan Juke","Faishal");
    DMLChild(L,3,25,"D 535 D","Motor","Blade","Rama");

    x = DMLParent(10,"Lantai Dua","Sukapura, Telkom University","Vatana","First");
    insertAscendingID(L,alokasi(x));
    DMLChild(L,6,10,"FF 9 Z","Motor","Supra X Helm In","Dani");
    DMLChild(L,6,25,"D 246 AA","Motor","Vario","Vatana");
    DMLChild(L,6,65,"Z 2556 S","Mobil","MIO GT","Sarah");
    DMLChild(L,6,66,"N 166 Z","Motor","Beat","Tukimin");


}

