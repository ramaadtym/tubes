#include <iostream>
#include <stdlib.h>
#include "parent.h"
using namespace std;


/** OBJECTIVE
1. xxxxx


**/

int main()
{
    cout << "Hello world!" << endl;
    ListP L;
    createList(L);
    infotypeP x;
    x.ID = 23;
    x.nama = "asd";
    x.lainlain = "haha";
    insertAscendingID(L,alokasi(x));
    x.ID = 20;
    insertAscendingID(L,alokasi(x));
    x.ID = 25;
    insertAscendingID(L,alokasi(x));
    x.ID = 21;
    insertAscendingID(L,alokasi(x));
    cout << "printparent" << endl;
    printParent(L);
    SortingParent(L);
    printParent(L);
    return 0;
}
