#include <iostream>
#include "utility.h"

/*
 * Key Idea:
 *
 *
 */

/// There is not such thing as array parameter to function , although the below syntax is valid , however
void foo(int a[])
{
}


///compiler deduces it like a pointer.
void foo_equivalent(int *a)
{
}

MAIN_FUNC
{
    int arr [] = {1,2};
};

