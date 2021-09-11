#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include "student.h"

template <class T>
class APMaxHeap
{
    public:
        APMaxHeap();
        APMaxHeap(const APMaxHeap &h);
        ~APMaxHeap();

        APMaxHeap& push(T elem);

        APMaxHeap& pop();
        void popMax(size_t ind);

        std::vector<T> show();
        int operator[](size_t ind);
        APMaxHeap operator+(T elem);

    private:
        std::vector<T*> arr{};
        size_t ind{};
        std::vector<T> arr_sh;
        T* arri;
};

#include "apmaxheap.hpp"

#endif