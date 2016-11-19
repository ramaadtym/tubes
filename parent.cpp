#include "parent.h"

#include "stdafx.h"

void createList(ListP &L)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//
    L.first = NULL;
    L.last = NULL;
}
bool isEmpty(ListP L)
{
    return (L.first == NULL && L.last == NULL);
}
addressP alokasi(infotypeP x)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//
    addressP P = new Parent;
    P->info.ID = x.ID;
    P->info.nama = x.nama;
    P->info.lainlain = x.lainlain;
    return P;

}
void dealokasi(addressP &P)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//

    delete P;
}

void insertFirst(ListP &L, addressP P)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//
    if (L.first != NULL)
    {
        P->next = L.first;
        P->prev = NULL;
        L.first->prev = P;
        L.first = P;
    }
    else
    {
        L.first = P;
        L.last = P;
        P->next = NULL;
        P->prev = NULL;
    }
}

void insertAfter(ListP &L,addressP Prec, addressP P)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//
    if (Prec == L.last)
    {
        insertLast(L,P);
    }
    else
    {
        P->next = Prec->next;
        P->prev = Prec->next->prev;
        Prec->next->prev = P;
        Prec->next = P;
    }
}
void insertLast(ListP &L, addressP P)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//
    if (L.last != NULL)
    {
        L.last->next = P;
        P->prev = L.last;
        P->next = NULL;
        L.last = P;
    }
    else
    {
        insertFirst(L,P);
    }
}
void insertAscendingID(ListP &L, addressP P)
{
    addressP Q = L.first;
    if (!isEmpty(L))
    {
        if (P->info.ID < Q->info.ID)
            insertFirst(L,P);
        else
        {
            while(P->info.ID > Q->info.ID && Q->next != NULL)
            {
                Q = Q->next;
            }

            if (P->info.ID > Q->info.ID && Q->next == NULL) //dia diujung
            {
                insertLast(L,P);
            }
            else if (P->info.ID < Q->info.ID)
            {
                insertAfter(L,Q->prev,P);
            }
            else if (P->info.ID == Q->info.ID)
            {
                cout << "ID SUDAH ADA" << endl;
            }

        }
    }
    else
    {
        insertFirst(L,P);
    }

}

void deleteFirst(ListP &L, addressP &P)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//

    if (!isEmpty(L))
    {
        if (L.first != L.last)
        {
            P = L.first;
            L.first = L.first->next;
            L.first->prev = NULL;
        }
        else
        {
            P = L.first;
            createList(L);
        }
    }
}
void deleteLast(ListP &L, addressP &P)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//

    if (!isEmpty(L))
    {
        if (L.first != L.last)
        {
            P = L.last;
            L.last = L.last->prev;
            L.last ->next = NULL;
        }
        else
        {
            P = L.last;
            createList(L);
        }
    }
}
void deletebySearch(ListP &L,infotypeP x, addressP &P)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//
    if (!isEmpty(L))
    {
        addressP cari = findElm(L,x);
        if (cari != NULL)
        {
            if (cari == L.last)
                deleteLast(L,P);
            else if (cari == L.first)
                deleteFirst(L,P);
            else
            {
                P = cari;
                cari->prev->next = cari->next;
                cari->next->prev = cari->prev;
            }
        }
        else
        {
            cout << "NOT FOUND" << endl;
        }


    }
}

addressP findElm(ListP L, infotypeP x)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//
    addressP cari = L.first;
    bool found = false;
    while(cari != NULL && !found)
    {

        if (cari->info.ID != x.ID)
            cari = cari->next;
        else
            found = true;
    }
    if (found)
    {
        return cari;
    }
    else
    {
        return NULL;
    }
}
void printParent(ListP L)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//
    if (!isEmpty(L))
    {

        addressP P = L.first;
        while(P != NULL)
        {
            infotypeP x = P->info;
               cout << "===ID : " << x.ID << endl;
         cout << "\tNama : " << x.nama << endl;
            cout << "\tLain-Lain : " << x.lainlain << endl;
            P = P->next;
        }
        cout << endl;
    }

}
void printAll(ListP L)
{
    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//
    if (!isEmpty(L))
    {
        for(addressP P = L.first; P!=NULL; P=P->next)
        {
            infotypeP x = P->info;
            cout << "ID : " << x.ID << endl;
            cout << "Nama : " << x.nama << endl;
            cout << "Lain-Lain : " << x.lainlain << endl;
            cout << "List Child = " << endl;
            printChild(P->child);
        }
    }

}
void SortingParent(ListP &L)
{
    addressP first = L.first;
    int minimum;
    while(first != L.last)
    {
        addressP Q = first;
        minimum = Q->info.ID;
        while(Q != NULL) //cari value minimum
        {
            if (Q->info.ID < minimum)
                minimum = Q->info.ID;
            Q = Q->next;
        }
        addressP P;
        infotypeP cari;
        cari.ID = minimum;
        if (findElm(L,cari) != L.first){
        deletebySearch(L,cari,P);
        if (first == L.first)
            insertFirst(L,P);
        else
        {
        insertAfter(L,first->prev,P);
        }
        }
        if (first->next != NULL)
        first = first->next;
    }

}
