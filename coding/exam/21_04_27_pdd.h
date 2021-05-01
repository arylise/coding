//
// Created by Arylise on 2021/4/27.
//

#ifndef CODING_21_04_27_PDD_H
#define CODING_21_04_27_PDD_H

#include <iostream>

using namespace std;

int log(int i)
{
    int k = 0;
    while (i != 1)
    {
        i = i >> 1;
        k++;
    }
    return k;
}

int high1(int i)
{
    i |= i >> 1;
    i |= i >> 2;
    i |= i >> 4;
    i |= i >> 8;
    i |= i >> 16;
    i++;
    i=i>>1;
    return log(i);
}

int fun1()
{
    int T;
    cin >> T;
    int day[32];
    while (T--)
    {
        for (int i = 0; i < 32; i++)
        {
            day[i] = 0;
        }
        int n;
        cin >> n;

        int max=high1(n)+1;

        cout<<max<<endl;

        int i = 1;
        while (i <= n)
        {
            if (i & n)
            {
                day[log(i)]++;
            }
            i = i << 1;
        }
        for (int i = 31; i >=0; i--)
        {
            if (day[i])
            {
                cout << max- i << " ";
                day[i] = 0;
            }
        }
        cout << endl;

    }
}

#endif //CODING_21_04_27_PDD_H
