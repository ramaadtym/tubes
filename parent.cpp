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
    P->info.alamat = x.alamat;
    createList(P->child);
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
bool insertAscendingID(ListP &L, addressP P)
{
    bool returnvalue = true;
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
            cout << "===ID Lantai : " << x.ID << endl;
            cout << "\tNama Lantai : " << x.nama << endl;
            cout << "\tAlamat Lantai : " << x.alamat << endl;
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
    if (isEmpty(L))
    {
        cout << "Data masih kosong" << endl;
    }
    else
    {
        cout << endl;
        addressP P = L.first;
        while(P != NULL)
        {
            cout << "Data pada " << P->info.nama << " (ID:"<<P->info.ID <<")"<< endl;
            cout << "Daftar Kendaraan :" << endl;
            if (P->child.first!=NULL)
            {
                addressc child = P->child.first;
                while(child != NULL)
                {
                    cout << "ID : " << child->info.ID << "\t Nomor Polisi : " << child->info.nopol << endl;
                    child = next(child);
                }
            }
            else
            {
                cout << "Kosong" << endl;
            }

            P = next(P);
        }

    }
}
void SortingParent(ListP &L)
{
    /**
    NIM : 1301154160
    **/
    addressP first = L.first;
    infotypeP minimum;
    while(first != L.last)
    {

        addressP Q = first;
        minimum.ID = Q->info.ID;
        minimum.nama = Q->info.nama;
        while(Q != NULL) //cari value minimum
        {
            if (Q->info.nama <= minimum.nama)
            {
                minimum.ID = Q->info.ID;
                minimum.nama = Q->info.nama;
            }
            Q = Q->next;
        }
        /*
        system("cls");
        cout << "minimum ID = " << minimum.ID << endl;
        cout << "first = " << first->info.ID << endl;
        printParent(L);
        system("pause");*/
        addressP P,Z;
        Z = first->prev;
        if (findElm(L,minimum) != L.first)
        {
            deletebySearch(L,minimum,P);
            if (first == L.first)
            {
                insertFirst(L,P);
                first = P->next;
            }
            else
            {
                insertAfter(L,Z,P);
                first = P->next;
            }
        }
        else
        {
            first = first->next;
        }
        minimum.ID = NULL;
        minimum.nama = "";
    }

}

void insertChild(ListP L)
{

    /**
        NIM : 1301154160
    **/

//PUT YOUR CODE HERE//
    infotypeP ortu;
    infotypec bocah;

    printParent(L);
    cout << "Masukkan ID Lantai yang mau di parkirin : ";
    cin >> ortu.ID;
    bocah.waktumasuk = time(0);
    addressP P = findElm(L,ortu);
    if (P==NULL)
    {
        cout << "Lantai parkir tidak ditemukan" << endl;
    }
    else
    {
        bool status = false;
        while(!status){
        cout << "Lantai Parkir ditemukan" << endl;
        cout << "Input ID :";
        cin >> bocah.ID;
        cout << "Nomor Polisi :";
        getline(cin,bocah.nopol);
        getline(cin,bocah.nopol);
        while(bocah.jenis != "Mobil" && bocah.jenis != "Motor")
        {
            cout << "Jenis Kendaraan (Mobil / Motor) : ";
            cin >> bocah.jenis;
        }
        status = insertAscendingID(P->child,alokasi(bocah));
        }
    }
}

void inputParent(ListP &L)
{
    bool status = false;
    while(!status)
    {
        infotypeP x;
        cout << "Masukkan ID : ";
        cin >> x.ID;
        cout << "Masukkan Nama Lantai : ";
        getline(cin,x.nama);
        getline(cin,x.nama);
        cout << "Masukkan Alamat Lantai : ";
        getline(cin,x.alamat);
        status = insertAscendingID(L,alokasi(x));
    }
}

addressc cariNopol(ListP L,string nopol)
{
    addressP P = L.first;
    addressc Q = NULL;
    infotypec x;
    bool found = false;
    while(P!=NULL && !found)
    {
        if (P->child.first != NULL && Q == NULL)
        {
            Q = findNopol(P->child,nopol);
            if (Q != NULL)
                found = true;
        }
        P = P->next;
    }
    return Q;
}

addressc CariKendaraan(ListP L)
{
    string nopol;
    cout << "Masukkan nopol : ";
    cin >> nopol;
    return cariNopol(L,nopol);
}

void reporting(ListP L)
{
    /**
    kendaraan, Lantai, Jam Masuk, Biaya, Jumlah, Rata-rata kendaraan tiap lantai, Keragaman data kendaraan

    **/
        /**
        NIM : 1301154160
        **/
    int totalkendaraan = 0;
    infotypec kendaraanterlama;
    double terlama = 0;
    double rata2lama = 0;

    addressP PParent = L.first;
    cout << "Reporting :" << endl;
    while(PParent!=NULL)
    {
        infotypeP x = PParent->info;
        cout << x.nama << endl;
        addressc PChild = PParent->child.first;
        cout << "Daftar Nomor Polisi yang Diparkir" << endl;
        int jumlah = 0;
        while(PChild != NULL)
        {
            jumlah++;
            infotypec y = PChild->info;
            cout << y.nopol << endl;
            struct tm * now = localtime( & y.waktumasuk );
            double selisihjam = (difftime(time(0),mktime(now))/3600);
            if (selisihjam > terlama)
            {
                terlama = selisihjam;
                kendaraanterlama = y;
            }
            rata2lama +=selisihjam;
            nextparent(PChild);
        }
        totalkendaraan += jumlah;
        cout << "Total Kendaraan di " << x.nama << " adalah " << jumlah << " buah kendaraan" << endl;

        cout << endl;
        nextparent(PParent);
    }
    if (totalkendaraan > 0)
    {
        struct tm * ubahkewaktu = localtime( & kendaraanterlama.waktumasuk );
        rata2lama = rata2lama/totalkendaraan;
        cout << "Kendaraan yang parkir terlama adalah " << kendaraanterlama.jenis
             << " dengan nomor polisi " << kendaraanterlama.nopol
             << " dengan lama parkir " << terlama << " jam"
             << " dari jam " << ubahkewaktu->tm_hour << ":" << ubahkewaktu->tm_min << ":" << ubahkewaktu->tm_sec << endl;
        cout << "Total kendaraan yang parkir di semua lantai adalah " << totalkendaraan << " buah kendaraan" << endl;
        cout << "Rata-rata lamanya parkir adalah " << rata2lama << " Jam" << endl;
    }
    else
    {
        cout << "Data kosong" << endl;
    }
}

void ubahdata(ListP &L)
{
    cout << "Data apa yang ingin diubah :\n1. Lantai\n2. Kendaraan" << endl;
    int pilihan;
    cin >> pilihan;
    if (pilihan == 1)
    {
        /**
        NIM : 1301154160
        **/
        printParent(L);
        infotypeP Lantai;
        cout << "Masukkan ID Lantai = ";
        cin >> Lantai.ID;
        addressP hasil = findElm(L,Lantai);
        if (hasil == NULL)
        {
            cout << "Data lantai tidak ditemukan" << endl;
        }
        else
        {
            cout << "Masukkan Nama Lantai baru : ";
            getline(cin,Lantai.nama);
            getline(cin,Lantai.nama);
            cout << "Masukkan Alamat Lantai baru : ";
            getline(cin,Lantai.alamat);
            hasil->info = Lantai;
        }
    }

    else if (pilihan == 2)
    {
        /**
        NIM : 1301150034
        **/


    }
    else
    {
        cout << "Pilihan salah" << endl;
    }
}
infotypeP createDML(int ID, string nama, string alamat){
    infotypeP x;
    x.ID = ID;
    x.nama = nama;
    x.alamat = alamat;
    return x;
}

/**fungsi createDML(int IDparent, string nopol, string jenis, string jammasuk)


    DIBAWAH INI BANTUAN YAH SAY
    infotypeP ortu;
    infotypec bocah;

    printParent(L);
    cout << "Masukkan ID Lantai yang mau di parkirin : ";
    cin >> ortu.ID;
    bocah.waktumasuk = time(0);
    addressP P = findElm(L,ortu);
    if (P==NULL)
    {
        cout << "Lantai parkir tidak ditemukan" << endl;
    }
    else
    {
        bool status = false;
        while(!status){
        cout << "Lantai Parkir ditemukan" << endl;
        cout << "Input ID :";
        cin >> bocah.ID;
        cout << "Nomor Polisi :";
        getline(cin,bocah.nopol);
        getline(cin,bocah.nopol);
        while(bocah.jenis != "Mobil" && bocah.jenis != "Motor")
        {
            cout << "Jenis Kendaraan (Mobil / Motor) : ";
            cin >> bocah.jenis;
        }
        status = insertAscendingID(P->child,alokasi(bocah));
        }
    }
    **/
