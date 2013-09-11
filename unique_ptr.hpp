#include "unique_ptr.h"

template <class T>
my::unique_ptr<T>::unique_ptr()
{
    pointer = NULL;
}

template <class T>
my::unique_ptr<T>::unique_ptr(T * const p)
{
    pointer = *p;
}

template <class T>
my::unique_ptr<T>::unique_ptr(my::unique_ptr<T> &&x)
{
    pointer = x.pointer;
}

template <class T>
my::unique_ptr<T>::~unique_ptr()
{
    if (pointer != NULL)
        delete pointer;
}

template <class T>
T & my::unique_ptr<T>::operator *()
{
    return *(pointer);
}

template <class T>
T & my::unique_ptr<T>::operator ->()
{
    return *(pointer);
}

template <class T>
T * my::unique_ptr<T>::release ()
{
    T *p = pointer;
    pointer = NULL;
    return p;
}

template <class T>
void my::unique_ptr<T>::reset(T * const p)
{
    delete pointer;
    pointer = p;
}

template <class T>
T * my::unique_ptr<T>::get ()
{
    return pointer;
}

template <class T>
void my::unique_ptr<T>::operator =(my::unique_ptr<T> &&x)
{
    pointer = x.pointer;
}

template <class T>
void my::unique_ptr<T>::operator =(T * const x)
{
    pointer = x;
}