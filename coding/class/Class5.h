//
// Created by Arylise on 2021/4/18.
//

#ifndef CODING_CLASS5_H
#define CODING_CLASS5_H

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
            int p = mid + 1;
            int start = left;
            int q = p;
            while (left <= mid && p <= right)
            {
                while (arr[left] >= (arr[q] - upper) && (arr[left] <= arr[q]))
                {
                    q++;
                }
                ans += q - p;
            }

            std::queue<int> queue;
            p = mid + 1;
            left = start;
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
            if (left == right)
            {
                if (arr[left] <= left && arr[left] >= right)
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
            int n = 10;
            arr = new int[n]{7, 4, 9, 6, 3, 5, 0, 2, 1, 8};
            lower = 6;
            upper = 11 - lower;
            for (int i = 1; i < n; i++)
            {
                arr[i] += arr[i - 1] - lower;
            }
            _process(0, n - 1);
            __coutArray(arr, n);
        }
    };
}

#endif //CODING_CLASS5_H
