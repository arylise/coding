//
// Created by Arylise on 2021/4/24.
//

#ifndef CODING_21_04_24_2_H
#define CODING_21_04_24_2_H

#include <iostream>

//long long b(int n);
//
//long long c(int n);
//
//long long a(int n)
//{
//    if (n == 0)
//    {
//        return 1;
//    }
//    return a(n - 1) + b(n - 1);
//}
//
//long long b(int n)
//{
//    if (n == 0)
//    {
//        return 1;
//    }
//    return c(n - 1);
//}
//
//long long c(int n)
//{
//    if (n == 0)
//    {
//        return 1;
//    }
//    return a(n - 1);
//}
//
//long long func(int n)
//{
//    return a(n) + b(n);
//}

void test()
{
    int arr[1000][3];
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[0][2] = 0;
    for (int i = 1; i < 10; i++)
    {
        arr[i][0] = (arr[i - 1][0] + arr[i - 1][2]) % 998244353;
        arr[i][1] = (arr[i - 1][0]) % 998244353;
        arr[i][2] = (arr[i - 1][1]) % 998244353;
        std::cout << i << ' ' << (arr[i][0] + arr[i][1] + arr[i][2]) % 998244353 << std::endl;
    }
}

void test2()
{
    int n;
    std::cin >> n;
    n -= 2;
    if (n < 3)
    {
        std::cout << n + 1 << std::endl;
        return;
    }
    long long arr[n];
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 4;
    for (int i = 3; i < n; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 3]) % 998244353;
    }
    std::cout << arr[n - 1] << std::endl;
}

#endif //CODING_21_04_24_2_H
