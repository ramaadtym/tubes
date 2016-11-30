#include "child.h"
#include "parkir.h"
void createList(Listc &L)
{
    /**
        NIM :1301150034
        FS: List dalam keadaan kosong
    **/

//PUT YOUR CODE HERE//
    first(L) = Nil;
}
addressc alokasi(infotypec x)
{
    /**
        NIM :1301150034
        FS: mengembalikan elemen list baru dengan info = x, next elemen = Nil
    **/

//PUT YOUR CODE HERE//
    addressc C;
    C = new Child;
    info(C).ID = x.ID;
    info(C).nama = x.nama;
    info(C).jenis = x.jenis;
    info(C).nopol = x.nopol;
    info(C).waktumasuk = time(0);
    info(C).pemilik = x.pemilik;
    next(C) = Nil;
    return C;
}
void dealokasi(addressc &P)
{
    /**
        NIM :1301150034
        FS: menghapus elemen yang ditunjuk oleh P   
    **/

//PUT YOUR CODE HERE//
    P = Nil;
    delete P;
}

void insertFirst(Listc &L, addressc P)
{
    /**
        NIM :1301150034
        IS : List L mungkin kosong
        FS : elemen yang ditunjuk P menjadi elemen pertama pada List L    
    **/

//PUT YOUR CODE HERE//
    if(first(L) == Nil)
    {
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(Listc &L,addressc Prec, addressc P)
{
    /**
        NIM :1301150034
        IS: list mungkin kosong
        FS: menambahkan elemen baru setelah elemen p
    **/

//PUT YOUR CODE HERE//
    if (first(L)== Nil)
    {
        insertFirst(L,P);
    }
    else if(next(Prec) == Nil)
    {
        cout<<"Parkiran Penuh";
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void insertLast(Listc &L, addressc P)
{
    /**
        NIM :1301150034
        IS : List L mungkin kosong
        FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    **/

//PUT YOUR CODE HERE//
    if(first(L) != Nil)
    {
        addressc Q;
        Q = first(L);
        while(next(Q) != Nil)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
    else
    {
        insertFirst(L,P);
    }
}

void deleteFirst(Listc &L, addressc &P)
{
    /**
        NIM :1301150034
        IS: list mungkin kosong
        FS: menghapus elemen pertama dari list
    **/

//PUT YOUR CODE HERE//
    if(first(L) != Nil)
    {
        P = first(L);
        first(L) = next(P);
        next(P) = Nil;
        dealokasi(P);
    }
}
void deleteLast(Listc &L, addressc &P)
{
    /**
        NIM :1301150034
        IS: list mungkin kosong
        FS: menghapus elemen terakhir dari list
    **/

//PUT YOUR CODE HERE//
    if(first(L) != Nil)
    {
        P = first(L);
        if(next(P) != Nil)
        {
            while (next(next(P)) != Nil)
                P = next(P);
            next(P) = Nil;

        }
        else
        {
            first(L) = Nil;
        }
    }
}
void deletebySearch(Listc &L,infotypec x, addressc &P)
{
    /**
        NIM :1301150034
        IS: list mungkin kosong
        FS: menghapus elemen yang dicari dari list
    **/

//PUT YOUR CODE HERE//
    addressc Prec;
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
            else
            {
                next(Prec) = next(P);
            }
        }
    }
}

addressc findElm(Listc L, infotypec x)
{
    /**
        NIM :1301150034
        IS: list mungkin kosong
        FS: mengembalikan elemen dengan info.ID = x.ID,
            mengembalikan Nil jika tidak ditemukan
    **/

//PUT YOUR CODE HERE//
    addressc C;
    if(first(L) != Nil)
    {
        C = first(L);
        while(C != Nil)
        {
            if(info(C).ID == x.ID)
            {
                return C;
            }
            C = next(C);
        }
        return Nil;
    }
    return C;
}
bool insertAscendingID(Listc &L, addressc P){
    /**
        NIM: 1301150034
        IS: List mungkin kosong
        FS: elemen yang ditunjuk p akan dimasukkan secara Ascending (terurut dari besar ke kecil)
    **/

    bool returnvalue = true;
    addressc Q = first(L);
    if (first(L) != Nil)
    {
        if (info(P).ID < info(Q).ID)
            insertFirst(L,P);
        else
        {
            while(info(P).ID > info(Q).ID && next(Q) != NULL)
            {
                Q = Q->next;
            }

            if (P->info.ID > Q->info.ID && Q->next == NULL) //dia diujung
            {
                insertLast(L,P);
            }
            else if (info(P).ID < info(Q).ID)
            {
                addressc Z = first(L);
                while(Z != Nil && next(Z) != Q){
                    Z = next(Z);
                }
                insertAfter(L,Z,P);

            }
            else if (info(P).ID == info(Q).ID)
            {
                cout << "ID SUDAH ADA" << endl;
                returnvalue = false;

            }

        }
    }
    else
    {
        insertFirst(L,P);
    }
    return returnvalue;
}
addressc findNopol(Listc L, string nopol)
{
    /**
        NIM :1301150034
        IS: list mungkin kosong
        FS: mencari nomor polisi yang ada di dalam list
    **/

//PUT YOUR CODE HERE//
    addressc C;
    infotypec x;
    x.nopol = nopol;
    if(first(L) != Nil)
    {
        C = first(L);
        while(C != Nil)
        {
            if(info(C).nopol == x.nopol)
            {
                return C;
            }
            C = next(C);
        }
        return Nil;
    }
    return C;
}
void printChild(Listc L,Harga hargaparkir)
{
    /**
        NIM :1301150034
        IS: list l mungkin kosong
        FS: menampilkan info dari seluruh child
    **/

//PUT YOUR CODE HERE//
    addressc C;
    C = first(L);
    if(first(L) == Nil)
    {
        cout<<"KOSONG";
    }
    else
    {
        while(C!=Nil)
        {
            infotypec c = info(C);
            cout << "ID : " << c.ID << endl;
            cout << "Nama : " << c.nama << endl;
            cout << "Jenis Kendaraan : " << c.jenis << endl;
            struct tm * now = localtime( & c.waktumasuk );
            cout << "Jam masuk : " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << endl;
            double selisihjam = (difftime(time(0),mktime(now))/3600);
            cout << "Biaya parkir = " << Hitungbiayaparkir(selisihjam,c.jenis,hargaparkir) << endl;
            C = next(C);
        }
    }
}
void SortingDesc(Listc &L)
{
    /**
    NIM : 1301150034
    IS  : list dalam keadaan Ascending (terurut dari kecil ke besar)
    FS  : list terurut dalam keadaan Descending (terurut dari besar ke kecil)
    **/
    addressc pertama = first(L);
    infotypec besar;
    if(pertama != Nil)
    while(next(pertama) != Nil && pertama != Nil) //bukan Last dan kosong
    {
        addressc Q = pertama;
        besar.nopol = info(Q).nopol;
        while(Q != NULL)
        {
            if (info(Q).nopol >= besar.nopol)
            {
                besar.nopol = info(Q).nopol;
                besar.ID = info(Q).ID;
                besar.nama = info(Q).nama;
            }
            Q = next(Q);
        }
        //Cari elemen buat di sorting
        addressc P,Z;
        infotypec x = besar;
        P = findElm(L,x);

 
        if(pertama == first(L)){
        Z = Nil;
        }
        else{
            Z = first(L);
            while(next(Z) != pertama){
                Z = next(Z);
            }
        }
        if(P != first(L)){
            deletebySearch(L,x,P);
            if(pertama == first(L)){
                insertFirst(L,P);
                pertama = next(P);
            }
            else{
                insertAfter(L,Z,P);
                pertama = next(P);
            }
        }
        else{
            pertama = next(pertama);
        }
    }
}
void detilKendaraan(infotypec x)
{
    /**
        NIM: 1301150034
        FS : menampilkan detil kendaraan sesuai yang di inputkan user
    **/
    cout<<"DETIL KENDARAAN "<<x.nopol<<endl;
    cout<<"ID Parkir: "<<x.ID<<endl;
    cout<<"Jenis Kendaraan: "<<x.jenis<<endl;
    cout<<"Merk: "<<x.nama<<endl;
    cout<<"Pemilik: "<<x.pemilik<<endl;
    struct tm * now = localtime( & x.waktumasuk );
    cout << "Jam masuk : " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << endl;
}
