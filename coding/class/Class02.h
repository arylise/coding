//
// Created by Arylise on 2021/4/7.
//

#ifndef CODING_CLASS02_H
#define CODING_CLASS02_H

#include <iostream>

using namespace std;


class Q1
{
    /**
     * 如何不用额外变量交换两个数
     *
     * 异或
     */
    static void swap(int a, int b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        cout << a << b;
    }
};

class Q2
{
    /**
     * 一个数组中有一种数出现了奇数次，其他数都出现了偶数次，怎么找到并打印这种数
     *
     * 异或
     */
    static void findOddTime(const int *a, int n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans ^= a[i];
        }
        cout << ans;
    }
};

class Q3
{
    /**
     * 怎么把一个int类型的数，提取出最右侧的1来
     *
     * 利用int取反加一为其负数特性
     * 01001110101000      a
     * 10110001010111 取反  b
     * 10110001011000 加一  c
     * a&c能达到目的
     *
     * 当n取反之后右边所有的0变为1，右边第一个1变0，加1后则最右边的0变1，
     */
    static void lastRight(int n)
    {
        n &= -n;
        cout << n;
    }
};

class Q4
{
    /**
     * 一个数组中有两种数出现了奇数次，其他数都出现了偶数次，怎么找到并打印这两种数
     */
    static void findTwoTimesOdd(int *a, int n)
    {
        int Y = 0;/// 找到所有数的异或
        for (int i = 0; i < n; i++)
        {
            Y ^= a[i];
        }
        int YY = (-Y) & Y;/// 这个异或就是需要找的两数异或值,只要找到他们为1的位置,就可以确定这两个树在这个位置不一样,方便起见就取最后一位为1的位置
        int ans = 0;
        for (int i = 0; i < n; i++)
        {/// 因为两数在YY位置不一样,就可以利用这个分开这两个数
            if (YY & a[i])
                ans ^= a[i];
        }
        Y ^= ans;/// 取另外那个数
        cout << ans << Y;
    }
};

class Q5
{
    /**
     * 一个数组中有一种数出现K次，其他数都出现了M次，
     * m > 1,  K < m
     * 找到，出现了K次的数，
     * 要求，额外空间复杂度O(1)，时间复杂度O(n)
     */
    static int log(int in)
    {
        int ans = -1;
        while (in)
        {
            ans++;
            in = in >> 1;
        }
        return ans;
    }

    static void findKTines(int *a, int n, int K, int M)
    {
        int loc[32];
        for (int & i : loc)
            i = 0;
        for (int i = 0; i < n; i++)
        {
            while (a[i])
            {
                int rightOne = (-a[i]) & a[i];
                loc[log(rightOne)]++;
                a[i] ^= rightOne;
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (loc[i] % M == K)
            {
                ans |= (1 << i);
            }
        }
        cout << ans;
    }
};

#endif //CODING_CLASS02_H
