#include <iostream>
#include "utility.h"

/*
 * Key Idea:
 *
 *   template deduction : void foo<char [14]>(char (&) [14])
 *   Although functions can't declare parameters that are truly arrays, they can
 *   declare parameters that are references to arrays.
 *
 *   The type deduced for T is the actual type of the array!  That type includes
 *   the size of the array, so in this example T is deduced to be const
 *   char[13], and the type of f's parameter (a reference to this array) is
 *   const char (&)[13].
 */

template<typename T>
void foo(T& param); //{}

/*MAIN_FUNC
{
    char buff[] = "some buffer.!";
    foo(buff);
};*/