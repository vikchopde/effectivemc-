#include <iostream>
#include "utility.h"

/*
 * Key Idea:
 *
 *      function type also decay into pointers.
 *      and everything which is true for array type deduction also applies to function type deduction.
 */

void somefunc(int, double) {}

template <typename T>
void f(T param) {}

template<typename T>
void f2(T& param) {}

/*MAIN_FUNC
{
    f(somefunc);   // param will deduce to : void (*)(int, double)

    f2(somefunc);  // param will deduce to : void (&)(int, double)
};*/