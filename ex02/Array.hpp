#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
    public:
            Array();
            Array(unsigned int n);
            Array(Array &other);
            ~Array();
            Array &operator=(Array &toher);
            T& operator[](unsigned int index);
            unsigned int size() const;
    private:
            T *tab;
            unsigned int tabSize;
};

# include "Array.tpp"

#endif