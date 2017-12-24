#include <iostream>

/*
 * Key Idea:
 *
 *  considering general form of template and calls to it
 *
 *   template<typename T>
 *   void foo(T& param)
 *   {
 *   }
 *
 *   foo(expr)
 *
 *   type deduction of  T is not only dependent on expr (what was passes in call) but also depends on form of paramtype.
 *   thus , in simple case where param is reference or pointer type but not an universal reference
 *   deduction of T and param works like this :
 *
 *   1 : if param is reference or pointer type , ignore the reference or pointer part
 *   2 : then pattern match expr with param to deduce the type of T
 *
 *   if param is changed from & to const& , then also constness of cx and rx in respected
 *   however since param is now declared const there is no need to const as part of T.(so expr will be int not const int)
 */

///reference
template<typename T>
void foo_reference(T& param) { }

///reference to const
template<typename T>
void foo_reference_to_const(const T& param) {}

///pointer
template<typename T>
void foo_pointer(T* param) {}

///pointer to const
template<typename T>
void foo_pointer_const(const T* param);// {}

int main()
{
    int x = 10;
    const int cx = 20;
    const int& rx = 25;
    const int* px = &x;

    ///reference
    foo_reference(x);    //   expr = int        , T = int         , param = int&
    foo_reference(cx);   //   expr = const int  , T = const int   , param = const int&
    foo_reference(rx);   //   expr = const int& , T = const int   , param = const int&

    ///reference to const
    foo_reference_to_const(x);    //   expr = int        , T = int         , param = const int&
    foo_reference_to_const(cx);   //   expr = const int  , T = int         , param = const int&
    foo_reference_to_const(rx);   //   expr = const int& , T = int         , param = const int&

    ///pointer
    foo_pointer(&x);    //   expr = int*        , T = int         , param = int*
    foo_pointer(&rx);   //   expr = const int* ,  T = const int   , param = const int*

    ///pointer
    foo_pointer_const(&x);    //   expr = int*        , T = int    , param = int*
    foo_pointer_const(&rx);   //   expr = const int* ,  T = int    , param = const int*

    return 0;
}