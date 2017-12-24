#include <iostream>
#include "utility.h"

/*
 * Key Idea:
 *
 *  considering general form of template and calls to it
 *
 *   template<typename T>
 *   void foo(T&& param)
 *   {
 *   }
 *
 *   foo(expr)
 *
 *   type deduction of  T is not only dependent on expr (what was passes in call) but also depends on form of paramtype.
 *   thus , in simple case where param is a universal reference
 *   deduction of T and param works like this :
 *
 *   1 : if expr is an lvalue , than both T and param type will deduce lvalue reference
 *   2 : else rules for case 1(param is pointer or reference will follow)
 *
 */

template <typename T>
void foo(T&& param){}

/*MAIN_FUNC
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
    foo(27);    //   expr = const int&& ,  T = int  , param = int&& (param is rvalue reference)
}*/



