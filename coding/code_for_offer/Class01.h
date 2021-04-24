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

    };

    class Q3
    {
        /**
 * 给定一个非负整数num，
 * 如何不用循环语句，
 * 返回>=num，并且离num最近的，2的某次方、
 */
        int nearest2Power(int in)
        {
            in--;
            in |= in >> 1;
            in |= in >> 2;
            in |= in >> 4;
            in |= in >> 8;
            in |= in >> 16;
            return in > 0 ? in + 1 : 1;
        }

    public:
        void test()
        {
            __coutN(nearest2Power(3));
        }
    };

    class Q4
    {
        /**
         * 一个数组中只有两种字符'G'和'B’，
         * 想让所有的G都放在左侧，所有的B都放在右侧
         * 但是只能在相邻字符之间进行交换操作，
         * 返回至少需要交换几次
         */

        char *arr;
        char A = 'G';
        char B = 'B';

        int minSwapStep(int n)
        {
            int funA = 0;
            int funB = 0;
            int left = 0;
            int right = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == A)
                {
                    funA += i - left++;
                } else
                {
                    funB += i - right++;
                }
//                __coutN(funA << " " << funB);
            }
            return funA < funB ? funA : funB;
        }

    public:
        void test()
        {
            int n = 14;
            arr = new char[n]{A, B, A, B, A, A, A, A, A, B, A, B, A, B};
            __coutN(minSwapStep(n));
        }
    };

    class Q5{
        /**
         * 给定一个二维数组matrix，
         * 你可以从任何位置出发，走向上下左右四个方向
         * 返回能走出来的最长的递增链长度
         */
    };

    class Q6{
        /**
         * 给定两个非负数组x和hp，长度都是N，再给定一个正数range
         * x有序，x[i]表示i号怪兽在x轴上的位置；hp[i]表示i号怪兽的血量
         * range表示法师如果站在x位置，用AOE技能打到的范围是：
         * [x-range,x+range]，被打到的每只怪兽损失1点血量
         * 返回要把所有怪兽血量清空，至少需要释放多少次AOE技能？
         */
    };

    class Q7{
        /**
         * 给定一个数组arr，你可以在每个数字之前决定+或者-
         * 但是必须所有数字都参与
         * 再给定一个数target，请问最后算出target的方法数是多少？
         */
    };

}

#endif //CODING_CLASS01_H

