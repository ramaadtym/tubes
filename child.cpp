#include "child.h"

void createList(Listc &L){
/**
    NIM :1301150034
**/

//PUT YOUR CODE HERE//
    first(L) = Nil;
}
addressc alokasi(infotypec x){
/**
    NIM :1301150034
**/

//PUT YOUR CODE HERE//
    addressc C;
    C = new Child;
    info(C).ID = x.ID;
    info(C).nama = x.nama;
    info(C).lainlain = x.lainlain;
    next(C) = Nil;
    return C;
}
void dealokasi(addressc &P){
/**
    NIM :1301150034
**/

//PUT YOUR CODE HERE//
    P = Nil;
    delete P;
}

void insertFirst(Listc &L, addressc P){
/**
    NIM :1301150034
**/

//PUT YOUR CODE HERE//
    if(first(L) == Nil){
        first(L) = P;
    }
    else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(Listc &L,addressc Prec, addressc P){
/**
    NIM :1301150034
**/

//PUT YOUR CODE HERE//
    if (first(L)== Nil){
        insertFirst(L,P);
    }
    else if(next(Prec) == Nil){
        cout<<"Parkiran Penuh";
    }
    else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void insertLast(Listc &L, addressc P){
/**
    NIM :1301150034
**/

//PUT YOUR CODE HERE//
    if(first(L) != Nil){
        addressc Q;
        Q = first(L);
        while(next(Q) != Nil){
            Q = next(Q);
        }
        next(Q) = P;
    }
    else{
        insertFirst(L,P);
    }
}

void deleteFirst(Listc &L, addressc &P){
/**
    NIM :1301150034
**/

//PUT YOUR CODE HERE//
    if(first(L) != Nil){
        P = first(L);
        first(L) = next(P);
        next(P) = Nil;
        dealokasi(P);
    }
}
void deleteLast(Listc &L, addressc &P){
/**
    NIM :1301150034
**/

//PUT YOUR CODE HERE//
    if(first(L) != Nil){
        P = first(L);
        if(next(P) != Nil){
            while (next(next(P)) != Nil)
                P = next(P);
                next(P) = Nil;

        }
        else{
            first(L) = Nil;
        }
    }
}
void deletebySearch(Listc &L,infotypec x){
/**
    NIM : 1301150034
**/

//PUT YOUR CODE HERE//
addressc Prec,P;
 Prec = first(L);
     P = findElm(L,x);
     if (P != Nil)
     {
         if (Prec == P)
         {
             deleteFirst(L,P);
         }
         else
         {

             while(next(Prec)!= P && next(Prec) != NULL)
                 Prec = next(Prec);

             if (next(Prec) == NULL)
             {
                 deleteLast(L,Prec);
             }
         }
     }
}

addressc findElm(Listc L, infotypec x){
/**
    NIM :1301150034
**/

//PUT YOUR CODE HERE//
    addressc C;
    if(first(L) != Nil){
        C = first(L);
        while(C != Nil){
            if(info(C).ID == x.ID){
                return C;
            }
            C = next(C);
        }
        return Nil;
    }
    return C;
}
void printChild(Listc L){
/**
    NIM :1301150034
**/

//PUT YOUR CODE HERE//
    addressc C;
    C = first(L);
    if(first(L) == Nil){
        cout<<"KOSONG";
    }
    else{
        while(C!=Nil){
            infotypec c = info(C);
            cout << "ID : " << c.ID << endl;
            cout << "Nama : " << c.nama << endl;
            cout << "Lain-Lain : " << c.lainlain << endl;
            C = next(C);
        }
    }
}
