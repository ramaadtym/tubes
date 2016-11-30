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
        long bayar = 0;
        infotypec x = P->info;
        detilKendaraan(x);
        struct tm * now = localtime( & x.waktumasuk );
        double selisihjam = (difftime(time(0),mktime(now))/3600);
        long harga = Hitungbiayaparkir(selisihjam,x.jenis,hargaparkir);
        cout << "Biaya parkir "<< x.jenis << " adalah Rp " << harga << endl;
        while(bayar < harga){

        cout << "Bayar : Rp ";
        cin >> bayar;
            if (bayar < harga)
                cout << "input salah atau uang kurang" << endl;
        }
        cout << "Uang yang dibayarkan : Rp" << bayar << endl;
        cout << "Kembalian : Rp" << abs(harga-bayar) << endl;
        addressc P;
        deletebySearch(child(Z),x,P);
        dealokasi(P);

    }
}
