#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include "child.h"
#include "stdafx.h"

#define nextparent(P) (P) = (P)->next
using namespace std;
struct infotypeP{
    int ID;
    string nama;
    string lainlain;
};
typedef struct Parent *addressP;
struct Parent{

    infotypeP info;
    Listc child;
    addressP next;
    addressP prev;

};

struct ListP{
    addressP first;
    addressP last;
};

void createList(ListP &L);
addressP alokasi(infotypeP x);
void dealokasi(addressP &P);

void insertFirst(ListP &L, addressP P);
void insertAfter(ListP &L,addressP Prec, addressP P);
void insertLast(ListP &L, addressP P);
void insertAscendingID(ListP &L, addressP P);

void deleteFirst(ListP &L, addressP &P);
void deleteLast(ListP &L, addressP &P);
void deletebySearch(ListP &L,infotypeP x, addressP &P);

addressP findElm(ListP L, infotypeP x);
void printParent(ListP L);
void printAll(ListP L);
bool isEmpty(ListP L);
void SortingParent(ListP &L);

#endif // PARENT_H_INCLUDED
