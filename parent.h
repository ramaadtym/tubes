#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include "child.h"
#include "stdafx.h"

#define nextparent(P) (P) = (P)->next
#define child(P) (P)->child
using namespace std;
struct infotypeP
{
    int ID;
    string nama;
    string alamat;
};
typedef struct Parent *addressP;
struct Parent
{

    infotypeP info;
    Listc child;
    addressP next;
    addressP prev;

};

struct ListP
{
    addressP first;
    addressP last;
};

void createList(ListP &L);
addressP alokasi(infotypeP x);
void dealokasi(addressP &P);

void insertFirst(ListP &L, addressP P);
void insertAfter(ListP &L,addressP Prec, addressP P);
void insertLast(ListP &L, addressP P);
bool insertAscendingID(ListP &L, addressP P);
void insertChild(ListP L);

void deleteFirst(ListP &L, addressP &P);
void deleteLast(ListP &L, addressP &P);
void deletebySearch(ListP &L,infotypeP x, addressP &P);

addressP findElm(ListP L, infotypeP x);
void printParent(ListP L);
void printAll(ListP L);
bool isEmpty(ListP L);
void SortingParent(ListP &L);
void ReportingLantai(ListP L);
void inputParent(ListP &L);
addressc CariKendaraan(ListP L,addressP &P);
addressc cariNopol(ListP L,string nopol);
void reporting(ListP L);
void ubahdata(ListP &L);
infotypeP DMLParent(int ID, string nama, string alamat);
void DMLChild(ListP &L,int ID, int IDKendaraan, string nopol, string jenis);
#endif // PARENT_H_INCLUDED
