//
// Created by Arylise on 2021/4/24.
//

#ifndef CODING_21_04_24_H
#define CODING_21_04_24_H

#include <iostream>
#include <queue>

// 网易笔试：网易游戏雷火事业群的笔试

//#define test
namespace sort
{
    int arr[100][100];
    int note[100];
    int N, M, T;
    int r1, r2, c1, c2, s, A;

    bool jud(int a, int b)
    {
        if (A)
            return a >= b;
        return a <= b;
    }

    void process(int left, int right)
    {
        if (left >= right)
            return;
        int mid = left + ((right - left) >> 1);
        process(left, mid);
        process(mid + 1, right);

        std::queue<int> queue;
        int start = left;
        int rightP = mid + 1;
        while (left <= mid && rightP <= right)
        {
#ifdef test
//            for(int i=0;i<5;i++){
//                std::cout<<note[i]<<" ";
//            }
            std::cout <<std::endl<< arr[note[left]][s] << " " << arr[note[rightP]][s] << " " << note[left] << " " << note[right]
                      << std::endl;
#endif
//3 5 2 4 3 1
//2 4 2 4 4 1
            queue.push(jud(arr[note[left]][s], arr[note[rightP]][s]) ? left++ : rightP++);
        }
        while (left <= mid)
        {
            queue.push(note[left++]);
        }
        while (!queue.empty())
        {
            note[start++] = queue.front();
            queue.pop();
        }
#ifdef test
        for(int i=0;i<5;i++){
            std::cout<<note[i]<<" ";
        }
        std::cout <<std::endl;
#endif
    }


    void output()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
#ifdef test
                std::cout << arr[i][j] << '\t';
#else
                std::cout << arr[i][j] << ' ';
#endif
            }
            std::cout << std::endl;
        }
    }

    void swap()
    {

#ifdef test
        std::cout << std::endl;
        for (int i = r1; i <= r2; i++)
        {
            std::cout << note[i] << " ";
        }
        std::cout << std::endl;
#endif
        for (int i = r1; i <= r2; i++)
        {
            while (note[i] != i)
            {
                for (int j = c1; j <= c2; j++)
                {
                    arr[i][j] = arr[i][j] ^ arr[note[i]][j];
                    arr[note[i]][j] = arr[i][j] ^ arr[note[i]][j];
                    arr[i][j] = arr[i][j] ^ arr[note[i]][j];
                }
                int c = note[i];
                note[i] = note[c];
                note[c] = c;
            }

        }
#ifdef test
        output();
        std::cout << std::endl;
        for (int i = r1; i <= r2; i++)
        {
            std::cout << note[i] << " ";
        }
        std::cout << std::endl;
#endif
    }

    void sortM()
    {
#ifdef test
        n = 5;
        m = 5;
        T = 1000;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = j + m * i;
#else
        std::cin >> N >> M >> T;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                std::cin >> arr[i][j];
#endif
        for (int i = 0; i < 100; i++)
            note[i] = i;
#ifdef test
        output();
#endif
        while (T--)
        {
            std::cin >> r1 >> r2 >> c1 >> c2 >> s >> A;
            r1--;
            r2--;
            c1--;
            c2--;
            s--;
#ifdef test
//            for (int i = 0; i < 5; i++)
//            {
//                std::cout << note[i];
//            }
            for (int i = r1; i <= r2; i++)
            {
                for (int j = c1; j <= c2; j++)
                {
                    std::cout << arr[i][j] << '\t';
                }
                std::cout << std::endl;
            }
#endif
            process(r1, r2);
            swap();
            for (int i = r1; i <= r2; i++)
            {
                note[i] = i;
            }
        }
        output();
    }
}


#endif //CODING_21_04_24_H
