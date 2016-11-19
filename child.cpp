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
    info(C) = x;
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
        P = first(L);
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
    NIM :
**/

//PUT YOUR CODE HERE//
}

addressc findElm(Listc L, infotypec x){
/**
    NIM :1301150034
**/

//PUT YOUR CODE HERE//
    address C;
    if(first(L) != Nil){
        C = first(L);
        while(C != Nil){
            if(info(C) == x){
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
    address C
    C = first(L);
    if(first(L) != Nil){
        while(C!=Nil){
            infotypec c = info(C)
            cout << "ID : " << c.ID << endl;
            cout << "Nama : " << c.nama << endl;
            cout << "Lain-Lain : " << c.lainlain << endl;

        }
    }
}
