#include <iostream>
#include <stdlib.h>
#include "parent.h"
using namespace std;


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
    cout << "Hello world!" << endl;
    ListP L;
    createList(L);
    infotypeP x;
    x.ID = 23;
    x.nama = "a";
    x.lainlain = "haha";
    insertAscendingID(L,alokasi(x));
    x.ID = 20;
    x.nama = "b";
    x.lainlain = "haha";
    insertAscendingID(L,alokasi(x));
    x.ID = 25;
    x.nama = "c";
    x.lainlain = "haha";
    insertAscendingID(L,alokasi(x));
    x.ID = 27;
    x.nama = "d";
    x.lainlain = "haha";
    insertAscendingID(L,alokasi(x));
    x.ID = 26;
    x.nama = "e";
    x.lainlain = "haha";
    insertAscendingID(L,alokasi(x));
    x.ID = 90;
    x.nama = "f";
    x.lainlain = "haha";
    insertAscendingID(L,alokasi(x));
    cout << "printparent" << endl;
    printParent(L);
    cout << "sorted by name" << endl;
    SortingParent(L);
    printParent(L);
    return 0;
}
