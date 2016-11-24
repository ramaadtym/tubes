#include "stdafx.h"
#include "parent.h"
struct Harga{
    long mobil;
    long motor;
};

Harga BiayaParkir(Harga &);
void BayarParkir(addressc &P,Harga hargaparkir);
long Hitungbiayaparkir(double berapajam, string jenis, Harga hargaparkir);
