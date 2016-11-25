#include "parkir.h"

Harga BiayaParkir(Harga &x)
{
    cout << "Biaya Parkir sebelumnya "<<endl;
    cout << "Mobil : " << x.mobil << endl;
    cout << "Motor : " << x.motor << endl;
    cout << "Masukkan biaya parkir perjam terbaru" << endl;
    cout << "Mobil :";
    cin >> x.mobil;
    cout << "Motor :";
    cin >> x.motor;
}
int ceil(double x){
    /** Sumber dari internet**/
    int a;
    a=x;
    if (a!=x)
    {
        return a+1;
    }
    else
    {
        return a;
    }
}

string lowercase(string S)
{
    for (int i = 0; i<=S.length(); i++)
    {
        if (S[i] >= 65 && S[i] <= 90)
        {
            S[i] = S[i] + 32;
        }
    }
    return S;
}
long Hitungbiayaparkir(double berapajam, string jenis, Harga hargaparkir)
{
    string kendaraan = lowercase(jenis);

    if (kendaraan == "mobil")
        return ceil(berapajam)*hargaparkir.mobil;
    else if (kendaraan == "motor")
        return ceil(berapajam)*hargaparkir.motor;
}
void BayarParkir(addressc &P,Harga hargaparkir,addressP &Z)
{

    if (P==NULL)
    {
        cout << "Kendaraan tidak ditemukan" << endl;
    }
    else
    {
        clrscr;
        long bayar;
        infotypec x = P->info;
        cout << "Nomor Polisi : " << x.nopol << endl;
        struct tm * now = localtime( & x.waktumasuk );
        cout << "Jam masuk : " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << endl;
        double selisihjam = (difftime(time(0),mktime(now))/3600);
        long harga = Hitungbiayaparkir(selisihjam,x.jenis,hargaparkir);
        cout << "Biaya parkir : " << harga << endl;
        cout << "Bayar = ";
        cin >> bayar;
        cout << "Uang yang dibayarkan : " << bayar << endl;
        cout << "Kembalian : " << harga-bayar << endl;
        deletebySearch(Z->child,x);

    }
}
