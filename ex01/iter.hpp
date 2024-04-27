#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>
# include <cstddef>

// a =address
// b =length
// c =function called on each elem of the array
template <typename T>
void iter(T *a, size_t b, void(*c)(T &))
{
    for (size_t i = 0; i < b; i++)
    {
        c(a[i]);
    }
}

#endif