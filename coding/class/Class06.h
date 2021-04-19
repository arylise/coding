//
// Created by Arylise on 2021/4/19.
//

#ifndef CODING_CLASS06_H
#define CODING_CLASS06_H

#include <algorithm>
#include "../base/BaseDefine.h"

class Heap
{
private:
    int limit;
    int *arr{};
    int heapSize = 0;

    int _cmp(int a, int b)
    {
        return arr[a] - arr[b];
    }

    void _swap(int a, int b)
    {
        if (a == b)
        {
            return;
        }
        int c = arr[a];
        arr[a] = arr[b];
        arr[b] = c;
    }

    void _heapInsert(int index)
    {
        int parent = (index - 1) / 2;
        while (_cmp(index, parent) > 0)
        {
            _swap(index, parent);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void _heapIfy(int index)
    {
        int left = index * 2 + 1;
        while (left < heapSize)
        {
            int largest = left + 1 < heapSize && _cmp(left, left + 1) < 0 ? left + 1 : left;
            largest = _cmp(largest, index) > 0 ? largest : index;
            if (largest == index)
            {
                break;;
            }
            _swap(largest, index);
            index = largest;
            left = index * 2 + 1;
        }
    }

public:
    Heap(int setLimit)
    {
        limit = setLimit;
        arr = new int[limit]{};
    }

    Heap()
    {
        limit = 16;
        arr = new int[limit]{};
    }

    bool push(int value)
    {
        if (isFull())
        {
            return false;
        }
        arr[heapSize] = value;
        _heapInsert(heapSize++);
        return true;
    }

    int pull()
    {
        int ans = top();
        pop();
        return ans;
    }

    bool pop()
    {
        if (isEmpty())
        {
            return false;
        }
        _swap(0, --heapSize);
        _heapIfy(0);
        return true;
    }

    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[0];
    }

    bool isEmpty() const
    {
        return heapSize == 0;
    }

    bool isFull() const
    {
        return heapSize == limit;
    }

    int size() const
    {
        return heapSize;
    }

    void showHeap()
    {
        __coutArray(arr, heapSize);
    }
};

class HeapSort
{
private:
    int *arr{};
    int heapSize = 0;

    int _cmp(int a, int b)
    {
        return arr[a] - arr[b];
    }

    void _swap(int a, int b)
    {
        if (a == b)
        {
            return;
        }
        int c = arr[a];
        arr[a] = arr[b];
        arr[b] = c;
    }

    void _heapInsert(int index)
    {
        int parent = (index - 1) / 2;
        while (_cmp(index, parent) > 0)
        {
            _swap(index, parent);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void _heapIfy(int index)
    {
        int left = index * 2 + 1;
        while (left < heapSize)
        {
            int largest = left + 1 < heapSize && _cmp(left, left + 1) < 0 ? left + 1 : left;
            largest = _cmp(largest, index) > 0 ? largest : index;
            if (largest == index)
            {
                break;;
            }
            _swap(largest, index);
            index = largest;
            left = index * 2 + 1;
        }
    }

public:
    int *sort()
    {
        __cinN(heapSize);
        arr = new int[heapSize];
        __cinArray(arr, heapSize);
        __coutArray(arr, heapSize);
        for (int i = (heapSize - 1) / 2; i >= 0; i--)
        {
            _heapIfy(i);
        }
        _swap(0, --heapSize);
        while (heapSize > 0)
        {
            _heapIfy(0);
            _swap(0, --heapSize);
        }
        __coutArray(arr, heapSize);
        return arr;
    }

    int *test(const int *a, int n)
    {
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = a[i];
        }
        heapSize = n;
        for (int i = (heapSize - 1) / 2; i >= 0; i--)
        {
            _heapIfy(i);
        }
        _swap(0, --heapSize);
        while (heapSize > 0)
        {
            _heapIfy(0);
            _swap(0, --heapSize);
        }
        return arr;
    }

    void end()
    {
        free(arr);
        free(this);
    }
};
namespace Cmp
{
    int cmpTimes = 100;
    int maxN = 100;
    int maxAi = 1000;


    bool judQ2(int *a, int n)
    {
        auto *fun = new HeapSort();
        int *b = fun->test(a, n);
        int *c = new int[n];
        for (int i = 0; i < n; i++)
        {
            c[i] = a[i];

        }
        std::sort(c, c + n - 1);
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        fun->end();
        free(c);
        return true;
    }

#define jud judQ2

    void test()
    {
        bool cmp = true;
        while (cmpTimes--)
        {
            int n = rand() % maxN;
            int *a = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = rand() % maxAi;
            }
            if (jud(a, n))
            {
#undef jud
                __coutN("mother fucker!" << std::endl << n);
                __coutArray(a, n);
                free(a);
                cmp = false;
                break;
            }

        }
        if (cmp)
        {
            __coutN("ok");
        }
    }
}

void test()
{
    Heap *heap = new Heap();
    heap->push(4);
    heap->push(6);
    heap->push(12);
    heap->push(7);
    heap->push(5);
    heap->push(0);
    heap->push(3);
    heap->push(4);
    while (!heap->isEmpty())
        __coutN(heap->pull());
}

#endif //CODING_CLASS06_H
