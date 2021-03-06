
#include <iostream>

#include "chapter_05.h"
#include "libmat.h"
#include "book.h"
#include "audio_book.h"
#include "../util/num_seq2.h"
#include "../util/fibon.h"
#include "../util/num_seq3.h"
#include "../util/fibon3.h"

using namespace std;

void Chapter_05()
{
    //Practice_5_2();
    //Practice_5_5();
    //Practice_5_9();
    Practice_5_10();
}

void Practice_5_2()
{
//    cout << "Creating a LibMat object to print.\n";
//    LibMat libmat;
//    Print(libmat);

//    Book book("aaa", "bb");
//    Print(book);

    AudioBook audio("aaa", "111", "***");
    audio.Print();
}

void Practice_5_5()
{
    Fibon fib;
    cout << "fib: the begging at element 1 for 1 element: "
         << fib << endl;

    Fibon fib2(16);
    cout << "fib: the begging at element 1 for 16 element: "
         << fib2 << endl;

    Fibon fib3(8, 12);
    cout << "fib: the begging at element 12 for 8 element: "
         << fib3 << endl;
}

void Print1(LibMat lib, const LibMat *p1, const LibMat &r1)
{
    lib.Print();    //基类切割
    cout << endl;

    p1->Print();
    cout << endl;

    r1.Print();
}

void Practice_5_9()
{
    // AudioBook a("1", "2", "3");
    // Print1(a, &a, a);

    Fibon3 b;
    cout << b.WhatAmI() << endl;
    Fibon3 *ptr = b.Clone();
    cout << ptr->WhatAmI() << endl;
}

//RTII
void Practice_5_10()
{
    Fibon3 fib;
    NumSeq3 *ps = &fib;

    if (typeid(*ps) == typeid(Fibon3))
    {
        //cout << ps->WhatAmI() << endl;
        ps->GenElems(64);
        //ps->Fibon3::GenElems(64);   //error
    }
    
    if (Fibon3 *pf = dynamic_cast<Fibon3 *>(ps))
        cout << pf->WhatAmI() << endl;
}