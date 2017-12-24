#include <iostream>
#include "utility.h"

/*
 * Key Idea:
 *
 *    template deduction : void foo<char*>(char*)
 */

template<typename T>
void foo(T param); //{}

/*MAIN_FUNC
{
    char buff[] = "some buffer.!";
    foo(buff);
};*/