#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>
#define Nil NULL
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info



#include "stdafx.h"


using namespace std;
struct infotypec{
    int ID;
    string nama,jenis,nopol;
    time_t waktumasuk;
};
typedef struct Child *addressc;
struct Child{

    infotypec info;
    addressc next;

};

struct Listc{
    addressc first;
};

void createList(Listc &L);
addressc alokasi(infotypec x);
void dealokasi(addressc &P);

void insertFirst(Listc &L, addressc P);
void insertAfter(Listc &L,addressc Prec, addressc P);
void insertLast(Listc &L, addressc P);
bool insertAscendingID(Listc &L, addressc P);

void deleteFirst(Listc &L, addressc &P);
void deleteLast(Listc &L, addressc &P);
void deletebySearch(Listc &L, infotypec x);

addressc findElm(Listc L, infotypec x);
void printChild(Listc L);
addressc findNopol(Listc L, string nopol);
#endif // CHILD_H_INCLUDED
