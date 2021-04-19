//
// Created by Arylise on 2021/4/18.
//

#ifndef CODING_CLASS05_H
#define CODING_CLASS05_H

#include "../base/BaseDefine.h"
#include <queue>

namespace C5
{
    class Q1
    {
        /**
         * 题目描述：
         * https://leetcode.com/problems/count-of-range-sum/
         * 给定一个数组arr，两个整数lower和upper，
         * 返回arr中有多少个子数组的累加和在[lower,upper]范围上
         */
        int *arr{};
        int ans = 0;
        int lower, upper;

        void _merge(int left, int mid, int right)
        {
            int l = left;
            int r = left;
            // [l, r)
            for (int i = mid + 1; i <= right; i++)
            {
                long min = arr[i] - upper;
                long max = arr[i] - lower;
                while (r <= mid && arr[r] <= max)
                {
                    r++;
                }
                while (l <= mid && arr[l] < min)
                {
                    l++;
                }
                ans += r - l;
            }
        }

        void _process(int left, int right)
        {
            if (left == right)
            {
                if (__range(lower, arr[left], upper))
                {
                    ans++;
                }
                return;
            }
            int mid = left + ((right - left) >> 1);
            _process(left, mid);
            _process(mid + 1, right);
            _merge(left, mid, right);
        }

    public:
        void countOfRangeSum()
        {
//            int n = 10;
//            arr = new int[n]{7, 4, 9, 6, 3, 5, 0, 2, 1, 8};
//            lower = 6;
//            upper = 11;
            __creatInt(n);
            arr = new int[n];
            __cinArray(arr, n);
            __cinN(lower);
            __cinN(upper);
            for (int i = 1; i < n; i++)
            {
                arr[i] += arr[i - 1];
//                arr[i-1]-=lower;
            }
//            arr[n-1]-=lower;
            __coutArray(arr, n);
            _process(0, n - 1);
            __coutN(ans);
        }

        int test(int *a, int n, int l, int u)
        {
            arr = new int[n];
            lower = l;
            upper = u;
            arr[0] = a[0];
            for (int i = 1; i < n; i++)
            {
                arr[i] = arr[i - 1] + a[i];
            }
            _process(0, n - 1);
            free(arr);
            return ans;
        }

        class Cmp
        {
            int *arr{};
            int ans = 0;
            int lower, upper;

            void _process(int left, int right)
            {
                for (int i = left; i <= right; i++)
                {
                    for (int j = i; j <= right; j++)
                    {
                        int res = 0;
                        for (int t = i; t <= j; t++)
                        {
                            res += arr[t];
                        }

                        if (__range(lower, res, upper))
                        {
                            ans++;
                        }
                    }
                }
            }

        public:
            void countOfRangeSum()
            {
                int n = 10;
                arr = new int[n]{7, 4, 9, 6, 3, 5, 0, 2, 1, 8};
                lower = 6;
                upper = 11;
//                __creatInt(n);
//                arr = new int[n];
//                __cinArray(arr, n);
//                __cinN(lower);
//                __cinN(upper);
                __coutArray(arr, n);
                _process(0, n - 1);
                __coutN(ans);
            }

            int test(int *a, int n, int l, int u)
            {
                arr = new int[n];
                lower = l;
                upper = u;
                for (int i = 0; i < n; i++)
                {
                    arr[i] = a[i];
                }
                _process(0, n - 1);
                free(arr);
                return ans;
            }
        };
    };

    class Q2
    {
        /**
         * Partition过程
         * 定一个数组arr，和一个整数num。请把小于等于num的数放在数组的左边，大于num的数放在数组的右边。
         * 要求额外空间复杂度O(1)，时间复杂度O(N)
         *
         * 荷兰国旗问题
         * 给定一个数组arr，和一个整数num。请把小于num的数放在数组的左边，等于num的数放在中间，大于num的数放在数组的右边。
         * 要求额外空间复杂度O(1)，时间复杂度O(N)
         */
    };

    class Q3
    {
        /**
         * 快速排序1.0
         *
         * 在arr[L..R]范围上，进行快速排序的过程：
         * 1）用arr[R]对该范围做partition，<= arr[R]的数在左部分并且保证arr[R]最后来到左部分的最后一个位置，记为M； <= arr[R]的数在右部分（arr[M+1..R]）
         * 2）对arr[L..M-1]进行快速排序(递归)
         * 3）对arr[M+1..R]进行快速排序(递归)
         * 因为每一次partition都会搞定一个数的位置且不会再变动，所以排序能完成
         *
         * 快速排序2.0
         * 在arr[L..R]范围上，进行快速排序的过程：
         * 1）用arr[R]对该范围做partition，< arr[R]的数在左部分，== arr[R]的数中间，>arr[R]的数在右部分。假设== arr[R]的数所在范围是[a,b]
         * 2）对arr[L..a-1]进行快速排序(递归)
         * 3）对arr[b+1..R]进行快速排序(递归)
         * 因为每一次partition都会搞定一批数的位置且不会再变动，所以排序能完成
         *
         * 快速排序1.0和2.0的时间复杂度分析
         *
         * 数组已经有序的时候就是复杂度最高的时候
         * 对于完全有序的数组会失去分治的优势，变为等差的排序（不管正序还是逆序）
         * 时间复杂度O(N^2)
         *
         * 快速排序3.0(随机快排+荷兰国旗技巧优化)
         *
         * 在arr[L..R]范围上，进行快速排序的过程：
         * 1）在这个范围上，随机选一个数记为num，
         * 1）用num对该范围做partition，< num的数在左部分，== num的数中间，>num的数在右部分。假设== num的数所在范围是[a,b]
         * 2）对arr[L..a-1]进行快速排序(递归)
         * 3）对arr[b+1..R]进行快速排序(递归)
         * 为每一次partition都会搞定一批数的位置且不会再变动，所以排序能完成
         *
         *
         * 随机快排的时间复杂度分析
         *
         * 1）通过分析知道，划分值越靠近中间，性能越好；越靠近两边，性能越差
         * 2）随机选一个数进行划分的目的就是让好情况和差情况都变成概率事件
         * 3）把每一种情况都列出来，会有每种情况下的时间复杂度，但概率都是1/N
         * 4）那么所有情况都考虑，时间复杂度就是这种概率模型下的长期期望！
         *
         * 时间复杂度O(N*logN)，额外空间复杂度O(logN)都是这么来的。
         */
    };
    namespace Cmp
    {

#define Question Q1
        int cmpTimes = 1000;
        int maxN = 1000;
        int maxAi = 1000;
        int maxU = 1000;

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
                int u = rand() % maxU;
                int l = rand() % u;

                auto *fun = new Question();
                auto *pCmp = new Question::Cmp();
#undef Question
                if (fun->test(a, n, l, u) != pCmp->test(a, n, l, u))
                {
                    __coutN("mother fucker!" << std::endl << n);
                    __coutArray(a, n);
                    __coutN(l << " " << u);
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


#endif //CODING_CLASS05_H
