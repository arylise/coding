//
// Created by Arylise on 2021/4/12.
//

#ifndef CODING_CLASS04_H
#define CODING_CLASS04_H

#include "../base/BaseDefine.h"
#include <queue>
#include <cmath>
#include <memory>

namespace C4
{

    class mergeSort
    {
/**
 * mergeSort
 */
        int *arr;

        void _merge(int left, int mid, int right)
        {
            std::queue<int> queue;
            int start = left;
            int p = mid + 1;

            while (left <= mid && p <= right)
            {
                queue.push(arr[left] < arr[p] ? arr[left++] : arr[p++]);
            }

            while (left <= mid)
            {
                queue.push(arr[left++]);
            }

            while (!queue.empty())
            {
                arr[start++] = queue.front();
                queue.pop();
            }
        }

        /// 递归实现
        void _process1(int left, int right)
        {
            if (left >= right)
            {
                return;
            }
            int mid = left + ((right - left) >> 1);
            _process1(left, mid);
            _process1(mid + 1, right);
            _merge(left, mid, right);
        }

        /// 非递归实现
        void _process2(int left, int right)
        {
            if (!arr)
            {
                return;
            }
            int step = 1;
            while (true)
            {
                int L = left;
                while (L <= right)
                {
                    if (L + step > right)
                    {
                        break;
                    }
                    int M = L + step - 1;
                    int R = step < (right - M) ? M + step : right;
                    _merge(L, M, R);
                    L = R + 1;
                }
                if (step > (right - left + 1) / 2)
                {
                    break;
                }
                step <<= 1;
            }
        }

    public:
        void sort()
        {
            __creatInt(n);
            arr = new int[n];
            __cinArray(arr, n);
            _process2(0, n - 1);
            __coutArray(arr, n);
        }
    };

    class Q1
    {
/**
 * 在一个数组中，一个数左边比它小的数的总和，叫数的小和，所有数的小和累加起来，叫数组小和。求数组小和。例子： [1,3,4,2,5]
 * 1左边比1小的数：没有
 * 3左边比3小的数：1
 * 4左边比4小的数：1、3
 * 2左边比2小的数：1
 * 5左边比5小的数：1、3、4、2
 * 所以数组的小和为1+1+3+1+1+3+4+2=16
 */
        int *arr{};
        int ans = 0;

        void _merge(int left, int mid, int right)
        {
            std::queue<int> queue;
            int p = mid + 1;
            int start = left;

            int count = 0;
            while (left <= mid && p <= right)
            {
                if (arr[left] < arr[p])
                {
                    count += arr[left];
                    ans += arr[left];
                    queue.push(arr[left++]);
                } else
                {
                    queue.push(arr[p++]);
                    if (p <= right)
                    {
                        ans += count;
                    }
                }
            }
            p++;
            while (p <= right)
            {
                ans += count;
                p++;
            }


            while (left <= mid)
            {
                queue.push(arr[left++]);
            }

            while (!queue.empty())
            {
                arr[start++] = queue.front();
                queue.pop();
            }
        }

        void _process(int left, int right)
        {
            if (left >= right)
            {
                return;
            }
            int mid = left + ((right - left) >> 1);
            _process(left, mid);
            _process(mid + 1, right);
            _merge(left, mid, right);
        }

    public:
        void samllSum()
        {
//        int n = 3;
//        arr = new int[n]{1, 6, 4};

            int n = 28;
            arr = new int[n]{4, 6, 2, 7, 6, 4, 3, 9, 1, 3, 5, 7, 8, 5, 3, 5, 6, 3, 2, 8, 6, 5, 4, 9, 1, 0, 6, 4};
//        int n = 5;
//        arr = new int[n]{1,3,4,2,5};
            _process(0, n - 1);
            free(arr);
            __coutN(ans);
            __coutArray(arr, n);
        }

        int test(const int *a, int n)
        {
            arr = new int[n];
            for (int i = 0; i < n; i++)
            {
                arr[i] = a[i];
            }
            _process(0, n - 1);
            return ans;
        }

        class Cmp
        {
            int *arr;
            int ans = 0;

            void _process(int left, int right)
            {
                for (int i = left; i <= right; i++)
                {
                    for (int j = i + 1; j <= right; j++)
                    {
                        if (arr[i] < arr[j])
                        {
                            ans += arr[i];
                        }
                    }
                }
            }

        public:
            int test(const int *a, int n)
            {
                arr = new int[n];
                for (int i = 0; i < n; i++)
                {
                    arr[i] = a[i];
                }
                _process(0, n - 1);
                return ans;
            }
        };
    };

    class Q2
    {
        /**
         * 在一个数组中，
         * 任何一个前面的数a，和任何一个后面的数b，
         * 如果(a,b)是降序的，就称为逆序对
         * 返回数组中所有的逆序对
         */
        int *arr{};

        int ans = 0;

        void _merge(int left, int mid, int right)
        {
            std::queue<int> queue;
            int p = mid + 1;
            int start = left;
            int count = 0;
//        __coutArrayFrom(arr, left, right);
            while (left <= mid && p <= right)
            {
                if (arr[left] > arr[p])
                {
                    count++;
//                __coutN(count <<"___" << arr[left]);
                    queue.push(arr[left++]);
                    ans++;
                } else
                {
                    queue.push(arr[p++]);
                    if (p <= right)
                    {
//                    __coutN(count << "___"<<-1);
                        ans += count;
                    }
                }
            }
            p++;
            while (p <= right)
            {
//            __coutN(count << "___"<<-1);
                ans += count;
                p++;
            }


            while (left <= mid)
            {
                queue.push(arr[left++]);
            }

            while (!queue.empty())
            {
                arr[start++] = queue.front();
                queue.pop();
            }
        }

        void _process(int left, int right)
        {
            if (left >= right)
            {
                return;
            }
            int mid = left + ((right - left) >> 1);
            _process(left, mid);
            _process(mid + 1, right);
            _merge(left, mid, right);
        }

    public:
        void reversePair()
        {
//        int n = 9;
//        arr = new int[n]{2, 6, 4, 8, 1, 3, 9, 5, 7};
            int n = 27;
            arr = new int[n]{2, 6, 3, 7, 5, 6, 2, 9, 5, 6, 3, 5, 8, 9, 0, 1, 3, 7, 6, 5, 4, 8, 3, 2, 9, 1, 7};

            _process(0, n - 1);
            __coutN(ans);
            __coutArray(arr, n);
            free(arr);
        }

        int test(const int *a, int n)
        {
            arr = new int[n];
            for (int i = 0; i < n; i++)
            {
                arr[i] = a[i];
            }
            _process(0, n - 1);
            return ans;
        }

        class Cmp
        {
            int ans = 0;
            int *arr{};

            void _process(int left, int right)
            {
                for (int i = left; i <= right; i++)
                {
                    for (int j = i + 1; j <= right; j++)
                    {
                        if (arr[i] > arr[j])
                        {
                            ans++;
                        }
                    }
                }
            }

        public:
            void reversePair()
            {
                int n = 27;
                arr = new int[n]{2, 6, 3, 7, 5, 6, 2, 9, 5, 6, 3, 5, 8, 9, 0, 1, 3, 7, 6, 5, 4, 8, 3, 2, 9, 1, 7};
                _process(0, n - 1);
                __coutN(ans);
                free(arr);
            }

            int test(const int *a, int n)
            {
                arr = new int[n];
                for (int i = 0; i < n; i++)
                {
                    arr[i] = a[i];
                }
                _process(0, n - 1);
                return ans;
            }
        };
    };

    class Q3
    {
        /**
         * 在一个数组中，
         * 对于每个数num，求有多少个后面的数 * 2 依然<num，求总个数
         * 比如：[3,1,7,0,2]
         * 3的后面有：1，0
         * 1的后面有：0
         * 7的后面有：0，2
         * 0的后面没有
         * 2的后面没有
         * 所以总共有5个
         */
        int *arr{};
        int ans = 0;

        void _merge(int left, int mid, int right)
        {

            int p = mid + 1;
            for (int i = left; i <= mid; i++)
            {
                while (p <= right && arr[i] > (arr[p] * 2))
                {
                    p++;
                }
                ans += p - mid - 1;
            }

            std::queue<int> queue;
            int start = left;
            p = mid + 1;

            while (left <= mid && p <= right)
            {
                if (arr[left] < arr[p])
                {
                    queue.push(arr[left++]);
                } else
                {
                    queue.push(arr[p++]);
                }
            }


            while (left <= mid)
            {
                queue.push(arr[left++]);
            }
            while (!queue.empty())
            {
                arr[start++] = queue.front();
                queue.pop();
            }
        }

        void _process(int left, int right)
        {
            if (left >= right)
            {
                return;
            }
            int mid = left + ((right - left) >> 1);
            _process(left, mid);
            _process(mid + 1, right);
            _merge(left, mid, right);
        }


    public:
        int test(const int *a, int n)
        {
            arr = new int[n];
            for (int i = 0; i < n; i++)
            {
                arr[i] = a[i];
            }
            _process(0, n - 1);
            return ans;
        }

        void bigTwoTimes()
        {
            int n = 10;
            arr = new int[n]{7, 4, 9, 6, 3, 5, 0, 2, 1, 8};
//        int n = 5;
//        arr = new int[n]{3, 1, 7, 0, 2};
            _process(0, n - 1);
            free(arr);
            __coutN(ans);
        }


        class Cmp
        {
            int *arr{};
            int ans = 0;

            void _process(int left, int right)
            {
                for (int i = left; i <= right; i++)
                {
                    for (int j = i + 1; j <= right; j++)
                    {
                        if (arr[i] > arr[j] << 1)
                        {
                            ans++;
                        }
                    }
                }

            }

        public:
            int test(const int *a, int n)
            {
                arr = new int[n];
                for (int i = 0; i < n; i++)
                {
                    arr[i] = a[i];
                }
                _process(0, n - 1);
                return ans;
            }

            void bigTwoTimes()
            {
//        int n = 27;
//        arr = new int[n]{2, 6, 3, 7, 5, 6, 2, 9, 5, 6, 3, 5, 8, 9, 0, 1, 3, 7, 6, 5, 4, 8, 3, 2, 9, 1, 7};
                int n = 10;
                arr = new int[n]{7, 4, 9, 6, 3, 5, 0, 2, 1, 8};
//        int n = 5;
//        arr = new int[n]{3, 1, 7, 0, 2};
                _process(0, n - 1);
                free(arr);
                __coutN(ans);
            }
        };


    };

    namespace Cmp
    {

#define Question Q1
        int cmpTimes = 1000;
        int maxN = 1000;
        int maxAi = 1000;

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
                auto *fun = new Question();
                auto *pCmp = new Question::Cmp();
#undef Question
                if (fun->test(a, n) != pCmp->test(a, n))
                {
                    __coutN("mother fucker!" << std::endl << n);
                    __coutArray(a, n);
                    cmp = false;
                    break;
                }
                free(fun);
                free(pCmp);
                free(a);
            }
            if (cmp)
            {
                __coutN("ok");
            }
        }
    }
}

#endif //CODING_CLASS04_H
