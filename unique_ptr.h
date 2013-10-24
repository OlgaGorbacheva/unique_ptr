#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <memory>
#include <utility>

//#define NULL 0;

namespace my {

template<class T>
class unique_ptr;

}

template<class T>
class my::unique_ptr
{
private:
    T *pointer;
public:

    unique_ptr();
    unique_ptr(T * const p);
    unique_ptr(my::unique_ptr<T> &x) = delete;
    unique_ptr(my::unique_ptr<T> &&x);
    ~unique_ptr();

    T & operator *();
    T * operator ->();
    void operator =(my::unique_ptr<T> &&x);
    void operator =(my::unique_ptr<T> &x) = delete;
    void operator =(T * const x);
    void reset(T * const p);
    T * release();
    T * get();
};

#include "unique_ptr.hpp"

#endif // UNIQUE_PTR_H
