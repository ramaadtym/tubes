#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED


#include "stdafx.h"


using namespace std;
struct infotypec{
    int ID;
    char nama,lainlain;
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

void deleteFirst(Listc &L, addressc &P);
void deleteLast(Listc &L, addressc &P);
void deletebySearch(Listc &L, infotypec x);

addressc findElm(Listc L, infotypec x);
void printChild(Listc L);

#endif // CHILD_H_INCLUDED
