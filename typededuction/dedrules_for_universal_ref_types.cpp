#include <iostream>
#include "utility.h"

template <typename T>
void foo(T&& param){}

MAIN_FUNC
{
    int x = 10;
    const int cx = 20;
    const int& rx = 25;
    const int* px = &x;

    ///passing reference
    foo(x);    //   expr = int        , T = int&        , param = int&
    foo(cx);   //   expr = const int  , T = const int&  , param = const int&
    foo(rx);   //   expr = const int& , T = const int&  , param = const int&

    ///passing pointer
    foo(&x);    //   expr = int*        , T = int*        , param = int*&&
    foo(&rx);   //   expr = const int* ,  T = const int*  , param = const int*&&

    ///passing rvalue reference
    foo(27);    //   expr = const int&& ,  T = int  , param = int&&
}



