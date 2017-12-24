#include <iostream>
#include <array>
#include "utility.h"

/*
 * Key Idea:
 *
 *    the ability to deduce array passed by refernce allow us to write template to get size of array at compile time.
 */

template <typename T, size_t N>
constexpr auto arr_size(T (&)[N])
    -> size_t
{
    return N;
};

MAIN_FUNC
{
    int old_arr[] = {10,20};
    std::array<int, arr_size(old_arr)> new_arr;
};