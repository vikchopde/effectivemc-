#include <iostream>
#include "utility.h"

/*
 * Key Idea:
 *
 *   considering general form of template and calls to it
 *
 *   template<typename T>
 *   void foo(T param)
 *   {
 *   }
 *
 *   foo(expr)
 *
 *   type deduction of  T is not only dependent on expr (what was passes in call) but also depends on form of paramtype.
 *   thus , in cases where param is a pass by value
 *   deduction of T and param works like this :
 *
 *   1 : as before , if paramtype is reference , ignore the reference part
 *   2 : else if paramtype is const or volatile , ignore them too.
 *
 */

template <typename T>
void foo(T param);//{}

MAIN_FUNC
{
    int x = 10;
    const int cx = 20;
    const int& rx = 25;
    const int* px = &x;

    ///passing reference
    foo(x);    //   expr = int        , T = int         , param = int
    foo(cx);   //   expr = const int  , T = int         , param = int
    foo(rx);   //   expr = const int& , T = int         , param = int

    ///passing pointer
    foo(&x);    //   expr = int*        , T = int*        , param = int*
    foo(&rx);   //   expr = const int* ,  T = const int*  , param = const int*

    ///passing rvalue reference
    foo(27);    //   expr = const int&& ,  T = int  , param = int&& (param is rvalue reference)


    const char* const data = "some data"; //data is const pointer (pointer cant point to something else)
                                          // to const data (data cant be modified)
    foo(data);   // since its passed by value , the pointer is copied and a new temp pointer object is created
                 // hence it makes sense tht paramtype = const char* (which is pointer to constant data , where pointer can point to anything)
                 // but data cant be modfied.
                 // expr = const char* const  ,  T = const char*  , param = const char*
};