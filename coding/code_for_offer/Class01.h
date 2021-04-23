//
// Created by Arylise on 2021/4/22.
//

#ifndef CODING_CLASS01_H
#define CODING_CLASS01_H

#include "../base/BaseDefine.h"
#include <algorithm>

namespace C1
{
    class Q1
    {
        /**
         * 给定一个有序数组arr，代表坐落在X轴上的点
         * 给定一个正数K，代表绳子的长度
         * 返回绳子最多压中几个点？
         * 即使绳子边缘处盖住点也算盖住
         */
        int *arr;
        int K;

        int test(int n)
        {
            int right = 0;
            while (arr[right] <= K && right < n)
                right++;
            int ans = right;
            int left = 1;
            while (right < n)
            {
                while (arr[left] < arr[right] - K)
                    left++;
                ans = ans > ++right - left ? ans : right - left;
            }
            return ans;
        }

    public:
        void cordCoverMaxPoint()
        {
            int n = 5;
            K = 4;
            arr = new int[n]{1, 2, 7, 8, 9};
            __coutN(test(n));
        }
    };

    class Q2
    {
        /**
         * 给定一个文件目录的路径，
         * 写一个函数统计这个目录下所有的文件数量并返回
         * 隐藏文件也算，但是文件夹不算
         */

#ifdef _WIN64
        int countFiles(FILE *p)
        {

        }
    };

}

#endif //CODING_CLASS01_H
