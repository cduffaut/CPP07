#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    tab = new T[0];
    tabSize = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    tabSize = n;
    tab = new T[n];
    for (int i = 0; i < tabSize; i++)
    {
        tab[i] = 0;
    }
}

// The operetor[] allow us to not put the "path".
template <typename T>
Array<T>::Array(Array &other)
{
    tab = new T[other.size()];
    tabSize = other.size();
    for (int i = 0; i < tabSize; i++)
    {
        tab[i] = other[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] tab;
}

template <typename T>
Array<T>& Array<T>::operator=(Array &other)
{
    if (this != &other)
    {
        delete[] tab;
        if (other.tab != nullptr)
        {

            tab = new T[other.size()];
            tabSize = other.size();

            for (int i = 0; i < tabSize; i++)
            {
                tab[i] = other[i];
            }
        }
        else
        {
            tab = nullptr;
            tabSize = 0;
        }
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= tabSize)
        throw std::out_of_range("Index out of range");
    return (tab[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (tabSize);
}
